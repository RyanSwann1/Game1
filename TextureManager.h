#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL.h>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void load();
	void draw(int x, int y, int width, int height, SDL_Renderer *renderer);


private:
};
#endif // !TEXTURE_MANAGER_H

