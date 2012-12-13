/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/
#include "stdafx.h"
#include "Character.h"
#include "Dice.h"
#include "CharacterObserver.h"
#include <iostream>
#include <string>
#include "Logger.h"
#include <vector>
using namespace::std;
using namespace d20Logic;
vector<CharacterObserver*> characterObservers;
Character::Character(){
	race = 1;
	strength = 0, dexterity = 0, constitution = 0, intelligence = 0, wisdom = 0, charisma = 0;
	strRaceMod = 0, dexRaceMod = 0, conRaceMod = 0, intRaceMod = 0, wisRaceMod = 0, chaRaceMod = 0;
	strMod = 0, dexMod = 0, conMod = 0, intMod = 0, wisMod = 0, chaMod = 0;
	armorClass = 0, armorBonus = 0, shieldBonus = 0;
	baseAttackBonus = 0, meleeAttackBonus = 0, rangedAttackBonus = 0, damageBonus = 0;
	sizeMod = 0;
	hitPoints = 0;
	type = "";
	level = 1;
	Type="C";

	theSprite = "Img\\characterBlock.jpg";
}
//Fighter constructor
Character::Character (int raceChoice, int levelChoice) 

{

	race = raceChoice;
	strength = 0, dexterity = 0, constitution = 0, intelligence = 0, wisdom = 0, charisma = 0;
	strRaceMod = 0, dexRaceMod = 0, conRaceMod = 0, intRaceMod = 0, wisRaceMod = 0, chaRaceMod = 0;
	strMod = 0, dexMod = 0, conMod = 0, intMod = 0, wisMod = 0, chaMod = 0;
	armorClass = 0, armorBonus = 0, shieldBonus = 0;
	baseAttackBonus = 0, meleeAttackBonus = 0, rangedAttackBonus = 0, damageBonus = 0;
	sizeMod = 0;
	hitPoints = 0;
	type = "";
	level = 1;
	Type="C";

	for(i=0; i<6; ++i){
		results[i]= dice.roll_4d6();
	}

	for(i=0; i<6; i++){
		for(j=0; j<6; ++j) 
		{
			if (results[j] > max) {
				max = results[j];
				indexFound = j;
			}
		}

		results[indexFound] = 0;
		sortedResults[i] = max;
		max = 0;
	}

	//Set race modifiers
	switch (race) {

		//Human
		case 1 : 
			//Nothing
		break;

		//Dwarf
		case 2 :
			conRaceMod = 2;
			chaRaceMod = -2;
		break;

		//Elf
		case 3 :
			dexRaceMod = 2;
			conRaceMod = -2;
		break;

		//Gnome
		case 4 :
			conRaceMod = 2;
			strRaceMod = -2;
			
			sizeMod = 1;
		break;

		//Half-Elf
		case 5 : 
			//Nothing
		break;
		
		//Half-Orc
		case 6 :
			strRaceMod = 2;
			intRaceMod = -2;
			chaRaceMod = -2;
		break;

		//Halfling
		case 7 :
			dexRaceMod = 2;
			strRaceMod = -2;
			
			sizeMod = 1;
		break;

		//Invalid class
		default : 
			//Nothing
		break;
	}
		
	strength = strRaceMod;
	dexterity = dexRaceMod;
	constitution = conRaceMod;
	intelligence = intRaceMod;
	wisdom = wisRaceMod;
	charisma = chaRaceMod;

	//Hit Points

	hitPoints = dice.roll_d10() + conMod;

	//Armor Class

	armorClass = 10 + armorBonus + shieldBonus;

	//Attack Bonus

	baseAttackBonus = 1;

	meleeAttackBonus = baseAttackBonus + strMod + sizeMod;

	rangedAttackBonus = baseAttackBonus + dexMod + sizeMod;

	//Damage Bonus

	//No such thing as Damage bonus, it is simply the strength modifier or penalty based on the type of weapon. 

	for (i=1; i<levelChoice; i++) {

		levelUp();

	}
	
	theSprite = "Img\\characterBlock.jpg";
}

//Abilities and modifiers
void Character::setStrength(int s) {
	
	strength = s;
	strMod = -5 + (strength/2);
	Notify();

}

void Character::setDexterity(int d) {

	dexterity = d;
	dexMod = -5 + (dexterity/2);
	Notify();

}

void Character::setConstitution(int c) {

	constitution = c;
	conMod = -5 + (constitution/2);
	Notify();

}

void Character::setIntelligence(int i) {

	intelligence = i;
	intMod = -5 + (intelligence/2);
	Notify();

}

void Character::setWisdom(int w) {

	wisdom = w;
	wisMod = -5 + (wisdom/2);
	Notify();

}

void Character::setCharisma(int c) {

	charisma = c;
	chaMod = -5 + (charisma/2);
	Notify();

}

