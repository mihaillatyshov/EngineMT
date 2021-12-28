#pragma once

#include <thread>
#include "Window.h"

namespace LM
{

	class Graphics
	{
	public:
		Graphics();
		~Graphics();

	protected:
		void Run();
	protected:
		std::shared_ptr<Window> m_Window;
		std::shared_ptr<std::thread> m_Thread;
	};

}