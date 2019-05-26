#include <iostream>
#include <fstream>
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
	//выбор положния для элементов стартового меню
	yesButton.sprite.setPosition(300, 400);
	noButton.sprite.setPosition(700, 400);
	yesActiveButton.sprite.setPosition(300, 400);
	noActiveButton.sprite.setPosition(700, 400);
	note1.sprite.setPosition(300, 50);
	note2.sprite.setPosition(200, 150);
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

	//Для добавления персонажа
	Texture herotexture;
	herotexture.loadFromFile("Data/heroBomb.png");

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 0, 50, 50));
	herosprite.setPosition(250, 250);

	float CurrentFrame = 0;//хранит текущий кадр
	Clock clock;

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

				//Управление персонажем с анимацией
				
				if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) 
				{ 
					CurrentFrame += 0.005*time; //служит для прохождения по кадрам
					if (CurrentFrame > 5) CurrentFrame -= 5; 
					herosprite.setTextureRect(IntRect(50 * int(CurrentFrame), 50, 50, 50)); 
					herosprite.move(-0.1*time, 0);
				}

				if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) 
				{
					CurrentFrame += 0.005*time; 
					if (CurrentFrame > 5) CurrentFrame -= 5; 
					herosprite.setTextureRect(IntRect(50 * int(CurrentFrame), 0, 50, 50)); 
					herosprite.move(0.1*time, 0);

				}

				if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) 
				{
					CurrentFrame += 0.005*time; 
					if (CurrentFrame > 3) CurrentFrame -= 3; 
					herosprite.setTextureRect(IntRect(50 * int(CurrentFrame), 150, 50, 50)); 
					herosprite.move(0, -0.1*time);
				}

				if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) 
				{
					CurrentFrame += 0.005*time; 
					if (CurrentFrame > 3) CurrentFrame -= 3; 
					herosprite.setTextureRect(IntRect(50 * int(CurrentFrame), 100, 50, 50)); 
					herosprite.move(0, 0.1*time);
				}

				window.clear();
				window.draw(herosprite);
			}
		}
		
		window.display();
		
	}
	return 0;
}