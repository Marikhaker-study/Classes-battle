#pragma once
#include "libraries.h"
#include "IWindow.h"
using namespace sf;

class AssetManager
{
private:
	Texture game_start_texture, win_texture, lose_texture;
public:
	AssetManager();

	static Sprite create_gamestate_sprite(char * filename, Texture &texture);

	virtual ~AssetManager();
};

