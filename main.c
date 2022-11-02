#include <ncurses.h>
#include <stdlib.h>
#include "misc.h"
#include "mapgen.h"
#include "walk.h"

int main() {
	int x = 10; // spawn cords + general char pos
	int y = 10;
	int* dx = &x; // pointers for ^
	int* dy = &y;
	int rows, cols;
	char ch;

	initscr();
	curs_set(0);

	getmaxyx(stdscr, rows, cols);
	rows--;
	cols--;

	move(y, x);

	mapinit(1,2,1722); // map top left pos, seed
	rect(0,0,cols,2,'#','+');
	rect(0,2,81,31,'#','+');

	while(true) {
		ch = getchar();
		switch(ch) {
			case 'h':
				walk(x,y,dx,dy,'w');
				break;
			case 'j':
				walk(x,y,dx,dy,'s');
				break;
			case 'k':
				walk(x,y,dx,dy,'n');
				break;
			case 'l':
				walk(x,y,dx,dy,'e');
				break;
			case 'q':
				endwin();
				return(0);
		}
	}
	refresh();
	getch();
	endwin();
	return(0);
}
