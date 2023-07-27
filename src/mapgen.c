#include <ncurses.h>

#include "main.h"
#include "mapgen.h"
#include "player.h"

struct Tile default_tile() { // face char, type, breakable, color
	struct Tile tile = {'.', 0, true, 0};
	return tile;
}
struct Tile empty_tile(){
	struct Tile tile = {' ', 1, false, 0};
	return tile;
}
struct Tile player_tile(){
	struct Tile tile = {'%', 2, false, 0};
	return tile;
}
struct Npc default_npc(){
	struct Npc npc = {0, 0, ' '};
	return npc;
}
struct Chunk testgen() {
	struct Chunk testmap;
	for(int i = 0; i < GAME_Y; i++) { // y
		for(int j = 0; j < GAME_X; j++) { // x

			testmap.tilemap[i][j] = default_tile();

		}
	}

	return testmap;
}
struct Chunk defaultGen(){
	struct Chunk c = genRandom(605);
	for(int i = 0; i < 10; i++){
		c = stepMapGen(0.78, 0.45,c);
	}
	spawnNPC(&c);
	return c;
}

struct Chunk cavegen() {
	struct Chunk genmap;

	return genmap;
}

//Generates randomly with the probability of it being per percent
struct Chunk genRandom(int per) {
	struct Chunk testmap;
	for(int i = 0; i < GAME_Y; i++) { // y
		for(int j = 0; j < GAME_X; j++) { // x
			if(rand()%1000 <= per-1){
				testmap.tilemap[i][j] = default_tile();
			} else{
				testmap.tilemap[i][j] = empty_tile();
			}
		}
	}
	return testmap;
}
int checkTile(int y, int x, struct Chunk c){
	if(c.npc.x == x && c.npc.y == y){
		return -1;
	}
	return c.tilemap[y][x].type;
}
//Should work for any coordinate given in bound, and any type.  Chunk is a placeholder for now.
int checkAdj(int y, int x, int type, struct Chunk c){
	int count = 0;
	for(int i = -1; i < 2; i++){
		for(int j = -1; j < 2; j++){
			if((i == 0 && j == 0) || y+i < 0 || x+j <0 || y+i >= GAME_Y|| x+j >= GAME_X){
				continue;
			}else if(c.tilemap[y+i][x+j].type == type){
				count++;
			}
		}
	}
	return count;
}
//CheckAdj's handy dandy sister. checks how many avalible spaces neighbor it.  Usually 8, 5 on a side, and 3 on a corner
int checkNumNeigh(int y, int x){
	int count = 0;
	for(int i = -1; i < 2; i++){
		for(int j = -1; j < 2; j++){
			if((i == 0 && j == 0) || y+i < 0 || x+j < 0 || y+i >= GAME_Y|| x+j >= GAME_X){
				continue;
			}else{
				count++;
			}
		}
	}
	return count;
}
//The big boy. This is a customizable Game of Life.  I used proportions because there are sides and corners of the map.
struct Chunk stepMapGen(double createPer, double deletePer, struct Chunk c){
	double per;
	struct Chunk next;
	for(int i = 0; i < GAME_Y; i++) { // y
		for(int j = 0; j < GAME_X; j++) { // x
			next.tilemap[i][j] = c.tilemap[i][j];
			per = (double)checkAdj(i, j, 0, c)/checkNumNeigh(i, j);
			if(per >= createPer){
				next.tilemap[i][j] = default_tile();
			} else if(per <= deletePer){
				next.tilemap[i][j] = empty_tile();
			}
		}
	}
	return next;
}
void changeTile(struct Chunk *d, int y, int x, int type){
	switch(type){
		case 0:
			d->tilemap[y][x].ch = '.';
			break;
		case 1:
			d->tilemap[y][x].ch = ' ';
			break;
	}
	d->tilemap[y][x].type = type;
}
void spawnNPC(struct Chunk *d){
	d->npc = default_npc();
	int off = 0;
	while(true){

		for(int j = 0+off; j < GAME_X-off;j++){//x
			if(checkTile(off, j, *d) == 1){
				d->npc.y = off;
				d->npc.x = j;
				return;
			}
			if(checkTile(GAME_Y-off-1, j, *d) == 1){
				d->npc.y = GAME_Y-off-1;
				d->npc.x = j;
				return;
			}
		}
		for(int i = 0+off; i < GAME_Y-off;i++){//y
			if(checkTile(i, off, *d) == 1){
				d->npc.y = i;
				d->npc.x = off;
				return;
			}
			if(checkTile(i, GAME_X-off-1, *d) == 1){
				d->npc.y = i;
				d->npc.x = GAME_X-off-1;
				return;
			}
		}
		off++;
	}
}
void setNPCIntent(struct Npc *n){
	int random = rand()%4;
	switch(random){
		case 0:
			n->intent = 'u';
			return;
		case 1:
			n->intent = 'h';
			return;
		case 2:
			n->intent = 'j';
			return;
		case 3:
			n->intent = 'k';
			return;
	}
}

void NPCAction(struct Chunk *c){
	switch(c->npc.intent){
		case 'h':
			if(checkTile(c->npc.y, c->npc.x-1, *c) == 1){
				c->npc.x--;
			}
			return;
		case 'u':
			if(checkTile(c->npc.y-1, c->npc.x, *c) == 1){
				c->npc.y--;
			}
			return;
		case 'j':
			if(checkTile(c->npc.y+1, c->npc.x, *c) == 1){
				c->npc.y++;
			}
			return;
		case 'k':
			if(checkTile(c->npc.y, c->npc.x+1, *c) == 1){
				c->npc.x++;
			}
			return;
	}
	return;
}
