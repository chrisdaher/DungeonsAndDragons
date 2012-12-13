#include "stdafx.h"
#include "Block.h"

//define Empty Block Default Attributes
#define DEFAULT_EmptyBlock_Name "EmptyBlock"
#define DEFAULT_EmptyBlock_Type " "
#define DEFAULT_EmptyBlock_IsOpen true
using namespace d20Logic;
EmptyBlock::EmptyBlock(){
	Name=DEFAULT_EmptyBlock_Name;
	Type=DEFAULT_EmptyBlock_Type;
	IsOpen=DEFAULT_EmptyBlock_IsOpen;
}
EmptyBlock::EmptyBlock(char* name, char* type, bool isopen){
	Name=name;
	Type=type;
	IsOpen=isopen;
}

char* EmptyBlock::getName(){
	return Name;
}
char* EmptyBlock::getType(){
	return Type;
}
bool EmptyBlock::getOpen(){
	return IsOpen;
}
