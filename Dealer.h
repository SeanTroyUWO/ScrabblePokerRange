#ifndef DEALER_H
#define DEALER_H

#include <random>
#include <vector>

#include "Constants.h"
#include "Player.h"

const long tableTileSize = 5;

class Dealer
{
public:
    Dealer(long playersNum, long languageNum = 0);
    void Deal();
    void ReturnTiles();
    void Shuffle();
    std::vector<long> Scores();

    void Print();

    void SetUpDeck(TileScores tileScores, TileSet tileSet);

    std::vector<Player> players_;
    std::vector<Tile> tableTiles_;
    std::vector<Tile> deck_;
    std::default_random_engine rng_;
};

#endif // DEALER_H
