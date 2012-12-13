#include "stdafx.h"
#include "Map.h"
#include "Combat.h"
#include <iostream>
#include "MapHelper.h"
#include "Block.h"
using std::cout;
using namespace d20Logic;
//define default grid size
#define DEFAULT_X_SIZE 10
#define DEFAULT_Y_SIZE 10

Map::Map(){
	GridSizeX = DEFAULT_X_SIZE;
	GridSizeY = DEFAULT_Y_SIZE;

	MapGrid = new Block*[GridSizeX];
	InitArray(GridSizeX, GridSizeY);	
}

Map::Map(int x, int y){
	GridSizeX = x;
	GridSizeY = y;

	MapGrid = new Block*[GridSizeX];
	InitArray(GridSizeX, GridSizeY);
}

Map::~Map(){
	delete [] MapGrid;
}

void Map::NotifyObservers(){
	for (int i=0; i<observerCollection.size();i++){
		observerCollection[i]->notify(MapGrid,GridSizeX, GridSizeY);
	}
}

void Map::RegisterObserver(MapObserver* observer){
	observerCollection.push_back(observer);
}

void Map::UnregisterLastObserver(){
	observerCollection.pop_back();
}

void Map::InitArray(unsigned int xSize, unsigned int ySize){	
	for (unsigned int i=0;i<xSize;i++){
		MapGrid[i] = new EmptyBlock[ySize];
	}
	for (unsigned int i=0;i<xSize;i++){
		for (unsigned int k=0;k<ySize;k++){
			MapGrid[i][k] =*new EmptyBlock();
		}
	}
}

Block* Map::GetBlockAt(int x, int y){
	if (x<0 || x>=GridSizeX) return 0;
	if (y<0 || y>=GridSizeY) return 0;
	return &MapGrid[x][y];
}

bool Map::IsOpenAt(int x, int y){
	if (x<0 || x >= GridSizeX) return false;
	if (y<0 || y >= GridSizeY) return false;
	
	/*
	 * 0: OPEN
	 * 1: WALL
	 * 2: TREASURE
	 * 3: CHARACTER%
	 * 4: OPPONENT
	*/
	Block* currValue = &MapGrid[y][x];
	if (currValue->IsOpen) return true;
	return false;
}

int Map::GetX(){
	return GridSizeX;
}

int Map::GetY(){
	return GridSizeY;
}

void Map::SetBlockValue(int x, int y, Block* val){
	if (x<0 || x >= GridSizeX) return;
	if (y<0 || y >= GridSizeY) return;

		MapGrid[x][y] = *val;
	NotifyObservers();
}

void Map::displayMap(){
	for (unsigned int i=0; i<GridSizeY; i++){
		for(unsigned int j=0; j<GridSizeX; j++){
			cout << MapGrid[i][j].getType();
		}
		cout<<"\n";
	}
}
void Map::EmptyBlockAt(int x, int y){
	if (x<0 || x >= GridSizeX) return;
	if (y<0 || y >= GridSizeY) return;

	MapGrid[y][x] = *new EmptyBlock();
	//NotifyObservers();
}
void Map::EntranceBlockAt(int x, int y){
	if (x<0 || x >= GridSizeX) return;
	if (y<0 || y >= GridSizeY) return;

	theStart=*new EntranceBlock();
	theStart.setPositionX(x);
	theStart.setPositionY(y);
	MapGrid[y][x] = theStart;
	//NotifyObservers();
}
void Map::WallBlockAt(int x, int y){
	if (x<0 || x >= GridSizeX) return;
	if (y<0 || y >= GridSizeY) return;

	MapGrid[y][x] = *new WallBlock();
	NotifyObservers();
}
void Map::TreasureBlockAt(int x, int y){
	if (x<0 || x >= GridSizeX) return;
	if (y<0 || y >= GridSizeY) return;

	MapGrid[y][x] = *new TreasureBlock();
	NotifyObservers();
}

