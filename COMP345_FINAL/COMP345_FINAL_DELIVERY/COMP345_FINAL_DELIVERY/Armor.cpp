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

		type = "padded armor";
		break;

	case 2:

		type = "leather armor";
		break;

	case 3:

		type = "studded leather armor";
		break;

	case 4:

		type = "chain shirt armor";
		break;

	case 5:

		type = "breast plate armor";
		break;

	case 6:

		type = "banded mail armor";
		break;

	case 7:

		type = "half plate armor";
		break;

	case 8:

		type = "full plate armor";
		break;

	default:

		//Nothing

		break;

	}

}