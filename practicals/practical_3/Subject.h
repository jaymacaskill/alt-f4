// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 30 August 2026

// Subject.h

#ifndef SUBJECT_H
#define SUBJECT_H

#include "Notice.h"
#include "Observer.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Maintains a list of registered observers and broadcasts notices
 * Subject is the Subject role in the GoF Observer pattern. This Subject stores
 * non-owning pointers: Observers must remain alive while registered and are responsible
 * for detaching themselves before own destruction
 */
class Subject
{
	public:
		/**
		 * @brief Virtual destructor
		 */
		virtual ~Subject();

		/**
		 * @brief Registers an observer for future notifications
		 * If the observer is already registered, nothing should happen to avoid duplicate notifications
		 * 
		 * @param observer Observer to registered. we do a nullcheck to prevent nullptr
		 */
		virtual void attach(Observer* observer);

		/**
		 * @brief Removes an observer from the notification list
		 * If the observer is not registered, this call can be exited instead of making an error
		 * 
		 * @param observer Observer to remove (if nullptr, exit the function safely)
		 */
		virtual void detach(Observer* observer);

		/**
		 * @brief Broadcasts a notice to every currently registered observer
		 * 
		 * Iterates the observer list and calls update(notice) on each one. Order of notification
		 * follows registration order
		 * 
		 * @param notice The notice to broadcast
		 */
		virtual void notify(Notice& notice);

	protected:
		/**
		 * @brief Non owning pointers to currently registered observers
		 */
		vector<Observer*> observers;
};

#endif // SUBJECT_H