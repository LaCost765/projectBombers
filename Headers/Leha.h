#pragma once
#define SHIFT 50

constexpr auto MAP_HEIGHT = 15;
constexpr auto MAP_WIDTH = 53;

using namespace sf;




class StageMap
{
public:
	Image mapImage;
	Texture mapTexture;
	Sprite mapSprite;
	String tileMap[MAP_HEIGHT] = {
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
	StageMap() {
		mapImage.loadFromFile("Data/mapTileSet.png");
		mapTexture.loadFromImage(mapImage);
		mapSprite.setTexture(mapTexture);
	}


	void draw_Map(RenderWindow& window);
	void camera_Follow(float x, float y, View & view, Sprite& stage, Sprite& time, Sprite& health);
	void box_Generator(int lvl);
};