// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

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
	CAPACITY_ALERT, /**< Capacity has reached a notable threshold */
	EVACUATE, /**< The vicinity needs to be evacuated */
	NETWORK_ERROR /**< Network failure */
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
	int value; /**< Any related value, such as for a capacity alert */
};

#endif // NOTICE_H