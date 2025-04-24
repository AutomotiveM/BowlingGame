#include <gtest/gtest.h>

#include "../../include/Constants.h"
#include "../../include/MyPlayer.h"
#include "../../include/BowlingFrames.h"

using namespace BowlingGameNM::Players;

class PlayerFunctionTest : public ::testing::Test
{
public:
    std::unique_ptr<BowlingGameNM::Players::Player> player{ nullptr };

protected:
    virtual void SetUp() override
    {
        player = std::make_unique<BowlingGameNM::Players::Player>();
    }

    virtual void TearDown() override
    {
    }
};

/*
@NAME : check all zero input. Output should be zero
@ASN : AM
*/
TEST_F(PlayerFunctionTest, checkAllZero)
{
    printf("******* checkAllZero \n");
    // Precondition
    std::vector<int> score{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int throwNumber = 1 ;
    int frameIndex = 0 ;
    int throw1Score = 0 , throw2Score= 0 , throw3Score= 0 ;
    bool success{ false };
    uint16_t scoreIndex{ 0 };
    uint16_t totalScore{ 0 };

    // Action

    for (; frameIndex < MAX_NUMBER_OF_FRAME - 1; frameIndex++)
    {
        throw1Score = score[scoreIndex];
        success = player->setthrowValue(throwNumber, frameIndex, throw1Score);
        EXPECT_TRUE(success);
        if (throw1Score < MAX_THROW_VALUE)
        {
            scoreIndex++;
            throwNumber++;
            throw2Score = score[scoreIndex];
            success = player->setthrowValue(throwNumber, frameIndex, throw2Score);
            EXPECT_TRUE(success);
        }
        scoreIndex++;
        throwNumber = 1;
    }

    if (frameIndex == (MAX_NUMBER_OF_FRAME - 1))
    {
        throw1Score = score[scoreIndex];
        success = player->setthrowValue(throwNumber, frameIndex, throw1Score);
        EXPECT_TRUE(success);
        scoreIndex++;
        throwNumber++;
        throw2Score = score[scoreIndex];
        success = player->setthrowValue(throwNumber, frameIndex, throw2Score);
        EXPECT_TRUE(success);

        if (throw1Score == MAX_THROW_VALUE || (throw2Score + throw1Score) == MAX_THROW_VALUE)
        {
            scoreIndex++;
            throwNumber++;
            throw3Score = score[scoreIndex];
            success = player->setthrowValue(throwNumber, frameIndex, throw3Score);
            EXPECT_TRUE(success);
        }
    }
    totalScore = player->calculateFrameScore();

    // Expected
    EXPECT_EQ(totalScore, 0);
}

/*
@NAME : check all 10.Output should be 300
@ASN : AM
*/

TEST_F(PlayerFunctionTest, checkAllMaxValue)
{
    printf("*********** checkAllMaxValue \n");
    // Precondition
    std::vector<int> score{ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    int throwNumber = 1 ;
    int frameIndex= 0 ;
    int throw1Score = 0 , throw2Score= 0 , throw3Score= 0 ;
    bool success{ false };
    uint16_t scoreIndex{ 0 };
    uint16_t totalScore{ 0 };


    for (; frameIndex < MAX_NUMBER_OF_FRAME - 1; frameIndex++)
    {
        throw1Score = score[scoreIndex];
        success = player->setthrowValue(throwNumber, frameIndex, throw1Score);
        EXPECT_TRUE(success);
        if (throw1Score < MAX_THROW_VALUE)
        {
            scoreIndex++;
            throwNumber++;
            throw2Score = score[scoreIndex];
            success = player->setthrowValue(throwNumber, frameIndex, throw2Score);
            EXPECT_TRUE(success);
        }
        scoreIndex++;
        throwNumber = 1;
    }

    if (frameIndex == (MAX_NUMBER_OF_FRAME - 1))
    {
        throw1Score = score[scoreIndex];
        success = player->setthrowValue(throwNumber, frameIndex, throw1Score);
        EXPECT_TRUE(success);
        scoreIndex++;
        throwNumber++;
        throw2Score = score[scoreIndex];
        success = player->setthrowValue(throwNumber, frameIndex, throw2Score);
        EXPECT_TRUE(success);

        if (throw1Score == MAX_THROW_VALUE || (throw2Score + throw1Score) == MAX_THROW_VALUE)
        {
            scoreIndex++;
            throwNumber++;
            throw3Score = score[scoreIndex];
            success = player->setthrowValue(throwNumber, frameIndex, throw3Score);
            EXPECT_TRUE(success);
        }
    }
    totalScore = player->calculateFrameScore();

    // Expected
    EXPECT_EQ(totalScore, MAX_SCORE);
}

/*
/*
@NAME : calculate total score with given input
@ASN : AM
*/
TEST_F(PlayerFunctionTest, calculateTotalScore)
{
    printf("*********** calculateTotalScore \n");
    // Precondition
    std::vector<int> score{ 1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6 };
    int throwNumber{ 1 };
    int frameIndex{ 0 };
    int throw1Score{ 0 }, throw2Score{ 0 }, throw3Score{ 0 };
    bool success{ false };
    uint16_t scoreIndex{ 0 };
    uint16_t totalScore{ 0 };

    // Action

    for (; frameIndex < MAX_NUMBER_OF_FRAME - 1; frameIndex++)
    {
        throw1Score = score[scoreIndex];
        success = player->setthrowValue(throwNumber, frameIndex, throw1Score);
        EXPECT_TRUE(success);
        if (throw1Score < MAX_THROW_VALUE)
        {
            scoreIndex++;
            throwNumber++;
            throw2Score = score[scoreIndex];
            success = player->setthrowValue(throwNumber, frameIndex, throw2Score);
            EXPECT_TRUE(success);
        }
        scoreIndex++;
        throwNumber = 1;
    }

    if (frameIndex == (MAX_NUMBER_OF_FRAME - 1))
    {
        throw1Score = score[scoreIndex];
        success = player->setthrowValue(throwNumber, frameIndex, throw1Score);
        EXPECT_TRUE(success);
        scoreIndex++;
        throwNumber++;
        throw2Score = score[scoreIndex];
        success = player->setthrowValue(throwNumber, frameIndex, throw2Score);
        EXPECT_TRUE(success);

        if (throw1Score == MAX_THROW_VALUE || (throw2Score + throw1Score) == MAX_THROW_VALUE)
        {
            scoreIndex++;
            throwNumber++;
            throw3Score = score[scoreIndex];
            success = player->setthrowValue(throwNumber, frameIndex, throw3Score);
            EXPECT_TRUE(success);
        }
    }
    totalScore = player->calculateFrameScore();

    // Expected
    EXPECT_EQ(totalScore, 133);
}