#include "stdafx.h"
#include "MapHelper.h"

Map* MapHelper::addMainCharacter(Map* theMap, Character* theChar, int x,int y){
		theMap->AddCharacter(theChar);
		theMap->CharacterBlockAt(x, y, theChar);
		return theMap;
}
Map* MapHelper::addMonster(Map* theMap, Character* theChar, int x,int y){
		theMap->addMonster(theChar);
		theMap->CharacterBlockAt(x, y, theChar);
		return theMap;
}
Map* MapHelper::changeBlockAt(Map* theMap, int x,int y, int blockType){
		switch(blockType){
		case 0:
				theMap->EmptyBlockAt(x,y);
				break;
		case 1:
				theMap->WallBlockAt(x,y);
				break;
		case 2:
				theMap->TreasureBlockAt(x,y);
				break;
		case 3:
				theMap->ExitBlockAt(x,y);
				break;
	}
		return theMap;
}

Map* MapHelper::wallFromToHorizontal(Map* theMap, int y, int from, int to){
	for(int i=from; i<=(to);i++)
	{
		theMap=changeBlockAt(theMap,i,y,1);
	}
	return theMap;
}

Map* MapHelper::wallFromToVertical(Map* theMap, int x, int from, int to) {

	for(int i=from; i<=(to);i++)
	{
		theMap=changeBlockAt(theMap, x,i,1);
	}
	return theMap;

}