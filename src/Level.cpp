#include "Level.h"

Level(){

}
Level(Display newDisplay,std::string newTextObjective,int newnumOftiles,int newnumOfColors,std::string newFilename,std::string newLevelName)
		:textObjective(newTextObjective),numOfTiles(newnumOftiles),numofColors(newnumOfColors),filename(newFilename),levelName(newLevelName),success(false) {
	this->display=newDisplay;

}

void setLevelName(std::string newLevelName){
	this->levelName=newLevelName;
}
std::string getLevelName(){
	return this->levelName;
}

void setFilename(std::string newFilename){
	this->filename=newFilename;
}
std::string getFilename(){
	return this->filename;
}

void setNumOfColors(int num){
	this->numofColors=num;
}
int getNumOfColors(){
	return this->numofColors;
}

void setNumOfTiles(int num){
	this->numOfTiles;
}
int getNumOfTiles(){
	return this->numOfTiles;
}

void setTextObjective(std::string text){
	this->textObjective=text;
}
std::string getTextObjective(){
	return this->textObjective;
}

void setSuccess(bool newsuccess){
	this->success=newsuccess;
}
bool getSuccess(){
	return this->success;
}	

void setDisplay(Display newDisplay){
	this->display=newDisplay;
}
Display getDisplay(){
	return this->display;
}