void Map::CharacterBlockAt(int x, int y, Character* theChar){
	if (x<0 || x >= GridSizeX) return;
	if (y<0 || y >= GridSizeY) return;

	MapGrid[y][x] = *theChar;
	NotifyObservers();
	
}
void Map::ExitBlockAt(int x, int y){
	if (x<0 || x >= GridSizeX) return;
	if (y<0 || y >= GridSizeY) return;
	theEnd = *new ExitBlock();
	theEnd.setPositionX(x);
	theEnd.setPositionY(y);
	MapGrid[y][x]= theEnd;
	NotifyObservers();
};
void Map::move(int fromX,int fromY,int toX,int toY){
	EmptyBlockAt(fromX, fromY);
	CharacterBlockAt(toX, toY, &c1);
	c1.setPositionX(toX);
	c1.setPositionY(toY);
}
void Map::KillMonster(){
	EmptyBlockAt(Monster.getPositionX(), Monster.getPositionY());
	theEnd.setOpen(true);
	MapGrid[theEnd.getPositionY()][theEnd.getPositionX()]=theEnd;
	NotifyObservers();
}
void Map::hitChest(Chest* theChest){
	vector<Item> theItems = theChest->contents;
	for (int i=0;i<theItems.size();i++){
		c1.takeItem(*theChest,i);
	}
	
}
System::Drawing::Point Map::MoveCharacter(/*int characterNumber,*/ char direction){
	//Character c1=CharacterList[characterNumber];
	bool MonsterDies;
	int tempX=c1.getPositionX();
	int tempY=c1.getPositionY();
	if(direction=='w'){
		if(IsOpenAt(tempX, tempY-1)){
			if(*(MapGrid[tempY-1][tempX].getType())=='E'){
				c1.levelUp();
				return System::Drawing::Point(-1,-1);
				
			}
			if(*(MapGrid[tempY-1][tempX].getType())=='T'){
				Block* theTreasure = &(MapGrid[tempY-1][tempX]);
				Chest* theChest = theTreasure->theChest;
				hitChest(theChest);
			}
			if(*(MapGrid[tempY-1][tempX].getType())=='C'){
				MonsterDies=Combat::Fight(c1,Monster);
				if(MonsterDies){
					KillMonster();
					return System::Drawing::Point(tempX,tempY-1);
				}
			}
			else{
				move(tempX, tempY, tempX, tempY-1);
				return System::Drawing::Point(tempX,tempY-1);
			}
			
			
		}
	}else if(direction=='s'){
		if(IsOpenAt(tempX, tempY+1)){
			if(*(MapGrid[tempY+1][tempX].getType())=='E') {
				c1.levelUp();
				return System::Drawing::Point(-1,-1);
			}
			if(*(MapGrid[tempY+1][tempX].getType())=='T'){
				Block* theTreasure = &(MapGrid[tempY+1][tempX]);
				Chest* theChest = theTreasure->theChest;
				hitChest(theChest);
			}
			if(*(MapGrid[tempY+1][tempX].getType())=='C') {
				MonsterDies=Combat::Fight(c1,Monster);
				if(MonsterDies){
					KillMonster();
					return System::Drawing::Point(tempX,tempY+1);
				}
			}
			else{
				move(tempX, tempY, tempX, tempY+1);
				return System::Drawing::Point(tempX,tempY+1);
			}
		}
	}else if(direction=='a'){
		if(IsOpenAt(tempX-1, tempY)){
			if(*(MapGrid[tempY][tempX-1].getType())=='E') {
				c1.levelUp();
				return System::Drawing::Point(-1,-1);
			}
			if(*(MapGrid[tempY][tempX-1].getType())=='T'){
				Block* theTreasure = &(MapGrid[tempY][tempX-1]);
				Chest* theChest = theTreasure->theChest;
				hitChest(theChest);
		
			}
			if(*(MapGrid[tempY][tempX-1].getType())=='C'){
				MonsterDies=Combat::Fight(c1,Monster);
				if(MonsterDies){
					KillMonster();
					return System::Drawing::Point(tempX  - 1,tempY);
				}
			}
			else{
				move(tempX, tempY, tempX-1, tempY);
				return System::Drawing::Point(tempX  - 1,tempY);
			}
			
		}
	}else if(direction=='d'){
		if(IsOpenAt(tempX+1, tempY)){
			if(*(MapGrid[tempY][tempX+1].getType())=='E') {
				c1.levelUp();
				return System::Drawing::Point(-1,-1);
			}
			if(*(MapGrid[tempY][tempX+1].getType())=='T'){
				Block* theTreasure = &(MapGrid[tempY][tempX+1]);
				Chest* theChest = theTreasure->theChest;
				hitChest(theChest);
			}
			if(*(MapGrid[tempY][tempX+1].getType())=='C') {
				MonsterDies=Combat::Fight(c1,Monster);
				if(MonsterDies){
					KillMonster();
					return System::Drawing::Point(tempX +1,tempY);
				}
			}
			else{
			move(tempX, tempY, tempX+1, tempY);
			return System::Drawing::Point(tempX +1,tempY);
			}
		}
	}
	
	return System::Drawing::Point(-2,-2);
}

