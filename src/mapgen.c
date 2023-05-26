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
struct Chunk defaultGen(){
	struct Chunk c = genRandom(605);
	for(int i = 0; i < 10; i++){
		c = stepMapGen(0.78, 0.45,c);
	}
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
	/*int testY, testX;
	testY = 0;
	testX = 0;
	testmap.tilemap[testY][testX].ch = '0'+checkNumNeigh(testY, testX); //Test the checkNeigh function*/
	return testmap;
}
//Your handy dandy adj function (I cannot spell the actual word)
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
