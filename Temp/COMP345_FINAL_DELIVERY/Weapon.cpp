#include "stdafx.h"
#include "Weapon.h"
#include <cstdlib>
#include <ctime>
using namespace d20Logic;
Weapon::Weapon(){
	
	srand((unsigned)time(0));
	
	int mod = (rand()%2)+1;

	switch(mod){

	case 1:
		attMod = (rand()%5)+1;
		modifies = "attack";
		break;

	case 2:
		damMod = (rand()%5)+1;
		modifies = "damage";
		break;

	}	

	setType();

}

Weapon::Weapon(int level){

	srand((unsigned)time(0));
	
	int mod = (rand()%2)+1;

	switch(mod){

	case 1:
		attMod = (rand()%5)+1;
		modifies = "attack";
		break;

	case 2:
		damMod = (rand()%5)+1;
		modifies = "damage";
		break;

	}

	setType();

}

void Weapon::setType() {

	int intType;

	intType = (rand()%2)+1;

	switch(intType) {

	case 1:
		type = "longsword";
		break;

	case 2:

		type = "longbow";
		break;

	}


}