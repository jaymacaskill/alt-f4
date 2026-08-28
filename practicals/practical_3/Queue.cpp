// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// Queue.cpp

#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"
#include "Notice.h"
#include "EventUnit.h"

#include <iostream>

using namespace std;

Queue::Queue(const string& name, int capacity) : EventUnit(name, capacity) { } 

void Queue::open()
{
	// TODO - implement Queue::open
	throw "Not yet implemented";
}

void Queue::close()
{
	// TODO - implement Queue::close
	throw "Not yet implemented";
}

void Queue::update(Notice& notice)
{
	// TODO - implement Queue::update
	throw "Not yet implemented";
}

#endif // QUEUE_CPP