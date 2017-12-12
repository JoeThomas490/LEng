#ifndef _LGAMEOBJECT_H_
#define _LGAMEOBJECT_H_

#include <SFML\Graphics.hpp>

using namespace sf;

class LGameObject : public Drawable, public Transformable
{
public:
	LGameObject();
	~LGameObject();

	void draw(RenderTarget& rTarget, RenderStates rStates) const;

	//that ones not used
	//void SetPosition(const Vector2f& mNewPos);


private:

	CircleShape* m_gameObject;

	Vector2f m_v2Position;
	
};

#endif
