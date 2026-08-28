// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// Subject.cpp

#ifndef SUBJECT_CPP
#define SUBJECT_CPP

#include "Subject.h"
#include "Notice.h"
#include "Observer.h"

#include <iostream>
#include <vector>

using namespace std;

Subject::~Subject() { }

void Subject::attach(Observer* observer)
{
	// TODO - implement Subject::attach
	throw "Not yet implemented";
}

void Subject::detach(Observer* observer)
{
	// TODO - implement Subject::detach
	throw "Not yet implemented";
}

void Subject::notify(Notice& notice)
{
    // TODO - implement Subject::notice
	throw "Not yet implemented";
}

#endif // SUBJECT_CPP