// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// ControlDesk.cpp

#ifndef CONTROLDESK_CPP
#define CONTROLDESK_CPP

#include "ControlDesk.h"
#include "Notice.h"
#include "Subject.h"

#include <iostream>

using namespace std;

void ControlDesk::issueNotice(Notice& notice)
{
	this->notify(notice); // forwards to Subject::notify(notice), which loop over observers, and call update(notice) on each one
}

#endif // CONTROLDESK_CPP