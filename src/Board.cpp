#include "Board.h"

#include <chrono>
#include <cmath>
#include <random>
#include <string>
#include <iostream>

/*
	BOARD CLASS FUNCTION DEFINITIONS
*********************/

//Used to generate Random Number
#ifdef _WIN32
std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
#elif defined __unix__ || defined __APPLE__
std::random_device seeder;
std::mt19937 engine(seeder());
#endif

Board::Board(){

}
		
Board::Board(int newWidth,int newHeight,int size,int newOffset):
			width(newWidth),height(newHeight),bwidth(newWidth/size),bheight(newHeight/size),boardSize(size), offset(newOffset){

	setPalette();

	makeBoard();

	printBoard();

}


//Set the Palette of the Game Board
void Board::setPalette(){

	SDL_Color colors[] = {
		{0,128,0,255}, //green
		{255,165,0,255}, //orange
		{0,0,255,255}, //blue
		{255,0,0,255}, //red
		{255,255,0,255}, //yellow
		{238,130,238,255}, //violet
		{255,255,255,255}, //white
		{128,0,128,255}, //purple
		{255,192,203,255} //pink
	};

	std::vector<SDL_Color> temp(colors, colors + sizeof(colors) / sizeof(SDL_Color) );

	this->palette = temp;

}

//Print the Colors for debbuging purposes
void Board::printPalette(){
	std::cerr << "PRINT PALETTE" << std::endl;
	for(int i=0;(unsigned)i<palette.size();i++){
		std::cerr << "Palette: " << " num: " << i << " r: " << (int)palette[i].r << " g: " << (int)palette[i].g << " b: " << (int)palette[i].b << " a: " << (int)palette[i].a << std::endl;
	}
}

//Get Palette of a Board
std::vector<SDL_Color> Board::getPalette(){
	return this->palette;
}

void Board::getClickedTile(int posx,int posy,int num){
	int x, y;

	x=(posx/bwidth)%boardSize;
	y=(posy/bheight)%boardSize;

	std::cerr << "CLICKED TILE: " << " x: " << x << " y: " << y <<  " posx: " <<  posx   << " posy: " << posy << std::endl; 
	
	(num%2==0)?clickedTiles[0]=&tiles[x][y]:clickedTiles[1]=&tiles[x][y];
}

void Board::deleteClickedTiles(){
	clickedTiles[0]=NULL;
	clickedTiles[1]=NULL;
}

//Make Board
void Board::makeBoard(){
	std::uniform_int_distribution<int> dist(0,palette.size()-1);
	int num;
	//tiles.resize(boardSize,std::vector<Tiles>(boardSize));

	//std::cerr << "TILES: " << "size: " << tiles.size() << std::endl;
 	SDL_Rect temp;
	temp.w=bwidth;
	temp.h=bheight;
	for(int i=0, w=0;i<boardSize;i++,w+=bwidth){
		tiles.push_back(std::vector<Tiles>());
		temp.x=w;
		//std::cerr << "Tiles: " << "size: " << tiles[i].size() << std::endl;
		for(int j=0,h=offset;j<boardSize;j++,h+=bheight){
			//std::cerr << "Tile Created :" << "i: " << i << " j: " << j << std::endl;
			temp.y=h;
			num=dist(engine);
			//std::cerr << "Tile Color :" << "num: " << num << " r: " << (int)this->palette[num].r << " g: " << (int)palette[num].g << " b: " << (int)palette[num].b << " a: " << (int)palette[num].a << std::endl;
			tiles[i].push_back(Tiles(this->palette[num],temp));
		}
	}
}

//Print a Board
void Board::printBoard(){
	std::cerr << "PRINT BOARD" << std::endl;
	for(int i=0;i<boardSize;i++){
		std::cerr << "Tiles: " << "size: " << tiles[i].size() << std::endl;
		for(int j=0;j<boardSize;j++){
			std::cerr << "Tile Created :" << "i: " << i << " j: " << j << std::endl;
			std::cerr << "Tile Position :" << "x: " << tiles[i][j].getBox().x << " y: " << tiles[i][j].getBox().y << " w: " << tiles[i][j].getBox().w << " h: " << tiles[i][j].getBox().h << std::endl;
			std::cerr << "Tile Color :" << " r: " << (int)tiles[i][j].getColor().r << " g: " << (int)tiles[i][j].getColor().g << " b: " << (int)tiles[i][j].getColor().b << " a: " << (int)tiles[i][j].getColor().a << std::endl;
		}
	}
	//printPalette();
}

//Get Width of Board
int Board::getWidth(){
	return this->width;
}

//Get Heigth of Board
int Board::getHeight(){
	return this->height;
}

//Get Width of Tiles
int Board::getBwidth(){
	return this->bwidth;
}

//Get Height of Tiles
int Board::getBheight(){
	return this->bheight;
}

//Get board Size if 3X3 board size is 3
int Board::getBoardSize(){
	return this->boardSize;
}

//Swap Colors of Two Tiles
void Board::swapColorsKeyboard(int x,int y,int num){

	int x1=x/bwidth,y1=y/bheight,x2=0,y2=0;

	switch(num){
		case UP://UP
			x2=x/bwidth;
			y2=(y+bheight)/bheight;
		break;
		case DOWN://DOWN
			x2=x/bwidth;
			y2=(y-bheight)/bheight;
		break;
		case LEFT://LEFT
			x2=(x+bwidth)/bwidth;
			y2=y/bheight;
		break;
		case RIGHT://RIGHT
			x2=(x-bwidth)/bwidth;
			y2=y/bheight;
		break;
		default:
			std::cerr << "INVALID DIRECTION FOR COLOR SWAP!" << std::endl;
		break;
	}

	/*std::cerr << "TILES: " << std::endl;
	tiles[x1][y1].printTile();
	tiles[x2][y2].printTile();*/
	
	Tiles temp = Tiles(tiles[x1][y1].getColor(),tiles[x1][y1].getBox());
	tiles[x1][y1].setColor(tiles[x2][y2].getColor());
	tiles[x2][y2].setColor(temp.getColor());
}

void Board::swapColorsMouse(){
	if(clickedTiles[0]!=NULL && clickedTiles[1]!=NULL){
		Tiles temp = Tiles(clickedTiles[0]->getColor(),clickedTiles[0]->getBox());
		clickedTiles[0]->setColor(clickedTiles[1]->getColor());
		clickedTiles[1]->setColor(temp.getColor());
		clickedTiles[0]=NULL;
		clickedTiles[1]=NULL;
	}
}

//Get Pointer to a tile on a board
Tiles* Board::getTileFromTiles(int i,int j){
	return &this->tiles[i][j];
}

void Board::close(){
	deleteClickedTiles();
}
