#ifndef HELMET_H
#define HELMET_H
#include "Item.h"
namespace d20Logic{
class Helmet: public Item{
public:
	Helmet();
	Helmet(int level);
};
}
#endif