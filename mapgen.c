#include <stdlib.h>
#include <ncurses.h>
#include "misc.h"
#include "mapgen.h"

int frencount(int x, int y) {
	int fren = 0;
	if (mvinch(y+1,x) == '#') {fren++;}
	if (mvinch(y+1,x+1) == '#') {fren++;}
	if (mvinch(y+1,x-1) == '#') {fren++;}
	if (mvinch(y,x+1) == '#') {fren++;}
	if (mvinch(y,x-1) == '#') {fren++;}
	if (mvinch(y-1,x+1) == '#') {fren++;}
	if (mvinch(y-1,x-1) == '#') {fren++;}
	if (mvinch(y-1,x) == '#') {fren++;}
	return fren;
}

void mapinit(int initx, int inity, int seed) {
	int fren;
	int depth = 5;
	const int scrsizex = 80;
	const int scrsizey = 30;
	const int dense = 34;

	srand((unsigned) seed);

	/* creates random noise to use later */
	for(int i = inity; i < inity + scrsizey; i++) { // y
		for(int j = initx; j < initx + scrsizex; j++) { // x
			if((rand() % 100) < dense) {
				mvaddch(i,j,'#');
			}
		}
	}

	square(7,7,13,13,' ');

	while(depth > 0) {
		/* main generation method based vaugly off of conways
		 * game of life, still needs exceptions to make complete
		 * cave systems, unaccesable rooms still an issue. */
		for(int i = inity; i < inity + scrsizey; i++) { // y
			for(int j = initx; j < initx + scrsizex; j++) { // x
				fren = frencount(j,i);

				if(mvinch(i,j) == '#' && fren >= 4) { // 4:5 GoL
					continue;
				} else if(fren >= 5) {
					mvaddch(i,j,'#');
				} else if(fren == 0) {
					mvaddch(i,j, ' ');
				} else if(depth <= 2 && fren <= 5) { // clean up cycle
					mvaddch(i,j,' ');
				}
			}
		}
		depth--;
	}
}
