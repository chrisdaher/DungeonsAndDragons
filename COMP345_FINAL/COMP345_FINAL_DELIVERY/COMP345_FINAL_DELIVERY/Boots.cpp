#include "stdafx.h"
#include "Boots.h"
#include <cstdlib>
#include <ctime>
using namespace d20Logic;
Boots::Boots(){

	srand((unsigned)time(0));
	
	int mod = (rand()%2)+1;

	switch(mod){

	case 1:
		armMod = (rand()%5)+1;
		modifies = "armor";
		break;

	case 2:
		strMod = (rand()%5)+1;
		modifies = "dexterity";
		break;

	}

	type = "boots";

}

Boots::Boots(int level){

	srand((unsigned)time(0));

	int mod = (rand()%2)+1;

	switch(mod) {

	case 1:
		armMod = (rand()%level)+1;
		if (armMod > 5) {

			armMod = 5;

		}
		modifies = "armor";
		break;

	case 2:
		dexMod = (rand()%level)+1;
		if (dexMod > 5) {

		dexMod = 5;

		}
		modifies = "dexterity";
		break;

	}

	type = "boots";

}