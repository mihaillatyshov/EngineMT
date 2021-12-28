#include "ThreadPool.h"

namespace LM
{

	void ThreadPool::Enqueue(Task _Task)
	{
		{
			std::unique_lock Lock(m_EventMutex);
			m_WorkingThreads++;
			m_Tasks.emplace(std::move(_Task));
		}

		m_EventVar.notify_one();
	}

	void ThreadPool::Enqueue(const std::vector<Task>& _Tasks)
	{
		{
			std::unique_lock Lock(m_EventMutex);
			m_WorkingThreads += _Tasks.size();
			for (size_t i = 0; i < _Tasks.size(); i++)
			{
				m_Tasks.emplace(std::move(_Tasks[i]));
			}
		}

		m_EventVar.notify_all();
	}

	void ThreadPool::Start(size_t _NumThreads)
	{
		for (int i = 0; i < _NumThreads; i++)
		{
			m_Threads.emplace_back([=] {
				while (true)
				{
					Task task;

					{
						std::unique_lock Lock(m_EventMutex);

						m_EventVar.wait(Lock, [=] { return m_Stopping || !m_Tasks.empty(); });

						if (m_Stopping && m_Tasks.empty())
							break;

						task = std::move(m_Tasks.front());
						m_Tasks.pop();
						//m_UsingThreads += 1;
					}

					task();
					m_WorkingThreads--;
				}
				});
		}
	}


	void ThreadPool::Stop() noexcept
	{
		{
			std::unique_lock Lock(m_EventMutex);
			m_Stopping = true;
		}

		m_EventVar.notify_all();

		for (auto& Thread : m_Threads)
		{
			Thread.join();
		}
	}

}