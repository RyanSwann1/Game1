#include "TextureManager.h"

TextureManager * TextureManager::m_pInstance = nullptr;


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

TextureManager * TextureManager::instance()
{
	if (m_pInstance == nullptr) {
		m_pInstance = new TextureManager();
	}

	return m_pInstance;
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
	//SDL_RenderCopy(renderer, )
}
