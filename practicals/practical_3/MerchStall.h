// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

// MerchStall.h

#ifndef MERCHSTALL_H
#define MERCHSTALL_H

#include "Notice.h"
#include "EventUnit.h"

#include <iostream>

using namespace std;

class EventUnit;

/**
 * @brief The merch stall inside the vendor hall
 * 
 * Closes entirely during EVACUATE and CLOSE
 * Switches to cash only during NETWORK_ERROR and POWER_ALERT
 * Opens during OPEN
 */
class MerchStall : public EventUnit
{
	public:
		/**
		 * @brief Shows whether the stall is doing cash only operations
		 */
		bool cashOnly = true;

		/**
		 * @brief Constructs a merch stall object with fixed customer capacity
		 * (Forwards to EventUnit for construction)
		 * @param name Display name for the stall
		 * @param capacity Maximum number of customers served at once
		 */
		MerchStall(const string& name, int capacity);

		/// @copydoc EventComponent::open
		void open() override;

		/// @copydoc EventComponent::close
		void close() override;

		/**
		 * @brief Closes entirely during EVACUATE, VENDOR_CLOSE and CLOSE
		 * Opens during OPEN
		 * Relays LOST_PERSON
		 * Switches to cash only during NETWORK_ERROR and POWER_ALERT
		 * @param notice The notice received
		 */
		void update(Notice& notice) override;
};

#endif // MERCHSTALL_H
