#ifndef EVENTUNIT_H
#define EVENTUNIT_H

class EventUnit : EventComponent {

protected:
	string name;
	int capacity;
	boolean isFull;

public:
	EventUnit(string& name, int capacity);

	void ~EventUnit();

	void reportStatus();

	int getCapacity();

	virtual void update(Notice& notice) = 0;
};

#endif
