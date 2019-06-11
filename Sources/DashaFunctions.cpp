//сюда пишем определения функций 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Dasha.h"
#include "Leha.h"


using namespace sf;

void Bomba::placeBomb(float time, Player& hero, StageMap& mainMap)
{
	if ((this->flagBomb == 0) && (Keyboard::isKeyPressed(Keyboard::Space)))
	{
		this->flagBomb = 1;
		//this->x = hero.x;
		//this->y = hero.y;
		if (hero.y == int((hero.y / 50) * 50))
		{
			if (int((hero.x / 50) * 50 + 25) >= hero.x)
			{
				this->x = int(hero.x / 50) * 50;
				this->y = hero.y;
			} else
			{ x = int(this->x / 50) * 51;
			  this->y = hero.y;
			}
		}
		if (hero.x == int((hero.x / 50) * 50))
		{
			if (int((hero.y / 50) * 50 + 25) >= hero.y)
			{
				this->y = int(hero.y / 50) * 50;
				this->x = hero.x;
			}
			else
			{
				this->y = int(hero.y / 50) * 51;
				this->x = hero.x;
			}
		}
		this->sprite.setPosition(x, y);
	}
	if (this->flagBomb == 1)//like update
	{
		this->CurrentFrameBomb += 0.005*time;
		this->sprite.setTextureRect(IntRect(50 * int(this->CurrentFrameBomb), 0, 50, 50));
		if (this->CurrentFrameBomb > 10)
		{
			this->CurrentFrameBomb = 0;
			this->flagBomb = 2;
		}
	}
	if (this->flagBomb == 2)
	{
		for (int i = 0; i < MAP_HEIGHT; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if ((this->x == j*50) || (this->x == (j + 1) * 50) || (this->x == (j - 1) * 50))
				{
					if ((this->y == i * 50) || (this->y == (i + 1) * 50) || (this->y == (i +2) * 50))
					{
						if (mainMap.tileMap[i][j] == 'b')
						{
							mainMap.tileMap[i][j] = ' ';
						}
					}
				}
			}
		}
		flagBomb = 0;
	}
}

