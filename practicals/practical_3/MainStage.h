#ifndef MAINSTAGE_H
#define MAINSTAGE_H

class MainStage : EventUnit {


public:
	MainStage(string& name, int capacity);

	void open();

	void close();

	void update(Notice& notice);
};

#endif
