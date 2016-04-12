#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL.h>
#include <map>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void load(std::string ID, std::string path);
	void draw(int x, int y, int width, int height, SDL_Renderer *renderer);


private:
	std::map<std::string, SDL_Texture*> m_textures;
};
#endif // !TEXTURE_MANAGER_H

