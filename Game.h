#ifndef GAME_H
#define GAME_H


#include <SDL.h>
#include "GameStates.h"
#include "TextureManager.h"

class MenuState;
class PlayState;
class GameStateMachine;
class Game
{
public:
	static Game* instance();

	bool init(const char* title, int sizeWidth, int sizeHeight);
	void update();
	void handleEvents();
	void endGame() { m_running = false; }


	bool isRunning() const { return m_running; }



private:

	static Game* m_instance;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	TextureManager m_textureManager;


	GameStateMachine* m_gameStateMachine;
	GameStates m_currentGameState;
	bool m_running;

	//Private so as not to be called from outside of the class
	Game();
	~Game();


};
#endif // !GAME_H

