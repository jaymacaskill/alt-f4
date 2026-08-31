// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 30 August 2026

// Queue.cpp

#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"
#include "Notice.h"
#include "EventUnit.h"

#include <iostream>
#include <vector>

using namespace std;

Queue::Queue(const string& name, int capacity) : EventUnit(name, capacity)
{

} 

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
			if (this->isOpen)
				this->close();
			break;

		case POWER_ALERT:
			if (this->isOpen)
			{
				cout << "We have received a power alert. Please note that you may continue queueing while the tournament is suspended if you wish.\n";
				powerAlert = true;
			}
			break;

		case POWER_STABILISED:
			if (powerAlert)
			{
				cout << "The arena has now reopened and power has been restored. Thank you for your patience.\n";
				powerAlert = false;
			}
			break;

		case EVACUATE:
			if (this->isOpen)
			{
				cout << "Attention all, please calmly exit via the arena doors due to an emergency evacuation.\n";
				this->isOpen = false;
			}
			break;

		case SECURITY_ANNOUNCEMENT:
			break;

		case LOST_PERSON:
			if (this->isOpen)
			{
				cout << "Please note that arena security will be closely monitoring the queueing area for the missing person.\n";
			}
			break;

		case VENDOR_CLOSE:
			break;

		case NETWORK_ERROR:
			if (this->isOpen)
			{
				cout << "The tournament has been suspended due to a network error. However, you may continue queueing if you wish.\n";
				networkAlert = true;
			}
			break;

		case NETWORK_RESTORED:
			if (networkAlert)
			{
				cout << "We are pleased to announce that the network has been restored, the arena has reopened and the tournament has continued. Thank you for your patience.\n";
				networkAlert = false;
			}
			break;

		case CAPACITY_ALERT:
			if (this->isOpen)
			{
				cout << "The tournament queue is full and will pause new entries until numbers drop.\n";
				this->close();
			}
			break;
	}
}

void Queue::addPlayer(const string& name)
{
	players.push_back(name);
	this->admit();
	cout << name << " joined the tournament queue! 👀" << endl;
}

pair<string, string> Queue::getNextTwo()
{
	string p1 = players.front();
	players.erase(players.begin());
	this->dismiss();

	string p2 = players.front();
	players.erase(players.begin());
	this->dismiss();

	cout << p1 << " and " << p2 << " are moving to the arena!" << endl;
	return {p1, p2};
}

string Queue::removePlayer()
{
	if(players.empty())
		return "";

	string name = players.front();
	players.erase(players.begin());
	this->dismiss();

	cout << name << " left the queue." << endl;

	return name;
}

bool Queue::isEmpty() const 
{
	return players.empty(); 
}

int Queue::size() const
{
	return players.size(); 
}


#endif // QUEUE_CPP