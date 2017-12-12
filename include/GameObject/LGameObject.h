#ifndef _LGAMEOBJECT_H_
#define _LGAMEOBJECT_H_

#include <SFML\Graphics.hpp>

using namespace sf;

enum LPrimitive
{
	LSQUARE,
	LTRIANGLE,
	LCIRCLE,
	LPOINT
};

class LGameObject : public Drawable, public Transformable
{
public:
	LGameObject(Vector2f mPos = Vector2f(0,0), Vector2f mSize = Vector2f(0,0));
	LGameObject(LPrimitive mPrimitiveType, Vector2f mPos = Vector2f(0,0), Vector2f mSize = Vector2f(5,5));
	~LGameObject();

	void draw(RenderTarget& rTarget, RenderStates rStates) const;
	virtual void Update(float dTime);

	bool GetIsActive() { return m_bIsActive; };
	void SetIsActive(bool mIsActive) { m_bIsActive = mIsActive; };

	FloatRect GetGlobalBounds() const { return m_frGlobalBounds; };

private:
	void InitVertexArray(LPrimitive mPrimitiveType, const Vector2f& mPos, const Vector2f& mSize);

	void UpdateGlobalBounds();

private:

	VertexArray m_vertexArray;
	Texture* m_pTexture = nullptr;

	FloatRect m_frGlobalBounds;

	bool m_bIsActive = false;

	Vector2f m_v2Size;

};

#endif
