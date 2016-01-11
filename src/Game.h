#ifndef _GAME_H_
#define _GAME_H_

#include "Level.h"
#include <vector>

class Game{
	private:

		std::string name;

		Player player;

		Options screen; 

		std::vector<Level> levels;


	public:

};

#endif
