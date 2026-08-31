// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

// Notice.h

#ifndef NOTICE_H
#define NOTICE_H

#include <iostream>

using namespace std;

/**
 * @brief Identifies the category of an event-wide notice
 */
enum NoticeType
{
	OPEN, /**< An area or unit should open */
	CLOSE, /**< An area or unit should close */
	POWER_ALERT, /**< A power-related safety concern */
	POWER_STABILISED, /** < An alert given to stabilise the power */
	CAPACITY_ALERT, /** < A unit or area has reached or exceeded its safe capacity threshold */
	EVACUATE, /**< The vicinity needs to be evacuated */
	SECURITY_ANNOUNCEMENT, /**< For any announcements brought forward by security e.g. parked car with windows down*/
	LOST_PERSON, /**< To make stage announcement for any missing persons */
	VENDOR_CLOSE, /**< Close the vendor hall */
	NETWORK_ERROR, /**< Network failure */
	NETWORK_RESTORED /**< An alert given once network has been restored */
};

/**
 * @brief The payload passed in from a Subject to its Observers
 * 
 * Used in the push model: all state an observer needs to react to in a notice
 * is directly in this struct, avoiding callback into the Subject for further state
 */
struct Notice
{
	NoticeType type; /**< The notice type */
	string message; /**< The accompanying message for the notice */
};

#endif // NOTICE_H