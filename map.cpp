#include <iostream>
#include "map.h"

using namespace std;

void	Map::set_sizes(short &map_size_x, short &map_size_y)
{
	size_x = map_size_x;
	size_y = map_size_y;
}

void	Map::allocate_memory(void)
{
	map = new bool *[size_y];
	for (int i = 0; i < size_y; i++)
		map[i] = new bool [size_x];
}

void	Map::display(void)
{
	system("clear");
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			cout << ((map[i][j]) ? "X " : ". ");
		}
		cout << endl;
	}
}

void	Map::init(short &map_size_x, short &map_size_y)
{
	set_sizes(map_size_x, map_size_y);
	allocate_memory();
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
			map[i][j] = false;
	}
}

void	Map::set_creature(short &y, short &x)
{
	map[y][x] = true;
}

Map::~Map(void)
{
	for (int i = 0; i < size_y; i++)
		delete[] map[i];
	delete[] map;
}
