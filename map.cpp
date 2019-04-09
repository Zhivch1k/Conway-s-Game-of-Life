#include <iostream>
#include "map.h"

using namespace std;

void	Map::set_sizes(short map_size_x, short map_size_y)
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
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			cout << ((map[i][j]) ? "X " : ". ");
		}
		cout << endl;
	}
}

void	Map::init(void)
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
			map[i][j] = false;
	}
}

void	Map::set_creature(short x, short y)
{
	if (x < 0 || x > size_x)
	{
		cout << "Error. X coordinate is invalid\n";
		return ();
	}
	if (y < 0 || x > size_x)
	{
		cout << "Error. Y coordinate is invalid\n";
		return ();
	}
	map[y][x] = ture;
}

Map::~Map(void)
{
	for (int i = 0; i < size_y; i++)
		delete[] map[i];
	delete[] map;
}
