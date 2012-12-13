#include "stdafx.h"
#include "Belt.h"
#include <cstdlib>
#include <ctime>
using namespace d20Logic;
Belt::Belt(){
	
	srand((unsigned)time(0));
	
	int mod = (rand()%2)+1;

	switch(mod){

	case 1:
		conMod = (rand()%5)+1;
		modifies = "constitution";
		break;

	case 2:
		strMod = (rand()%5)+1;
		modifies = "strength";
		break;

	}

	type = "belt";

}

Belt::Belt(int level){
	
	srand((unsigned)time(0));

	int mod = (rand()%2)+1;

	switch(mod) {

	case 1:
		conMod = (rand()%level)+1;
		if (conMod > 5) {

			conMod = 5;

		}
		modifies = "constitution";
		break;

	case 2:
		strMod = (rand()%level)+1;
		if (strMod > 5) {

		strMod = 5;

		}
		modifies = "strength";
		break;

	}

	type = "belt";

}