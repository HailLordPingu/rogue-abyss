#include <ncurses.h>
#include <stdio.h>

#include "main.h"
#include "mapgen.h"
#include "player.h"

void gamerend(WINDOW* win, struct Player player, struct Chunk chunk) {
	for(int i = 0; i < GAME_Y; i++) { // y
		for(int j = 0; j < GAME_X; j++) { // x
			
			// main rendering code per tile

			// sets ch to the face char @ i,j within the chunk
			char ch = chunk.tilemap[i][j].ch;
			mvwaddch(win,i,j,ch);

			// color (?)
		}
	}
	mvwaddch(win, player.y, player.x, 'p');
	wrefresh(win);
}
