#ifndef blockIncluded
#define blockIncluded
namespace d20Logic{
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
	};}
#endif