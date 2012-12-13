#include "stdafx.h"
#include "Map.h"
#include "Character.h"
#include "MapObserver.h"
#include "CharacterObserver.h"
#include "Builder.h"
using namespace d20Logic;
Character * theMainChar = 0;
Map * theMap = 0;


Character* createCharacterMenu(){
		int raceChoice, hold;

	cout << "Character Classes: " << endl;
	cout << "1. Human" << endl;
	cout << "2. Dwarf" << endl;
	cout << "3. Elf" << endl;
	cout << "4. Gnome" << endl;
	cout << "5. Half-Elf" << endl;
	cout << "6. Half-Orc" << endl;
	cout << "7. Halfling" << endl;

	cout << endl;
	int charLevel;
	cout << "Which race would you like your character to belong to?: ";
	cin >> raceChoice;
	cout << "Which level would you like your character to be?: ";
	cin >> charLevel;
	Character* theChar = new Character(raceChoice, charLevel);
	return theChar;
}

void changeBlockAt(int x,int y, int blockType){
		switch(blockType){
		case 0:
				theMap->EmptyBlockAt(x,y);
				break;
		case 1:
				theMap->WallBlockAt(x,y);
				break;
		case 2:
				theMap->TreasureBlockAt(x,y);
				break;
		case 3:
				Character* aChar = createCharacterMenu();
				theMap->CharacterBlockAt(x,y, aChar);

				break;
	}
}

void wallFromToHorizontal(int y, int from, int to){
	for(int i=from; i<=(to);i++)
	{
		changeBlockAt(i,y,1);
	}
}

void wallFromToVertical(int x, int from, int to) {

	for(int i=from; i<=(to);i++)
	{
		changeBlockAt(x,i,1);
	}

}

int DisplayMenu(){
	int value = 0;
	while (value!=4){
		cout << "Select an option\n1. Create map\n2. View Map\n3. Edit Map\n4. Exit" << endl;
		if (cin >> value){
			if (value < 0 || value >4){
				cout << "Invalid selection!" << endl;
			}else{
				return value;
			}
		}
		else{
			cout << "Invalid selection!" << endl;
			value = 0;
			cin.clear();
		}	
	}
	return 4;
}

void CreateMap(){
	//int x;
	//int y;
	//cout << "Please input length of map" << endl;
	//cin >> x;
	//cout << "Please input width of map" << endl;
	//cin >> y;
	theMap = new Map(20,20);
	cout << "Map successfully created!" << endl;
}
void initDefaultMap(){
	CreateMap();
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			if(i==0 || j==0 || i==19 ||j==19){
				changeBlockAt(i, j,1);
			}
		}
	}
	wallFromToVertical(5, 0,19);
	wallFromToHorizontal(12, 5, 9);
	wallFromToVertical(9, 0, 12);
	wallFromToVertical(9, 15, 19);
	wallFromToHorizontal(15, 9, 19);
	Character* c = new Character(1,1);
	c->setPositionX(7);
	c->setPositionY(18);
	theMap->AddCharacter(c);
	theMap->CharacterBlockAt(7,18, c);
	theMap->ExitBlockAt(18, 2);

}
void ViewMap(){
	int x = theMap->GetX();
	int y = theMap->GetY();
	theMap->displayMap();
}

void EditMap(){
	int x = theMap->GetX();
	int y = theMap->GetY();
	int selX;
	int selY;
	int val;


	cout << "Current map is " << x << " by " << y << endl;	
	cout << "To edit particular block, input X value" << endl;
	if (!(cin >> selX)) return;
	cout << "input Y value" << endl;
	if (!(cin >> selY)) return;
	if (selX < 0 || selX >= x || selY<0 || selY>=y){
		cout << "Invalid selection!" << endl;
		return;
	}

	bool isOpen = theMap->IsOpenAt(selX, selY);
	Block* tempBlock = theMap->GetBlockAt(selX, selY);
	cout << "At [" << selX << "," << selY << "]" <<  " \nBlock Open: " << isOpen << "\nBlock Value: " << tempBlock->getType() << endl;

	cout << "Select new value for this block\n0: OPEN\n1: WALL\n2. TREASURE\n3. CHARACTER" << endl;
	cin >> val;
	changeBlockAt(selX, selY,val);

}

void ShowSelection(){
	/*
		1: Create map
		2: View map
		3: Edit Map
	*/
	int val = DisplayMenu();
	while (val!=4){
		string sel; 
		switch (val){
			case 1:
				if (theMap != 0){
					cout << "A map is already created, do you want to replace? (y/n)" << endl;
					cin >> sel;
					if (sel[0] == 'y'){
						CreateMap();
					}							
				}
				else{
					CreateMap();
				}
				break;
			case 2:
				if (theMap == 0){
					cout << "Create a map first!" << endl;
				}
				else{
					ViewMap();
				}
				break;
			case 3:
				if (theMap == 0){
					cout << "Create a map first!" << endl;
				}
				else{
					EditMap();
				}
				break;
		}
		val = DisplayMenu();
	}
}
void PlayGame(){
	bool done=false;
	char input;
	theMap->displayMap();
	while(!done){
		cout<<"w=up s=down a=left d=down q=quit"<<endl;
		cin>>input;
		if(input=='q'){
			done=true;
		}else{
//			done=theMap->MoveCharacter(input);
		}
	}
}
int mainer(){
	//theMainChar = createCharacterMenu();
	//initDefaultMap();
	//ShowSelection();
	Builder* theBuilder= new ArenaBuilder();
	theBuilder->BuildMap();
	theMap=theBuilder->getMap();
	MapObserver* observer= new CmdDisplay();
	theMap->RegisterObserver(observer);
	PlayGame();
	return 0;
}

//int main()
//{	
//	//cout << "WELCOME TO d20 MAP GENERATOR" << endl;
//	//ShowSelection();
//	//bool done=false;
//	int finished;
//	theMap= new Map(10,10);// create a map of size 10x10
//	theMap->displayMap();
//	MapObserver* observer=new CmdDisplay();
//	theMap->RegisterObserver(observer);
//	while(finished!=1){
//		EditMap();
//		cout<<"Are you finished?\tyes=1\n";
//		cin>>finished;
//	}
//
//    return 0;
//}