#include "GameObject\LGameObject.h"

LGameObject::LGameObject(Vector2f mPos, Vector2f mSize)
{
	InitVertexArray(LPrimitive::LSQUARE, mPos, mSize);
	setPosition(mPos);
	m_v2Size = mSize;
}

LGameObject::LGameObject(LPrimitive mPrimitiveType, Vector2f mPos, Vector2f mSize)
{
	InitVertexArray(mPrimitiveType, mPos, mSize);
	setPosition(mPos);
	m_v2Size = mSize;
}

void LGameObject::draw(sf::RenderTarget & renderTarget, sf::RenderStates renderStates) const
{
	if (m_bIsActive)
	{
		renderStates.transform *= getTransform();
		renderStates.texture = m_pTexture;

		renderTarget.draw(m_vertexArray, renderStates);
	}
}

void LGameObject::Update(float dTime)
{
	//UpdateGlobalBounds();
}

void LGameObject::SetSize(const Vector2f& mSize)
{
	InitVertexArray(LPrimitive::LSQUARE, getPosition(), mSize);
	m_v2Size = mSize;
}

bool LGameObject::IsCollisionBetween(LGameObject * obj1, LGameObject * obj2)
{
	if (obj1->GetIsActive() && obj2->GetIsActive())
	{
		if (obj1 != obj2)
		{
			if (obj1->GetGlobalBounds().intersects(obj2->GetGlobalBounds()))
			{
				return true;
			}
		}
	}

	return false;
}

void LGameObject::InitVertexArray(LPrimitive mPrimitiveType, const Vector2f& mPos, const Vector2f& mSize)
{
	switch (mPrimitiveType)
	{
		case LPrimitive::LSQUARE:

			m_vertexArray = VertexArray(PrimitiveType::Quads, 4);

			m_vertexArray[0].position = Vector2f(mPos.x, mPos.y);
			m_vertexArray[1].position = Vector2f(mPos.x + mSize.x, mPos.y);
			m_vertexArray[2].position = Vector2f(mPos.x + mSize.x, mPos.y + mSize.y);
			m_vertexArray[3].position = Vector2f(mPos.x, mPos.y + mSize.y);

			m_vertexArray[0].texCoords = Vector2f(0, 0);
			m_vertexArray[1].texCoords = Vector2f(mSize.x, 0);
			m_vertexArray[2].texCoords = Vector2f(mSize.x, mSize.y);
			m_vertexArray[3].texCoords = Vector2f(0, mSize.y);

			m_bIsActive = true;
		break;
		default:
			m_bIsActive = false;
		break;
	}
}

void LGameObject::UpdateGlobalBounds()
{
	Vector2f topLeft = getTransform().transformPoint(0, 0);

	m_frGlobalBounds.left = topLeft.x;
	m_frGlobalBounds.top = topLeft.y;
	m_frGlobalBounds.width = m_v2Size.x;
	m_frGlobalBounds.height = m_v2Size.y;

}



LGameObject::~LGameObject()
{
	m_vertexArray.clear();
}
