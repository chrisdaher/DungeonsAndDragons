#include "stdafx.h"
#include "Block.h"
using namespace d20Logic;
//define Wall Block Default Attributes
#define DEFAULT_TreasureBlock_Name "TreasureBlock"
#define DEFAULT_TreasureBlock_Type "T"
#define DEFAULT_TreasureBlock_IsOpen true
#define DEFAULT_TreasureBlock_Ammount 1000;

TreasureBlock::TreasureBlock(){
	Name=DEFAULT_TreasureBlock_Name;
	Type=DEFAULT_TreasureBlock_Type;
	IsOpen=DEFAULT_TreasureBlock_IsOpen;
	Ammount=DEFAULT_TreasureBlock_Ammount;
}
TreasureBlock::TreasureBlock(char* name, double ammount){
	Name=name;
	Type=DEFAULT_TreasureBlock_Type;
	IsOpen=DEFAULT_TreasureBlock_IsOpen;
	Ammount=ammount;
}
TreasureBlock::TreasureBlock(char* name, char* type, bool isopen, double ammount){
	Name=name;
	Type=type;
	IsOpen=isopen;
	Ammount=ammount;
}

char* TreasureBlock::getName(){
	return Name;
}
char* TreasureBlock::getType(){
	return Type;
}
bool TreasureBlock::getOpen(){
	return IsOpen;
}
double TreasureBlock::getAmmount(){
	return Ammount;
}

void TreasureBlock::setName(char* name){
	Name=name;
}
void TreasureBlock::setAmmount(double ammount){
	Ammount=ammount;
}
