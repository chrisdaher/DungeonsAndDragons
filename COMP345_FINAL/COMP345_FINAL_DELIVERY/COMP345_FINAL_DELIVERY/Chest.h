#ifndef CHEST_H
#define CHEST_H
#include <vector>
#include "Item.h"
namespace d20Logic{
class Chest{
public:
	Chest();
	Chest(int level);
	vector<Item> contents;
};
}
#endif