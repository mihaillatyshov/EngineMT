#pragma once

#include <thread>
#include <vector>

#include <glm.hpp>

#include "Window.h"
#include "Renderer/Renderer.h"

namespace LM
{

	class Graphics
	{
	public:
		Graphics();
		~Graphics();

	protected:
		void Init();
		void Run();
		void TestRender();
	protected:
		std::shared_ptr<Window> m_Window;
		std::shared_ptr<std::thread> m_Thread;

		std::shared_ptr<Renderer> m_Renderer;
		std::vector<glm::vec3> m_Renderables;
	};

}