#pragma once

#include "Character.h"

class Player : public Character
{
public:
	Player() {};
	~Player() {};

	void update(float deltaTime, std::vector<Object*> &activeObjects) override;

private:
	//abilities and blah

};
