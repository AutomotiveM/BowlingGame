#include <gtest/gtest.h>
#include "../../include/MyPlayer.h"
#include "../../include/BowlingFrames.h"

using namespace BowlingGameNM::Players;

class PlayerFunctionTest : public ::testing::Test
{
public:
    BowlingGameNM::Players::Player *player;

protected:
    virtual void SetUp() override
    {
        player = new BowlingGameNM::Players::Player();
    }

    virtual void TearDown() override
    {
    }
};

/*
@NAME : check invalid value of score
@ASN : AM
*/
TEST_F(PlayerFunctionTest, setPlayerName)
{
    printf("*********** setPlayerName \n");
    // Precondition
    std::string name = "Germany";
    name.append(" ");

    // Action
    bool isName = player->setPlayerName(name);

    // Expected
    EXPECT_TRUE(isName);
    EXPECT_EQ(player->playerName(), name);
}

