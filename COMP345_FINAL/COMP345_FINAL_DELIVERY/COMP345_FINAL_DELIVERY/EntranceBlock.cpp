#include "stdafx.h"
#include "Block.h"

//define Empty Block Default Attributes
#define DEFAULT_EntranceBlock_Name "EntranceBlock"
#define DEFAULT_EntranceBlock_Type "S"
#define DEFAULT_EntranceBlock_IsOpen true
using namespace d20Logic;
EntranceBlock::EntranceBlock(){
	Name=DEFAULT_EntranceBlock_Name;
	Type=DEFAULT_EntranceBlock_Type;
	IsOpen=DEFAULT_EntranceBlock_IsOpen;

	theSprite = "Img\\entranceBlock.jpg";
}

char* EntranceBlock::getName(){
	return Name;
}
char* EntranceBlock::getType(){
	return Type;
}
bool EntranceBlock::getOpen(){
	return IsOpen;
}

int EntranceBlock::getPositionX(){
	return positionX;	
}
int EntranceBlock::getPositionY(){
	return positionY;
}
void EntranceBlock::setPositionX(int posX){
	positionX=posX;
}
void EntranceBlock::setPositionY(int posY){
	positionY=posY;
}

char* EntranceBlock::getSprite(){
	return theSprite;
}