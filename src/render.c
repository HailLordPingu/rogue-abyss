#include <ncurses.h>
#include <stdio.h>

#include "main.h"
#include "mapgen.h"

void gamerend(WINDOW* win, struct Chunk chunk) {
	for(int i = 0; i < GAME_Y; i++) { // y
		for(int j = 0; j < GAME_X; j++) { // x
			
			// main rendering code per tile

			// sets ch to the face char @ i,j within the chunk
			char ch = chunk.tilemap[i][j].ch;
			mvwaddch(win,i,j,ch);

			// color (?)

		}
	}
	wrefresh(win);
}
