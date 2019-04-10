#include <iostream>
#include "game.h"

using namespace std;

int main(void)
{
	Game *new_game = new Game;
	new_game->run_a_game();
	return (0);
}