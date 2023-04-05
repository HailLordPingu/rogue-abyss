#ifndef MAPGEN_H
#define MAPGEN_H

struct Tile {
	char ch; // face char
	int type; // eg. land, chest, pc, etc
	bool breakable; // if can be broken
	int color; // self explanitory
};

struct Chunk {
	struct Tile tilemap[30][100];
	// int biome;
};

struct Chunk testgen();

#endif
