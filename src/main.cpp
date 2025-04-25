// BowlingGame.cpp : This file contains the 'main' function.This is driver code.

#include <iostream>
#include "MyPlayer.h"
#include "BowlingGame.h"
//#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    /* uncommnet this line if you want to run the gtest */
    //::testing::InitGoogleTest(&argc, argv);
    std::cout << "Bowling Game!!!\n";
    BowlingGameNM::BowlingGame bowlingAppObj;
    BowlingGameNM::Players::Player playerObj;
    std::string player1_Name{"Tata Technolgies"} ;
    if (playerObj.setPlayerName(player1_Name))// Display name of player on console
    {
        std::cout<<"\nPlayer "<<player1_Name<<" "<<" is playing bowling game"<<"\n";
    }
    bowlingAppObj.run();

    //return RUN_ALL_TESTS();

}