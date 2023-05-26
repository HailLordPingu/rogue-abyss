#include <ncurses.h>

#include "mapgen.h"
#include "main.h"
#include "render.h"

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


	gamerend(game, test);
	while(true) { // keybinds, game stuff
		switch(wgetch(game)) {
			default:
				seed++;
				test = defaultGen();
				gamerend(game, test);
				continue;
			case 'q': //Unless you press this key
				endwin();
				return 0;
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

