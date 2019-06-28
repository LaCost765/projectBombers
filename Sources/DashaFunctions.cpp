//ñþäà ïèøåì îïðåäåëåíèÿ ôóíêöèé 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Dasha.h"
#include "Leha.h"


using namespace sf;

void Bomba::placeBomb(float time, Player& hero, StageMap& mainMap)
{
	if ((this->flagBomb == 0) && (Keyboard::isKeyPressed(Keyboard::Space)))
	{
		this->flagBomb = 1;
		this->x = hero.x;
		this->y = hero.y;
		if (this->x - int(this->x / 50) * 50 > 25) this->x = int(this->x / 50) * 50 + 50;
		else this->x = int(this->x / 50) * 50;
		if (this->y - int(this->y / 50) * 50 > 25) this->y = int(this->y / 50) * 50 + 50;
		else this->y = int(this->y / 50) * 50;
		this->sprite.setPosition(this->x, this->y);
	}
	if (this->flagBomb == 1)//like update
	{
		this->CurrentFrameBomb += 0.005*time;
		this->sprite.setTextureRect(IntRect(50 * int(this->CurrentFrameBomb), 0, 50, 50));
		if (this->CurrentFrameBomb > 10)
		{
			this->CurrentFrameBomb = 0;
			this->flagBomb = 0;
			int indRow = this->y / 50 - 1, indBar = this->x / 50;
			destroyBoxes(mainMap, indRow, indBar);
		}
	}
	
}

void Bomba::destroyBoxes(StageMap& mainMap, int indRow, int indBar)
{
	if (mainMap.tileMap[indRow + 1][indBar] == 'b') mainMap.tileMap[indRow + 1][indBar] = ' ';
	if (mainMap.tileMap[indRow - 1][indBar] == 'b') mainMap.tileMap[indRow - 1][indBar] = ' ';
	if (mainMap.tileMap[indRow][indBar + 1] == 'b') mainMap.tileMap[indRow][indBar + 1] = ' ';
	if (mainMap.tileMap[indRow][indBar - 1] == 'b') mainMap.tileMap[indRow][indBar - 1] = ' ';
}