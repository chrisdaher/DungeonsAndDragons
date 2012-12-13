/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

#ifndef CHARACTER_H
#define CHARACTER_H
#include "Dice.h"
#include "CharacterObserver.h"
#include "Block.h"
#include <string>
#include <vector>
#include<list>
using namespace::std;

class Character: public Block {
  public:
    Character();
	Character(int raceChoice, int levelChoice);
	
	void Attach(class CharacterObserver* characterObserver);
  
	void Detach(class CharacterObserver* characterObserver);
 
	void Notify();

	void levelUp();

	void display();

	void setStrength(int s);

	void setDexterity(int d);

	void setConstitution(int c);

	void setIntelligence(int i);

	void setWisdom(int w);

	void setCharisma(int c);
	
	void setType(string t);

	void attack(Character enemy);

	int sortedResults[6];
	char* getName();
   
	char* getType();
	
	bool getOpen();
	int getPositionX();
	int getPositionY();
	void setPositionX(int posX);
	void setPositionY(int posY);

private:

	int race;
	int strength, dexterity, constitution, intelligence, wisdom, charisma;
	int strRaceMod, dexRaceMod, conRaceMod, intRaceMod, wisRaceMod, chaRaceMod;
	int strMod, dexMod, conMod, intMod, wisMod, chaMod;
	int armorClass, armorBonus, shieldBonus;
	int baseAttackBonus, meleeAttackBonus, rangedAttackBonus, rangePenalty;
	int sizeMod;
	int hitPoints;
	int level;
	int i, j, max, indexFound;
	int results[6];
	string type;
	Dice dice;
	int positionX, positionY;

};

#endif