#include "stdafx.h"
#include "Item.h"
using namespace d20Logic;

Item::Item(){

	intMod, wisMod, armMod, strMod, conMod, chaMod, dexMod, attMod, damMod = 0;
	int armorVal = 0;

}

void Item::setIntMod(int mod) {

	intMod = mod;

}

void Item::setWisMod(int mod) {

	wisMod = mod;

}

void Item::setArmMod(int mod) {

	armMod = mod;

}

void Item::setStrMod(int mod) {

	strMod = mod;

}

void Item::setConMod(int mod) {

	conMod = mod;

}

void Item::setChaMod(int mod) {

	chaMod = mod;

}

void Item::setDexMod(int mod) {

	dexMod = mod;

}
	
void Item::setModifies(string m) {

	modifies = m;

}

int Item::getIntMod() {

	return intMod;

}

int Item::getWisMod() {

	return wisMod;

}

int Item::getArmMod() {

	return armMod;

}

int Item::getStrMod() {

	return strMod;

}

int Item::getConMod() {

	return conMod;

}

int Item::getChaMod() {

	return chaMod;

}

int Item::getDexMod() {

	return dexMod;

}

int Item::getAttMod() {

	return attMod;

}

int Item::getDamMod() {

	return damMod;

}

string Item::getModifies() {

	return modifies;

}

string Item::getType() {

	return type;

}

int Item::getArmorVal() {

	return armorVal;

}