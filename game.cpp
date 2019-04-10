#include "game.h"
#include "map.h"

void		Game::init(Map *game_map)
{
	short		x = -1;
	short		y = -1;
	short		creature_x = 0;
	short		creature_y = 0;

	cout << "Welcome to the Conway's game of life!\n\n";
	while (x < 0 || y < 0 || x > 100 || y > 100)
	{
		cout << "Please enter the height of the map\n";
		cin >> y;
		cout << "Please enter the width of the map\n";
		cin >> x;
	}
	cout << "Initializing map with entered sizes...\n\n";
	game_map->set_sizes(x, y);
	game_map->allocate_memory();
	game_map->init();
	cout << "Successfully initialized!\n";
	cout << "Not it's time to fill the map with creatures\n";
	while (!(creature_x == -1 && creature_y == -1))
	{
		cout << "Enter two numbers x and y to place the creature on that position\n";
		cout << "To stop adding creatures and run a game enter -1 and -1\n";
		cin >> creature_x >> creature_y;
		if ((creature_x >= 0 && creature_x < x) &&
			(creature_y >= 0 && creature_y < y))
			game_map->set_creature(creature_y, creature_x);
		game_map->display();
	}
}

void		Game::run_a_game(void)
{
	Map		game_map;
	init(&game_map);
}