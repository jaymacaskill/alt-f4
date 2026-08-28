// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// ArcadeRow.cpp

#ifndef ARCADEROW_CPP
#define ARCADEROW_CPP

#include "ArcadeRow.h"
#include "EventUnit.h"
#include "Notice.h"

#include <iostream>

using namespace std;

ArcadeRow::ArcadeRow(const string& name, int capacity) : EventUnit(name, capacity) { }

void ArcadeRow::open()
{
	// TODO - implement ArcadeRow::open
	throw "Not yet implemented";
}

void ArcadeRow::close()
{
	// TODO - implement ArcadeRow::close
	throw "Not yet implemented";
}

void ArcadeRow::update(Notice& notice)
{
	// TODO - implement ArcadeRow::update
	throw "Not yet implemented";
}

#endif //  ARCADEROW_CPP