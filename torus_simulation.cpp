#include <iostream>
#include "game.h"

using namespace std;

bool		Game::check_left_pos(Map *m, int x, int y)
{
	if (x > 0 && m->map[y][x - 1] == 1)
		return (true);
	if (x == 0 && m->map[y][m->size_x - 1] == 1)
		return (true);
	return (false);
}

bool		Game::check_right_pos(Map *m, int x, int y)
{
	if (x < (m->size_x - 1) && m->map[y][x + 1] == 1)
		return (true);
	if (x == (m->size_x - 1) && m->map[y][0] == 1)
		return (true);
	return (false);
}

bool		Game::check_up_pos(Map *m, int x, int y)
{
	if (y < (m->size_y - 1) && m->map[y + 1][x] == 1)
		return (true);
	if (y == (m->size_y - 1) && m->map[0][x] == 1)
		return (true);
	return (false);
}

bool		Game::check_down_pos(Map *m, int x, int y)
{
	if (y > 0 && m->map[y - 1][x] == 1)
		return (true);
	if (y == 0 && m->map[m->size_y - 1][x] == 1)
		return (true);
	return (false);
}

bool		Game::check_up_left_pos(Map *m, int x, int y)
{
	if (y > 0 && x > 0 && m->map[y - 1][x - 1] == 1)
		return (true);
	if (y > 0 && x == 0 && m->map[y - 1][m->size_x - 1] == 1)
		return (true);
	if (y == 0 && x > 0 && m->map[m->size_y - 1][x - 1] == 1)
		return (true);
	if (y == 0 && x == 0 && m->map[m->size_y - 1][m->size_x - 1] == 1)
		return (true);
	return (false);
}

bool		Game::check_up_right_pos(Map *m, int x, int y)
{
	if (y > 0 && x < (m->size_x - 1) && m->map[y - 1][x + 1] == 1)
		return (true);
	if (y > 0 && x == (m->size_x - 1) && m->map[y - 1][0] == 1)
		return (true);
	if (y == 0 && x < (m->size_x - 1) && m->map[m->size_y - 1][x + 1] == 1)
		return (true);
	if (y == 0 && x == (m->size_x - 1) && m->map[m->size_y - 1][0] == 1)
		return (true);
	return (false);
}

bool		Game::check_down_right_pos(Map *m, int x, int y)
{
	if (y < (m->size_y - 1) && x < (m->size_x - 1) && m->map[y + 1][x + 1] == 1)
		return (true);
	if (y < (m->size_y - 1) && x == (m->size_x - 1) && m->map[y + 1][0] == 1)
		return (true);
	if (y == (m->size_y - 1) && x < (m->size_x - 1) && m->map[0][x + 1] == 1)
		return (true);
	if (y == (m->size_y - 1) && x == (m->size_x - 1) && m->map[0][0] == 1)
		return (true);
	return (false);
}

bool		Game::check_down_left_pos(Map *m, int x, int y)
{
	if (y < (m->size_y - 1) && x > 0 && m->map[y + 1][x - 1] == 1)
		return (true);
	if (y < (m->size_y - 1) && x == 0 && m->map[y + 1][m->size_x - 1] == 1)
		return (true);
	if (y == (m->size_y - 1) && x > 0 && m->map[0][x - 1] == 1)
		return (true);
	if (y == (m->size_y - 1) && x == 0 && m->map[0][m->size_x - 1] == 1)
		return (true);
	return (false);
}

int			Game::count_neighbours(Map *m, int x, int y)
{
	int		num_of_neighbours = 0;

	if (check_left_pos(m, x, y))
		num_of_neighbours++;
	if (check_right_pos(m, x, y))
		num_of_neighbours++;
	if (check_up_pos(m, x, y))
		num_of_neighbours++;
	if (check_down_pos(m, x, y))
		num_of_neighbours++;
	if (check_up_left_pos(m, x, y))
		num_of_neighbours++;
	if (check_up_right_pos(m, x, y))
		num_of_neighbours++;
	if (check_down_right_pos(m, x, y))
		num_of_neighbours++;
	if (check_down_left_pos(m, x, y))
		num_of_neighbours++;
	return (num_of_neighbours);
}
