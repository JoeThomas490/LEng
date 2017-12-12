#ifndef _LRENDERER_H_
#define _LRENDERER_H_

#include <SFML\Graphics.hpp>
#include <vector>

#include "LGameObject.h"
#include "LApplication.h"

typedef std::vector<LGameObject*> RenderQueue;

class LRenderer
{
public:
	LRenderer();
	~LRenderer();

	void AddToQueue(LGameObject* mObj);
	void RemoveFromQueue(LGameObject* mObj);

	void Render();


private :

	bool IsInQueue(LGameObject* mObj);

	void ClearQueue();

private:

	RenderQueue m_renderQueue;

};

#endif

