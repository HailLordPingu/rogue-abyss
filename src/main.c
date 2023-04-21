#include <ncurses.h>

#include "mapgen.h"
#include "main.h"
#include "render.h"

int main() {
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

	struct Chunk test = genRandom(62);
	gamerend(game, test);

	while(true) { // keybinds, game stuff
		switch(wgetch(game)) {
			default:
				continue;
			case 'q':
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
int checkAdj(int x, int y, int type){
	int count = 0;
	for(int i = -1; i < 2; i++){
		for(int j = -1; j < 2; j++){
			if(i == 0 && j == 0){
				continue;
			} /*else if(c.tilemap[y+i][x+j].type == type){
				count++;
			}*/
		}
	}
	return count;
}

