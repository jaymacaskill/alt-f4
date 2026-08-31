// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 31 August 2026

// EventUnit.cpp

#ifndef EVENTUNIT_CPP
#define EVENTUNIT_CPP

#include "EventUnit.h"
#include "EventComponent.h"
#include "Notice.h"

#include <iostream>

using namespace std;

EventUnit::~EventUnit()
{

}

const string& EventUnit::getName()
{
	return name;
}

EventUnit::EventUnit(const string& name, int capacity)
{
	this->name = name;
	this->capacity = capacity;
	isFull = false;
}

void EventUnit::reportStatus()
{
	if (this->isOpen)
		cout << this->name << ": OPEN (" << this->total_capacity << "/" << this->capacity << " capacity)\n";
	else cout << this->name << ": CLOSED\n";
}

bool EventUnit::admit()
{
	isFull = total_capacity >= capacity; // Just to be safe, in case a venue for some reason has capacity 0
	if (isFull || !isOpen)
	{
			cout << "Sorry! We couldn't admit you right now.\n";
			return false;
	}

	total_capacity ++;
	isFull = total_capacity >= capacity;
	return true;
}

void EventUnit::dismiss()
{
	if (this->total_capacity <= 0)
	{
		cout << "There is no one here to dismiss.\n";
		return;
	}
	total_capacity --;
	if (this->total_capacity < this->capacity)
		this->isFull = false;
}

int EventUnit::getCapacity()
{
	return this->capacity;
}

int EventUnit::getOccupancy()
{
	return this->total_capacity;
}

#endif // EVENTUNIT_CPP