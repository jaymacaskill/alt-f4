// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

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
	cout << "The demonstration station, " << this->name << ", is open for business.\n";
	this->isOpen = true;
}

void DemoStation::close()
{
	cout << "The demonstration station, " << this->name << ", is now closed.\n";
	this->isOpen = false;
}

void DemoStation::update(Notice& notice)
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
			if (isOpen)
			{
				cout << "Power alert received, " << this->name << " is temporarily closed.\n";
				this->isOpen = false;
				this->powerAlert = true;
			}
			break;

		case POWER_STABILISED:
			if (this->powerAlert)
			{
				cout << "Venue power has stabilised, reopening " << this->name << ".\n";
				this->isOpen = true;
				this->powerAlert = false;
			}
			break;

		case EVACUATE:
			if (this->isOpen)
			{
				cout << "Emergency evacuation. Please calmly follow vendor staff to the nearest emergency exit.\n";
				this->isOpen = false;
			}
			break;

		case SECURITY_ANNOUNCEMENT:
			break;

		case LOST_PERSON:
			if (this->isOpen)
			cout << "Please keep an eye out for the missing individual while you enjoy your demonstrations.\n";
			break;

		case VENDOR_CLOSE:
			if (this->isOpen)
			{
				cout << "The Vendor Hall has now closed. Thank you for spending time with " << this->name << " today.\n";
				this->close();
			}
			break;

		case NETWORK_ERROR:
			if (this->isOpen)
			{
				cout << "Please note that we will be swithing all demostrations to offline mode due to the network error.\n";
				this->offlineMode = true;
				networkAlert = true;
			}
			break;

		case NETWORK_RESTORED:
			if (this->isOpen && networkAlert)
			{
				cout << "Network has been fully restored. We apologise for any inconvenience.\n";
				this->offlineMode = false;
				networkAlert = false;
			}
			break;
	}
}

#endif // DEMOSTATION_CPP