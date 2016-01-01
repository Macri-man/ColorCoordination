#ifndef _BOARD_H_
#define _BOARD_H_

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#elif defined __unix__ || defined __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

#include <vector>

#include "Tiles.h"

/*
	BOARD CLASS
*********************/

enum {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Board{
	private:

		int width;						//Width of Board Window
		int height;						//Height of Board Window

		int bwidth;						//Width of Tiles
		int bheight;					//Height of Tiles

		int boardSize;					//Number of a Row if 3X3 the boardsize is 3

		int offset;

		std::vector<SDL_Color> palette; //Colors in the Game

		std::vector<std::vector<Tiles> > tiles; //Vector of vectors of Tiles

		Tiles *clickedTiles[2];

	public:

		Board();
		Board(int width,int height,int size,int offset);

		void makeBoard();						//Make the game board

		void printBoard();						//Print Game Board in the terminal

		void getClickedTile(int posx,int posy,int num);

		void deleteClickedTiles();

		void setPalette();						//Create the Colors of the Board
		std::vector<SDL_Color> getPalette();	//Get the Colors of the Board
		void printPalette();					//Print the Colors for debbuging purposes

		int getWidth();							//Get width of Board
		int getHeight();						//Get height of Board

		int getBwidth();						//Get tile width
		int getBheight();						//Get tile height

		int getBoardSize();						//Get board size

		void swapColorsKeyboard(						//Swap Tile Colors
					int x1,int y1,				//The x and y position of tile
					int num
					);

		void swapColorsMouse();

		Tiles* getTileFromTiles(int i,int j);	//Get the pointer a tile in the Board

		void close();

};

#endif