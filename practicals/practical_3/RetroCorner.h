// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 31 August 2026

// RetroCorner.h

#ifndef RETROCORNER_H
#define RETROCORNER_H

#include "EventGroup.h"

#include <iostream>

using namespace std;

class EventGroup;

/**
 * @brief Retro corner containing the arcade row, inside of the classic games container
 */
class RetroCorner : public EventGroup
{
	public:
		/**
		 * @brief Constructs a retro corner by forwarding to EventGroup
		 */
		RetroCorner();
};

#endif // RETROCORNER_H