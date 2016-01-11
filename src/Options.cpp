#include "Options.h"

Options::Options(){

}
Options::Options(int newWidth, int newHeight){

}

std::vector<SDL_Texture> Options::getAllTextures(){
	return this->textures; 
}
SDL_Texture Options::getTexture(int num){
	return this->textures[num];
}

std::vector<SDL_Renderer> Options::getAllRenderers(){
	return this->renderers; 
}
SDL_Renderer Options::getRenderer(int num){
	return this->renderers[num];
}

std::vector<SDL_Window> Options::getAllWindows(){
	return this->windows;
}
SDL_Window Options::getWindow(int num){
	return this->windows[num];
}

std::vector<SDL_Texture> Options::getAllTextTextures(){
	return this->textTextures;
}
SDL_Texture Options::getTextTexture(int num){
	return this->textTextures[num];
}

std::vector<SDL_Surface> Options::getAllTextSurfaces(){
	return this->textSurfaces;
}
SDL_Surface Options::getTextSurface(int num){
	return this->textSurfaces[num];
}

int Options::getWidth(){
	return this->width;
}
int Options::getHeight(){
	return this->height;
}