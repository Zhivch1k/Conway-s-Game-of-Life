#include <iostream>
#include "map.h"

int main(void)
{
	Map *game_map = new Map;
	game_map->set_sizes(100, 100);
	game_map->allocate_memory();
	game_map->init();
	game_map->display();
	delete game_map;
	system("leaks a.out");
	return (0);
}