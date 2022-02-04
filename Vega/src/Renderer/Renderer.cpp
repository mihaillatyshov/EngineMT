#include "Renderer.h"

#include <gl/glew.h>
#include <gtx/transform.hpp>
#include <ranges>

namespace LM
{

	Renderer::Renderer()
	{

	}

	Renderer::~Renderer()
	{

	}

	void Renderer::Draw()
	{
		AddToDraw();

		glBegin(GL_TRIANGLES);
		for (size_t i = 0; i < m_PointsBuffer.size(); i += 4)
		{
			Vertex2f(glm::vec2(m_PointsBuffer[i + 0].x, m_PointsBuffer[i + 0].y) + m_RenderableInfo[i / 4].UID->GetPosition());
			Vertex2f(glm::vec2(m_PointsBuffer[i + 1].x, m_PointsBuffer[i + 1].y) + m_RenderableInfo[i / 4].UID->GetPosition());
			Vertex2f(glm::vec2(m_PointsBuffer[i + 2].x, m_PointsBuffer[i + 2].y) + m_RenderableInfo[i / 4].UID->GetPosition());
			
			Vertex2f(glm::vec2(m_PointsBuffer[i + 0].x, m_PointsBuffer[i + 0].y) + m_RenderableInfo[i / 4].UID->GetPosition());
			Vertex2f(glm::vec2(m_PointsBuffer[i + 2].x, m_PointsBuffer[i + 2].y) + m_RenderableInfo[i / 4].UID->GetPosition());
			Vertex2f(glm::vec2(m_PointsBuffer[i + 3].x, m_PointsBuffer[i + 3].y) + m_RenderableInfo[i / 4].UID->GetPosition());
		}
		glEnd();
	}

	void Renderer::Vertex2f(const glm::vec2& _Vertex)
	{
		glVertex2f(_Vertex.x, _Vertex.y);

	}

	void Renderer::Add(std::shared_ptr<Renderable> _Renderable)
	{
		std::unique_lock Lock(m_AddMtx);
		m_AddRenderables.push(_Renderable);	
	}

	void Renderer::AddToDraw()
	{
		std::shared_lock Lock(m_AddMtx);
		while (!m_AddRenderables.empty())
		{
			auto Item = m_AddRenderables.front();
			m_AddRenderables.pop();
			m_RenderableInfo.emplace_back(Item, m_RenderableInfo.size() * 4, 4);
			m_PointsBuffer.emplace_back(-Item->GetSize().x / 2.0f, -Item->GetSize().y / 2.0f, 0.0f, 0.0f);
			m_PointsBuffer.emplace_back( Item->GetSize().x / 2.0f, -Item->GetSize().y / 2.0f, 0.0f, 0.0f);
			m_PointsBuffer.emplace_back( Item->GetSize().x / 2.0f,  Item->GetSize().y / 2.0f, 0.0f, 0.0f);
			m_PointsBuffer.emplace_back(-Item->GetSize().x / 2.0f,  Item->GetSize().y / 2.0f, 0.0f, 0.0f);
		}
	}

}