#include <SFML/Graphics.hpp>
#include <iostream>
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

			mapSprite.setPosition(j * 50, i * 50 + SHIFT);
			window.draw(mapSprite);
		}
	}
};

void Player::block_Motion()
{
	for (int i = (this->y - SHIFT) / 50; i < (this->y - SHIFT + this->h) / 50; ++i)
	{
		std::cout << this->x << " " << this->y << std::endl;
		for (int j = this->x / 50; j < (this->x + this->w) / 50; ++j)
		{
			if (tileMap[i][j] == 'w' || tileMap[i][j] == 'b')
			{
				if (this->dy > 0) { this->y = i * 50 - this->h + SHIFT; }
				if (this->dy < 0) { this->y = i * 50 + 50 + SHIFT; }
				if (this->dx > 0) { this->x = j * 50 - this->w; }
				if (this->dx < 0) { this->x = j * 50 + 50; }
			}

		}
	}
}

void StageMap::camera_Follow(float x, float y, View & view, Sprite& stage, Sprite& time, Sprite& health)
{
	float tempX = x; float tempY = y;

	if (x < 600) tempX = 600;
	else
	{
		time.setPosition(x - 600 + 400, time.getPosition().y);
		stage.setPosition(x - 600, stage.getPosition().y);
		health.setPosition(x - 600 + 1050, health.getPosition().y);
	}
	if (x > 2050)
	{
		tempX = 2050;
		time.setPosition(2050 - 600 + 400, time.getPosition().y);
		stage.setPosition(2050 - 600, stage.getPosition().y);
		health.setPosition(2050 - 600 + 1050, health.getPosition().y);
	}
	if (y < 900) tempY = 400;


	view.setCenter(tempX, tempY);
}

void StageMap::box_Generator(int lvl)
{
	int numberOfBoxes = 180 + (lvl * 15);
	for (int i = 0; i < numberOfBoxes; ++i)
	{
		int xBoxCord = 1 + rand() % 51;
		int yBoxCord = 1 + rand() % 13;
		if (tileMap[yBoxCord][xBoxCord] == ' ' && (xBoxCord > 4 || yBoxCord > 4))
		{
			tileMap[yBoxCord][xBoxCord] = 'b';
		}
	}
}


