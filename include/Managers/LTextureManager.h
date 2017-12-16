#ifndef _LTEXTURE_MANAGER_H_
#define _LTEXTURE_MANAGER_H_

#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

typedef std::vector<sf::Texture> LTextureList;
typedef std::map<std::string, int> LTextureLookup;
typedef std::map<std::string, int>::iterator LTextureLookupIterator;

class LTextureManager
{
public:

	~LTextureManager();

	static LTextureManager& GetTextureManagerInstance()
	{
		static LTextureManager* instance = new LTextureManager();

		return *instance;
	}


	void SetResourcePath(const string& mPath) { m_sResourcePath = mPath; };

	Texture* LoadTexture(const string& mPath);
	Texture* GetTextureFromTag(const string& mTag);

	Texture* RemoveTexture(const string& mTag);


private:

	std::string m_sResourcePath;

	LTextureList m_textureList;
	LTextureLookup m_textureLookup;

private:

	LTextureManager();

};

#endif
