// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// TournamentWing.h

#ifndef TOURNAMENTWING_H
#define TOURNAMENTWING_H

#include "EventGroup.h"

#include <iostream>

using namespace std;

class EventGroup;

/**
 * @brief Tournament wing contains the eSports arena and the queue
 */
class TournamentWing : public EventGroup
{
	public:
		/**
		 * @brief Constructor creates a tournament wing by forwarding to EventGroup
		 */
		TournamentWing();
};

#endif
