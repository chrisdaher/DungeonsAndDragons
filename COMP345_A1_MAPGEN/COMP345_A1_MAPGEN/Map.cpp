#include "stdafx.h"
#include "Map.h"
#include "Combat.h"
#include <iostream>
using std::cout;
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

	MapGrid[y][x]= *new ExitBlock();
	NotifyObservers();
};
bool Map::MoveCharacter(/*int characterNumber,*/ char direction){
	//Character c1=CharacterList[characterNumber];
	int tempX=c1.getPositionX();
	int tempY=c1.getPositionY();
	if(direction=='w'){
		if(IsOpenAt(tempX, tempY-1)){
			if(*(MapGrid[tempY-1][tempX].getType())=='E'){
				return true;
			}
			if(*(MapGrid[tempY-1][tempX].getType())=='C'){
				Combat::Fight(c1,Monster);
			}
			EmptyBlockAt(tempX, tempY);
			CharacterBlockAt(tempX, tempY-1, &c1);
			c1.setPositionY(tempY-1);
			
		}
	}else if(direction=='s'){
		if(IsOpenAt(tempX, tempY+1)){
			if(*(MapGrid[tempY+1][tempX].getType())=='E') {
				return true;
			}
			EmptyBlockAt(tempX, tempY);
			CharacterBlockAt(tempX, tempY+1, &c1);
			c1.setPositionY(tempY+1);
		}
	}else if(direction=='a'){
		if(IsOpenAt(tempX-1, tempY)){
			if(*(MapGrid[tempY][tempX-1].getType())=='E') {
				return true;
			}
			EmptyBlockAt(tempX, tempY);
			CharacterBlockAt(tempX-1, tempY, &c1);
			c1.setPositionX(tempX-1);
		}
	}else if(direction=='d'){
		if(IsOpenAt(tempX+1, tempY)){
			if(*(MapGrid[tempY][tempX+1].getType())=='E') {
				return true;
			}
			EmptyBlockAt(tempX, tempY);
			CharacterBlockAt(tempX+1, tempY,&c1);
			c1.setPositionX(tempX+1);
		}
	}
	return false;
	
}

void Map::AddCharacter(/*int characterNumber,*/Character* theChar){
	//Character c1 = CharacterList[characterNumber];
	c1=*theChar;
}
void Map::addMonster(/*int characterNumber,*/Character* theChar){
	//Character c1 = CharacterList[characterNumber];
	Monster=*theChar;
}

