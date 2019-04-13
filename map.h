#ifndef MAP_H
# define MAP_H

class Game;

class Map
{
	friend	Game;

private:
	bool	**map;
	short	size_x;
	short	size_y;
	void	set_sizes(short &, short &);
	void	allocate_memory(void);

public:
	void	display(void);
	void	init(short &, short &);
	void	set_creature(short &, short &);
	~Map(void);
};

#endif //MAP_H
