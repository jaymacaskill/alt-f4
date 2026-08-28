// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// EventGroup.cpp

#ifndef EVENTGROUP_CPP
#define EVENTGROUP_CPP

#include "EventGroup.h"
#include "Subject.h"
#include "EventComponent.h"
#include "Notice.h"

#include <iostream>
#include <vector>

using namespace std;

EventGroup::EventGroup(const string& name) : Subject()
{
	this->name = name;
}

void EventGroup::add(EventComponent* child)
{
	// TODO - implement EventGroup::add
	throw "Not yet implemented";
}

void EventGroup::remove(EventComponent* child)
{
	// TODO - implement EventGroup::remove
	throw "Not yet implemented";
}

void EventGroup::open()
{
	// TODO - implement EventGroup::open
	throw "Not yet implemented";
}

void EventGroup::close()
{
	// TODO - implement EventGroup::close
	throw "Not yet implemented";
}

void EventGroup::reportStatus()
{
	// TODO - implement EventGroup::reportStatus
	throw "Not yet implemented";
}

int EventGroup::getCapacity()
{
	// TODO - implement EventGroup::getCapacity
	throw "Not yet implemented";
}

void EventGroup::update(Notice& notice)
{
	// TODO - implement EventGroup::update
	throw "Not yet implemented";
}

#endif // EVENTGROUP_CPP