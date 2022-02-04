#pragma once

#include "ThreadPool.h"
#include "Core/Graphics.h"

namespace LM
{

	class ThreadsController
	{
	public:
		ThreadsController();
		~ThreadsController();
	protected:
		void TestFoo();
		void TestFoo2();
	protected:
		std::shared_ptr<Graphics> m_Graphics;
		std::shared_ptr<ThreadPool> m_ThreadPool;
	};

}