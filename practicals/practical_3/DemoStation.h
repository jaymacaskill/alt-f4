#ifndef DEMOSTATION_H
#define DEMOSTATION_H

class DemoStation : EventUnit {


public:
	DemoStation(string& name, int capacity);

	void open();

	void close();

	void update(Notice& notice);
};

#endif
