// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// DemoStation.cpp

#ifndef DEMOSTATION_CPP
#define DEMOSTATION_CPP

#include "DemoStation.h"
#include "EventUnit.h"
#include "Notice.h"

#include <iostream>

using namespace std;

DemoStation::DemoStation(const string& name, int capacity) : EventUnit (name, capacity) { }

void DemoStation::open()
{
	// TODO - implement DemoStation::open
	throw "Not yet implemented";
}

void DemoStation::close()
{
	// TODO - implement DemoStation::close
	throw "Not yet implemented";
}

void DemoStation::update(Notice& notice)
{
	// TODO - implement DemoStation::update
	throw "Not yet implemented";
}

#endif // DEMOSTATION_CPP