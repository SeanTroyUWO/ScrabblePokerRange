#include "Player.h"

#include <assert.h>

void Player::Give(Tile input)
{
    assert(hand.size() >= 0 && hand.size() <= handSize-1);
    hand.push_back(input);
}

std::vector<Tile> &Player::Read()
{
    return hand;
}

Tile Player::Take()
{
    assert(hand.size() >= 1 && hand.size() <= handSize);
    Tile output = hand.back();
    hand.pop_back();
    return output;
}
