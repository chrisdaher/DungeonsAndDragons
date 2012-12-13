#include "stdafx.h"
#include "Shield.h"
#include <cstdlib>
#include <ctime>
using namespace d20Logic;
Shield::Shield(){
	
	srand((unsigned)time(0));
	
	armMod = (rand()%5)+1;
	modifies = "armor";

	setType();

}
Shield::Shield(int level){

	srand((unsigned)time(0));
	armMod = (rand()%level)+1;

	if (armMod > 5) {

		armMod = 5;

	}
	modifies = "armor";

	setType();

}

void Shield::setType() {

	int intType;

	intType = (rand()%4)+1;

	if (intType == 3) {

		intType--;

	}

	armorVal = intType;

	switch(intType) {

	case 1:

		type = "buckler";
		break;

	case 2:

		type = "heavy shield";
		break;

	case 4:

		type = "tower shield";
		break;

	}

}