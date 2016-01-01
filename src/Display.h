#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#elif defined __unix__ || defined __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

#include <string>
#include <iostream>

#include "Board.h"


/*
	DISPLAY CLASS
*********************/
class Display{

	private:
		SDL_Texture* texture;
		SDL_Renderer* renderer;
		SDL_Surface* surface;
		SDL_Window* windows;

		SDL_Texture* textTexture;
		SDL_Surface* textSurface;

		TTF_Font* font;

		int width;						//Width of Display Window
		int height;						//Height of Display Window

		int tWidth;						//Text Box Width
		int tHeight;					//Text Box Height

		Board board;					//Board to be Displayed

	public:
		//Contructor
		Display(std::string name, 				//Name of Window
				int initialPosX,				//intial X position of the window
				int initialPosY,				//intial Y position of the window
				int newWidth,					//Width of Window;
				int newHeight,					//Height of Window;
				int size,						//Size of the Board;
				int newTWidth,					//Text Box Width
				int newTHeight					//Text Box Height
				);

		Board getBoard();

		void initSDL();							//Initialize SDL
		void initTTF();							//Initialize TTF

		void loadTexture();						//Load Textrues From file

		void createWindow(	std::string name,	//Name of Window
							int initialPosX,	//Initial X Position of Window
							int initialPosY,	//Initial Y Position of Window
							int width,			//Width of Window
							int height 			//Height of Window
							);

		void createRenderer();					//Creates the SDL Renderer

		void createTextTexture();				//Create Textures from Text using TTF

		void openFontFile(std::string filename);

		void textTexturefromtextSurface();		//Creates Text Textures from Text Surface

		void surfaceFromText(std::string surfaceText,SDL_Color textColor);

		void textureFromSurface();				//Creates A Texture From A Surface
		void createRGBSurface();				//Creates a Surface from RGB Masks
		void surfaceFromImage(					//Creates Surface from Image using SDL_Image
					std::string filename		//Filename of Image
					);

		void setupRenderer();					//Setup the renderer target and scale of Renderer

		bool checkCollision(int posx,int posy);	//Check the Collision of the Player with the window boundaries

		void makeBoard();						//Make the game board

		void printBoard();						//Print Game Board in the terminal

		void setPalette();						//Create the Colors of the Display
		std::vector<SDL_Color> getPalette();	//Get the Colors of the Display
		void printPalette();					//Print the Colors for debbuging purposes

		void getClickedTile(int posx,int posy,int num);

		void deleteClickedTiles();

		void render(SDL_Rect box);				//Render Player and Board
		void renderPlayer(SDL_Rect box);		//Render The Player
		void renderTile(int x,int y);						//Render Tiles

		void renderBoard();						//Render the Board

		void renderText();

		void renderPlayerScale(					//Change the Thickness of the Line for the Player
					SDL_Rect* newBox,			//Players Box
					int size
					);

		void close();							//Close the Display and SDL


		int getWidth();							//Get width of Display
		int getHeight();						//Get height of Display

		int getTWidth();						//Get text width
		int getTHeight();						//Get text height

};


#endif
