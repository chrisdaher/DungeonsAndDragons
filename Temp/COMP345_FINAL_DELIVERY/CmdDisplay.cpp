#include "stdafx.h"
#include "MapObserver.h"
#include <iostream>
using namespace std;
using namespace d20Logic;
CmdDisplay::CmdDisplay(){

}

void CmdDisplay::notify(Block** theBlock, int sizeX, int sizeY){
	for (unsigned int i=0; i<sizeY; i++){
		for(unsigned int j=0; j<sizeX; j++){
			cout<< theBlock[i][j].getType();
		}
		cout<<"\n";
	}
}