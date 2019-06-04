#include <SFML/Graphics.hpp>
#include "Leha.h"
#include "Dasha.h"

using namespace sf;

void StageMap::draw_Map(RenderWindow& window)
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			switch (tileMap[i][j])
			{
			case 'w': {mapSprite.setTextureRect(IntRect(0, 0, 50, 50)); break; };
			case 'b': {mapSprite.setTextureRect(IntRect(50, 0, 50, 50)); break; };
			case ' ': {mapSprite.setTextureRect(IntRect(100, 0, 50, 50)); break; };
			default: break;
			}

			mapSprite.setPosition(j * 50, i * 50);
			window.draw(mapSprite);
		}
	}
};

void Player:: block_Motion()
{
	for (int i = (this->y)	 / 50; i < (this->y + this->h) / 50; ++i)
	{
		for (int j = this->x / 50; j < (this->x + this->w) / 50; ++j)
		{
			if (tileMap[i][j] == 'w' || tileMap[i][j] == 'b')
			{
				if (this->dy > 0) { this->y = i * 50 - this->h; }
				if (this->dy < 0) { this->y = i * 50 + 50; }
				if (this->dx > 0) { this->x = j * 50 - this->w; }
				if (this->dx < 0) { this->x = j * 50 + 50; }
			}

		}
	}
}

void StageMap:: camera_Follow(float x, float y, View & view)
{
	float tempX = x; float tempY = y;

	if (x < 600) tempX = 600;
	if (y < 800) tempY = 400;	

	view.setCenter(tempX, tempY);
}

void StageMap::box_Generator(int lvl)
{
	int numberOfBoxes = 180+(lvl*15);
	for (int i = 0; i < numberOfBoxes; ++i)
	{
		int xBoxCord = 1 + rand() % 51;
		int yBoxCord = 1 + rand() % 13;
		if (tileMap[yBoxCord][xBoxCord] == ' '&&(xBoxCord > 4 || yBoxCord > 4))
		{
			tileMap[yBoxCord][xBoxCord] = 'b';
		}
	}
}


