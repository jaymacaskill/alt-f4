// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// EventUnit.cpp

#ifndef EVENTUNIT_CPP
#define EVENTUNIT_CPP

#include "EventUnit.h"
#include "EventComponent.h"
#include "Notice.h"

#include <iostream>

using namespace std;

EventUnit::EventUnit(const string& name, int capacity)
{
	this->name = name;
	this->capacity = capacity;
	isFull = false;
}

void EventUnit::reportStatus()
{
	// TODO - implement EventUnit::reportStatus
	throw "Not yet implemented";
}

bool EventUnit::admit()
{
	isFull = total_capacity >= capacity; // Just to be safe, in case a venue for some reason has capacity 0
	if (isFull || !isOpen) { cout << "Sorry! We couldn't admit you right now."; return false; }
	total_capacity ++;
	isFull = total_capacity >= capacity;
	return true;
}

void EventUnit::dismiss()
{
	if (this->capacity <= 0) { cout << "There is no one here to dismiss.";  return; }
	total_capacity --;
}

int EventUnit::getCapacity()
{
	return this->capacity;
}

#endif // EVENTUNIT_CPP