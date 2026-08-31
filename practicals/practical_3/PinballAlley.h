// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 31 August 2026

// PinballAlley.cpp

#ifndef PINBALLALLEY_H
#define PINBALLALLEY_H

#include "EventUnit.h"
#include "Notice.h"

#include <iostream>

using namespace std;

class EventUnit;

/**
 * @brief An arcade row with all of the arcade machines, contained in the retro corner.
 * 
 * Closes entirely during EVACUATE, POWER_ALERT and CLOSE
 * Opens during OPEN
 */
class PinballAlley : public EventUnit
{
	public:

		/**
		 * @brief Constructs a pinball alley object with fixed customer capacity
		 * (Forwards to EventUnit for construction)
		 * @param name Display name for the pinball alley
		 * @param capacity Maximum number of customers served at once
		 */
		PinballAlley(const string& name, int capacity);

		/// @copydoc EventComponent::open
		void open() override;

		/// @copydoc EventComponent::close
		void close() override;

		/**
		 * @brief Closes entirely during EVACUATE, POWER_ALERT and CLOSE
		 * Opens during OPEN
		 * Informs staff of LOST_PERSON
		 * @param notice The notice received
		 */
		void update(Notice& notice) override;
};

#endif // PINBALLALLEY_H