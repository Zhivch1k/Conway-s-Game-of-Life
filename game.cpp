#include <iostream>
#include <unistd.h>
#include "game.h"

using namespace std;

void		Game::init(Map *curr_map, Map *prev_map)
{
	short		x = -1;
	short		y = -1;
	short		creature_x = 0;
	short		creature_y = 0;

	cout << "Welcome to the Conway's game of life!\n\n";
	while (x < 1 || y < 1 || x > 100 || y > 100)
	{
		cout << "Please enter the height of the map\n";
		cin >> y;
		cout << "Please enter the width of the map\n";
		cin >> x;
	}
	cout << "Initializing map with entered sizes...\n\n";

	curr_map->init(x, y);
	prev_map->init(x, y);

	cout << "Successfully initialized!\n";
	cout << "Not it's time to fill the map with creatures\n";
	while (!(creature_x == -1 && creature_y == -1))
	{
		cout << "Enter two numbers x and y to place the creature on that position\n";
		cout << "To stop adding creatures and run a game enter -1 and -1\n";
		cin >> creature_x >> creature_y;
		if ((creature_x >= 0 && creature_x < x) &&
			(creature_y >= 0 && creature_y < y))
			curr_map->set_creature(creature_y, creature_x);
		curr_map->display();
	}
	copy_map(curr_map, prev_map);
}

void		Game::copy_map(Map *from, Map *in)
{
	if ((from->size_x != in->size_x) || (from->size_y != in->size_y))
	{
		cout << "Error. Different sizes.\n";
		exit(1);
	}
	for (int i = 0; i < from->size_y; i++)
	{
		for (int j = 0; j < from->size_x; j++)
			in->map[i][j] = from->map[i][j];
	}
}

bool		Game::check_empty_map(Map *m)
{
	for (int i = 0; i < m->size_y; i++)
	{
		for (int j = 0; j < m->size_x; j++)
		{
			if (m->map[i][j] == 1)
				return (0);
		}
	}
	return (1);
}

bool		Game::check_if_maps_stable(Map *curr, Map *prev)
{
	for (int i = 0; i < curr->size_y; i++)
	{
		for (int j = 0; j < curr->size_x; j++)
		{
			if (curr->map[i][j] != prev->map[i][j])
				return (0);
		}
	}
	return (1);
}

bool		Game::tick(Map *curr, Map *prev)
{
	int		num_of_neighbours;
	static int	num_of_generation = 1;

	for (int i = 0; i < prev->size_y; i++)
	{
		for (int j = 0; j < prev->size_x; j++)
		{
			num_of_neighbours = count_neighbours(prev, j, i);
			if (num_of_neighbours < 2 || num_of_neighbours > 3)
				curr->map[i][j] = 0;
			else if (num_of_neighbours == 3)
				curr->map[i][j] = 1;
			else if (num_of_neighbours == 2 && prev->map[i][j] == 1)
				curr->map[i][j] = 1;
		}
	}
	if (check_empty_map(curr))
	{
		cout << "It seems that all cells died.\n";
		return (0);
	}
	if (check_if_maps_stable(curr, prev))
	{
		cout << "It seems that generation is stable.\n";
		return (0);
	}
	curr->display();
	cout << "Current generation is " << num_of_generation << endl;
	num_of_generation++;
	copy_map(curr, prev);
	usleep(1000000);
	return (1);
}

void		Game::run_a_game(void)
{
	Map		curr_map;
	Map		prev_map;

	init(&curr_map, &prev_map);

	while (tick(&curr_map, &prev_map)){}

	cout << "Run me again with a new map setting.\n";
}
