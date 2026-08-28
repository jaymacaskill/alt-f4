#ifndef ARCADEROW_H
#define ARCADEROW_H

class ArcadeRow : EventUnit {


public:
	ArcadeRow(string& name, int capacity);

	void open();

	void close();

	void update(Notice& notice);
};

#endif
