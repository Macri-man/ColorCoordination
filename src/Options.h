#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <vector>

class Options{

	private:

		std::vector<SDL_Texture> textures;
		std::vector<SDL_Renderer> renderers;
		std::vector<SDL_Window> windows;

		std::vector<SDL_Texture> textTextures;
		std::vector<SDL_Surface> textSurfaces;

		TTF_Font* font;

		int width;						
		int height;						

	public:
		std::vector<SDL_Texture> getAllTextures();
		SDL_Texture getTexture(int num);



		std::vector<SDL_Renderer> getAllRenderers();
		SDL_Renderer getRenderer(int num);


		std::vector<SDL_Window> getAllWindows();
		SDL_Window getWindow(int num);

		std::vector<SDL_Texture> getAllTextTextures();
		SDL_Texture getTextTexture(int num);

		std::vector<SDL_Surface> getAllTextSurfaces();
		SDL_Surface getTextSurface(int num);

};	

#endif
