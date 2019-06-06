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

void Enemy::movement(float time, float& CurrentFrame, StageMap& mainMap)
{
	if (((this->y - int(this->y / 50) * 50) < 0.49) && ((this->x - int(this->x / 50) * 50) < 0.49))
	{
		check(mainMap);
		this->dir = chooseDir();
	}
	if (dir == 1)
	{
		this->speed = 0.1;
		CurrentFrame += 0.006 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		this->sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 150, 50, 50));
	}
	else if (this->dir == 2)
	{
		this->speed = 0.1;
		CurrentFrame += 0.006 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		this->sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 100, 50, 50));
	}
	else if (this->dir == 3)
	{
		this->speed = 0.1;
		CurrentFrame += 0.006 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		this->sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 50, 50, 50));
	}
	else if (this->dir == 4)
	{
		this->speed = 0.1;
		CurrentFrame += 0.006 * time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		this->sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 0, 50, 50));
	}
}

void Enemy::update2(float time, StageMap& mainMap) // function of "update" the class object.
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

int Enemy::chooseDir()
{
	int k = rand() % 4 + 1;
	if (!this->dirs[k]) chooseDir();
	else return k;
}