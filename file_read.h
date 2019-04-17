#ifndef CONWAY_S_GAME_OF_LIFE_FILE_READ_H
# define CONWAY_S_GAME_OF_LIFE_FILE_READ_H

# include <fstream>
# include <iostream>
# include <string>
# include "map.h"

using namespace std;

class File_reading
{
private:
	short		map_size_x;
	short		map_size_y;
	string		file_name;
	ifstream	file;
	void		get_map_sizes(void);
	void		fill_map_from_file(Map *curr_map);

public:
	void		read_map_from_file(Map *curr_map, Map *prev_map);
};

#endif //CONWAY_S_GAME_OF_LIFE_FILE_READ_H
