#ifndef BELT_H
#define BELT_H
#include "Item.h"
namespace d20Logic{
	class Belt: public Item{
	public:
		Belt();
		Belt(int level);
	};
}
#endif