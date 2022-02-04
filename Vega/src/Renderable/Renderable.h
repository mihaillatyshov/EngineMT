#pragma once



namespace LM
{

	class Renderable
	{
	public:
		Renderable(glm::vec2 _Pos, glm::vec2 _Size)
			: m_Pos(_Pos), m_Size(_Size) { }

		inline const glm::vec2 GetPosition()	const { return m_Pos; }
		inline const glm::vec2 GetSize()		const { return m_Size; }
	protected:
		glm::vec2 m_Pos;
		glm::vec2 m_Size;
	};

}