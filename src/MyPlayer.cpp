#include "../include/MyPlayer.h"
#include "../include/Constants.h"

/*
*/
BowlingGameNM::Players::Player::Player() : m_finalScore{0}, m_Name{}, m_frameNumber{0}
{
    m_frames.reserve(MAX_NUMBER_OF_FRAME);
    for (uint16_t frameIndex = 0; frameIndex < (MAX_NUMBER_OF_FRAME - 1); frameIndex++)
    {
        m_frames.push_back(std::make_unique<BowlingGameNM::Frame::Frame>());
    }
    m_frames.push_back(std::make_unique<BowlingGameNM::Frame::LastTenthFrame>());

    m_frameNumber = m_frames.size();
}


/*
*/
bool BowlingGameNM::Players::Player::setPlayerName(const std::string &name)
{
    if ((m_Name != name))
	{
        m_Name = name;
		return true;
	}
	return false;
}

/*
*/
std::string BowlingGameNM::Players::Player::playerName()
{
    return m_Name;
}

/*
 calculte each frame scrore
*/
const uint16_t & BowlingGameNM::Players::Player::calculateFrameScore()
{
    uint16_t frameNumber{ 0 };

    calculateFirstNineFrameScore(frameNumber);
    calculateTenthScore(frameNumber);
    frameNumber++;
    calculateFinalFrameScore(frameNumber);

    return m_finalScore;
}
/*
Getter function for Final score
*/
const uint16_t & BowlingGameNM::Players::Player::getFinalScore()
{
	return m_finalScore;
}

/*
   Getting the score for each throw depending upon the frame number
*/
void BowlingGameNM::Players::Player::getThrowScore()
{
    uint16_t throw1Score{0}, throw2Score{0}, throw3Score{0};

    for (uint16_t frame = 0; frame < MAX_NUMBER_OF_FRAME; ++frame)
    {
        uint16_t throwNum = 1;

        throw1Score = getEachThrowScoreUser(frame, throwNum++);
        m_frames[frame]->setFirstThrowScore(throw1Score);

        // Handle 10th frame separately
        if (frame == MAX_NUMBER_OF_FRAME - 1)
        {
            if (m_frames[frame]->isStrike())
            {
                throw2Score = getEachThrowScoreUser(frame, throwNum++);
                m_frames[frame]->setSecondThrowScore(throw2Score);

                throw3Score = getEachThrowScoreUser(frame, throwNum);
                m_frames[frame]->setThirdThrowScore(throw3Score);
            }
            else
            {
                throw2Score = getEachThrowScoreUser(frame, throwNum++, throw1Score);
                m_frames[frame]->setSecondThrowScore(throw2Score);

                if (m_frames[frame]->isSpare())
                {
                    throw3Score = getEachThrowScoreUser(frame, throwNum);
                    m_frames[frame]->setThirdThrowScore(throw3Score);
                }
            }

            m_frames[frame]->setFrameScore(throw1Score + throw2Score + throw3Score);
        }
        else
        {
            if (throw1Score < MAX_THROW_VALUE)
            {
                throw2Score = getEachThrowScoreUser(frame, throwNum, throw1Score);
                m_frames[frame]->setSecondThrowScore(throw2Score);
            }

            m_frames[frame]->setFrameScore(throw1Score + throw2Score);
        }

        // Reset for next frame
        throw1Score = throw2Score = throw3Score = 0;
    }
}

/*
*/
bool BowlingGameNM::Players::Player::setthrowValue(const uint16_t &throwNumber, const uint16_t &frameIndex, const uint16_t &Score)
{
    bool flag{false};
    if (frameIndex < 0 || frameIndex >= MAX_NUMBER_OF_FRAME)
	{
		return false;
	}
    if(throwNumber == THROW_ONE)
         flag = m_frames[frameIndex]->setFirstThrowScore(Score);

    else if(throwNumber == THROW_SECOND)
        flag = m_frames[frameIndex]->setSecondThrowScore(Score);

    else if(throwNumber == THROW_THREE)
        flag = m_frames[frameIndex]->setThirdThrowScore(Score);

    return flag;
}


