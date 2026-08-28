// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// TicketGate.h

#ifndef TICKETGATE_H
#define TICKETGATE_H

#include "Notice.h"
#include "EventUnit.h"

#include <iostream>

using namespace std;

class EventUnit;

/**
 * @brief The ticket gate inside the main hall
 * 
 * Closes entirely during EVACUATE, CLOSE and CAPACITY_ALERT
 * Opens during OPEN
 */
class TicketGate : public EventUnit
{
	public:
		/**
		 * @brief Constructs a ticket gate object with fixed customer capacity
		 * (Forwards to EventUnit for construction)
		 * @param name Display name for the queue
		 * @param capacity Maximum number of customers served at once
		 */
		TicketGate(const string& name, int capacity);

		/// @copydoc EventComponent::open
		void open() override;

		/// @copydoc EventComponent::close
		void close() override;

		/**
		 * @brief Closes entirely during EVACUATE, CLOSE and CAPACITY_ALERT
		 * Opens during OPEN
		 * @param notice The notice received
		 */
		void update(Notice& notice) override;
};

#endif // TICKETGATE_H