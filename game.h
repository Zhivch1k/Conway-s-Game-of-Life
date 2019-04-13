#ifndef GAME_H
# define GAME_H

#include "map.h"

class Game
{
private:
	void	init(Map *, Map *);
	void	copy_map(Map *, Map *);
	bool	tick(Map *, Map *);
	bool	check_if_maps_stable(Map *, Map *);
	bool	check_empty_map(Map *);

public:
	void	run_a_game(void);
};

#endif //GAME_H