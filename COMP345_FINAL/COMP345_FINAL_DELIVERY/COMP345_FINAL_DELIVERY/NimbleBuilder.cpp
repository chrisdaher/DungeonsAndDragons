/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/
#include "stdafx.h"
#include "NimbleBuilder.h"
#include "CharacterBuilder.h"
#include "Character.h"
using namespace d20Logic;
//Distributes points according to Nimble preferences
void NimbleBuilder::buildAttributes() {

	character->setType("Nimble");
	character->setDexterity(character->sortedResults[0]);
	character->setConstitution(character->sortedResults[1]);
	character->setStrength(character->sortedResults[2]);
	character->setIntelligence(character->sortedResults[3]);
	character->setWisdom(character->sortedResults[4]);
	character->setCharisma(character->sortedResults[5]);

}