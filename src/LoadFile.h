#ifndef _LOADFILE_H_
#define _LOADFILE_H_

class LoadFile{
	private:

		std::string filename;

		std::string text;

		std::map<std::string,SDL_Color> colors;

		std::vector<std::string> board;

		int width,height;

	public:

	LoadFile();
	LoadFile(std::string filename);

	std::string getFilename();

	std::string getText();

	std::map<std::string,SDL_Color> getColors();

	std::vector<std::string> getBoard();

	int getWidth();
	int getHeight();

};

#endif