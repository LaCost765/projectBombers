#pragma once

constexpr auto MAP_HEIGHT = 15;
constexpr auto MAP_WIDTH = 53;

using namespace sf;

static    String tileMap[MAP_HEIGHT] = {
	"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
	"w                                                   w",
	"w w w w w w w w w w w w w w w w w w w w w w w w w w w",
	"w                                                   w",
	"w w w w w w w w w w w w w w w w w w w w w w w w w w w",
	"w                                                   w",
	"w w w w w w w w w w w w w w w w w w w w w w w w w w w",
	"w                                                   w",
	"w w w w w w w w w w w w w w w w w w w w w w w w w w w",
	"w                                                   w",
	"w w w w w w w w w w w w w w w w w w w w w w w w w w w",
	"w                                                   w",
	"w w w w w w w w w w w w w w w w w w w w w w w w w w w",
	"w                                                   w",
	"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
};


class StageMap
{
public:
	Image mapImage;
	Texture mapTexture;
	Sprite mapSprite;
	int lvl;

	StageMap(){
		lvl = 1;
		mapImage.loadFromFile("Data/mapTileSet.png");
		mapTexture.loadFromImage(mapImage);
		mapSprite.setTexture(mapTexture);
	}


	void draw_Map(RenderWindow& window);
	void camera_Follow(float x, float y, View & view);
	void box_Generator(int lvl);
};
	
