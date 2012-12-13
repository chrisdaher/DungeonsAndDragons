#ifndef SHIELD_H
#define SHIELD_H
#include "Item.h"
namespace d20Logic{
class Shield: public Item{
public:
	Shield();
	Shield(int level);
	void setType();
};
}
#endif