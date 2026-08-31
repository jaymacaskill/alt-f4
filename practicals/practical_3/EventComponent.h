// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

// EventComponent.h

#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include "Notice.h"
#include "Observer.h"

#include <iostream>

using namespace std;

class Observer;

/**
 * @brief Common interface for every node in the EventFlow Composite tree
 * 
 * EventComponent is the Component role in the Composite pattern and also
 * an Observer, allowing leaves and composites to receive notifications from
 * a Subject. Concrete leaves and EventGroup provide the real implementations of these operations
 */
class EventComponent : public Observer
{
	public:
		/**
		 * @brief Virtual destructor ensuring correct polymorphic cleanup
		 */
		virtual ~EventComponent();

		/**
		 * @brief Opens this component, making it ready for operation
		 */
		virtual void open() = 0;

		/**
		 * @brief Closes this component, making it no longer operational
		 */
		virtual void close() = 0;

		/**
		 * @brief Prints the current state of this component.
		 * 
		 * For a leaf, this prints its own status, for a composite, this recursively
		 * prints the status of every owned child as well
		 */
		virtual void reportStatus() = 0;

		/**
		 * @brief Returns the capacity of the component
		 * @return For a leaf, it returns its own fixed capacity. For a composite,
		 * it returns the sum of its children's capacities
		 */
		virtual int getCapacity() = 0;

		/**
		* @brief Returns how many people currently occupy this component, as
		* opposed to getCapacity() which returns how many it can hold at most.
		* @return For a leaf, its current occupancy. For a composite, the sum
		* of its children's current occupancy.
		*/
		virtual int getOccupancy() = 0;

		/**
		 * @brief Update function to be implemented in children classes, since components are observers
		 */
		virtual void update(Notice& notice) = 0;

		/**
		 * @brief Getter for the name of the component
		 * 
		 * @return The name of this component
		 */
		virtual const string& getName() = 0;

	protected:
		/**
		 * @brief Tells us whether this component is open
		 */
		bool isOpen = false;

		bool powerAlert = false;  //Tells us whether a power alert is occurring

		bool networkAlert = false; //Tells us whether a network alert is occurring

		/**
		 * @brief The total amount of customers currently inside this component
		 */
		int total_capacity = 0;
};

#endif // EVENTCOMPONENT_H