void Map::AddCharacter(/*int characterNumber,*/Character* theChar){
	c1=*theChar;
	int x=theStart.getPositionX();
	int y=theStart.getPositionY();
	c1.setPositionX(x);
	c1.setPositionY(y);
	MapGrid[y][x] = *theChar;
	NotifyObservers();
	//Character c1 = CharacterList[characterNumber];
}
void Map::addMonster(/*int characterNumber,*/Character* theChar, int x, int y){
	//Character c1 = CharacterList[characterNumber];
	Monster=*theChar;
	Monster.setPositionX(x);
	Monster.setPositionY(y);
	MapGrid[y][x] = Monster;
	NotifyObservers();
}

bool Map::saveMap(System::String^ mapName){

	System::String^ toAppend = "\\" + mapName + MAP_FILE_TYPE;
	System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(DEFAULT_LOCATION_MAP_DATA + toAppend);
	Block* tempBlock;
	char* aType;
	System::String^ temp;
	System::String^ sizeX = System::Convert::ToString(GridSizeX);
	System::String^ sizeY = System::Convert::ToString(GridSizeY);
	
	sw->WriteLine(sizeX);
	sw->WriteLine(sizeY);

		for (int i=0;i<GridSizeX;i++){
			for (int k=0;k<GridSizeY;k++){
				tempBlock = GetBlockAt(i,k);
				aType = tempBlock->getType();
				temp = gcnew System::String(aType);
				sw->WriteLine(temp);
			}
		}

		sw->Close();

	return true;

}

Map* Map::loadMap(System::String^ location){
	System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(location);	
	Map* toRet;
	System::String^ theLine;

		int sizeX = System::Convert::ToUInt32(sr->ReadLine());
		int sizeY = System::Convert::ToUInt32(sr->ReadLine());
		toRet = new Map(sizeX, sizeY);
		MapHelper* mh = new MapHelper();
		for (int i=0;i<sizeX;i++){
			for (int k=0;k<sizeY;k++){
				theLine = sr->ReadLine()->ToUpper();

				switch(theLine[0]){
				case ' ':
					toRet->EmptyBlockAt(k,i);
					break;
				
				case 'S':
					toRet->EntranceBlockAt(k,i);
					break;
				case 'E':
					toRet->ExitBlockAt(k,i);
					break;
				case 'T':
					toRet->TreasureBlockAt(k,i);
					break;
				case 'W':
					toRet->WallBlockAt(k,i);
					break;
				case 'C':
					mh->addMonster(toRet,new Character(3,1),k,i);
					break;
			}
		}
		}

	return toRet;
}


int Map::GetXStartPosition(){

	return theStart.getPositionX();
}
int Map::GetYStartPosition(){
	return theStart.getPositionY();
}

System::Drawing::Point Map::getCharacterPosition(){
	return System::Drawing::Point(c1.getPositionX(),c1.getPositionY());
}

Character* Map::getCurrentCharacter(){
	return &c1;
}