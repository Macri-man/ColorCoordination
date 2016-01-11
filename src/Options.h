#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <vector>

class Options{

	private:

		std::vector<Texture> textures;
		std::vector<SDL_Renderer> renderers;
		std::vector<SDL_Window> windows;

		std::vector<Texture> textTextures;
		std::vector<SDL_Surface> textSurfaces;

		int width;						
		int height;						

	public:

		Options();
		Options(int newWidth, int newHeight);

		std::vector<SDL_Texture> getAllTextures();
		Texture getTexture(int num);

		std::vector<SDL_Renderer> getAllRenderers();
		SDL_Renderer getRenderer(int num);

		std::vector<SDL_Window> getAllWindows();
		SDL_Window getWindow(int num);

		std::vector<SDL_Texture> getAllTextTextures();
		Texture getTextTexture(int num);

		std::vector<SDL_Surface> getAllTextSurfaces();
		SDL_Surface getTextSurface(int num);

		int getWidth();
		int getHeight();

		void renderTextures();
};	

#endif
