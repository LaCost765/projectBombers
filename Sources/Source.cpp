#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;

#include "Dasha.h"
#include "Egor.h"	
#include "Leha.h"
#include "Misha.h"
#include "commonData.h"


int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(1200, 800), "Bomberman");
	Clock clock;
	mainMap.box_Generator(hero.level);
	view.reset(FloatRect(0, 0, 1200, 800));
	

	while (window.isOpen())
	{
		// To store the mouse coordinates
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);

		Event event;


		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left)
				{
					if (!inGame)
					{
						if (quitButton.sprite.getGlobalBounds().contains(pos.x, pos.y)) window.close();
						if (newGameButton.sprite.getGlobalBounds().contains(pos.x, pos.y)) { newGameMenu = true; inGame = true; }
						if (continueButton.sprite.getGlobalBounds().contains(pos.x, pos.y))
						{
							levelInProcess = true;
							std::ifstream fin("Data/level.txt");
							fin >> hero.level;
							inGame = true;
							clock.restart();
						}
					}
					else
					{
						if (newGameMenu)
						{
							if (yesButton.sprite.getGlobalBounds().contains(pos.x, pos.y))
							{
								newGameMenu = false;
								levelInProcess = true;
								hero.level = 1;
								clock.restart();
							}

							if (noButton.sprite.getGlobalBounds().contains(pos.x, pos.y))
							{
								newGameMenu = false;
								inGame = false;
							}
						}
					}
				}
		}

		window.clear();
		if (!inGame) // draw the initial menu if the user has not started the game yet
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
		else
		{
			if (newGameMenu)
			{
				window.draw(note1.sprite);
				window.draw(note2.sprite);
				if (yesButton.sprite.getGlobalBounds().contains(pos.x, pos.y)) window.draw(yesActiveButton.sprite);
				else window.draw(yesButton.sprite);
				if (noButton.sprite.getGlobalBounds().contains(pos.x, pos.y)) window.draw(noActiveButton.sprite);
				else window.draw(noButton.sprite);
			}

			if (levelInProcess)
			{
				// there will be action
				window.clear();
				float time = clock.getElapsedTime().asMicroseconds();
				clock.restart();
				time = time / 800;
				// character with animation

				hero.move(time, hero.currentFrame, hero, mainMap, view, stage1Header.sprite, timeInfoHeader.sprite, health.sprite);

				hero.update(time, hero, mainMap);


				enemySp.movement(time, enemySp.currentFrame, mainMap, clock);
				enemySp.update(time, mainMap);
				bomba.placeBomb(time, hero, mainMap);

				window.setView(view);

				window.clear();

				mainMap.draw_Map(window);

				window.draw(hero.sprite);

				if(bomba.y !=0) window.draw(bomba.sprite);

				window.draw(enemySp.sprite);

				window.draw(stage1Header.sprite);

				window.draw(timeInfoHeader.sprite);

				health.sprite.setTextureRect(IntRect(3 - hero.healPoints, 0, 150, 50));
				window.draw(health.sprite);
			}
		}

		window.display();

	}
	return 0;
}