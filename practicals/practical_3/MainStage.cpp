// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 31 August 2026

// MainStage.cpp

#ifndef MAINSTAGE_CPP
#define MAINSTAGE_CPP

#include "MainStage.h"
#include "Notice.h"
#include "EventUnit.h"

#include <iostream>

using namespace std;

MainStage::MainStage(const string& name, int capacity) : EventUnit(name, capacity)
{
	//inline
}

void MainStage::open()
{
	cout << "The Main Stage has opened and our performers and guest speakers will take to it soon!\n";
	this->isOpen = true;
}

void MainStage::close()
{
	cout << "The Main Stage is now closing, thank you for joining us and all our performers and guest speakers today.\n";
	this->isOpen = false;
}

void MainStage::update(Notice& notice)
{
	switch (notice.type)
	{
		case OPEN:
			this->open();
			break;

		case CLOSE:
			if(this->isOpen)
				this->close();
			break;

		case POWER_ALERT:
			if (this->isOpen)
			{
				cout << "We will be switching to backup power due to a power alert, this will dim the lights, but will not interrupt our activities for today.\n";
				powerAlert = true;
			}
			break;

		case POWER_STABILISED:
			if (powerAlert)
			{
				cout << "Venue power has been stabilised, it is wonderful to see you all in full brightness again. Enjoy the rest of our agenda.\n";
				powerAlert = false;
			}
			break;

		case EVACUATE:
			if (this->isOpen)
			{
				cout << "This is an emergency evacuation. Remain calm and exit via stage left.\n";
				this->isOpen = false;
			}
			break;

		case SECURITY_ANNOUNCEMENT:
			if (this->isOpen)
			{
				cout << "Attention everyone, this is an announcement from our security team: \n";
				cout << notice.message << "\n";
			}
			break;

		case LOST_PERSON:
			if (this->isOpen)
			{
				cout << "Attention. There is a missing person alert: \n" << notice.message << "\n";
				cout << "If anyone sees the missing person fitting the description, please report to the Control Desk.\n";
			}
			break;

		case VENDOR_CLOSE:
			if (this->isOpen)
			{
				cout << "Please note that the Vendor Hall will be closing now, this will not affect any of the other festivities. Thank you to our wonderful vendors for bringing their magic to GameFest!\n";
			}
			break;

		case NETWORK_ERROR:
			break;

		case NETWORK_RESTORED:
			break;

		case CAPACITY_ALERT:
			break; //no capacity behaviour
	}
}

#endif // MAINSTAGE_CPP