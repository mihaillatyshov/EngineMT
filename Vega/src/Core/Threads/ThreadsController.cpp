#include "ThreadsController.h"

#include <thread>

#include "Core/Application.h"
#include "Debug/ConsoleLog.h"

namespace LM
{

	ThreadsController::ThreadsController()
	{
		m_Graphics = std::make_shared<Graphics>();

		m_ThreadPool = std::make_shared<ThreadPool>(std::max(1u, std::thread::hardware_concurrency()));
		m_ThreadPool->Enqueue([=]() { TestFoo2(); });
		m_ThreadPool->Enqueue([=]() { TestFoo2(); });
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

	void ThreadsController::TestFoo2()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		for (size_t i = 0; i < 100'000; i++)
		{
			float x = float(std::rand() % 1800 - 900) / 1000.0f;
			float y = float(std::rand() % 1800 - 900) / 1000.0f;
			std::shared_ptr<Renderable> Obj = std::make_shared<Renderable>(glm::vec2(x, y), glm::vec2(0.1f, 0.1f));
			Application::Get()->GetRenderer()->Add(Obj);
			if (i % 10'000 == 0)
				LOGI("Renderables count:", i);
		}
		LOGI("End of TestFoo2");
	}

}