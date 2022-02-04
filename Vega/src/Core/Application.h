#pragma once

#include "Threads/ThreadsController.h"
#include "Renderer/Renderer.h"

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

		std::shared_ptr<Renderer> GetRenderer() { return m_Renderer; }

		inline static Application* Get() { return s_Application; }
	protected:
		inline static Application* s_Application = nullptr;

		std::shared_ptr<Renderer> m_Renderer;

		std::shared_ptr<ThreadsController> m_ThreadsController;
	};

}