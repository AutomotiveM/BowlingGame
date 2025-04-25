#pragma once
#include "Constants.h"
#include "BowlingFrames.h"

namespace BowlingGameNM::Players
{
    class Player
    {

    private:
        std::vector<std::unique_ptr<BowlingGameNM::Frame::Frame>> m_frames;
        uint16_t m_finalScore;
        uint16_t m_frameNumber;
        std::string m_Name;

        //get the each throw data from user
        inline uint16_t getEachThrowScoreUser(const uint16_t& frameIndex, const uint16_t& throwNum, const uint16_t& prevthrowValue = 0);

        //check the score is valid or not for each throw
        bool isScoreValueValid(const uint8_t& throwValue);

    public:
        Player();
        ~Player() = default;

        //set player name
        bool setPlayerName(const std::string& first_name);

        //return player name
        std::string playerName();

        //calculate the total score from each frame
        const uint16_t& calculateFrameScore();

        //return total score of the player
        const uint16_t& getFinalScore();

        void resetFinalScore();

        //get the each throw score from user
        void getThrowScore();

        //calculate the total score from frame1 to frame8

        void calculateFirstNineFrameScore(uint16_t& frameIndex);

        //calculate the total score of frame 9
        void calculateTenthScore(uint16_t& frameIndex);

        //calculate the total score of Tenth frame
        void calculateFinalScore(uint16_t& frameIndex);

        //set roll score for unit testing
        bool setAllthrowValue(const uint16_t& throwNumber, const uint16_t& frameIndex, const uint16_t& throwValue);

    };
}