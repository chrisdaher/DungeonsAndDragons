#ifndef MAPOBSERVER_H
#define MAPOBSERVER_H
#include "Block.h"
class MapObserver{
public:
	virtual void notify(Block** theBlock, int sizeX, int sizeY)=0;
};

class CmdDisplay : public MapObserver{
public:
	CmdDisplay();
	void notify(Block** theBlock, int sizeX, int sizeY);
};
#endif