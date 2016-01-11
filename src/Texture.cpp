#include "Texture.h"

Texture::Texture(){}

Texture::Texture(SDL_Texture texture,SDL_Renderer renderer,int newWidth,int newHeight)
				:width(newWidth),height(newHeight){
					this->texture=texture;
					this->renderTexture=renderer;
}

Texture::Texture(int newWidth,int newHeight):width(newWidth),height(newHeight){}

void Texture::createTexture(){
	this->texture = SDL_CreateTexture(renderTexture, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, this->width, this->height);
	if(!this->texture){
        std::cerr << "Texture! SDL Error: " <<  SDL_GetError() << std::endl;
        exit(1);
    }
}

void Texture::createTextTexture(std::string surfaceText,SDL_Color textColor,std::string filename,int fontSize){
	//"Fonts/LiberationSerif-Regular.ttf"
	TTF_Font* font = TTF_OpenFont(filename,fontSize);
    if(!font){
        std::cerr << "Error Load File: " << filename << " SDL_ttf Error: " << TTF_GetError() << std::endl;
        exit(1);
    }

	SDL_Surface* textSurface = TTF_RenderText_Solid(font,surfaceText.c_str(),textColor);
	if(!textSurface){
        std::cerr << "Text Surface! SDL_ttf Error: " <<  TTF_GetError() << std::endl;
        exit(1);
    }

    this->texture = SDL_CreateTextureFromSurface(renderTexture,this->textSurface);
    if(!this->texture){
        std::cerr << "Text  Texture! SDL Error: " <<  SDL_GetError() << std::endl;
        exit(1);
    }

    if(this->width < textSurface->w || this->height < textSurface->h){
      	std::cerr << "THE TEXT IS TOO BIG! " << std::endl;
    }

    this->width = textSurface->w;
    this->height = textSurface->h;

    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
    font = NULL;
}
void Texture::createTextureFromSurface(){
	Uint32 rmask, gmask, bmask, amask;
	#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
	#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
	#endif

	SDL_Surface* surface=SDL_CreateRGBSurface(0,this->width,this->height,32,rmask, gmask, bmask, amask);
	if(!surface){
        std::cerr << "Create RGB Surface Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    this->texture=SDL_CreateTextureFromSurface(renderTexture,surface);
	if(!this->texture){
    	std::cerr << "Texture from Surface Error: " << SDL_GetError() << std::endl;
    	exit(1);
	}
}

void Texture::createTextureFromImage(std::string filename){
	SDL_Surface* surface=IMG_Load(filename.c_str());
	if(!surface){
        std::cerr << "Create Surface from Image Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    this->texture=SDL_CreateTextureFromSurface(renderTexture,surface);
	if(!this->texture){
    	std::cerr << "Texture from Surface Error: " << SDL_GetError() << std::endl;
    	exit(1);
	}

	SDL_QueryTexture(SDLTexture, NULL, NULL, &Width, &Height);

	SDL_FreeSurface(surface);
}

SDL_Texture Texture::getTexture(){
	return this->texture;
}
SDL_Renderer Texture::getRenderer(){
	return this->renderTexture;
}

int Texture::getWidth(){
	return this->width;
}

int Texture::getHeight(){
	return this->height;
}

void Texture::render(int x, int y){
	SDL_Rect rect = {x, y, this->width, this->height};

	SDL_RenderCopy(renderTexture, texture, NULL, &rect);
}

void Texture::render(int x, int y, int newWidth, int newHeight){
	SDL_Rect rect = {x, y, newWidth, newHeight};

	SDL_RenderCopy(renderTexture, this->texture, NULL, &rect);
}

void Texture::render(int destX, int destY, int destWidth, int destHeight, int sourX, int sourY, int sourWidth, int sourHeight){
	SDL_Rect sourcRect = {sourX, sourY, sourWidth, sourHeight};
	SDL_Rect destRect = {destX, destY, destWidth, destHeight};

	SDL_RenderCopy(renderTexture, this->texture, &sourcRect, &destRect);
}
