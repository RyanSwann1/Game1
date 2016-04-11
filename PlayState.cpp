#include "PlayState.h"
#include "Player.h"
#include <iostream>

const std::string PlayState::m_playStateID = "Play";

PlayState::PlayState()
{
	addGameObjects(); //Initialize all game objects
}


PlayState::~PlayState()
{
}

void PlayState::update()
{
	for(auto &gameObject : m_gameObjects)
	{ 
		gameObject->update();
	}
}

void PlayState::render()
{

}

bool PlayState::onEnter()
{
	std::cout << "Entering the play state.\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "Exiting the play state.\n";
	return true;
}

void PlayState::addGameObjects()
{
	//Upon entering the play state. Add all neccessary game objects
	
	m_gameObjects.push_back(new Player());
	
}
