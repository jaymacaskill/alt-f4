// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 28 August 2026

// MerchStall.cpp

#ifndef MERCHSTALL_CPP
#define MERCHSTALL_CPP

#include "MerchStall.h"
#include "Notice.h"
#include "EventUnit.h"

#include <iostream>

using namespace std;

MerchStall::MerchStall(const string& name, int capacity) : EventUnit(name, capacity) { } 

void MerchStall::open()
{
	// TODO - implement MerchStall::open
	throw "Not yet implemented";
}

void MerchStall::close()
{
	// TODO - implement MerchStall::close
	throw "Not yet implemented";
}

void MerchStall::update(Notice& notice)
{
	// TODO - implement MerchStall::update
	throw "Not yet implemented";
}

#endif // MERCHSTALL_CPP