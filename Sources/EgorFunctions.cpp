//сюда пишем определения функций 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Dasha.h"
#include "Leha.h"

using namespace sf;

void Player::move(float time, float& CurrentFrame, Player& hero, StageMap& mainMap, View& view, Sprite& stage, Sprite& timeInfo, Sprite& health)
{
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {

		if (mainMap.tileMap[int((this->y - SHIFT) / 50)][int(this->x / 50) - 1] == 'w' || mainMap.tileMap[int((this->y - SHIFT) / 50)][int(this->x / 50) - 1] == 'b')
		{
			if (mainMap.tileMap[int((this->y - SHIFT) / 50) - 1][int(this->x / 50) - 1] == ' ' || mainMap.tileMap[int((this->y - SHIFT) / 50) + 1][int(this->x / 50) - 1] == ' ')
			{
				if (this->x == int(this->x / 50) * 50)
				{
					if (this->y - int(this->y / 50) * 50 >= 25 && mainMap.tileMap[int((this->y - SHIFT) / 50) + 1][int(this->x / 50) - 1] == ' ')
					{

						hero.dir = 2; hero.speed = 0.1;
						CurrentFrame += 0.006*time;
						if (CurrentFrame > 3) CurrentFrame -= 3;
						hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 100, 50, 50));
						mainMap.camera_Follow(hero.x, hero.y, view, stage, timeInfo, health);
						return;
					}
				}
			}
		}

		if (mainMap.tileMap[int((this->y - SHIFT) / 50)][int(this->x / 50) - 1] == ' ' && this->y - int(this->y / 50) * 50 < 25)
		{
			if (this->y != int(this->y / 50) * 50 && this->y - int(this->y / 50) * 50 > 1)
			{
				hero.dir = 3; hero.speed = 0.1;
				CurrentFrame += 0.006*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 150, 50, 50));
				mainMap.camera_Follow(hero.x, hero.y, view, stage, timeInfo, health);
				return;
			}
			else
			{
				this->y = int(this->y / 50) * 50;
			}
		}

		hero.dir = 1; hero.speed = 0.1;
		CurrentFrame += 0.006*time;
		if (CurrentFrame > 5) CurrentFrame -= 5;
		hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 50, 50, 50));
		mainMap.camera_Follow(hero.x, hero.y, view, stage, timeInfo, health);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {

		if (mainMap.tileMap[int(this->y - SHIFT) / 50][int(this->x / 50) + 1] == 'w' || mainMap.tileMap[int(this->y - SHIFT) / 50][int(this->x / 50) + 1] == 'b')
		{
			if (mainMap.tileMap[int(this->y - SHIFT) / 50 + 1][int(this->x / 50) + 1] == ' ' || mainMap.tileMap[int(this->y - SHIFT) / 50 - 1][int(this->x / 50) + 1] == ' ')
			{
				if (this->x == int(this->x / 50) * 50)
				{
					if (this->y - int(this->y / 50) * 50 >= 25 && mainMap.tileMap[int((this->y - SHIFT) / 50) + 1][int(this->x / 50) + 1] == ' ')
					{

						hero.dir = 2; hero.speed = 0.1;
						CurrentFrame += 0.006*time;
						if (CurrentFrame > 3) CurrentFrame -= 3;
						hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 100, 50, 50));
						mainMap.camera_Follow(hero.x, hero.y, view, stage, timeInfo, health);
						return;
					}
				}
			}
		}

		if (mainMap.tileMap[int((this->y - SHIFT) / 50)][int(this->x / 50) + 1] == ' ' && this->y - int(this->y / 50) * 50 < 25)
		{
			if (this->y != int(this->y / 50) * 50 && this->y - int(this->y / 50) * 50 > 1)
			{
				hero.dir = 3; hero.speed = 0.1;
				CurrentFrame += 0.006*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 150, 50, 50));
				mainMap.camera_Follow(hero.x, hero.y, view, stage, timeInfo, health);
				return;
			}
			else
			{
				this->y = int(this->y / 50) * 50;
			}
		}

		hero.dir = 0; hero.speed = 0.1;
		CurrentFrame += 0.006*time;
		if (CurrentFrame > 5) CurrentFrame -= 5;
		hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 0, 50, 50));
		mainMap.camera_Follow(hero.x, hero.y, view, stage, timeInfo, health);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {

		if (mainMap.tileMap[int((this->y - SHIFT) / 50) - 1][int(this->x / 50)] == 'w' || mainMap.tileMap[int((this->y - SHIFT) / 50) - 1][int(this->x / 50)] == 'b')
		{
			if (mainMap.tileMap[int((this->y - SHIFT) / 50) - 1][int(this->x / 50) - 1] == ' ' || mainMap.tileMap[int((this->y - SHIFT) / 50) - 1][int(this->x / 50) + 1] == ' ')
			{
				if (this->y == int(this->y / 50) * 50)
				{
					if (this->x - int(this->x / 50) * 50 >= 25 && mainMap.tileMap[int((this->y - SHIFT) / 50) - 1][int(this->x / 50) + 1] == ' ')
					{

						hero.dir = 0; hero.speed = 0.1;
						CurrentFrame += 0.006*time;
						if (CurrentFrame > 5) CurrentFrame -= 5;
						hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 0, 50, 50));
						mainMap.camera_Follow(hero.x, hero.y, view, stage, timeInfo, health);
						return;
					}
				}
			}
		}

		if (mainMap.tileMap[int((this->y - SHIFT) / 50) - 1][int(this->x / 50)] == ' ' && this->x - int(this->x / 50) * 50 < 25)
		{
			if (this->x != int(this->x / 50) * 50 && this->x - int(this->x / 50) * 50 > 1)
			{
				hero.dir = 1; hero.speed = 0.1;
				CurrentFrame += 0.006*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 50, 50, 50));
				mainMap.camera_Follow(hero.x, hero.y, view, stage, timeInfo, health);
				return;
			}
			else
			{
				this->x = int(this->x / 50) * 50;
			}
		}

		hero.dir = 3; hero.speed = 0.1;
		CurrentFrame += 0.006*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 150, 50, 50));
	}

	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {

		if (mainMap.tileMap[int((this->y - SHIFT) / 50) + 1][int(this->x / 50)] == 'w' || mainMap.tileMap[int((this->y - SHIFT) / 50) + 1][int(this->x / 50)] == 'b')
		{
			if (mainMap.tileMap[int((this->y - SHIFT) / 50) + 1][int(this->x / 50) + 1] == ' ' || mainMap.tileMap[int((this->y - SHIFT) / 50) + 1][int(this->x / 50) - 1] == ' ')
			{
				if (this->y == int(this->y / 50) * 50)
				{
					if (this->x - int(this->x / 50) * 50 >= 25 && mainMap.tileMap[int((this->y - SHIFT) / 50) + 1][int(this->x / 50) + 1] == ' ')
					{

						hero.dir = 0; hero.speed = 0.1;
						CurrentFrame += 0.006*time;
						if (CurrentFrame > 5) CurrentFrame -= 5;
						hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 0, 50, 50));
						mainMap.camera_Follow(hero.x, hero.y, view, stage, timeInfo, health);
						return;
					}
				}
			}
		}

		if (mainMap.tileMap[int((this->y - SHIFT) / 50) + 1][int(this->x / 50)] == ' ' && this->x - int(this->x / 50) * 50 < 25)
		{
			if (this->x != int(this->x / 50) * 50 && this->x - int(this->x / 50) * 50 > 1)
			{
				hero.dir = 1; hero.speed = 0.1;
				CurrentFrame += 0.006*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 50, 50, 50));
				mainMap.camera_Follow(hero.x, hero.y, view, stage, timeInfo, health);
				return;
			}
			else
			{
				this->x = int(this->x / 50) * 50;
			}
		}

		hero.dir = 2; hero.speed = 0.1;
		CurrentFrame += 0.006*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 100, 50, 50));
	}
}

void Player::update(float time, Player & hero, StageMap& mainMap) // function of "update" the class object.
{
	switch (dir)
	{
	case 0: dx = speed; dy = 0;   break;
	case 1: dx = -speed; dy = 0;   break;
	case 2: dx = 0; dy = speed;   break;
	case 3: dx = 0; dy = -speed;   break;
	}

	x += dx * time;
	y += dy * time;

	speed = 0;
	sprite.setPosition(x, y);
	this->block_Motion(mainMap);
}