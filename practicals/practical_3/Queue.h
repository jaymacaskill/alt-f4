// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 30 August 2026

// Queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include "Notice.h"
#include "EventUnit.h"

#include <iostream>
#include <vector>

using namespace std;

class EventUnit;

/**
 * @brief The queue inside the tournament wing
 * 
 * Closes entirely during EVACUATE, CLOSE and CAPACITY_ALERT
 * Opens during OPEN
 */
class Queue : public EventUnit
{
	public:
		/**
		 * @brief Constructs a queue object with fixed customer capacity
		 * (Forwards to EventUnit for construction)
		 * @param name Display name for the queue
		 * @param capacity Maximum number of customers served at once
		 */
		Queue(const string& name, int capacity);

		/// @copydoc EventComponent::open
		void open() override;

		/// @copydoc EventComponent::close
		void close() override;

		/**
		 * @brief Closes entirely during EVACUATE and CLOSE
		 * Opens during OPEN
		 * Relays LOST_PERSON
		 * @param notice The notice received
		 */
		void update(Notice& notice) override;

// ===== LIVE TOURNAMENT ====== //
	// public:

		/**
		 * @brief Adds a player into the queue
		 * 
		 * @param name The name of the player to be added to the queue
		 */
		void addPlayer(const string& name);

		/**
		 * @brief Returns two people to be added into the match
		 * 
		 * @return The two people to be added into the match
		 */
		pair<string, string> getNextTwo();

		/**
		 * @brief Returns one person to be added into the match
		 * 
		 * @return The one person to be added into the match
		 */
		string getNext();

		/**
		 * @brief An isEmpty function for the players queue
		 * 
		 * @return True if the players queue is empty, false if the players queue is not
		 */
		bool isEmpty() const;

		/**
		 * @brief A function to get the size of the queue
		 * 
		 * @return The size of the queue
		 */
		int size() const;

		/**
		 * @brief Removes a player from the queue
		 * 
		 * @return The name of the player removed
		 */
		string removePlayer();

	private:
		vector<string> players; /**< The vector of players */

};

#endif // QUEUE_H
