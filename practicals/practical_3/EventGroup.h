#ifndef EVENTGROUP_H
#define EVENTGROUP_H

class EventGroup : EventComponent, Subject {

private:
	string name;
	vector<EventComponent*> children;

public:
	EventGroup(string& name);

	void ~EventGroup();

	void add(EventComponent* child);

	void remove(EventComponent* child);

	void open();

	void close();

	void reportStatus();

	int getCapacity();

	void update(Notice& notice);
};

#endif
