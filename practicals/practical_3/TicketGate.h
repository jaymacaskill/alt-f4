#ifndef TICKETGATE_H
#define TICKETGATE_H

class TicketGate : EventUnit {


public:
	TicketGate(string& name, int capacity);

	void open();

	void close();

	void update(Notice& notice);
};

#endif