void Character::setType(string t) {

	type = t;

}

//Attach an observer
void Character::Attach(class CharacterObserver* observer){

	characterObservers.push_back(observer);

}
  
//Detach an observer
void Character::Detach(class CharacterObserver* observer){

	for (int i = 0; i < characterObservers.size(); i++) {

		if (characterObservers[i] == observer) {

			characterObservers.erase(characterObservers.begin() + i);

		}

	}

}
 
//Notify observers
void Character::Notify(){

	for each (class CharacterObserver* characterObserver in characterObservers) {

		characterObserver->Update(this);

	}

}

//Level-up the character
void Character::levelUp() {

	level++;

	baseAttackBonus++;

	meleeAttackBonus = baseAttackBonus + strMod + sizeMod;

	rangedAttackBonus = baseAttackBonus + dexMod + sizeMod;

	hitPoints = hitPoints + dice.roll_d10() + conMod; 

	cout << "LEVELED UP TO LEVEL " << level << endl;

}

//Fix according to weapon type
void Character::attack(Character* enemy) {

	int temp = meleeAttackBonus;

	if (weapon->getType()=="longsword")
		temp = meleeAttackBonus;
	else if (weapon->getType()=="longbow")
		temp = rangedAttackBonus;
	
	int turn = 1;
	System::String^ currentName = gcnew System::String("ATTACKER");
	System::String^ enemyName = gcnew System::String("ENEMY");
	while (temp>0) {
		Logger::LogInfo(gcnew System::String(currentName + " attack turn " + turn));

		int attackRoll = dice.roll_d20();
		int attackValue = attackRoll + temp;

		Logger::LogInfo(gcnew System::String(currentName + " rolls " + attackRoll + " +" + temp + " attack bonus"));

		if (attackValue > enemy->armorClass) {

			int damageRoll = dice.roll_d8();
			int damage;

			if(temp==meleeAttackBonus) {
				damage = damageRoll + strMod + damageBonus;
				enemy->hitPoints -= damage;

				Logger::LogInfo(gcnew System::String(currentName + " HITS and deals " + damageRoll + " +" + strMod + " strength modifier +" + damageBonus + " damage bonus to " + enemyName));
				
			}
			else if(temp == rangedAttackBonus) {
				damage = damageRoll + damageBonus;
				enemy->hitPoints -= damage;
				
				Logger::LogInfo(gcnew System::String(currentName + " HITS and deals " + damageRoll + " +" + damageBonus + " damage bonus to "+ enemyName));
			}
			
		}

		else {
			Logger::LogInfo(gcnew System::String(currentName + " MISSES " + enemyName));

		}

		temp -= 5;

	}

}

//Display fighter stats
void Character::display() {

	cout << endl;
	cout << "Race: ";

	switch(race)
	{

	case 1:
		cout << "Human";
	break;

	case 2:
		cout << "Dwarf";
	break;

	case 3:
		cout << "Elf";
	break;

	case 4:
		cout << "Gnome";
	break;

	case 5:
		cout << "Half-Elf";
	break;

	case 6:
		cout << "Half-Orc";
	break;

	case 7:
		cout << "Halfling";
	break;

	default:
		//Nothing
	break;

	}

	cout << endl;

	cout << "Class: Fighter" << endl;
	cout << endl;
	
	cout << "Type: " << type << endl;
	cout << "Level: " << level << endl;
	cout << endl;

	cout << "Strength: " << strength << " ";
	if (strMod > -1)
		cout << "+";
		cout << strMod << endl;

	cout << "Dexterity: " << dexterity << " ";
	if (dexMod > -1)
		cout << "+";
		cout << dexMod << endl;

	cout << "Constitution: " << constitution << " ";
	if (conMod > -1)
		cout << "+";
		cout << conMod << endl;

	cout << "Intelligence: " << intelligence << " ";
	if (intMod > -1)
		cout << "+";
		cout << intMod << endl;

	cout << "Wisdom: " << wisdom << " ";
	if (wisMod > -1)
		cout << "+";
		cout << wisMod << endl;

	cout << "Charisma: " << charisma << " ";
	if (chaMod > -1)
		cout << "+";
		cout << chaMod << endl;

	cout << endl;

	cout << "HP: " << hitPoints << endl;

	cout << "Armor Class: " << armorClass << endl;

	cout << endl;

	cout << "Melee Attack Bonus: " << meleeAttackBonus << endl;

	cout << "Ranged Attack Bonus: " << rangedAttackBonus << endl;

}

char* Character::getName(){
	return Name;
}
   
char* Character::getType(){
	return Type;
}

bool Character::getOpen(){
	return IsOpen;
}

int Character::getPositionX(){
	return positionX;
}
int Character::getPositionY(){
	return positionY;
}

