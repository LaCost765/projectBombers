#pragma once
//���� ����� ��������� �������
class Picture
{
public:
	float x, y, width, height; //x,y - ���������� ����� �� ��������, ������ ��� ����� �������������, width, height - ������ � ������
	String File;																							//�������������� �������
	Sprite sprite;
	Image image;
	Texture texture;
	Picture(String f, float x, float y, float wid, float heig, float coordX, float coordY)
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
		sprite.setPosition(coordX, coordY);
	}
};