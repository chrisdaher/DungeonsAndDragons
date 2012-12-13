#include "stdafx.h"
#include "Builder.h"
#include "MapHelper.h"
using namespace d20Logic;
void ArenaBuilder::BuildMap(){
	Map* tempMap= new Map(9,9);
	MapHelper::wallFromToHorizontal(tempMap,0,0,8);
	MapHelper::wallFromToHorizontal(tempMap,8,0,8);
	MapHelper::wallFromToVertical(tempMap,0,0,8);
	MapHelper::wallFromToVertical(tempMap,8,0,8);
	MapHelper::changeBlockAt(tempMap,4,0,0);
	//tempMap=MapHelper::changeBlockAt(tempMap,4,8,0);
	MapHelper::changeBlockAt(tempMap,4,4,2);
	MapHelper::changeBlockAt(tempMap,4,8,3);
	Character* mainCharacter= new Character(1,1);
	mainCharacter->setPositionX(4);
	mainCharacter->setPositionY(0);
	Character* opponentCharacter= new Character(2,1);
	opponentCharacter->setPositionX(4);
	opponentCharacter->setPositionY(7);
	MapHelper::addMainCharacter(tempMap,mainCharacter,4,0);
	MapHelper::addMonster(tempMap, opponentCharacter,4,7);
	BuiltMap=tempMap;


}
Map* ArenaBuilder::getMap(){
	return BuiltMap;
}

