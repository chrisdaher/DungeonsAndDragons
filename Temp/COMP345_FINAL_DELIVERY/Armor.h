#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"
using namespace::std;
namespace d20Logic{
	class Armor: public Item{
	public:
		Armor();
		Armor(int level);
		void setType();
	private:
		int armorVal;
	};
}
#endif
