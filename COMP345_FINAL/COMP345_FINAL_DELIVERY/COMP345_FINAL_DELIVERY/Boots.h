#ifndef BOOTS_H
#define BOOTS_H
#include "Item.h"
namespace d20Logic{
	class Boots: public Item{
	public:
		Boots();
		Boots(int level);
	};
}
#endif