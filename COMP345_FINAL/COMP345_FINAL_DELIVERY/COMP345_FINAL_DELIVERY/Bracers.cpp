#include "stdafx.h"
#include "Bracers.h"
#include <cstdlib>
#include <ctime>
using namespace d20Logic;
Bracers::Bracers(){
	
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

	}

	type = "bracers";

}

Bracers::Bracers(int level){
	
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

	}

	type = "bracers";

}