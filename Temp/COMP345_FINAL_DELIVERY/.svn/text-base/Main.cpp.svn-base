/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

/*
Please note that this driver is purely for controlled testing purposes.
It does not prevent you from inputting an invalid choice.
*/
#include "stdafx.h"
#include <iostream>
#include "Character.h"
#include "Creator.h"
#include "BullyBuilder.h"
#include "NimbleBuilder.h"
#include "TankBuilder.h"
#include <list>
using namespace::std;

int main()
{

	int race, level, type, hold;

	cout << "Character Races: " << endl;
	cout << "1. Human" << endl;
	cout << "2. Dwarf" << endl;
	cout << "3. Elf" << endl;
	cout << "4. Gnome" << endl;
	cout << "5. Half-Elf" << endl;
	cout << "6. Half-Orc" << endl;
	cout << "7. Halfling" << endl;

	cout << endl;

	cout << "Which race would you like your character to belong to?: ";
	cin >> race;

	cout << "1. Bully" << endl;
	cout << "2. Nimble" << endl;
	cout << "3. Tank" << endl;

	cout << endl;

	cout << "Which type would you like your character to belong to?: ";
	cin >> type;

	cout << "What level would you like your character to be?: ";
	cin >> level;

	Creator creator;
    CharacterBuilder* bullyBuilder = new BullyBuilder();
    CharacterBuilder* nimbleBuilder = new NimbleBuilder();
	CharacterBuilder* tankBuilder = new TankBuilder();

	//Decide which CharacterBuilder to use
	switch(type) {

		case 1:
			creator.setCharacterBuilder(bullyBuilder);
		break;

		case 2:
			creator.setCharacterBuilder(nimbleBuilder);
		break;

		case 3:
			creator.setCharacterBuilder(tankBuilder);
		break;

		default:
			//Nothing
		break;

	}

	//Create Character through Creator
    creator.createCharacter(race, level);
 
    Character* character = creator.getCharacter();
    character->display();

	cin >> hold;

	return 0;

}