#ifndef OBSERVABLE
#define OBSERVABLE
#include "MapObserver.h"
#include <vector>
using namespace std;
class Observable{
protected:
	vector<MapObserver*> observerCollection;
public:
	virtual void NotifyObservers()=0;
	virtual void RegisterObserver(MapObserver* observer)=0;
	virtual void UnregisterLastObserver()=0;
};
#endif