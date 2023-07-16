#include <ncurses.h>

#include "main.h"
#include "mapgen.h"
#include "player.h"

//Sets the player with all values of 0
struct Player initial_player(){
	struct Player player = {0, 0, 0, 0, 0, 0};
	return player;
}
//Directly sets player coords
void setPlayerCoords(struct Player *p, int y, int x){
	p->y = y;
	p->x = x;
}

//Circles around the outer edges of the tilemap to find a suitable space.
void spawnInitialPlayer(struct Player *p, struct Chunk c){
	for(int off = 0; off < 50; off++){
		for(int i = GAME_Y/2-off; i <= GAME_Y/2+off; i++){
			for(int j = GAME_X/2-off; j <= GAME_X/2+off; j++){
				if(c.tilemap[i][j].type == 1){
					setPlayerCoords(p, i, j);
					return;
				}
			}
		}
	}
}
//The movement is hardcoded, it would be changed later to fufill conditionals (if the tile is blocked)
void controlPlayer(struct Player *p, int key, struct Chunk *d){
	switch(key){
		case 'u':
			if(checkTile(p->y-1, p->x, 1, *d)){
				p->y-=1;
			} else{
				changeTile(d, p->y-1, p->x, 1);
			}
			break;

		case 'j':
			if(checkTile(p->y+1, p->x, 1, *d)){
				p->y+=1;
			} else{
				changeTile(d, p->y+1, p->x, 1);
			}
			break;

		case 'h':
			if(checkTile(p->y, p->x-1, 1, *d)){
				p->x-=1;
			}else{
				changeTile(d, p->y, p->x-1, 1);
			}
			break;

		case 'k':
			if(checkTile(p->y, p->x+1, 1, *d)){
				p->x+=1;
			} else{
				changeTile(d, p->y, p->x+1, 1);
			}
			break;
		default:
			break;
	}
}

