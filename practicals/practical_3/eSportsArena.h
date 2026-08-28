#ifndef ESPORTSARENA_H
#define ESPORTSARENA_H

class eSportsArena : EventUnit {


public:
	eSportsArena(string& name, int capacity);

	void open();

	void close();

	void update(Notice& notice);
};

#endif
