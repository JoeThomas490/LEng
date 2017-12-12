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
	if (!IsInQueue(mObj))
	{
		return;
	}

	int i = 0;
	for (i; i < m_renderQueue.size(); ++i)
	{
		if (mObj == m_renderQueue.at(i))
		{
			break;
		}
	}

	m_renderQueue.erase(m_renderQueue.begin() + i);

}

bool LRenderer::IsInQueue(LGameObject* mObj)
{
	for (auto& obj : m_renderQueue)
	{
		if (obj == mObj)
		{
			return true;
		}
	}

	return false;
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


