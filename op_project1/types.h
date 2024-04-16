#pragma once

typedef struct Point {
	int x;
	int y;
} Point;

enum event_type {
	DEFEND,
	KILL,
	REPRODUCE,
	EAT,
	FLEE,
	PLANT,
	MOVE
};
enum creature_type {
	WILK,
	LIS,
	TUTEL,
	ANTYLOPA,
	OWCA,
	CYBER_OWCA,
	TRAWA,
	MLECZ,
	GUARANA,
	WILCZE_JAGODY,
	BARSZCZ_SOSNOWSKIEGO,
};

void gotoxy(int x, int y);
char get_symbol(creature_type type);
const char* get_name(creature_type type);