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

private:

	CircleShape* m_gameObject;
	
};

#endif
