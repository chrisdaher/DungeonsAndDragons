#include "stdafx.h"
#include "Chest.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Bracers.h"
#include "Ring.h"
#include "Belt.h"
#include "Boots.h"
#include "Weapon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace::std;
using namespace d20Logic;
Chest::Chest(){
	
	
	srand((unsigned)time(0));
	int chestSize = (rand()%5)+1;

	int itemType[6];

	for (int i=0; i<chestSize; i++) {

		itemType[i] = (rand()%8)+1;

	}

	for (int i=0; i<chestSize; i++) {
		
		//itemType[i] = (rand()%8)+1;

		switch (itemType[i]) {

		case 1: {

			Helmet* helmet = new Helmet();
			contents.push_back(*helmet);
				}break;

		case 2: {

			Armor* armor = new Armor();
			contents.push_back(*armor);
				}break;

		case 3: {

			Shield* shield = new Shield();
			contents.push_back(*shield);
				}break;

		case 4: {

			Bracers* bracers = new Bracers();
			contents.push_back(*bracers);
				}break;

		case 5:{

			Ring* ring = new Ring();
			contents.push_back(*ring);
			   }break;

		case 6:{

			Belt* belt = new Belt();
			contents.push_back(*belt);
			   }break;

		case 7:{

			Boots* boots = new Boots();
			contents.push_back(*boots);
			   }break;

		case 8:{

			Weapon* weapon = new Weapon();
			contents.push_back(*weapon);
			   }break;

		}

	}

}

Chest::Chest(int level){
	
	srand((unsigned)time(0));
	int chestSize = (rand()%5)+1;

	int itemType[6];

	for (int i=0; i<chestSize; i++) {

		itemType[i] = (rand()%8)+1;

	}

	for (int i=0; i<chestSize; i++) {

	//	itemType = (rand()%8)+1;

		switch (itemType[i]) {

		case 1:{

			Helmet* helmet = new Helmet(level);
			contents.push_back(*helmet);
			   }break;

		case 2:{

			Armor* armor = new Armor(level);
			contents.push_back(*armor);
			   }break;

		case 3:{

			Shield* shield = new Shield(level);
			contents.push_back(*shield);
			   }break;

		case 4:{

			Bracers* bracers = new Bracers(level);
			contents.push_back(*bracers);
			   }break;

		case 5:{

			Ring* ring = new Ring(level);
			contents.push_back(*ring);
			   }break;

		case 6:{

			Belt* belt = new Belt(level);
			contents.push_back(*belt);
			   }break;

		case 7:{

			Boots* boots = new Boots(level);
			contents.push_back(*boots);
			   }break;

		case 8:{

			Weapon* weapon = new Weapon(level);
			contents.push_back(*weapon);
			   }break;

		}

	}

}
