/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>
#include<list>
#include "Dice.h"
#include "CharacterObserver.h"
#include "Block.h"
#include "Chest.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Bracers.h"
#include "Ring.h"
#include "Belt.h"
#include "Boots.h"
#include "Weapon.h"
#include "Item.h"
using namespace::std;
namespace d20Logic{

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

		void attack(Character* enemy);

		int sortedResults[6];
		char* getName();

		char* getType();

		bool getOpen();
		int getPositionX();
		int getPositionY();
		void setPositionX(int posX);
		void setPositionY(int posY);

		void takeItem(Chest chest, int index);

		void setHelmet(Item helmet);
		void setArmor(Item armor);
		void setShield(Item shield);
		void setBracers(Item bracers);
		void setRing(Item ring);
		void setBelt(Item belt);
		void setBoots(Item boots);
		void setWeapon(Item weapon);

		int getHitPoints();
		int getDexMod();

		void setDefaultItems();

		void equip(int index);

		char* getSprite();
		Chest* getChest(){ return 0;}
		vector<Item> getListOfItems();

		Item* helmet;
		Item* armor;
		Item* shield;
		Item* bracers;
		Item* ring;
		Item* belt;
		Item* boots;
		Item* weapon;
	private:

		int race;
		int strength, dexterity, constitution, intelligence, wisdom, charisma;
		int strRaceMod, dexRaceMod, conRaceMod, intRaceMod, wisRaceMod, chaRaceMod;
		int strMod, dexMod, conMod, intMod, wisMod, chaMod;
		int armorClass, armorBonus, shieldBonus;
		int baseAttackBonus, meleeAttackBonus, rangedAttackBonus, rangePenalty, damageBonus;
		int sizeMod;
		int hitPoints;
		int level;
		int i, j, max, indexFound;
		int results[6];
		string type;
		Dice dice;
		int positionX, positionY;

		vector<Item> inventory;

	};
}
#endif