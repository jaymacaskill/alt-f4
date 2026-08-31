// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 31 August 2026

// CosplayCorner.cpp

#ifndef COSPLAYCORNER_CPP
#define COSPLAYCORNER_CPP

#include "CosplayCorner.h"
#include "EventUnit.h"
#include "Notice.h"

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

CosplayCorner::CosplayCorner(const string& name, int capacity) : EventUnit(name, capacity) { }

void CosplayCorner::open()
{
	cout << this->name << " is open! Come show off your cosplay and vote for your favourites.\n";
	this->isOpen = true;
}

void CosplayCorner::close()
{
	cout << this->name << " is now closed. Thank you to everyone who entered the Best Dressed competition.\n";
	this->isOpen = false;
}

void CosplayCorner::update(Notice& notice)
{
	switch (notice.type)
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
				cout << "Due to a power alert, judging at " << this->name << " will be paused until power is restored.\n";
				powerAlert = true;
			}
			break;

		case POWER_STABILISED:
			if (powerAlert)
			{
				cout << "Power has been stabilised, judging at " << this->name << " may resume.\n";
				powerAlert = false;
			}
			break;

		case CAPACITY_ALERT:
			break;

		case EVACUATE:
			if (this->isOpen)
			{
				cout << "Emergency evacuation. Please calmly exit the cosplay corner.\n";
				this->isOpen = false;
			}
			break;

		case SECURITY_ANNOUNCEMENT:
			if (this->isOpen)
			{
				cout << "Attention cosplayers, please note the following security announcement: \n";
				cout << notice.message << "\n";
			}
			break;

		case LOST_PERSON:
			if (this->isOpen)
			{
				cout << "All cosplay corner staff are keeping an eye out for the missing person.\n";
			}
			break;

		case VENDOR_CLOSE:
			break;

		case NETWORK_ERROR:
			break;

		case NETWORK_RESTORED:
			break;
	}
}

void CosplayCorner::enterContestant(const string& name)
{
	contestants.push_back(name);
	cout << name << " has entered the Best Dressed competition!\n";
}

void CosplayCorner::judgeContest()
{
	if (contestants.size() < 3)
	{
		cout << "Not enough contestants have entered the Best Dressed competition yet.\n";
		return;
	}

	vector<string> pool = contestants; // judge from a copy, keep the original entry list intact

	int i1 = rand() % pool.size();
	first = pool[i1];
	pool.erase(pool.begin() + i1);

	int i2 = rand() % pool.size();
	second = pool[i2];
	pool.erase(pool.begin() + i2);

	int i3 = rand() % pool.size();
	third = pool[i3];

	cout << "Best Dressed Competition Results!\n";
	cout << "1st: " << first << "\n";
	cout << "2nd: " << second << "\n";
	cout << "3rd: " << third << "\n";
}

string CosplayCorner::getFirstPlace() const { 
    
    return first; 
}

string CosplayCorner::getSecondPlace() const { 

    return second; 
}

string CosplayCorner::getThirdPlace() const { 
    
    return third; 
}

#endif // COSPLAYCORNER_CPP