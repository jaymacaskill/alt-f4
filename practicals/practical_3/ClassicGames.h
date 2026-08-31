// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 31 August 2026

// ClassicGames.cpp

#ifndef CLASSICGAMES_H
#define CLASSICGAMES_H

#include "EventGroup.h"

#include <iostream>

using namespace std;

class EventGroup;

/**
 * @brief Classic games container containing the retro corner, inside of the main hall
 */
class ClassicGames : public EventGroup
{
	public:
		/**
		 * @brief Constructs a classic games object by forwarding to EventGroup
		 */
		ClassicGames();
};

#endif // CLASSICGAMES_H