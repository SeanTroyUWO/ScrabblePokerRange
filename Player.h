#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "Constants.h"

const long handSize = 2;

class Player
{
public:
    void Give(Tile input);
    Tile Take();
    std::vector<Tile>& Read();

    long score;
    std::vector<Tile> hand;
    std::string word;
};

#endif // PLAYER_H
