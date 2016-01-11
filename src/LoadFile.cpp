#include "LoadFile.h"

LoadFile::LoadFile(){

}

LoadFile::LoadFile(std::string newFilename):
					filename(newFilename){
		
}

std::string getFilename(){
	return this->filename;
}

std::string getText(){
	return this->text
}

std::map<std::string,SDL_Color> getColors(){
	return this->colors;
}	

std::vector<std::string> getBoard(){
	return this->board;
}

int getWidth(){
	return this->width;
}

int getHeight(){
	return this->height;
}