// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 30 August 2026

// eSportsArena.cpp

#ifndef ESPORTSARENA_CPP
#define ESPORTSARENA_CPP

#include "eSportsArena.h"
#include "Notice.h"
#include "EventUnit.h"

#include <iostream>
#include <vector>

using namespace std;

eSportsArena::eSportsArena(const string& name, int capacity) : EventUnit(name, capacity) { }

void eSportsArena::open()
{
	this->isOpen = true;
	cout << "The eSports Arena is now open. Good luck to all contestants.\n";
}

void eSportsArena::close()
{
	this->isOpen = false;
	cout << "We are now closing the arena. Congratulations to all contestants! The competition was intense; prize-winners will be contacted soon.\n";
}

void eSportsArena::update(Notice& notice)
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
			cout << "Due to a power alert delivered by the control desk, the arena will be temporarily closing.\n";
			this->isOpen = false;
			break;

		case POWER_STABILISED:
			cout << "Thank you contestants for your patience. Power is restored and matches will resume shortly.\n";
			this->isOpen = true;
			break;

		case EVACUATE:
			cout << "Emergency evacuation. Please exit via arena doors.\n";
			this->isOpen = false;
			break;

		case SECURITY_ANNOUNCEMENT:
			cout << "Competitors, please take note of the security announcement: \n";
			cout << notice.message << "\n";
			break;

		case LOST_PERSON:
			cout << "We have a missing person. Please listen to the description and keep an eye out.\n";
			cout << notice.message << "\n";
			break;

		case VENDOR_CLOSE:
			break;

		case NETWORK_ERROR:
			cout << "Due to a network error we will be unable to proceed with the competition. We will resume as soon as possible.\n";
			this->isOpen = false;
			break;

		case NETWORK_RESTORED:
			cout << "Thank you for your patients, contestants. Network has been restored and competitions have resumed.\n";
			this->isOpen = true;
			break;
	}
}

void eSportsArena::addPlayer(const string& name)
{
	currentPlayers.push_back(name);
	admit();
	cout << name << " has entered the arena!" << endl;
}

string eSportsArena::runMatch()
{
	string p1 = currentPlayers[0];
	string p2 = currentPlayers[1];
	currentPlayers.clear();

	int score1 = rand() % 100 + 1;
	int score2 = rand() % 100 + 1;

	cout << p1 << " rolled: " << score1 << " 🎲" << endl;
	cout << p2 << " rolled: " << score2 << " 🎲" << endl;

	if (score1 > score2)
	{
		cout << "🏆 " << p1 << " wins!" << endl;
		champion = p1;
		dismiss();
		currentPlayers.erase(currentPlayers.begin());
		return p1;
	}
	else if (score2 > score1)
	{
		cout << "🏆 " << p2 << " wins!" << endl;
		champion = p2;
		dismiss();
		currentPlayers.erase(currentPlayers.begin() + 1);
		return p2;
	}
	else
	{
		cout << "Tie! Rematch..." << endl;
		currentPlayers.push_back(p1);
		currentPlayers.push_back(p2);
	}
	return runMatch();
}

string eSportsArena::getWinner() const { return champion; }

void eSportsArena::clearArena() { currentPlayers.clear(); champion = ""; }

#endif // ESPORTSARENA_CPP