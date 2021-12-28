#include "Application.h"

namespace LM
{

	Application::Application()
	{
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