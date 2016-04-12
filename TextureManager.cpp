#include "TextureManager.h"
#include "Game.h"
#include <assert.h>

//TextureManager * TextureManager::m_pInstance = nullptr;


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}
//
//TextureManager * TextureManager::instance()
//{
//	if (m_pInstance == nullptr) {
//		m_pInstance = new TextureManager();
//	}
//
//	return m_pInstance;
//}

void TextureManager::load(std::string ID, std::string path)
{
	//Load surface
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());
	assert(surface != nullptr);
	//Optimize said surface
	SDL_Surface* optimizedSurface = SDL_ConvertSurface(surface, Game::instance()->getWindowSurface()->format, 0);
	assert(optimizedSurface != nullptr);
	//Convert surface into texture
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), optimizedSurface);
	//Free the surface
	SDL_FreeSurface(surface);

	if (texture != nullptr) {
		m_textures[ID] = texture;
		return;
	}

}

void TextureManager::draw(int x, int y, int width, int height, SDL_Renderer * renderer)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	

}
