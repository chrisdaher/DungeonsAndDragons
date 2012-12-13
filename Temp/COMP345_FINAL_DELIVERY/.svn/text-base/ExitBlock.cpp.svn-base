#include "stdafx.h"
#include "Block.h"

//define Empty Block Default Attributes
#define DEFAULT_ExitBlock_Name "ExitBlock"
#define DEFAULT_ExitBlock_Type "E"
#define DEFAULT_ExitBlock_IsOpen true
using namespace d20Logic;
ExitBlock::ExitBlock(){
	Name=DEFAULT_ExitBlock_Name;
	Type=DEFAULT_ExitBlock_Type;
	IsOpen=DEFAULT_ExitBlock_IsOpen;
}

char* ExitBlock::getName(){
	return Name;
}
char* ExitBlock::getType(){
	return Type;
}
bool ExitBlock::getOpen(){
	return IsOpen;
}
int ExitBlock::getPositionX(){
	return positionX;	
}
int ExitBlock::getPositionY(){
	return positionY;
}
void ExitBlock::setPositionX(int posX){
	positionX=posX;
}
void ExitBlock::setPositionY(int posY){
	positionY=posY;
}
void ExitBlock::setOpen(bool OPEN){
	IsOpen=OPEN;
}