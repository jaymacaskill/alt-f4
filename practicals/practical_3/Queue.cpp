// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

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
	cout << "The queue for the tournament has now opened. Try your luck!\n";
	this->isOpen = true;
}

void Queue::close()
{
	cout << "The queue for the tournament has now closed. Thank you for your patience and ensuring smooth operation.\n";
	this->isOpen = false;
}

void Queue::update(Notice& notice)
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
			cout << "We have received a power alert. Please note that you may continue queueing while the tournament is suspended if you wish.\n";
			break;

		case POWER_STABILISED:
			cout << "The arena has now reopened and power has been restored. Thank you for your patience.\n";
			break;

		case EVACUATE:
			cout << "Attention all, please calmly exit via the arena doors due to an emergency evacuation.\n";
			this->isOpen = false;
			break;

		case SECURITY_ANNOUNCEMENT:
			break;

		case LOST_PERSON:
			cout << "Please note that arena security will be closely monitoring the queueing area for the missing person.\n";
			break;

		case VENDOR_CLOSE:
			break;

		case NETWORK_ERROR:
			cout << "The tournament has been suspended due to a network error. However, you may continue queueing if you wish.\n";
			break;

		case NETWORK_RESTORED:
			cout << "We are pleased to announce that the network has been restored, the arena has reopened and the tournament has continued. Thank you for your patience.\n";
			break;
	}
}

#endif // QUEUE_CPP