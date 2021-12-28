#pragma once

#include <condition_variable>
#include <functional>
#include <future>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>
#include <queue>

namespace LM
{

	class ThreadPool
	{
	public:
		using Task = std::function<void()>;

		explicit ThreadPool(size_t _NumThreads)
		{
			m_WorkingThreads = 0;
			Start(_NumThreads);
		}

		~ThreadPool()
		{
			Stop();
		}

		//template<class T>
		//auto Enqueue(T task)->std::future<decltype(task())>
		//{
		//	auto wrapper = std::make_shared<std::packaged_task<decltype(task())()>>(std::move(task));
		//
		//	{
		//		std::unique_lock lock(m_EventMutex);
		//		m_Tasks.emplace([=]
		//		{
		//			(*wrapper)();
		//		});
		//	}
		//
		//	m_EventVar.notify_one();
		//	return wrapper->get_future();
		//}

		void Enqueue(Task _Task);
		void Enqueue(const std::vector<Task>& _Tasks);
		inline int32_t GetWorkingThreads() const { return m_WorkingThreads; }
	private:
		void Start(size_t _NumThreads);
		void Stop() noexcept;
	private:
		std::vector<std::thread> m_Threads;
		std::condition_variable m_EventVar;
		std::mutex m_EventMutex;
		bool m_Stopping = false;

		std::queue<Task> m_Tasks;
		std::atomic<int32_t> m_WorkingThreads;
	};

}