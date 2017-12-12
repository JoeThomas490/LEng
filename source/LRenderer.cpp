#include "LRenderer.h"


LRenderer::LRenderer()
{
	m_renderQueue = RenderQueue();
}

LRenderer::~LRenderer()
{
	ClearQueue();
}

void LRenderer::AddToQueue(LGameObject* mObj)
{
	m_renderQueue.push_back(mObj);
}

void LRenderer::RemoveFromQueue(LGameObject* mObj)
{

}

bool LRenderer::IsInQueue(LGameObject* mObj)
{
	return true;
}

void LRenderer::ClearQueue()
{
	m_renderQueue.clear();
}

void LRenderer::Render()
{
	RenderWindow* const target = LApplication::GetApplicationInstance()->GetWindowInstance();

	target->clear();

	for (auto& obj : m_renderQueue)
	{
		target->draw(*obj);
	}

	target->display();
}


