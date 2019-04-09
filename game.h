#ifndef GAME_H
# define GAME_H

#include <iostream>

#include "map.h"

using namespace std;

class Game
{
private:
	void	init(void);
	void	game_tick(void);

public:
	void	run_a_game();
	void	run_a_game(short map_size_x, short map_size_y);
};

#endif //GAME_H