void Character:: setPositionX(int posX){
	positionX=posX;
}
void Character:: setPositionY(int posY){
	positionY=posY;
}


char* Character::getSprite(){
	return theSprite;
}
// Take an item from a chest

void Character::takeItem(Chest chest, int index) {

	inventory.push_back(chest.contents[index]);
	chest.contents.erase(chest.contents.begin()+index);

}

// Select an item from inventory

void Character::equip(int index) {

	Item temp = inventory[index];
	inventory.erase(inventory.begin()+index);

	if(temp.getType()=="helmet")
		setHelmet(temp);

	else if(temp.getType()=="padded armor"
		|| temp.getType()=="leather armor"
		|| temp.getType()=="studded leather armor"
		|| temp.getType()=="chain shirt armor"
		|| temp.getType()=="breast plate armor"
		|| temp.getType()=="banded mail armor"
		|| temp.getType()=="half plate armor"
		|| temp.getType()=="full plate armor")
		setArmor(temp);

	else if(temp.getType()=="buckler"
		|| temp.getType()=="heavy shield"
		|| temp.getType()=="tower shield")
		setShield(temp);

	else if(temp.getType()=="bracers")
		setBracers(temp);

	else if(temp.getType()=="ring")
		setRing(temp);

	else if(temp.getType()=="belt")
		setBelt(temp);

	else if(temp.getType()=="boots")
		setBoots(temp);

	else if(temp.getType()=="longsword"
		|| temp.getType()=="longbow")
		setWeapon(temp);

}

// Equip and Unequip Items

void Character::setHelmet(Item helmet) {
	
	armorClass -= this->helmet->getArmMod();
	intelligence -= this->helmet->getIntMod();
	wisdom -= this->helmet->getWisMod();

	inventory.push_back(*(this->helmet));

	this->helmet = &helmet;

	armorClass += this->helmet->getArmMod();
	intelligence += this->helmet->getIntMod();
	wisdom += this->helmet->getWisMod();

}

void Character::setArmor(Item armor) {
	
	armorClass -= this->armor->getArmMod();
	armorBonus -= this->armor->getArmorVal();

	inventory.push_back(*(this->armor));

	this->armor = &armor;

	armorClass += this->armor->getArmMod();
	armorBonus += this->armor->getArmorVal();

}

void Character::setShield(Item shield) {

	armorClass -= this->shield->getArmMod();
	shieldBonus -= this->shield->getArmorVal();

	inventory.push_back(*(this->shield));

	this->shield = &shield;

	armorClass += this->shield->getArmMod();
	shieldBonus += this->shield->getArmorVal();

}

void Character::setBracers(Item abracers) {

	armorClass -= bracers->getArmMod();
	strength -= bracers->getStrMod();

	Item currBracer = *(bracers);

	inventory.push_back(currBracer);

	bracers =&abracers;

	armorClass += bracers->getArmMod();
	strength += bracers->getStrMod();

}

void Character::setRing(Item ring) {

	armorClass -= this->ring->getArmMod();
	strength -= this->ring->getStrMod();
	constitution -= this->ring->getConMod();
	wisdom -= this->ring->getWisMod();
	charisma -= this->ring->getChaMod();

	inventory.push_back(*(this->ring));

	this->ring = &ring;

	armorClass += this->ring->getArmMod();
	strength += this->ring->getStrMod();
	constitution += this->ring->getConMod();
	wisdom += this->ring->getWisMod();
	charisma += this->ring->getChaMod();

}

void Character::setBelt(Item belt) {

	strength -= this->belt->getStrMod();
	constitution -= this->belt->getConMod();

	inventory.push_back(*(this->belt));

	this->belt = &belt;

	strength += this->belt->getStrMod();
	constitution += this->belt->getConMod();

}

void Character::setBoots(Item boots) {

	armorClass -= this->boots->getArmMod();
	dexterity -= this->boots->getConMod();

	inventory.push_back(*(this->boots));

	this->boots = &boots;

	armorClass += this->boots->getStrMod();
	dexterity += this->boots->getConMod();

}

void Character::setWeapon(Item weapon) {

	baseAttackBonus -= this->weapon->getAttMod();
	damageBonus -= this->weapon->getDamMod();

	inventory.push_back(*(this->weapon));

	this->weapon = &weapon;

	baseAttackBonus += this->weapon->getAttMod();
	damageBonus += this->weapon->getDamMod();

}

int Character::getDexMod() {

	return dexMod;

}

int Character::getHitPoints() {

	return hitPoints;

}

vector<Item> Character::getListOfItems(){

	return inventory;
}

void Character::setDefaultItems(){
	armor = new Armor();
	belt = new Belt();
	ring = new Ring();
	boots = new Boots();
	shield = new Shield();
	weapon = new Weapon();
	helmet = new Helmet();
	bracers = new Bracers();

}