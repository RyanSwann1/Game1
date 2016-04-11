#include "Player.h"
#include "InputHandler.h"
#include <iostream>

Player::Player()
{
}


Player::~Player()
{
}

void Player::update()
{
	if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_W)) {
		std::cout << "Move Forwards.";
	}
}

void Player::draw()
{
}

void Player::handleEvents()
{
	if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_W)) {
		
	}
}
