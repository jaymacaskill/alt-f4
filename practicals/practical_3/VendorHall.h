// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// VendorHall.h

#ifndef VENDORHALL_H
#define VENDORHALL_H

#include "EventGroup.h"

#include <iostream>

using namespace std;

class EventGroup;

/**
 * @brief Vendor hall for different vendors' merch sales and demonstration stations
 */
class VendorHall : public EventGroup
{
	public:
		/**
		 * @brief Constructs a vendor hall object by forwarding to EventGroup
		 */
		VendorHall();
};

#endif // VENDORHALL_H