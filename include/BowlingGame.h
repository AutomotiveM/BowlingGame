#pragma once

#include "MyPlayer.h"
#include "Constants.h"

namespace BowlingGameNM
{
	class BowlingGame
	{
	public:
		BowlingGame() = default;
		~BowlingGame() = default;

		/*
	   \brief	start the bowling game
	   \author	AM
	   \param	Driver code
	   \return None
	   */
		void run();

	private:
		BowlingGameNM::Players::Player PlayerObject;
	};

}
