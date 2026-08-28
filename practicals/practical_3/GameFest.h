// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// GameFest.h

#ifndef GAMEFEST_H
#define GAMEFEST_H

#include "EventGroup.h"

#include <iostream>

using namespace std;

class EventGroup;

/**
 * @brief Game Fest contains the main hall, the tournament wing and the vendor hall
 */
class GameFest : public EventGroup
{
	public:
		/**
		 * @brief Constructor creates a GameFest object by forwarding to EventGroup
		 */
		GameFest();
};

#endif // GAMEFEST_H