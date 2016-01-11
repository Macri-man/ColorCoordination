#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#elif defined __unix__ || defined __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

class Texture {
	private:
		SDL_Texture* texture;
		SDL_Renderer* renderTexture;

		int width;
		int height;

	public:
		Texture();
		Texture(int newWidth,int newHeight);
		Texture(SDL_Texture texture,int newWidth,int newHeight);
		
		void createTextTexture();
		void createTextureFromSurface();
		void createTextureFromImage();

		SDL_Texture getTexture();
		SDL_Renderer getRenderer();
		int getWidth();
		int getHeight();

		void Texture::render(int x, int y);
		void Texture::render(int x, int y, int newWidth, int newHeight);
		void render(int destX, int destY, int destWidth, int destHeight, int sourX, int sourY, int sourWidth, int sourHeight);

}

#endif