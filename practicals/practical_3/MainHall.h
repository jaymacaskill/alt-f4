// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// MainHall.h

#ifndef MAINHALL_H
#define MAINHALL_H

#include "EventGroup.h"

#include <iostream>

using namespace std;

class EventGroup;

/**
 * @brief The main hall containing the main stage, the ticket gate and the retro corner of arcades
 */
class MainHall : public EventGroup
{
	public:
		/**
		 * @brief Constructor of the main hall, forwards to EventGroup
		 */
		MainHall();
};

#endif // MAINHALL_H