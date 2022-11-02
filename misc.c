#include <ncurses.h>
#include "misc.h"

/* draws rectange with cornors @ x1,y1 and x2,y2
   using ch as walls and cor and corners 	*/
void rect(int x1, int y1, int x2, int y2, char ch, char cor) {
	for(int i = x1; i < x2; i++) { // walls in y
		mvaddch(y1, i, ch);
		mvaddch(y2, i, ch); 
	}
	for(int i = y1; i < y2; i++) { // walls in x
		mvaddch(i, x1, ch);
		mvaddch(i, x2, ch);
	}
	mvaddch(y1, x1, cor); // corners
	mvaddch(y1, x2, cor);
	mvaddch(y2, x1, cor);
	mvaddch(y2, x2, cor);
}

/* similar to rect, but has no corners and fills in with ch*/
void square(int x1, int y1, int x2, int y2, char ch) {
	for(int i = x1; i < x2; i++) {
		for(int j = y1; j < y2; j++) {
			mvaddch(j,i,ch);	
		}
	}
}
