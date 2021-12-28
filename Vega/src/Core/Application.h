#pragma once

#include "Threads/ThreadsController.h"

namespace LM
{

	// Layers - Game Logic
	// Physics
	// Graphics
	// AI

	class Application
	{
	public:
		Application();
		~Application();
		void Run();
	protected:
		std::shared_ptr<ThreadsController> m_ThreadsController;
	};

}