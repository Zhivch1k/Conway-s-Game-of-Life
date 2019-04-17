#ifndef GAME_H
# define GAME_H

# define GAME_TIME 500000

# include "map.h"
# include "file_read.h"

class Game
{
private:
	void	init(Map *, Map *);
	void	copy_map(Map *, Map *);
	bool	tick(Map *, Map *);
	bool	check_if_maps_stable(Map *, Map *);
	bool	check_empty_map(Map *);
	int		count_neighbours(Map *, int, int);
	bool	check_right_pos(Map *, int, int);
	bool	check_left_pos(Map *, int, int);
	bool	check_up_pos(Map *, int, int);
	bool	check_down_pos(Map *, int, int);
	bool	check_up_left_pos(Map *, int, int);
	bool	check_up_right_pos(Map *, int, int);
	bool	check_down_left_pos(Map *, int, int);
	bool	check_down_right_pos(Map *, int, int);

public:
	void	run_a_game(void);
};

#endif //GAME_H
