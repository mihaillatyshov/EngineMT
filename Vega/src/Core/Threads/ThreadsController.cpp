#include "ThreadsController.h"

#include <thread>

namespace LM
{

	ThreadsController::ThreadsController()
	{
		m_Graphics = std::make_shared<Graphics>();

		m_ThreadPool = std::make_shared<ThreadPool>(std::max(1u, std::thread::hardware_concurrency()));
		m_ThreadPool->Enqueue([=]() { TestFoo(); });
		m_ThreadPool->Enqueue([=]() { TestFoo(); });
	}

	ThreadsController::~ThreadsController()
	{

	}

	void ThreadsController::TestFoo()
	{
		float sum = 0.0f;
		while (true)
		{
			sum += std::sin(rand() / 5.0f) + 2 * std::cos(rand() / 15.0f) + std::fmod(std::log(rand() % 1'000 + 1), 100.0f);
		}
	}

}