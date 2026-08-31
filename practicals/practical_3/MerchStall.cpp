// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

// MerchStall.cpp

#ifndef MERCHSTALL_CPP
#define MERCHSTALL_CPP

#include "MerchStall.h"
#include "Notice.h"
#include "EventUnit.h"

#include <iostream>

using namespace std;

MerchStall::MerchStall(const string& name, int capacity) : EventUnit(name, capacity)
{

} 

void MerchStall::open()
{
	cout << this->name << " open now! Grab your merch before it's sold out.\n";
	this->isOpen = true;
}

void MerchStall::close()
{
	cout << "Thank you for supporting " << this->name << " by buying merch. Stay awesome!\n";
	this->isOpen = false;
}

void MerchStall::update(Notice& notice)
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
				cout << "We have just received a power alert. The Vendor Hall lights may dim due to backup power kicking in and we will continue with cash-only operations.\n";
				this->cashOnly = true;
				powerAlert = true;
			}
			break;

		case POWER_STABILISED:
			if (powerAlert)
			{
				cout << "It is great to see all your happy faces in full-bright! Thank you for supporting us, we are now fully operational.\n";
				this->cashOnly = false;
				powerAlert = false;
			}
			break;

		case EVACUATE:
			if (this->isOpen)
			{
				cout << "Attention all customers. Please calmly proceed to the nearest emergency exit.\n Staff, please ensure to lock cashboxes before exiting.\n";
				this->isOpen = false;
			}
			break;

		case SECURITY_ANNOUNCEMENT:
			break;

		case LOST_PERSON:
			if (this->isOpen)
			{
				cout << "All " << this->name << " staff have their eye out for the missing person.\n";
			}
			break;

		case VENDOR_CLOSE:
			if (this->isOpen)
			{
				cout << "The Vendor Hall is now closed, ensure to wrap up your purchases with " << this->name << ".\n";
				this->close();
			}
			break;

		case NETWORK_ERROR:
			if (this->isOpen)
			{
				cout << "Due to a network error, we will be switching to cash-only sales. We apologise for any inconvenience caused.\n";
				this->cashOnly = true;
				networkAlert = true;
			}
			break;

		case NETWORK_RESTORED:
			if (networkAlert)
			{
				cout << "We are pleased to announce that the network has been restored and sales are back online. Thank you for your patience.\n";
				this->cashOnly = false;
				networkAlert = false;
			}
			break;
	}
}
#endif // MERCHSTALL_CPP