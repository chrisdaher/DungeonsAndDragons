#include "stdafx.h"
#include "Ring.h"
#include <cstdlib>
#include <ctime>
using namespace d20Logic;
Ring::Ring(){
	
	srand((unsigned)time(0));
	
	int mod = (rand()%2)+1;

	switch(mod){

	case 1:
		armMod = (rand()%5)+1;
		modifies = "armor";
		break;

	case 2:
		strMod = (rand()%5)+1;
		modifies = "strength";
		break;

	case 3:
		conMod = (rand()%5)+1;
		modifies = "constitution";
		break;

	case 4:
		wisMod = (rand()%5)+1;
		modifies = "wisdom";
		break;

	case 5:
		chaMod = (rand()%5)+1;
		modifies = "charisma";
		break;

	}

	type = "ring";

}
Ring::Ring(int level){
	
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
		strMod = (rand()%level)+1;
		if (strMod > 5) {

		strMod = 5;

		}
		modifies = "strength";
		break;

	case 3:
		conMod = (rand()%level)+1;
		if (conMod > 5) {

		conMod = 5;

		}
		modifies = "constitution";
		break;

	case 4:
		wisMod = (rand()%level)+1;
		if (wisMod > 5) {

		wisMod = 5;

		}
		modifies = "wisdom";
		break;

	case 5:
		chaMod = (rand()%level)+1;
		if (chaMod > 5) {

		chaMod = 5;

		}
		modifies = "charisma";
		break;

	}

	type = "ring";

}