uint16_t BowlingGameNM::Players::Player::getEachThrowScoreUser(const uint16_t &frameIndex, const uint16_t &throwNum, const uint16_t &prevthrowValue)
{
    bool checkScoreValue{false};
    uint16_t throwValue{0};
    do
    {
        std::cout << "Frame:{" << (frameIndex + 1) << "}" << "throw{" << throwNum << "}:";
        std::cin >> throwValue;
        checkScoreValue = isScoreValueValid(throwValue + prevthrowValue);
        if (!checkScoreValue)
        {
            std::cout << "Please enter valid score (0-10)\n";
        }
    } while (!checkScoreValue);
    return throwValue;
}

bool BowlingGameNM::Players::Player::isScoreValueValid(const uint8_t &throwValue)
{
    if ((throwValue < LEAST_THROW_VALUE) || (throwValue > MAX_THROW_VALUE))
    {
        return false;
    }
    return true;
}

bool isValidFrameScore(uint8_t firstRoll, uint8_t secondRoll) {
    return (firstRoll <= 10 && secondRoll <= 10 && (firstRoll + secondRoll) <= 10);
}

void BowlingGameNM::Players::Player::calculateFirstNineFrameScore(uint16_t& frameIndex)
{
    for (; frameIndex < (MAX_NUMBER_OF_FRAME - 2); frameIndex++)
    {
        m_finalScore += m_frames[frameIndex]->getFirstThrowScore(); // get first rool score
        if (m_frames[frameIndex]->isStrike())
        {
            m_finalScore += m_frames[frameIndex + 1]->getFirstThrowScore(); // if strike, next roll score from next frame
            if (m_frames[frameIndex + 1]->isStrike())
            {
                m_finalScore += m_frames[frameIndex + 2]->getFirstThrowScore(); // if strike, next roll score from next frame
            }
            else
            {
                m_finalScore += m_frames[frameIndex + 1]->getSecondThrowScore();
            }
        }
        else if (m_frames[frameIndex]->isSpare())
        {
            m_finalScore += m_frames[frameIndex]->getSecondThrowScore();
            m_finalScore += m_frames[frameIndex + 1]->getFirstThrowScore();
        }
        else
        {
            m_finalScore += m_frames[frameIndex]->getSecondThrowScore(); // if no strike, get score of the current frame
        }

        std::cout << "Frame:" << "{" << (frameIndex + 1) << "}" << "=" << m_finalScore << " ";
    }
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGameNM::Players::Player::calculateTenthScore(uint16_t& frameIndex)
{
    if (frameIndex == MAX_NUMBER_OF_FRAME - 2)
    {
        m_finalScore += m_frames[frameIndex]->getFirstThrowScore();
        if (m_frames[frameIndex]->isStrike())
        {
            m_finalScore += m_frames[MAX_NUMBER_OF_FRAME - 1]->getFirstThrowScore();
            m_finalScore += m_frames[MAX_NUMBER_OF_FRAME - 1]->getSecondThrowScore();
        }
        else if (m_frames[frameIndex]->isSpare())
        {
            m_finalScore += m_frames[frameIndex]->getSecondThrowScore();
            m_finalScore += m_frames[MAX_NUMBER_OF_FRAME - 1]->getFirstThrowScore();
        }
        else
        {
            m_finalScore += m_frames[frameIndex]->getSecondThrowScore();
        }

        std::cout << "Frame:"<< "{" << (frameIndex + 1) << "}" << "=" << m_finalScore << " ";
    }
}


/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGameNM::Players::Player::calculateFinalFrameScore(uint16_t& frameIndex)
{
    if (frameIndex == MAX_NUMBER_OF_FRAME - 1)
    {
        m_finalScore += m_frames[frameIndex]->getFirstThrowScore();
        m_finalScore += m_frames[frameIndex]->getSecondThrowScore();

        if (m_frames[frameIndex]->isStrike() || m_frames[frameIndex]->isSpare())
        {
            m_finalScore += m_frames[frameIndex]->getThirdThrowScore();
        }

        std::cout << "Frame:{" << (frameIndex + 1) << "}" << "=" << m_finalScore << "\n";
    }
}