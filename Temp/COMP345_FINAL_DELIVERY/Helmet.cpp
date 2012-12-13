#include "stdafx.h"
#include "Helmet.h"
#include <cstdlib>
#include <ctime>
using namespace d20Logic;
Helmet::Helmet(){

	srand((unsigned)time(0));
	
	int mod = (rand()%2)+1;

	switch(mod){

	case 1:
		armMod = (rand()%5)+1;
		modifies = "armor";
		break;

	case 2:
		intMod = (rand()%5)+1;
		modifies = "intelligence";
		break;

	case 3:
		wisMod = (rand()%5)+1;
		modifies = "wisdom";
		break;

	}

	type = "helmet";

}

Helmet::Helmet(int level){
	
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
		intMod = (rand()%level)+1;
		if (intMod > 5) {

		intMod = 5;

		}
		modifies = "intelligence";
		break;

	case 3:
		wisMod = (rand()%level)+1;
		if (wisMod > 5) {

		wisMod = 5;

		}
		modifies = "wisdom";
		break;

	}

	type = "helmet";

}