#include "stdafx.h"
#include "Block.h"
using namespace d20Logic;
//define Wall Block Default Attributes
#define DEFAULT_WallBlock_Name "WallBlock"
#define DEFAULT_WallBlock_Type "W"
#define DEFAULT_WallBlock_IsOpen false

WallBlock::WallBlock(){
	Name=DEFAULT_WallBlock_Name;
	Type=DEFAULT_WallBlock_Type;
	IsOpen=DEFAULT_WallBlock_IsOpen;
}
WallBlock::WallBlock(char* name, char* type, bool isopen){
	Name=name;
	Type=type;
	IsOpen=isopen;
}

char* WallBlock::getName(){
	return Name;
}
char* WallBlock::getType(){
	return "C";
}
bool WallBlock::getOpen(){
	return IsOpen;
}
