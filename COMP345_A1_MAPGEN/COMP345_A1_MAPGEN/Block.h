#ifndef blockIncluded
#define blockIncluded
public class Block{
public:
	char* Name;
	char* Type;
	bool IsOpen;
	
	virtual char* getName()=0;
	virtual char* getType()=0;
	virtual bool getOpen()=0;

};

class EmptyBlock : public Block{
public:
	EmptyBlock();
	EmptyBlock(char* name, char* type, bool isopen);

	char* getName();
	char* getType();
	bool getOpen();
};

class WallBlock : public Block{
public:
	WallBlock();
	WallBlock(char* name, char* type, bool isopen);

	char* getName();
	char* getType();
	bool getOpen();
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
	double getAmmount();

	void setName(char* name);
	void setAmmount(double ammount);
};

class ExitBlock: public Block{
public:
	ExitBlock();

	char* getName();
	char* getType();
	bool getOpen();
};
//class CharacterBlock: public Block{
//private:
//	int PositionX;
//	int PositionY;
//	char* Group;
//public:
//	CharacterBlock();
//	CharacterBlock(char* name, int positionX, int positionY, char* group);
//	CharacterBlock(char* name, char* type, bool isopen, int positionX, int positionY, char* group);
//
//	char* getName();
//	char* getType();
//	bool getOpen();
//	int getPositionX();
//	int getPositionY();
//	char* getGroup();
//
//	void setName(char* name);
//	void setPosition(int x, int y);
//	void setGroup(char* group);
//};
#endif