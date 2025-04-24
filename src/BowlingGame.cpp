#include "BowlingGame.h"

/*
Tracebility comments
@SRS: NA
*/
void BowlingGameNM::BowlingGame::run()
{
    std::cout << "\n" << PlayerObject.playerName() << " starts game...\n";
    PlayerObject.getThrowScore();
    if (PlayerObject.calculateFrameScore() == MAX_SCORE)
       {
         std::cout << "\n Got maximum score!\n";
       }
         std::cout << "\n" << PlayerObject.playerName() << " Game Finished...\n";
}