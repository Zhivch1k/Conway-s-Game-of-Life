#ifndef GAME_H
# define GAME_H

#include <iostream>

#include "map.h"

using namespace std;

class Game
{
private:
	void	init(Map *game_map);
	void	tick(void);

public:
	void	run_a_game(void);
};

#endif //GAME_H