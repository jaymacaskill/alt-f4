// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 31 August 2026

// PinballAlley.cpp

#ifndef PINBALLALLEY_CPP
#define PINBALLALLEY_CPP

#include "PinballAlley.h"
#include "EventUnit.h"
#include "Notice.h"

#include <iostream>

using namespace std;

PinballAlley::PinballAlley(const string& name, int capacity) : EventUnit(name, capacity)
{

}

void PinballAlley::open()
{
	cout << "Good news! " << this->name << " is open.\n";
	this->isOpen = true;
}

void PinballAlley::close()
{
	cout << this->name << " is now closed.\n";
	this->isOpen = false;
}

void PinballAlley::update(Notice& notice)
{
	switch (notice.type)
	{
		case OPEN:
			this->open();
			break;

		case CLOSE:
			if (this->isOpen) this->close();
			break;

		case EVACUATE:
			if (this->isOpen)
			{
				this->isOpen = false;
				cout << "Emergency evacuation. Please calmly make use of alley exits.\n";
			}
			break;

		case POWER_ALERT:
			if (this->isOpen)
			{
				cout << "Due to a power alert, the pinball alley will be closing.\n";
				this->isOpen = false;
				powerAlert = true;
			}
			break;

		case POWER_STABILISED:
			if (powerAlert)
			{
				cout << "Power has been stabilised and the pinball alley is open.\n";
				this->isOpen = true;
				powerAlert = false;
			}
			break;

		case NETWORK_ERROR:
			break;

		case NETWORK_RESTORED:
			break;

		case CAPACITY_ALERT:
			break; //no capacity behaviour

		case SECURITY_ANNOUNCEMENT:
			break;

		case LOST_PERSON:
			cout << "All staff in the pinball alley is on the lookout for the missing person.\n";
			break;

		case VENDOR_CLOSE:
			break;
	}
}

#endif //  PINBALLALLEY_CPP