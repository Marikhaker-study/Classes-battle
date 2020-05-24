#include "AssetManager.h"

AssetManager::AssetManager()
{
}

// type can be: StartState, WinState, 
Sprite AssetManager::create_gamestate_sprite(char * filename, Texture &texture)
{
	if (!texture.loadFromFile(filename))
	{
		std::cout << "Win sprite texture not loaded" << std::endl;
	}

	Sprite sprite(texture);
	return sprite;
}

AssetManager::~AssetManager()
{
}
