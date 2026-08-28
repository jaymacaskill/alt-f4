#ifndef QUEUE_H
#define QUEUE_H

class Queue : EventUnit {


public:
	Queue(string& name, int capacity);

	void open();

	void close();

	void update(Notice& notice);
};

#endif
