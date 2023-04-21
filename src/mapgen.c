#include <ncurses.h>

#include "main.h"
#include "mapgen.h"

struct Tile default_tile() { // face char, type, breakable, color
	struct Tile tile = {'.', 0, true, 0};
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


struct Chunk genRandom(int per) {
	struct Chunk testmap;
	for(int i = 0; i < GAME_Y; i++) { // y
		for(int j = 0; j < GAME_X; j++) { // x
			if(rand()%100 <= per-1){
				testmap.tilemap[i][j] = default_tile();
			}
		}
	}

	return testmap;
}
