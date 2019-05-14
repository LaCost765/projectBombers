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
	bomberMan.sprite.setPosition(0, 0);
	titleBomberMan.sprite.setPosition(600, 50);
	newGameButton.sprite.setPosition(700, 250);
	continueButton.sprite.setPosition(700, 450);
	quitButton.sprite.setPosition(700, 650);

	RenderWindow window(VideoMode(1200, 800), "Bomberman");
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		if (!inGame) //отрисовка начального меню, если пользователь еще не начал игру
		{
			window.draw(bomberMan.sprite);
			window.draw(newGameButton.sprite);
			window.draw(continueButton.sprite);
			window.draw(quitButton.sprite);
			window.draw(titleBomberMan.sprite);
		}
		window.display();
	}
	return 0;
}