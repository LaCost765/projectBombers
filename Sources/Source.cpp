#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;

#include "commonData.h"
#include "Dasha.h"
#include "Egor.h"	
#include "Leha.h"
#include "Misha.h"



int main()
{  
	srand(time(0));

	setParametrs();
	RenderWindow window(VideoMode(1200, 800), "Bomberman");
	


	float CurrentFrame = 0;// stores the current frame
	Clock clock;

	Player hero("Data/heroBomb.png", 50, 50, 50.0, 50.0);
	StageMap mainMap;
	mainMap.box_Generator(mainMap.lvl);
	View view;

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
							fin >> level;
							inGame = true; 
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
								level = 1;
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
				if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
					hero.dir = 1; hero.speed = 0.1;
					CurrentFrame += 0.005*time;
					if (CurrentFrame > 5) CurrentFrame -= 5;
					hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 50, 50, 50));
					mainMap.camera_Follow(hero.x, hero.y, view);
				}

				if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
					hero.dir = 0; hero.speed = 0.1;
					CurrentFrame += 0.005*time;
					if (CurrentFrame > 5) CurrentFrame -= 5;
					hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 0, 50, 50));
					mainMap.camera_Follow(hero.x, hero.y,view);
				}

				if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
					hero.dir = 3; hero.speed = 0.1;
					CurrentFrame += 0.005*time;
					if (CurrentFrame > 3) CurrentFrame -= 3;
					hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 150, 50, 50));
				}

				if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { 
					hero.dir = 2; hero.speed = 0.1;
					CurrentFrame += 0.005*time; 
					if (CurrentFrame > 3) CurrentFrame -= 3; 
					hero.sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 100, 50, 50));
				}

				hero.update(time, hero);

				window.setView(view);
				
				window.clear();

				mainMap.draw_Map(window);

				window.draw(hero.sprite);

			}
		}
		
		window.display();
		
	}
	return 0;
}