// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

// DemoStation.h

#ifndef DEMOSTATION_H
#define DEMOSTATION_H

#include "EventUnit.h"
#include "Notice.h"

#include <iostream>

using namespace std;

class EventUnit;

/**
 * @brief A demo station for vendors, inside the vendor hall
 * 
 * Closes entirely during EVACUATE, POWER_ALERT and CLOSE
 * Opens during OPEN
 */
class DemoStation : public EventUnit
{
	public:
		/**
		 * @brief Constructs a demo station object with fixed customer capacity
		 * (Forwards to EventUnit for construction)
		 * @param name Display name for the demo station
		 * @param capacity Maximum number of customers served at once
		 */
		DemoStation(const string& name, int capacity);

		/// @copydoc EventComponent::open
		void open() override;

		/// @copydoc EventComponent::close
		void close() override;

		/**
		 * @brief Closes entirely during EVACUATE, POWER_ALERT, VENDOR_CLOSE and CLOSE
		 * Opens during OPEN
		 * Relays LOST_PERSON
		 * @param notice The notice received
		 */
		void update(Notice& notice) override;

	protected:
		bool offlineMode = false; //Whether demonstrations are offline or not
};

#endif // DEMOSTATION_H
