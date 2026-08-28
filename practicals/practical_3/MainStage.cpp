// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// MainStage.cpp

#ifndef MAINSTAGE_CPP
#define MAINSTAGE_CPP

#include "MainStage.h"
#include "Notice.h"
#include "EventUnit.h"

#include <iostream>

using namespace std;

MainStage::MainStage(const string& name, int capacity) : EventUnit(name, capacity) { }

void MainStage::open()
{
	// TODO - implement MainStage::open
	throw "Not yet implemented";
}

void MainStage::close()
{
	// TODO - implement MainStage::close
	throw "Not yet implemented";
}

void MainStage::update(Notice& notice)
{
	// TODO - implement MainStage::update
	throw "Not yet implemented";
}

#endif // MAINSTAGE_CPP