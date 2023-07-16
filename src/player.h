#ifndef PLAYER_H
#define PLAYER_H
#include "mapgen.h"

struct Player {
	int str, mov, brn, hrd; // stats
	// strength, movement, brains, hardyness

	int x,y; // cords
};
struct Player initial_player();
void spawnInitialPlayer(struct Player *p, struct Chunk c);
void setPlayerCoords(struct Player *p, int y, int x);
void controlPlayer(struct Player *p, int key, struct Chunk *d);
#endif
