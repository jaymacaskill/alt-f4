// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 31 August 2026

// CosplayCorner.h

#ifndef COSPLAYCORNER_H
#define COSPLAYCORNER_H

#include "EventUnit.h"
#include "Notice.h"

#include <iostream>
#include <vector>

using namespace std;

class EventUnit;

/**
 * @brief The best-dressed cosplay corner inside the main hall
 *
 * Original feature (not required by Composite/Observer): attendees can
 * enter the Best Dressed competition, and judging randomly selects a
 * first, second and third place from the entrants.
 *
 * Closes entirely during EVACUATE
 * Stays open but pauses judging during POWER_ALERT
 * Opens during OPEN
 */
class CosplayCorner : public EventUnit
{
	public:
		/**
		 * @brief Constructs a cosplay corner object with fixed spectator capacity
		 * (Forwards to EventUnit for construction)
		 * @param name Display name for the cosplay corner
		 * @param capacity Maximum number of spectators watching at once
		 */
		CosplayCorner(const string& name, int capacity);

		/// @copydoc EventComponent::open
		void open() override;

		/// @copydoc EventComponent::close
		void close() override;

		/**
		 * @brief Closes entirely during EVACUATE and CLOSE
		 * Opens during OPEN
		 * Pauses judging during POWER_ALERT, resumes during POWER_STABILISED
		 * Relays SECURITY_ANNOUNCEMENT and LOST_PERSON
		 * @param notice The notice received
		 */
		void update(Notice& notice) override;

		/**
		 * @brief Enters a new contestant into the Best Dressed competition
		 * @param name The name of the contestant entering
		 */
		void enterContestant(const string& name);

		/**
		 * @brief Judges the Best Dressed competition, randomly selecting a
		 * first, second and third place from the current contestants
		 * (without replacement). Requires at least three contestants.
		 */
		void judgeContest();

		/// @brief Getter for the first place winner
		/// @return The first place winner, or an empty string if judging hasn't happened yet
		string getFirstPlace() const;

		/// @brief Getter for the second place winner
		/// @return The second place winner, or an empty string if judging hasn't happened yet
		string getSecondPlace() const;

		/// @brief Getter for the third place winner
		/// @return The third place winner, or an empty string if judging hasn't happened yet
		string getThirdPlace() const;

	private:
		vector<string> contestants; /**< Everyone currently entered into the competition */
		string first;  /**< The first place winner, once judged */
		string second; /**< The second place winner, once judged */
		string third;  /**< The third place winner, once judged */
};

#endif // COSPLAYCORNER_H