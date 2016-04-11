#include "Game.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"

#include <assert.h>
#include <iostream>

Game* Game::m_instance = nullptr;

Game::Game()
{

	std::cout << "Game Running.";
}

Game::~Game()
{

}

Game * Game::instance()
{
	if (m_instance == nullptr) {
		m_instance = new Game();
	}

	return m_instance;
}

bool Game::init(const char* title, int sizeWidth, int sizeHeight)
{
	//Initialize SDL Video
	SDL_INIT_VIDEO;
	//Initialize SDL Window
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sizeWidth, sizeHeight, SDL_WINDOW_SHOWN);
	assert(m_window != nullptr);

	//Initialize SDL 
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	assert(m_renderer != nullptr);

	//Set current state to the menu state
	m_currentGameState = GameStates::MENU; 
	std::cout << "Before INIT State.\n";
	//Initialize the menu state
	m_gameStateMachine = new GameStateMachine();
	m_gameStateMachine->changeState(new MenuState());
	std::cout << "After INIT State.\n";

	//Initialize Texture Manager
	

	//Initiazzation has been successful
	m_running = true;
	return true;
	
}

void Game::handleEvents()
{
	InputHandler::instance()->update();

	if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		m_gameStateMachine->changeState(new PlayState());
	}
}

void Game::update()
{
	m_gameStateMachine->update();
	////Depend on current game states
	//switch (m_currentGameState)
	//{
	//	//Handle the main menu
	//case GameStates::MENU:
	//	break;
	//	//Handle all objects that are in play
	//case GameStates::PLAY:
	//	break;
	//	//End the game
	//case GameStates::GAMEOVER:
	//	//clean;
	//	break;
	//}
}