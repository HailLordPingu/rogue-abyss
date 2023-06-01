#ifndef PLAYER_H
#define PLAYER_H

struct Player {
	int str, mov, brn, hrd; // stats
	// strength, movement, brains, hardyness

	int x,y; // cords
};
//Player with all stats 0
struct Player initial_player();
struct Player spawnPlayer(struct Chunk c);
struct Player findGoodSpace(int y, int x);
#endif
