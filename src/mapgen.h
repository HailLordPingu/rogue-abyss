#ifndef MAPGEN_H
#define MAPGEN_H
#include <stdlib.h>

struct Tile {
	char ch; // face char
	int type; // eg. land, chest, pc, etc.  0 - nothing, 1 block
	bool breakable; // if can be broken
	int color; // self explanitory

};

struct Chunk {
	struct Tile tilemap[30][100];
	// int biome;
};

struct Chunk testgen();

struct Chunk genRandom();

//int findChunk();

#endif
