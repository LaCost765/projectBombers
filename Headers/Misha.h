#pragma once
#include "Leha.h"

using namespace sf;

class Enemy : public Parent
{
public:
	bool dirs[5];
	
	Enemy(String F, float X, float Y, float W, float H) : Parent(F, X, Y, W, H)
	{
		
	}
	bool dirJustChoosen = false;
	void check(StageMap& mainMap);
	void movement(float time, float& CurrentFrame, StageMap& mainMap, Clock& clock);
	void place(StageMap& mainMap);
	void update(float time, StageMap& mainMap);
	int chooseDir(Clock& clock);
};