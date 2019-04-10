#ifndef MAP_H
# define MAP_H

class Map
{
private:
	bool **map;
	short size_x;
	short size_y;

public:
	void	set_sizes(short &, short &);
	void	allocate_memory(void);
	void	display(void);
	void	init(void);
	void	set_creature(short &, short &);
	~Map(void);
};

#endif //MAP_H
