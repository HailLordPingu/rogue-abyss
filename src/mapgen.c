#include <ncurses.h>

#include "main.h"
#include "mapgen.h"

struct Tile default_tile() { // face char, type, breakable, color
	struct Tile tile = {'.', 0, true, 0};
	return tile;
}
struct Tile empty_tile(){
	struct Tile tile = {' ', 1, false, 0};
	return tile;
}
struct Tile special_tile(){
	struct Tile tile = {'%', 2, false, 0};
	return tile;
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

struct Chunk cavegen() {
	struct Chunk genmap;

	return genmap;
}

//Generates randomly with the probability of it being per percent
//Tested the checkAdj function.  It works.
//However, this "random" generation seems to generate the same thing every time.  That's a problem.
struct Chunk genRandom(int per) {
	struct Chunk testmap;
	for(int i = 0; i < GAME_Y; i++) { // y
		for(int j = 0; j < GAME_X; j++) { // x
			if(rand()%100 <= per-1){
				testmap.tilemap[i][j] = default_tile();
			} else{
				testmap.tilemap[i][j] = empty_tile();
			}
		}
	}
	testmap.tilemap[15][50].ch = '0'+checkAdj(13, 48, 0, testmap); //Test the checkadj function
	return testmap;
}
//Your handy dandy adj function (I cannot spell the actual word)
//Should work for any coordinate given in bound, and any type.  Chunk is a placeholder for now.
int checkAdj(int y, int x, int type, struct Chunk c){
	int count = 0;
	for(int i = -1; i < 2; i++){
		for(int j = 0; j < 2; j++){
			if(i == 0 && j == 0){
				continue;
			}else if(c.tilemap[y+i][x+j].type == type){
				count++;
			}
		}
	}
	return count;
}
