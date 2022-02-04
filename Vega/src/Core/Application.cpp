#include "Application.h"
#include "Debug/ConsoleLog.h"

namespace LM
{

	Application::Application()
	{
		srand(time(NULL));
		s_Application = this;

		m_Renderer = std::make_shared<Renderer>();

		m_ThreadsController = std::make_shared<ThreadsController>();
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (true)
		{

		}
	}

}