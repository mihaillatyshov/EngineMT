#pragma once

#include <vector>
#include <deque>
#include <queue>
#include <memory>
#include <shared_mutex>

#include <glm.hpp>

#include "Renderable/Renderable.h"

namespace LM
{

	struct RenderableInfo
	{
		std::shared_ptr<Renderable> UID;			// UID
		// size_t DataId;							// Id of data arrays in Renderer
		// size_t IndStartId;						// Indices start id in Renderer data
		// size_t IndCount;							// Indices count
		size_t StartId;								// Points start id in Renderer data
		size_t Count;								// Points count
		// And for another buffers info like transormation matrices(not need for count)
	};

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Draw();
		void Vertex2f(const glm::vec2& _Vertex);

		void Add(std::shared_ptr<Renderable> _Renderable);
	protected:
		void AddToDraw();
	protected:
		std::vector<glm::vec4> m_PointsBuffer;
		std::deque<RenderableInfo> m_RenderableInfo;
		std::queue<std::shared_ptr<Renderable>> m_AddRenderables;
		std::shared_mutex m_AddMtx;
	};

}