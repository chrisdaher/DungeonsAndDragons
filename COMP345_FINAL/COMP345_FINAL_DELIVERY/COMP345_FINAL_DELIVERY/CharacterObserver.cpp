/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/
#include "stdafx.h"
#include <iostream>
#include "CharacterObserver.h"
using namespace::std;
using namespace d20Logic;
CharacterObserver::CharacterObserver(){}

//Updates and displays after being informed of changes
void CharacterObserver::Update(Character* character)
{
	
	cout << "SOMETHING WAS CHANGED";
	character->display();

}