#ifndef MERCHSTALL_H
#define MERCHSTALL_H

class MerchStall : EventUnit {

public:
	boolean cashOnly;

	MerchStall(string& name, int capacity);

	void open();

	void close();

	void update(Notice& notice);
};

#endif
