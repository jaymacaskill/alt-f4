// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// TicketGate.cpp

#ifndef TICKETGATE_CPP
#define TICKETGATE_CPP

#include "TicketGate.h"
#include "Notice.h"
#include "EventUnit.h"

#include <iostream>

using namespace std;

TicketGate::TicketGate(const string& name, int capacity) : EventUnit(name, capacity) { }

void TicketGate::open()
{
	// TODO - implement TicketGate::open
	throw "Not yet implemented";
}

void TicketGate::close()
{
	// TODO - implement TicketGate::close
	throw "Not yet implemented";
}

void TicketGate::update(Notice& notice)
{
	// TODO - implement TicketGate::update
	throw "Not yet implemented";
}

#endif // TICKETGATE_CPP