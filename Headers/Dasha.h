#pragma once
//—юда пишем прототипы функций
#include "Leha.h"

using namespace sf;

class Player {
public:
	float x, y, w, h, dx, dy, speed = 0; //player coordinates x and y, height width, acceleration (in x and y), speed
	int healPoints = 3, level = 1;
	int dir = 0; //player direction
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Player(String F, float X, float Y, float W, float H) {  // Constructor with parameters for class Player
		File = F;
		w = W; h = H;//height & width
		image.loadFromFile(File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;//sprite appearance coordinate
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}

	void block_Motion();

	void update(float time, Player & hero);

	void move(float time, float& currentFrame, Player& hero, StageMap& mainMap, View& view, Sprite& stage, Sprite& timeInfo, Sprite& health);

};