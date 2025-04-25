#include "../include//BowlingFrames.h"
#include "../include/Constants.h"

/*
*/
BowlingGameNM::Frame::Frame::Frame() : firstThrow{0}, secondThrow{0}, eachFrameScore{0},
                                     isSpareFlag{false}, isStrikeFlag{false}
{
}

/*
set first throw score for each frame
*/
bool BowlingGameNM::Frame::Frame::setFirstThrowScore(const uint16_t &throwValue)
{
    if (checkScoreIsValid(throwValue))
	{
        firstThrow = throwValue;
        if (throwValue == MAX_THROW_VALUE)
		{
            isStrikeFlag = true; // if 10 pin cleared in first roll, set strike in that frame
		}
		return true;
	}
	return false;
}

/*
get first throw score for each frame
*/
const uint16_t & BowlingGameNM::Frame::Frame::getFirstThrowScore() const
{
    return firstThrow;
}

/*
set the second throw score for each frame
*/
bool BowlingGameNM::Frame::Frame::setSecondThrowScore(const uint16_t &throwValue)
{
    if (checkScoreIsValid(throwValue))
	{
        secondThrow = throwValue;
        if (firstThrow == LEAST_THROW_VALUE && secondThrow == MAX_THROW_VALUE)
		{
            isStrikeFlag = true; // for score 10 in first go , set strike in that frame
		}
        else if (auto value{firstThrow + secondThrow}; value == MAX_THROW_VALUE)
		{
            isSpareFlag = true; // for score 10 in seond go then set spare in that frame
		}
		return true;
	}
	return false;
}

/*
get the second throw score for each frame
*/
const uint16_t & BowlingGameNM::Frame::Frame::getSecondThrowScore() const
{
    return secondThrow;
}

/*
store each the frame score
*/
bool BowlingGameNM::Frame::Frame::setFrameScore(const uint16_t &frameScore)
{
    if (eachFrameScore != frameScore)
	{
        eachFrameScore = frameScore;
		return true;
	}
	return false;
}

/*
get each the frame score
*/
const uint16_t & BowlingGameNM::Frame::Frame::getFrameScore() const
{
    return eachFrameScore;
}

/*
set third throw score
*/
bool BowlingGameNM::Frame::Frame::setThirdThrowScore(const uint16_t &throwValue)
{
	return false;
}

/*
get third throw score
*/
uint16_t BowlingGameNM::Frame::Frame::getThirdThrowScore() const
{
	return 0;
}

/*
check the throw score is valid or not
*/
bool BowlingGameNM::Frame::Frame::checkScoreIsValid(const uint8_t &throwValue)
{
    if ((throwValue < LEAST_THROW_VALUE) || (throwValue > MAX_THROW_VALUE))
	{
		return false;
	}
	return true;
}

/*
*/
BowlingGameNM::Frame::LastTenthFrame::LastTenthFrame() : m_thirdThrow{0}
{

}

/*
Set third throw score
*/
bool BowlingGameNM::Frame::LastTenthFrame::setThirdThrowScore(const uint16_t &throwValue)
{
    if (checkScoreIsValid(throwValue))
	{
		m_thirdThrow = throwValue;
        if (throwValue == MAX_THROW_VALUE)
		{
            isStrikeFlag = true; // if 10 pins cleared in first throw, set strike in that frame
		}
		return true;
	}
	return false;
}

/*
getter third throw score
*/
uint16_t BowlingGameNM::Frame::LastTenthFrame::getThirdThrowScore() const
{
	return m_thirdThrow;
}

/*
check is frame is strike frame
*/
const bool& BowlingGameNM::Frame::Frame::isStrike() const
{
	return isStrikeFlag;
}

/*
check is frame is spare frame
*/
const bool& BowlingGameNM::Frame::Frame::isSpare() const
{
	return isSpareFlag;
}