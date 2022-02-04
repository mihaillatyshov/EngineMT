#include "Graphics.h"

#include "Core/Application.h"
#include "Debug/ConsoleLog.h"

namespace LM
{

	Graphics::Graphics()
	{
		m_Thread = std::make_shared<std::thread>([=]()
			{
				LOGI("[ GT ]: Init . . .");
				Init();
				
				LOGI("[ GT ]: Window Opened");
				Run();
				LOGI("[ GT ]: Window Closed");
			});
	}

	Graphics::~Graphics()
	{

	}

	void Graphics::Init()
	{
		m_Window = std::make_shared<Window>("EngineMT", 800, 600);
		m_Renderer = Application::Get()->GetRenderer();

		//m_Renderables.emplace_back(0.0f, 0.0f, 0.0f);
		//m_Renderables.emplace_back(0.0f, 0.5f, 0.0f);
		//m_Renderables.emplace_back(0.5f, 0.5f, 0.0f);
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

			//TestRender();
			m_Renderer->Draw();
			//m_ImGuiLayer->Start();
			//for (Layer* layer : m_LayerStack)
			//	layer->OnImGuiRender();
			//m_ImGuiLayer->End();

			m_Window->Update();
		}
	}

	void Graphics::TestRender()
	{
		for (const auto& Center : m_Renderables)
		{
			std::vector<glm::vec3> Points = {
				Center + glm::vec3(-0.1f, -0.1f, 0.0f),
				Center + glm::vec3(0.1f, -0.1f, 0.0f),
				Center + glm::vec3(0.0f,  0.1f, 0.0f)
			};
			glBegin(GL_TRIANGLES);
			for (const auto& Point : Points)
			{
				glVertex3f(Point.x, Point.y, Point.z);
			}
			glEnd();
		}
	}

}