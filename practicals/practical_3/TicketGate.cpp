// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

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
	cout << "Welcome to GameFest! We are so excited to have you here. Please queue in an orderly fashion.\n";
	this->isOpen = true;
}

void TicketGate::close()
{
	cout << "The Ticket Gate will be closing now. Thank you for your support.\n";
	this->isOpen = false;
}

void TicketGate::update(Notice& notice)
{
	switch(notice.type)
	{
		case OPEN:
			this->open();
			break;

		case CLOSE:
			if (this->isOpen) this->close();
			break;

		case POWER_ALERT:
			if (this->isOpen)
			{
				cout << "There has been a power notice, we will be switching to backup scanners, this will not cause any issues.\n";
				powerAlert = true;
			}
			break;

		case POWER_STABILISED:
			if (powerAlert)
			{
				cout << "The power is stabilised and operations will resume as normal.\n";
				powerAlert = false;
			}
			break;

		case EVACUATE:
			if (this->isOpen)
			{
				cout << "Please calmly evacuate via the gates due to an emergency underway.\n";
				this->isOpen = false;
			}
			break;

		case SECURITY_ANNOUNCEMENT:
			break;

		case LOST_PERSON:
			if (this->isOpen)
			{
				cout << "Security will be sweeping the entrances and exits for the missing person. Here is the alert, please keep an eye out: \n";
				cout << notice.message << "\n";
			}
			break;

		case VENDOR_CLOSE:
			break;

		case NETWORK_ERROR:
			if (this->isOpen)
			{
				cout << "Due to a network error, the scanning process may take longer than usual. Please remain patient.\n";
				networkAlert = true;
			}
			break;

		case NETWORK_RESTORED:
			if (networkAlert)
			{
				cout << "The network has been fully restored and operations continue as usual. Thank you for your patience.\n";
				networkAlert = false;
			}
			break;
	}
}

#endif // TICKETGATE_CPP