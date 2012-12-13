#ifndef MAPHELPER_H
#define MAPHELPER_H
#include "Map.h"
#include "Character.h"

static class MapHelper{
public:
	static Map* addMainCharacter(Map* theMap, Character* theChar, int x,int y);
	static Map* addMonster(Map* theMap, Character* theChar, int x,int y);
	static Map* changeBlockAt(Map* theMap, int x,int y, int blockType);
	static Map* wallFromToHorizontal(Map* theMap, int y, int from, int to);
	static Map* wallFromToVertical(Map* theMap, int x, int from, int to);
};
#endif