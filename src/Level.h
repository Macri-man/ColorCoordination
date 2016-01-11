#ifndef _LEVEL_H_
#define _LEVEL_H_

class Level{
	private:

		std::string levelName;
		std::string filename;

		int numOfColors;
		int numOftiles;

		std::string textObjective;

		bool success;

		Display display;

	public:

		Level();
		Level(Display newDisplay,std::string newTextObjective,int newnumOftiles,int newnumOfColors,std::string newfilename,std::string newLevelName);

		void setLevelName(std::string newLevelName);
		std::string getLevelName();

		void setFilename(std::string newFilename);
		std::string getFilename();

		void setNumOfColors(int num);
		int getNumOfColors();

		void setNumOfTiles(int num);
		int getNumOfTiles();

		void setTextObjective(std::string text);
		std::string getTextObjective();

		void setSuccess(bool newsuccess);
		bool getSuccess();

		void setDisplay(Display newDisplay);
		Display getDisplay();
};

#endif