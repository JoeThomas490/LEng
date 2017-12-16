#include "Managers\LTextureManager.h"

LTextureManager::LTextureManager()
{

}

LTextureManager::~LTextureManager()
{
	for (auto& texture : m_textureList)
	{
		delete texture;
	}
}

Texture * LTextureManager::LoadTexture(const string & mPath)
{
	string fullPath = m_sResourcePath + mPath;

	LTextureLookupIterator it = m_textureLookup.find(mPath);
	if (it != m_textureLookup.end())
	{
		return m_textureList[it->second];
	}

	Texture* t = new Texture();

	if(!t->loadFromFile(mPath))
	{
		printf("WARNING : File couldn't be loaded! Path : %s", mPath);
		return nullptr;
	}
	else
	{
		m_textureList.push_back(t);
		m_textureLookup.emplace(mPath, m_textureList.size() - 1);

		return m_textureList[m_textureList.size() - 1];
	}
}

Texture * LTextureManager::GetTextureFromTag(const string & mTag)
{
	LTextureLookupIterator it = m_textureLookup.find(mTag);
	if (it != m_textureLookup.end())
	{
		return m_textureList[it->second];
	}

	printf("WARNING : File couldn't be loaded! Path : %s", mTag);
	return nullptr;
}

Texture * LTextureManager::RemoveTexture(const string & mTag)
{
	return nullptr;	
}
