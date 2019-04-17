#include "file_read.h"

void		File_reading::read_map_from_file(Map *curr_map, Map *prev_map)
{
	cout << "Please enter file name: " << endl;
	cin >> file_name;
	if (!ifstream(file_name))
	{
		cout << "Error while opening file\n";
		exit(2);
	}
	get_map_sizes();
	curr_map->init(map_size_x, map_size_y);
	prev_map->init(map_size_x, map_size_y);
	fill_map_from_file(curr_map);
}

void		File_reading::fill_map_from_file(Map *curr_map)
{
	string	str;
	short	y = 0;

	file.open(file_name);
	while (getline(file, str))
	{
		for (int i = 0; i < map_size_x; i++)
		{
			if (str[i] == 'X')
				curr_map->map[y][i] = true;
		}
		y++;
	}
	file.close();
}

void		File_reading::get_map_sizes(void)
{
	string		str;

	file.open(file_name);
	map_size_y = 0;
	while (getline(file, str))
	{
		map_size_x = str.length();
		map_size_y++;
	}
	file.close();
	cout << "x = " << map_size_x << " y = " << map_size_y << endl;
}
