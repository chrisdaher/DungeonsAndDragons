#ifndef blockIncluded
#define blockIncluded
#include "Chest.h"
using System::Drawing::Bitmap;
namespace d20Logic{
	public class Block{
	public:
		char* Name;
		char* Type;
		bool IsOpen;
		char* theSprite;
		Chest* theChest;

		virtual char* getName()=0;
		virtual char* getType()=0;
		virtual bool getOpen()=0;
		virtual char* getSprite()=0;
		virtual Chest* getChest()=0;
	};

	class EmptyBlock : public Block{
	public:
		EmptyBlock();
		EmptyBlock(char* name, char* type, bool isopen);

		char* getName();
		char* getType();
		bool getOpen();
		char* getSprite();
		Chest* getChest(){ return 0;}
	};

	class WallBlock : public Block{
	public:
		WallBlock();
		WallBlock(char* name, char* type, bool isopen);

		char* getName();
		char* getType();
		bool getOpen();
		char* getSprite();
		Chest* getChest(){ return 0;}
	};

	class TreasureBlock: public Block{
	private:
		double Ammount;
	public:
		TreasureBlock();
		TreasureBlock(char* name, double ammount);
		TreasureBlock(char* name, char* type, bool isopen, double ammount);

		char* getName();
		char* getType();
		bool getOpen();
		char* getSprite();
		double getAmmount();
		Chest* getChest();

		void setName(char* name);
		void setAmmount(double ammount);
	};
	class EntranceBlock: public Block{
	private:
		int positionX;
		int positionY;
	public:
		EntranceBlock();
		int getPositionX();
		int getPositionY();
		void setPositionX(int posX);
		void setPositionY(int posY);
		char* getName();
		char* getType();
		bool getOpen();
		char* getSprite();
		Chest* getChest(){ return 0;}
	};

	class ExitBlock: public Block{
	private:
		int positionX;
		int positionY;
	public:
		ExitBlock();
		int getPositionX();
		int getPositionY();
		void setPositionX(int posX);
		void setPositionY(int posY);
		void setOpen(bool OPEN);
		char* getName();
		char* getType();
		bool getOpen();
		char* getSprite();
		Chest* getChest(){ return 0;}
	};}
#endif