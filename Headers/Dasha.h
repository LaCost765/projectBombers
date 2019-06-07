#pragma once
//���� ����� ��������� �������
#include "Leha.h"

using namespace sf;

class Parent {
public:
	float x, y, w, h, dx, dy, speed = 0; //player coordinates x and y, height width, acceleration (in x and y), speed
	int dir = 0; //player direction
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Parent(String F, float X, float Y, float W, float H) {  // Constructor with parameters for class Player
		File = F;
		w = W; h = H;//height & width
		image.loadFromFile(File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;//sprite appearance coordinate
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}

};

class Player : public Parent
{
public:
	int healPoints = 3, level = 1;

	Player(String F, float X, float Y, float W, float H) : Parent(F, X, Y, W, H)
	{  

	}

	void block_Motion(StageMap& mainMap);
	void update(float time, Player & hero, StageMap& mainMap);
	void move(float time, float& currentFrame, Player& hero, StageMap& mainMap, View& view, Sprite& stage, Sprite& timeInfo, Sprite& health);

};

class Bomba {
public:
	float x, y, w, h, flagBomb, CurrentFrameBomb = 0;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Bomba(String F, float X, float Y, float W, float H, float flagBomb) {
		File = F;
		w = W; h = H;//height & width
		image.loadFromFile(File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;//sprite appearance coordinate
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}

	void placeBomb(float time, Player& hero);
};