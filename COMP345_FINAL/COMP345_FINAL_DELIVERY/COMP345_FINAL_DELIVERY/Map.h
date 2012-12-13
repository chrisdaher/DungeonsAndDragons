#ifndef MapH
#define MapH
#include <vector>
#include "Observable.h"
#include "Block.h"
#include "Character.h"
#include <iostream>
#include <fstream>
#include "Chest.h"
using namespace std;
using namespace System::IO;
namespace d20Logic{
#define DEFAULT_LOCATION_MAP_DATA "data\\maps"
#define MAP_FILE_TYPE ".mph"
	class Map: public Observable{
private:
	unsigned int GridSizeX;
	unsigned int GridSizeY;
	Block ** MapGrid;
	void InitArray(unsigned int xSize, unsigned int ySize);
	Character c1;//Character* CharacterList;
	Character Monster;
	void move(int fromX,int fromY,int toX,int toY);
	void KillMonster();
	EntranceBlock theStart;
	ExitBlock theEnd;
public:
	Map();
	Map(int x, int y);
	~Map();

	bool saveMap(System::String^ mapName);
	Map* loadMap(System::String^ location);

	void NotifyObservers();
	void RegisterObserver(MapObserver* observer);
	void UnregisterLastObserver();

	Block* GetBlockAt(int x, int y);
	bool IsOpenAt(int x, int y);
	void SetBlockValue(int x, int y, Block* val);
	int GetX();
	int GetY();

	void AddCharacter(Character* theChar);
	void addMonster(Character* theChar, int x, int y);
	void displayMap();
	void EmptyBlockAt(int x, int y);
	void EntranceBlockAt(int x, int y);
	void WallBlockAt(int x, int y);
	void TreasureBlockAt(int x, int y);
	void CharacterBlockAt(int x, int y, Character* theChar);
	void ExitBlockAt(int x, int y);
	void hitChest(Chest* chestHit);
	System::Drawing::Point MoveCharacter(/*int characterNumber,*/ char direction);

	int GetXStartPosition();
	int GetYStartPosition();
	System::Drawing::Point getCharacterPosition();

	Character* getCurrentCharacter();
};
}
#endif
