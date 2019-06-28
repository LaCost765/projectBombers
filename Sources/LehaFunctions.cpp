#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include <string>
#include <ctime>
#include "Dasha.h"
#include "Misha.h"
#include "Leha.h"
#include "Egor.h"

using namespace sf;

int koef[MAP_HEIGHT][MAP_WIDTH];

void StageMap::draw_Map(RenderWindow& window)
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			switch (tileMap[i][j])
			{
			case 'w': {mapSprite.setTextureRect(IntRect(0, 0, 50, 50)); break; };
			case 'b': {mapSprite.setTextureRect(IntRect(50, 0, 50, 50)); break; };
			case ' ': {mapSprite.setTextureRect(IntRect(100 + 50 * koef[i][j], 0, 50, 50)); break; };
			default: break;
			}

			mapSprite.setPosition(j * 50, i * 50 + SHIFT);
			window.draw(mapSprite);
		}
	}
	
};

void Player::block_Motion(StageMap& mainMap)
{
	for (int i = (this->y - SHIFT) / 50; i < (this->y - SHIFT + this->h) / 50; ++i)
	{
		for (int j = this->x / 50; j < (this->x + this->w) / 50; ++j)
		{
			if (mainMap.tileMap[i][j] == 'w' || mainMap.tileMap[i][j] == 'b')
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
	for (int i = 0; i < MAP_HEIGHT; i++) 
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			koef[i][j] = rand() % 5;
		}
	
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

void generateEnemies(int level, std::list<Enemy*> & enemies, StageMap map)
{
	bool checkExtra = false;

	for (int i = 1; i <= MAP_HEIGHT-2; ++i) //four zones
	{
		int x = 4 + rand() % (MAP_WIDTH - 6);
		int y = i;
		while (map.tileMap[y][x] != ' ')
		{
			x = 4 + rand() % (MAP_WIDTH - 6);

		}
		enemies.push_back(new Enemy("Data/enemy.png", x*50, y*50+SHIFT, 50.0, 50.0));		
		
	}

	if (level > 1) //extra enemies 
	{
		for (int j = 1; j <= level * 5; ++j)
		{
			int x = 4 + rand() % (MAP_WIDTH - 6);
			int y = 1 + rand() % 13;
			while (map.tileMap[y][x] != ' ')
			{
				x = 4 + rand() % (MAP_WIDTH - 6);
				y = 1 + rand() % 13;
			}
			enemies.push_back(new Enemy("Data/enemy.png", x * 50, y * 50 + SHIFT, 50.0, 50.0));
		}
	}
}

void updateEnemies(std::list<Enemy*> enemies,
	std::list<Enemy*>::iterator iterator, float time)
{
	for (iterator = enemies.begin();iterator != enemies.end(); iterator++)
	{
		(*iterator)->update(time);
	}
}

void moveEnemies(std::list<Enemy*> enemies,
	std::list<Enemy*>::iterator iterator, float time, StageMap& mainMap, Clock& clock)
{
	for (iterator = enemies.begin(); iterator != enemies.end(); iterator++)
	{
		(*iterator)->movement(time,(*iterator)->currentFrame,mainMap,clock);
	}
}

void drawEnemies(std::list<Enemy*> enemies,
	std::list<Enemy*>::iterator iterator, RenderWindow & window)
{
	for (iterator = enemies.begin(); iterator != enemies.end(); iterator++)
	{
		window.draw((*iterator)->sprite);
	}
}
String loadStageImage(int level)
{
	String path = "Data/Stages/stage" + std::to_string(level) + ".png";
	return path;
}

void loadDigit(int & stageTime, Picture digits, RenderWindow & window, int & stopFlag, Player hero)
{
	int d = 0;
	int tempTime = stageTime;
	int delCameraX = 0;
	if (hero.x < 600) delCameraX = 0;
	 else if (hero.x > 2050) delCameraX = 1450;
	 else delCameraX = hero.x - 600;
	for (int i = 0; i < 3; ++i)
	{
		d = tempTime % 10;
		tempTime /= 10;
		digits.sprite.setTextureRect(IntRect(d * 50, 0, 50, 50));
		digits.sprite.setPosition(675 - i * 50 + delCameraX, 0);
		window.draw(digits.sprite);
	}
	if (stageTime > 0)
	{
		if (stopFlag == 0)
		{
			--stageTime;
			++stopFlag;
		}
		else
		{
			if (stopFlag < 350)
			{
				++stopFlag;
			}
			else { stopFlag = 0; }

		}
	}
					
}


