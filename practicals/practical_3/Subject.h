#ifndef SUBJECT_H
#define SUBJECT_H

class Subject {

protected:
	vector<Observer*> observers;

public:
	virtual void ~Subject() = 0;

	virtual void attach(Observer* observer) = 0;

	virtual void detach(Observer* observer) = 0;

	virtual void notify(Notice& notice) = 0;
};

#endif
