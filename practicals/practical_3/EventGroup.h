// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

// EventGroup.cpp

#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "Subject.h"
#include "EventComponent.h"
#include "Notice.h"

#include <iostream>
#include <vector>

using namespace std;

class EventComponent;
class Subject;

/**
 * @brief A composite grouping of EventComponents (e.g. the main hall)
 * 
 * EventGroup is the Composite role in the Composite pattern and participates in Observer
 * in two distinct roles: as an Observer, it receives notices from the Subject it is registered with
 * (parent or ControlDesk); as a Subject, it re-broadcasts notices to its own children, producing the
 * cascading notification required across the event tree
 */
class EventGroup : public EventComponent, public Subject
{
	public:
		/**
		 * @brief Constructor for this event group
		 * 
		 * @param name The name of this event group
		 */
		explicit EventGroup(const string& name);

		/**
		 * @brief Polymorphic destructor, deletes its children as well, since it owns the children's lifetimes
		 */
		virtual ~EventGroup();

		/**
		 * @brief Add a new child for this group to own
		 * 
		 * @param child The child we are adding to this group
		 */
		void add(EventComponent* child);

		/**
		 * @brief Removes a child from the group, if the child is present and return
		 * the child as well, so that we don't have to worry about finding orphans and we can pass control
		 * 
		 * @param child The child we are trying to remove from the group
		 * 
		 * @return The component which was just removed, that way we can move control from one place to another
		 */
		EventComponent* remove(EventComponent* child);

		/// @copydoc EventComponent::open
		void open();

		/// @copydoc EventComponent::close
		void close();

		/**
		 * @brief Calls reportStatus() on all children objects
		 */
		void reportStatus();

		/**
		 * @brief The total capacity of this component
		 * 
		 * @return Returns the total capacity of all of the children
		 */
		int getCapacity();

		/// @copydoc EventComponent::getName
		const string& getName() override;

		/**
		 * @brief Issues a notice to all its observers (since EventGroup is an Observer and a Subject)
		 * calls notify() on itself (fulfill Subject duties)
		 * 
		 * @param notice The notice to issue
		 */
		void update(Notice& notice);

	private:
		/**
		 * @brief The name of this group
		 */
		string name;

		/**
		 * @brief All the Event Component children owned by this group (e.g. Retro Corner owns the Arcade row)
		 */
		vector<EventComponent*> children;
};

#endif
