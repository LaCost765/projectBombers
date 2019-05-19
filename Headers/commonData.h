#pragma once
class Picture
{
public:
	float x, y, width, height; //x,y - координаты точки на картинке, откуда она будет срисовываться, width, height - ширина и высота
	String File;																							//срисовываемого участка
	Sprite sprite;
	Image image;
	Texture texture;
	Picture(String f, float x, float y, float wid, float heig)
	{
		this->x = x;
		this->y = y;
		this->width = wid;
		this->height = heig;
		File = f;
		image.loadFromFile(File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(this->x, this->y, width, height));
	}
};

Picture bomberMan("Data/bomberman.png", 0, 0, 573, 780);
Picture titleBomberMan("Data/titleBomberman.png", 0, 0, 600, 150);
Picture newGameButton("Data/newGameButton.png", 0, 0, 400, 100);
Picture newGameActiveButton("Data/newGameActiveButton.png", 0, 0, 400, 100);
Picture continueButton("Data/continueButton.png", 0, 0, 400, 100);
Picture continueActiveButton("Data/continueActiveButton.png", 0, 0, 400, 100);
Picture quitButton("Data/quitButton.png", 0, 0, 400, 100);
Picture quitActiveButton("Data/quitActiveButton.png", 0, 0, 400, 100);
Picture background("Data/background.jpg", 0, 0, 1600, 800);
