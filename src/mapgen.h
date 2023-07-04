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

//Randomly generates tiles in a chunk with each increase in per being 1/1000 probability
struct Chunk genRandom(int per);

//Checks the number of tiles of type 'type' around coords (y, x) in chunk c
int checkAdj(int y, int x, int type, struct Chunk c);

struct Chunk stepMapGen(double createPer, double deletePer, struct Chunk c);
//struct Chunk findChunk(int y, int x); //This is supposed to find the chunk the coordinates are in
struct Chunk defaultGen();

//Check the total number of neighboors.  Should usually be 8; 5 if it is a side tile; 3 if it is a corner tile
int checkNumNeigh(int y, int x);

bool checkTile(int y, int x, int type, struct Chunk c);
#endif
