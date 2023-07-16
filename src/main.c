#include <ncurses.h>

#include "mapgen.h"
#include "main.h"
#include "render.h"
#include "player.h"

int main() {
	//seed
	int seed = 1;
	srand(seed);
	// vars
	int cols, rows;
	getmaxyx(stdscr, rows, cols);
	cols--;
	rows--;

	WINDOW *game; // add more as needed


	//curses initial settings
	initscr();
	curs_set(0);

	// Windows for UI, Game, etc
	game = newwin(GAME_Y, GAME_X, 0, 0);

	// Game loop

	struct Chunk test = defaultGen();
	struct Player theMan = initial_player();
	spawnInitialPlayer(&theMan, test);
	int in;
	gamerend(game, theMan, test);
	while(true) { // keybinds, game stuff
		in = wgetch(game);
		switch(in) {
			default:
				controlPlayer(&theMan, in, &test);
				gamerend(game, theMan, test);
				continue;
			case 'q': //Unless you press this key
				endwin();
				return 0;
			case 'z':
				seed++;
				test = defaultGen();
				spawnInitialPlayer(&theMan, test);
				gamerend(game, theMan, test);
		}
	}
	endwin();
	return 0;
}

void rect(int y1, int x1, int y2, int x2) {
	for(int i = y1; i < y2; i++) {
		for(int j = x1; j < x2; j++) {
			mvaddch(i,j,'#');
		}
	}
}

