// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// Observer.h

#ifndef OBSERVER_H
#define OBSERVER_H

#include "Notice.h"

#include <iostream>

using namespace std;

/**
 * @brief Receives notifications from a Subject it is registered with
 * 
 * Observer is the Observer role in the GoF Observer pattern. Any class that wants
 * to react to a Notice implements update()
 */
class Observer 
{
public:
		/**
		 * @brief Virtual destructor
		 */
		virtual ~Observer();

		/**
		 * @brief Called by a Subject when a notice is issued
		 * Implementation inspects notice.type (and notice.value and notice.message where appropriate)
		 * and react according to their rules.
		 * 
		 * This follows the push model. All information needed to react is contained in notice, so no callback
		 * to the Subject is required.
		 * 
		 * @param notice The event notice being broadcast
		 */
		virtual void update(Notice& notice) = 0;
};

#endif // OBSERVER_H