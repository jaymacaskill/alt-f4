// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 31 August 2026

// eSportsArena.h

#ifndef ESPORTSARENA_H
#define ESPORTSARENA_H

#include "Notice.h"
#include "EventUnit.h"

#include <iostream>
#include <vector>

using namespace std;

class EventUnit;

/**
 * @brief An eSports arena for tournament hosting, contained in the tournament wing.
 * 
 * Closes entirely during EVACUATE, POWER_ALERT, NETWORK_ERROR and CLOSE
 * Opens during OPEN
 */
class eSportsArena : public EventUnit
{
	public:
		/**
		 * @brief Constructs an eSports arena object with fixed customer capacity
		 * (Forwards to EventUnit for construction)
		 * @param name Display name for the arena
		 * @param capacity Maximum number of customers served at once
		 */
		eSportsArena(const string& name, int capacity);

		/// @copydoc EventComponent::open
		void open() override;

		/// @copydoc EventComponent::close
		void close() override;

		/**
		 * @brief Closes entirely during EVACUATE, POWER_ALERT, NETWORK_ERROR and CLOSE
		 * Opens during OPEN
		 * Relays SECURITY_ANNOUNCEMENT and LOST_PERSON
		 * @param notice The notice received
		 */
		void update(Notice& notice) override;

	//=====LIVE TOURNAMENT=====
	//public:
		/**
		 * @brief Adds a player to the match
		 * 
		 * @param name The name of the player to be added
		 */
		void addPlayer(const string& name);

		/**
		 * @brief Runs a match, returning the winner of the match
		 * 
		 * @return The winner of the match, or if it's a draw it returns a recursion of the function
		 */
		string runMatch();

		/**
		 * @brief Gets the overall winner
		 * 
		 * @return this->champion
		 */
		string getWinner() const;

		/**
		 * @brief Clears the arena and the champion
		 */
		void clearArena();

	private:
		vector<string> currentPlayers; //Vector of the current players
		string champion; //The champion currently
};

#endif // ESPORTSARENA_H
