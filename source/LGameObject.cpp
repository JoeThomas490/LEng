#include "LGameObject.h"

LGameObject::LGameObject()
{
	m_gameObject = new CircleShape(25.0f);
	m_gameObject->setFillColor(Color::Green);
}

void LGameObject::draw(sf::RenderTarget & renderTarget, sf::RenderStates renderStates) const
{
	//renderStates.texture = mp_texture;
	renderStates.transform *= getTransform();

	renderTarget.draw(*m_gameObject);
}


LGameObject::~LGameObject()
{
	delete m_gameObject;
}
