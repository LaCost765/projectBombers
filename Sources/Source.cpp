#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace sf;

#include "commonData.h"
#include "Dasha.h"
#include "Egor.h"
#include "Leha.h"
#include "Misha.h"

int main()
{
	
	bool inGame = false;

	//выбор положния для элементов стартового меню
	background.sprite.setPosition(0, 0);
	bomberMan.sprite.setPosition(0, 0);
	titleBomberMan.sprite.setPosition(600, 50);
	newGameButton.sprite.setPosition(700, 250);
	continueButton.sprite.setPosition(700, 450);
	quitButton.sprite.setPosition(700, 650);
	newGameActiveButton.sprite.setPosition(700, 250);
	continueActiveButton.sprite.setPosition(700, 450);
	quitActiveButton.sprite.setPosition(700, 650);

	RenderWindow window(VideoMode(1200, 800), "Bomberman");
	while (window.isOpen())
	{
		//Для хранения координат мыши
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		if (!inGame) //отрисовка начального меню, если пользователь еще не начал игру
		{
			window.draw(background.sprite);
			window.draw(bomberMan.sprite);
			if (newGameButton.sprite.getGlobalBounds().contains(pos.x, pos.y)) window.draw(newGameActiveButton.sprite);
			else window.draw(newGameButton.sprite);
			if (continueButton.sprite.getGlobalBounds().contains(pos.x, pos.y)) window.draw(continueActiveButton.sprite);
			else window.draw(continueButton.sprite);
			if (quitButton.sprite.getGlobalBounds().contains(pos.x, pos.y)) window.draw(quitActiveButton.sprite);
			else window.draw(quitButton.sprite);
			window.draw(titleBomberMan.sprite);
		}
		window.display();
	}
	return 0;
}