// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 31 August 2026

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

EventGroup::EventGroup(const string& name) : Subject() // is also a subject, dont call EventComp constr cuz it doesnt have one
{
	this->name = name;
}

void EventGroup::add(EventComponent* child)
{
	if (child == nullptr)
	{
		return;
	}

	// dupe check
	if (find(children.begin(), children.end(), child) != children.end())
	{
		return; // already owned by this group, we avoid double ownership/double free so it doesnt have dupe children
	}

	// Composite side
	children.push_back(child); // 'this' owns this childs lifetime now

	// Observer side
	this->attach(child); // every child added to the group is auto registered to hear the groups notices
}

const string& EventGroup::getName()
{
	return this->name;
}

// doesnt destrow the child, only detach it
EventComponent* EventGroup::remove(EventComponent* child)
{
	if (child == nullptr)
	{
		return nullptr;
	}

	auto it = find(children.begin(), children.end(), child);

	if (it == children.end())
	{
		cout << "Could not remove an unrecognised component from " << this->name << ".\n";
		return nullptr;
	}

	children.erase(it); // removes the ownership relationshp
	this->detach(child); // remove observer registration, call code from Subject class

	return child; // return ptr instead of delete,

}

// for a group it will open the whole tree 
void EventGroup::open()
{
	cout << this->name << " is now open.\n";

	this->isOpen = true;

	for (EventComponent* child : children)
	{
		child->open();
	}
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

void EventGroup::transfer(EventGroup* new_parent, EventComponent* unit)
{
	// TODO - implement EventGroup::transfer
	throw "Not yet implemented";
}

EventGroup::~EventGroup()
{
	// free whole subtree, calls delete on all pointers in 'children'
	for (EventComponent* child : children)
	{
		delete child;
	}

	children.clear();
}

#endif // EVENTGROUP_CPP