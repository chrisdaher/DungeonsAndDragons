#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
namespace d20Logic{
	class Weapon: public Item{
	public:
		Weapon();
		Weapon(int level);
		void setType();
	};
}
#endif