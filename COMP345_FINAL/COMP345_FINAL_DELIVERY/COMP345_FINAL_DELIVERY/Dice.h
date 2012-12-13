/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

#ifndef DICE_H
#define DICE_H
namespace d20Logic{
	class Dice
	{
		public:
			Dice();
			int roll_4d6();
			int roll_d8();
			int roll_d10();
			int roll_d20();
	};
}
#endif