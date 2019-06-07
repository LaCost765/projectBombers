//сюда пишем определения функций 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Dasha.h"
#include "Leha.h"

using namespace sf;

void Bomba::placeBomb(float time, Player& hero)
{
	if ((this->flagBomb == 0) && (Keyboard::isKeyPressed(Keyboard::Space)))
	{
		this->flagBomb = 1;
		this->x = hero.x;
		this->y = hero.y;
		this->sprite.setPosition(x, y);
	}
	if (this->flagBomb == 1)//like update
	{
		this->CurrentFrameBomb += 0.005*time;
		this->sprite.setTextureRect(IntRect(50 * int(this->CurrentFrameBomb), 0, 50, 50));
		if (this->CurrentFrameBomb > 10)
		{
			this->CurrentFrameBomb = 0;
			this->flagBomb = 0;
		}
	}
	
}

