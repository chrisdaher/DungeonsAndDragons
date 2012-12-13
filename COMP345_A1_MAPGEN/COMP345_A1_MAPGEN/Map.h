#ifndef MapH
#define MapH
#include "Observable.h"
#include "Block.h"
#include "Character.h"
#include <vector>
class Map: public Observable{
private:
	unsigned int GridSizeX;
	unsigned int GridSizeY;
	Block ** MapGrid;
	void InitArray(unsigned int xSize, unsigned int ySize);
	Character c1;//Character* CharacterList;
	Character Monster;
public:
	Map();
	Map(int x, int y);
	~Map();

	void NotifyObservers();
	void RegisterObserver(MapObserver* observer);
	void UnregisterLastObserver();

	Block* GetBlockAt(int x, int y);
	bool IsOpenAt(int x, int y);
	void SetBlockValue(int x, int y, Block* val);
	int GetX();
	int GetY();

	void AddCharacter(Character* theChar);
	void addMonster(Character* theChar);
	void displayMap();
	void EmptyBlockAt(int x, int y);
	void WallBlockAt(int x, int y);
	void TreasureBlockAt(int x, int y);
	void CharacterBlockAt(int x, int y, Character* theChar);
	void ExitBlockAt(int x, int y);
	bool MoveCharacter(/*int characterNumber,*/ char direction);
};
#endif
