#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <ctime>
#include "Dasha.h"
#include "Leha.h"
#include "Misha.h"

using namespace sf;

void Enemy::check(StageMap& mainMap)
{
	for (int i = 1;i <= 4;i++)
	{
		this->dirs[i] = 0;
	}
	if (mainMap.tileMap[int((this->y - SHIFT) / 50) - 1][int(this->x / 50)] == ' ')
	{
		this->dirs[1] = 1;//up
	}
	if (mainMap.tileMap[int((this->y - SHIFT) / 50) + 1][int(this->x / 50)] == ' ')
	{
		this->dirs[2] = 1;//down
	}
	if (mainMap.tileMap[(int((this->y - SHIFT) / 50))][(int(this->x / 50)) - 1] == ' ')
	{
		this->dirs[3] = 1;//left
	}
	if (mainMap.tileMap[(int((this->y - SHIFT) / 50))][(int(this->x / 50)) + 1] == ' ')
	{
		this->dirs[4] = 1;//right
	}
}

void Enemy::movement(float time, float& CurrentFrame, StageMap& mainMap, Clock& clock)
{
	if (((this->y - int(this->y / 50) * 50) < 1) && ((this->x - int(this->x / 50) * 50) < 1) && !this->dirJustChoosen)
	{
		this->x = int(this->x / 50) * 50;
		this->y = int(this->y / 50) * 50;
		check(mainMap);
		this->dir = chooseDir(clock);
		this->dirJustChoosen = true;
	}
	else
	{
		if (((this->y - int(this->y / 50) * 50) > 1 && (this->dir == 1 || this->dir == 2)) || ((this->x - int(this->x / 50) * 50) > 1 && (this->dir == 3 || this->dir == 4))) this->dirJustChoosen = false;
	}

	if (this->dir == 1)
	{
		this->speed = 0.07;
		CurrentFrame += 0.006 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		this->sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 150, 50, 50));
	}
	if (this->dir == 2)
	{
		this->speed = 0.07;
		CurrentFrame += 0.006 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		this->sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 100, 50, 50));
	}
	if (this->dir == 3)
	{
		this->speed = 0.07;
		CurrentFrame += 0.006 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		this->sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 50, 50, 50));
	}
	if (this->dir == 4)
	{
		this->speed = 0.07;
		CurrentFrame += 0.006 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		this->sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 0, 50, 50));
	}
}

void Enemy::update(float time) // function of "update" the class object.
{
	switch (dir)
	{
	case 4: dx = speed; dy = 0;   break;
	case 3: dx = -speed; dy = 0;   break;
	case 2: dx = 0; dy = speed;   break;
	case 1: dx = 0; dy = -speed;   break;
	}

	x += dx * time;
	y += dy * time;

	speed = 0;
	sprite.setPosition(x, y);
}

int Enemy::chooseDir(Clock& clock)
{
	int result = 0;
	if (dirs[1]+dirs[2]+dirs[3]+dirs[4] == 0)
	{
		this->speed = 0;
		return -1;
	}
	else { this->speed = 0.07;}
	while (result == 0)
	{
		int k = rand() % 4 + 1;
		if (!this->dirs[k]) continue;
		else
		{
			if (this->dir != 0 && ((dirs[1] + dirs[2] + dirs[3] + dirs[4]) > 1) && ((this->dir == 1 && k == 2) || (this->dir == 2 && k == 1) || (this->dir == 3 && k == 4) || (this->dir == 4 && k == 3)))  continue;
			else result = k;
		}
	}
	return result;
}

void Enemy::place(StageMap& mainMap)
{

}