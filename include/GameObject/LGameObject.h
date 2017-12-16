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

	void CreatePrimitive(LPrimitive mPrimtiveType, const Vector2f& mSize = Vector2f(5, 5));

	void draw(RenderTarget& rTarget, RenderStates rStates) const;
	virtual void Update(float dTime);

	void SetSize(const Vector2f& mSize);
	Vector2f GetSize() { return m_v2Size; };

	void SetTexture(Texture* pTexture);

	void SetRenderLayer(int mLayer) { m_iRenderLayer = mLayer; };
	int GetRenderLayer() { return m_iRenderLayer; };

	void SetColor(Color mColor);

	bool GetIsActive() { return m_bIsActive; };
	void SetIsActive(bool mIsActive) { m_bIsActive = mIsActive; };

	FloatRect GetGlobalBounds() { UpdateGlobalBounds(); return m_frGlobalBounds; };

	static bool IsCollisionBetween(LGameObject* obj1, LGameObject* obj2);

private:
	void InitVertexArray(LPrimitive mPrimitiveType, const Vector2f& mPos, const Vector2f& mSize);

	void UpdateGlobalBounds();

protected:
	VertexArray m_vertexArray;

private:

	Texture* m_pTexture = nullptr;

	FloatRect m_frGlobalBounds;
	IntRect m_irTextureRect;

	bool m_bIsActive = false;

	int m_iRenderLayer = 0;

	Vector2f m_v2Size;
};

#endif
