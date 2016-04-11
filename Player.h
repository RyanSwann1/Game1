#pragma once
#include "SDLGameObject.h"
#include "Vector2.h"
#include <SDL.h>
class Player :
	public SDLGameObject
{
public:
	Player();
	~Player();

	void update() override;
	void draw() override;
	void handleEvents() override;

private:
	Vector2 m_position;

};

