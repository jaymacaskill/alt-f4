#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

class EventComponent : Observer {

public:
	boolean isOpen;

	virtual void ~EventComponent() = 0;

	virtual void open() = 0;

	virtual void close() = 0;

	virtual void reportStatus() = 0;

	virtual int getCapacity() = 0;

	virtual void update(Notice& notice) = 0;
};

#endif
