#ifndef _LRENDERER_H_
#define _LRENDERER_H_

#include <SFML\Graphics.hpp>
#include <vector>

#include "GameObject\LGameObject.h"
#include "LApplication.h"

class LRenderer
{
public:
	LRenderer();
	~LRenderer();

	void AddToQueue(Drawable* mObj);
	void RemoveFromQueue(Drawable* mObj);

	void Render();


private :

	bool IsInQueue(Drawable* mObj);
	void ClearQueue();

private:

	typedef std::vector<Drawable*> RenderQueue;
	RenderQueue m_renderQueue;

};

#endif

