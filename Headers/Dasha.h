#pragma once
//—юда пишем прототипы функций

class Player {
public:
	float x, y, w, h, dx, dy, speed = 0; //player coordinates x and y, height width, acceleration (in x and y), speed
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



	void update(float time) // function of "update" the class object.
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
	}
};
