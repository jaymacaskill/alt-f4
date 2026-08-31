// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

// EventUnit.h

#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"
#include "Notice.h"

#include <iostream>

using namespace std;

class EventComponent;

/**
 * @brief Abstract base for leaf event units (stages, gates, stalls, etc.)
 * 
 * EventUnit is the Leaf role in the Composite pattern. Unlike EventGroup, it
 * has no children and does not act as a Subject (only an Observer)
 */
class EventUnit : public EventComponent
{
	public:
		/**
		 * @brief Constructs a named unit with a fixed capacity
		 * @param name Display name for this unit
		 * @param capacity Maximum capacity of this unit
		 */
		EventUnit(const string& name, int capacity);

		/**
		 * @brief Virtual destructor to maintain polymorphism
		 */
		virtual ~EventUnit();

		/// @copydoc EventComponent::reportStatus
		void reportStatus();

		/// @copydoc EventComponent::getCapacity
		int getCapacity();

		/**
		 * @brief This function admits a customer into the unit and increments total capacity
		 * @return Tells us whether or not we successfully admitted the customer
		 */
		bool admit();

		/// @copydoc EventComponent::open
		virtual void open() = 0;

		/// @copydoc EventComponent::close
		virtual void close() = 0;

		/// @copydoc EventComponent::getName;
		const string& getName() override;

		/**
		 * @brief This function removes a customer from the unit and decrements total capacity
		 */
		void dismiss();

		/// @brief To be implemented in the children classes, used for receiving notices (Observer)
		/// @param notice The notice received
		virtual void update(Notice& notice) = 0;

	protected:
		string name; /**< Display name of this unit */
		int capacity; /**< Maximum capacity of this unit */
		bool isFull = false; /**< Whether this unit is currently full */
};

#endif // EVENTUNIT_H