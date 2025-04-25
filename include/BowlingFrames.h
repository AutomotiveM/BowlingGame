#pragma once
#include "Constants.h"

namespace BowlingGameNM::Frame
{
	class Frame
	{
	public:
		Frame();
		virtual ~Frame() = default;

		/*
        set the first throw score for each frame
		*/
        virtual bool setFirstThrowScore(const uint16_t &throwValue);

		/*
        get score value of first throw for each frame
		*/
        virtual const uint16_t &getFirstThrowScore() const;

		/*
        set the second throw score for each frame
		*/
        virtual bool setSecondThrowScore(const uint16_t &throwValue);

		/*
        \get score value of second throw for each frame
		*/
        virtual const uint16_t &getSecondThrowScore() const;

		/*
        set each frame score
		*/
		virtual bool setFrameScore(const uint16_t &frameScore);

		/*
        get score value of each frame
		*/
		virtual const uint16_t &getFrameScore() const;

		/*
        set third throw score of 10th frame
		*/
        virtual bool setThirdThrowScore(const uint16_t &throwValue);

		/*
        return score value of third roll of 10th frame
		*/
        virtual uint16_t getThirdThrowScore() const;

		/*
        check throw score is valid or not
		*/
        bool checkScoreIsValid(const uint8_t &throwValue);

		/*
		 check is frame is strike frame
		*/
		virtual const bool& isStrike() const;

		/*
		check is frame is spare in each frame
		*/
		virtual const bool& isSpare() const;


	protected:
        uint16_t firstThrow;
        uint16_t secondThrow;
        uint16_t eachFrameScore;
        bool isStrikeFlag;
        bool isSpareFlag;
	};

    class LastTenthFrame : public Frame
	{
        //Tenth frame is having extra 3rd throw
	public:
        LastTenthFrame();
        ~LastTenthFrame() = default;

		/*
        store the third throw score of 10th frame
		*/
        bool setThirdThrowScore(const uint16_t &throwValue);

		/*
        return score value of third throw of 10th frame
		*/
        uint16_t getThirdThrowScore() const;

        uint16_t m_thirdThrow;
	};
};