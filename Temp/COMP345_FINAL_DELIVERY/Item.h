#ifndef ITEM_H
#define ITEM_H
#include<string>
using namespace::std;
namespace d20Logic{
class Item{
public:

	void setIntMod(int mod);

	void setWisMod(int mod);

	void setArmMod(int mod);

	void setStrMod(int mod);

	void setConMod(int mod);

	void setChaMod(int mod);

	void setDexMod(int mod);
	
	void setModifies(string m);

	int getIntMod();

	int getWisMod();

	int getArmMod();

	int getStrMod();

	int getConMod();

	int getChaMod();

	int getDexMod();

	string getModifies();

protected:
	int intMod, wisMod, armMod, strMod, conMod, chaMod, dexMod, attMod, damMod;
	string modifies;
	string type;
};
}
#endif