#include <gtest/gtest.h>
#include "../../include/MyPlayer.h"
#include "../../include/BowlingFrames.h"
#include "../../include/Constants.h"
#include <memory>


class FrameFunctionTest : public ::testing::Test
{
public:
    std::unique_ptr<BowlingGameNM::Frame::Frame> simpleFrame{ nullptr };
    std::unique_ptr<BowlingGameNM::Frame::LastTenthFrame> TenthFrame{ nullptr };

protected:
    virtual void SetUp() override
    {
        simpleFrame = std::make_unique<BowlingGameNM::Frame::Frame>();
        TenthFrame = std::make_unique<BowlingGameNM::Frame::LastTenthFrame>();
    }

    virtual void TearDown() override
    {
    }
};

/*
@NAME : setFirstThrowScore
@ASN : AM
*/

TEST_F(FrameFunctionTest, setFirstThrowScore)
{
    printf("*********** setFirstThrowScore \n");

    // Precondition
    uint16_t throwScore = 10;

    // Action
    simpleFrame->setFirstThrowScore(throwScore);

    // Expected
    EXPECT_EQ(throwScore, simpleFrame->getFirstThrowScore());
}

/*
@NAME : check first throw is strike
@ASN : AM
*/

TEST_F(FrameFunctionTest, CheckFirstThrowisStrike)
{
    printf("*********** CheckFirstThrowisStrike \n");

    // Precondition
    uint16_t throwScore{ 10 };

    // Action
    simpleFrame->setFirstThrowScore(throwScore);

    // Expected
    EXPECT_TRUE(simpleFrame->isStrike());
}

/*
@NAME : check first throw is not strike
@ASN : AM
*/

TEST_F(FrameFunctionTest, CheckFirstThrowisNotStrike)
{
    printf("*********** CheckFirstThrowisNotStrike \n");

    // Precondition
    uint16_t throwScore = 5;

    // Action
    simpleFrame->setFirstThrowScore(throwScore);

    // Expected
    EXPECT_FALSE(simpleFrame->isStrike());
}

/*
@NAME : Invalid First throw score value
@ASN : AM
*/
TEST_F(FrameFunctionTest, setInvalidFirstThrow)
{
    printf("*********** setInvalidFirstThrow \n");

    // Precondition
    int16_t throwScore = -1;

    // Action
    bool isValidScore = simpleFrame->setFirstThrowScore(throwScore);

    // Expected
    EXPECT_FALSE(isValidScore);
}

/*
@NAME : CheckinvalidThrowScore
@ASN : AM
*/
TEST_F(FrameFunctionTest, CheckinvalidThrowScore)
{
    printf("*********** setFirstThrowScore4 \n");

    // Precondition
    int16_t throwScore = 100;

    // Action
    bool isValidScore = simpleFrame->setFirstThrowScore(throwScore);

    // Expected
    EXPECT_FALSE(isValidScore);
}

/*
@NAME : check frame is spare
@ASN : AM
*/
TEST_F(FrameFunctionTest, checkFrameIsSpare)
{
    printf("*********** checkFrameIsSpare \n");

    // Precondition
    uint16_t throwScore{ 5 };
    simpleFrame->setFirstThrowScore(throwScore);

    // Action
    simpleFrame->setSecondThrowScore(throwScore);

    // Expected
    EXPECT_FALSE(simpleFrame->isStrike());
    EXPECT_TRUE(simpleFrame->isSpare());
}

/*
@NAME : check invalid value of score 
@ASN : AM
*/
TEST_F(FrameFunctionTest, checkInvalidSecondthrow)
{
    printf("*********** checkInvalidSecondthrow \n");

    // Precondition
    int16_t throwScore{ -1 };

    // Action
    bool isValidScore = simpleFrame->setSecondThrowScore(throwScore);

    // Expected
    EXPECT_FALSE(isValidScore);
}

/*
@NAME : Set Invalid score
@ASN : AM
*/
TEST_F(FrameFunctionTest, checkInvalidSecondThrow)
{
    printf("*********** checkInvalidSecondThrow \n");

    // Precondition
    int16_t throwScore{ 100 };

    // Action
    bool isValidScore = simpleFrame->setSecondThrowScore(throwScore);

    // Expected
    EXPECT_FALSE(isValidScore);
}

/*
@NAME : setFrameScore
@ASN : AM
*/
TEST_F(FrameFunctionTest, setFrameScore)
{
    printf("*********** setFrameScore \n");

    // Precondition
    uint16_t throwScore{ 5 };
    simpleFrame->setFirstThrowScore(throwScore);
    throwScore = 4;
    simpleFrame->setSecondThrowScore(throwScore);

    // Action
    uint16_t frameScore = simpleFrame->getFirstThrowScore();
    frameScore += simpleFrame->getSecondThrowScore();
    simpleFrame->setFrameScore(frameScore);

    // Expected
    EXPECT_EQ(frameScore, simpleFrame->getFrameScore());
}

/*
@NAME : setThirdThrowScore
@ASN : AM
*/
TEST_F(FrameFunctionTest,setThirdThrowScore)
{
    printf("*********** setThirdThrowScore \n");

    // Precondition
    uint16_t throwScore{ 5 };

    // Action
    TenthFrame->setThirdThrowScore(throwScore);

    // Expected
    EXPECT_EQ(throwScore, TenthFrame->getThirdThrowScore());
}

/*
@NAME : Check invalid third score
@ASN : AM
*/
TEST_F(FrameFunctionTest, checkInvalidThirdThrow)
{
    printf("*********** checkInvalidThirdThrow \n");

    // Precondition
    int16_t throwScore{ -1 };

    // Action
    bool isValidScore = TenthFrame->setThirdThrowScore(throwScore);

    // Expected
    EXPECT_FALSE(isValidScore);
}