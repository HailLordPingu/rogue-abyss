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
	//int x;
	//int y;
	// int biome;
};

struct Chunk testgen();

int findAdj(int x, int y, int type){
	int i = 0;
	int j = 0;
	int count = 0;
	for(int i = 0; i < 4; i++){
		for int(j = 0; j < 4; j++){
			if(i == 0 && j == 0){
				continue;
			} else{
				if(tilemap[x+i][x+j] == type){
					count++;
				}
			}
		}
	}
	return count;
}
int findMap(){
}
int generateRan(int per, chunk c){
	int i = 0;
	int j = 0;
	for(int i = 0; i < 30; i++){
		for(int j = 0; j < 100; j++){
			if(rand()%100 < per){
				c[i][j].type = 1;
			}
		}
	}

}

#endif
