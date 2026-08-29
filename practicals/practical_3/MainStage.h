// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

// MainStage.h

#ifndef MAINSTAGE_H
#define MAINSTAGE_H

#include "Notice.h"
#include "EventUnit.h"

#include <iostream>

using namespace std;

class EventUnit;

/**
 * @brief The main stage inside the main hall
 * 
 * Closes entirely during EVACUATE and CLOSE
 * Opens during OPEN
 */
class MainStage : public EventUnit
{
	public:
		/**
		 * @brief Constructs a main stage object with fixed customer capacity
		 * (Forwards to EventUnit for construction)
		 * @param name Display name for the stage
		 * @param capacity Maximum number of customers served at once
		 */
		MainStage(const string& name, int capacity);

		/// @copydoc EventComponent::open
		void open() override;

		/// @copydoc EventComponent::close
		void close() override;

		/**
		 * @brief Closes entirely during EVACUATE and CLOSE
		 * Opens during OPEN
		 * Relays SECURITY_ANNOUNCEMENT, LOST_PERSON, VENDOR_CLOSE
		 * @param notice The notice received
		 */
		void update(Notice& notice) override;
};

#endif // MAINSTAGE_H
