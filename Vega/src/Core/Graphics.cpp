#include "Graphics.h"

namespace LM
{

	Graphics::Graphics()
	{
		m_Thread = std::make_shared<std::thread>([=]()
			{
				m_Window = std::make_shared<Window>("EngineMT", 800, 600);

				Run();
			});
	}

	Graphics::~Graphics()
	{

	}

	void Graphics::Run()
	{
		while (!m_Window->Closed()) // Add in Application class this data
		{
			//PROFILE_SCOPE("Game Loop");
			//Timer timer;
			m_Window->Clear();

			//for (Layer* layer : m_LayerStack)
			//	layer->OnUpdate();


			//m_ImGuiLayer->Start();
			//for (Layer* layer : m_LayerStack)
			//	layer->OnImGuiRender();
			//m_ImGuiLayer->End();

			m_Window->Update();
		}
	}

}