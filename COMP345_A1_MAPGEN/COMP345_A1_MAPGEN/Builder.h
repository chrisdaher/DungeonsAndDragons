#include "Map.h"
public class Builder{
protected:
	Map* BuiltMap;
public:
	virtual void BuildMap()=0;
	virtual Map* getMap()=0;

};

public class ArenaBuilder: public Builder{
public:
	void BuildMap();
	Map* getMap();
};

//public class DefaultBuilder: public Builder{
//public:
//	void BuildMap();
//	Map* getMap();
//}