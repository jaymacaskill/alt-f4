// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// Subject.cpp

#ifndef SUBJECT_CPP
#define SUBJECT_CPP

#include "Subject.h"
#include "Notice.h"
#include "Observer.h"

#include <iostream>
#include <vector>

using namespace std;

Subject::~Subject()
{
	
}

void Subject::attach(Observer* observer)
{
	if (observer == nullptr) // null check, so program dont crash when 'notify()' tries to call 'update()' on the nullptr
	{
		return;
	}

	for(Observer* exist : observers) // we check for dupes, so observer can never register more than once
	{
		if (exist == observer)
		{
			return; // do nothing if we found a dupe
		}
	}

	// if we come here, we add the observer ptr to end of the vector
	// also decides the 'notify' order bcs observers get notified in the order they were attached
	// bcs notify() goes front to back

	observers.push_back(observer);
}

void Subject::detach(Observer* observer)
{
	if (observer == nullptr)// null check
	{
		return;
	}

	
	for (auto it = observers.begin(); it != observers.end(); ++it)
	{
		if (*it == observer) // deref 'it' to get its actual stored Observer*(ptr)
		{
			observers.erase(it); // if we found it we remove it from vec
			return;
		}
	}

	// so nothing happens when it isnt found
}

// push function, push everything an observer needs to know, which is inside 'notice'
void Subject::notify(Notice& notice)
{
    // loop over all observers and all update(notice) on all of them, in registr order
	for(Observer* observer : observers)
	{
		observer->update(notice);
	}
}

#endif // SUBJECT_CPP