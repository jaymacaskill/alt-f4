#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {


public:
	virtual void ~Observer() = 0;

	virtual void update(Notice& notice) = 0;
};

#endif
