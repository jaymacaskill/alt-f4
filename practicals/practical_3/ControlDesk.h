// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// ControlDesk.h

#ifndef CONTROLDESK_H
#define CONTROLDESK_H

#include "Notice.h"
#include "Subject.h"

#include <iostream>

using namespace std;

class Subject;

/**
 * @brief Concrete Subject acting as the event's central control point
 * 
 * ControlDesk originates notices such as power alerts or evacuation
 * instructions and broadcasts them to whichever observers are registered with it
 */
class ControlDesk : public Subject
{
	public:
		/**
		 * @brief Issues a new notice to all registered observers
		 * @param notice The notice to broadcast
		 */
		void issueNotice(Notice& notice);
};

#endif // CONTROLDESK_H
