#include <ncurses.h>

bool walktest(int x, int y) { // tests if there is something unwalkable
	switch(mvinch(y,x)) { // at x,y
		case '#': // add more to switch statement as needed
			return false;
		default:
			return true;
	}
}

void walk(int x, int y, int* dx, int* dy, char dir) {
	char dis;

	switch(dir) {
		case 'n':
			if(walktest(x,y-1)) {
				y--;
			}
			break;
		case 's':
			if(walktest(x,y+1)) {
				y++;
			}
			break;
		case 'e':
			if(walktest(x+1,y)) {
				x++;
			}
			break;
		case 'w':
			if(walktest(x-1,y)) {
				x--;
			}
			break;
	}
	move(y,x);
	dis = inch();
	addch('@');
	refresh();
	move(y,x); // replaces x,y with displaced char
	addch(dis);
	*dx = x;
	*dy = y;
}
