#include "stdafx.h"
#include "Armor.h"
#include <cstdlib>
#include <ctime>
using namespace d20Logic;
Armor::Armor(){
	
	srand((unsigned)time(0));
	
	armMod = (rand()%5)+1;
	modifies = "armor";

	setType();

}

Armor::Armor(int level){
	
	srand((unsigned)time(0));
	armMod = (rand()%level)+1;

	if (armMod > 5) {

		armMod = 5;

	}
	modifies = "armor";

	setType();

}

void Armor::setType() {

	int intType;

	intType = (rand()%8)+1;

	armorVal = intType;

	switch(intType) {

	case 1:

		type = "padded";
		break;

	case 2:

		type = "leather";
		break;

	case 3:

		type = "studded leather";
		break;

	case 4:

		type = "chain shirt";
		break;

	case 5:

		type = "breast plate";
		break;

	case 6:

		type = "banded mail";
		break;

	case 7:

		type = "half plate";
		break;

	case 8:

		type = "full plate";
		break;

	default:

		//Nothing

		break;

	}

}