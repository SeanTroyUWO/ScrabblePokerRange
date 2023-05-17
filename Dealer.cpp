#include <algorithm>
#include <assert.h>
#include <iostream>

#include "Dealer.h"

#include "Mechanics.h"

Dealer::Dealer(long playersNum, long languageNum)
{
    assert(languageNum == 0); // English Only do something with this later

    SetUpDeck(englishScores, englishSet);
    Shuffle();

    for(int i = 0; i < playersNum; i++)
    {
        players_.emplace_back();
    } // maybe do this better?

    assert(deck_.size() == englishTileNum);
}

void Dealer::Deal()
{
    for(int i = 0; i < handSize; i++ )
    {
        for(auto it = players_.begin(); it < players_.end(); it++)
        {
            it->Give(deck_.back());
            deck_.pop_back();
        }
    }

    for(int i = 0; i < tableTileSize; i++ )
    {
        tableTiles_.push_back(deck_.back());
        deck_.pop_back();
    }
}

void Dealer::ReturnTiles()
{
    for(int i = 0; i < handSize; i++ )
    {
        for(auto it = players_.begin(); it < players_.end(); it++)
        {
            deck_.push_back(it->Take());
        }
    }

    for(int i = 0; i < tableTileSize; i++ )
    {
        deck_.push_back(tableTiles_.back());
        tableTiles_.pop_back();
    }
}

void Dealer::Shuffle()
{
    std::shuffle(std::begin(deck_), std::end(deck_), rng_);
}

std::vector<long> Dealer::Scores()
{
    assert(deck_.size() != englishTileNum);
    assert(deck_.size() == englishTileNum - (players_.size()*handSize + tableTileSize));

    std::vector<long> returnScoresVec;
    std::vector<Tile> checkVec;
    for(auto it = players_.begin(); it < players_.end(); it++)
    {
        checkVec.clear();
        checkVec.insert(checkVec.end(), tableTiles_.begin(), tableTiles_.end());
        checkVec.insert(checkVec.end(), it->hand.begin(), it->hand.end());

        it->score = HighestScore(checkVec, it->word);
        returnScoresVec.push_back(it->score);
    }

    return returnScoresVec;
}

void Dealer::Print()
{
    assert(deck_.size() != englishTileNum);
    assert(deck_.size() == englishTileNum - (players_.size()*handSize + tableTileSize));

    long playerNum = 0;

    std::cout << "Current Table: " << std::endl;
    for(int i = 0; i < tableTileSize; i++)
    {
        std::cout << tileCharMap.at(tableTiles_[i]) << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Players: " << std::endl;
    for(auto it = players_.begin(); it < players_.end(); it++)
    {
        // Player Names
        std::cout << "#" << playerNum << " ";
        playerNum += 1;

        std::cout << std::endl;

        //Tiles
        for(int i = 0; i < handSize; i++)
        {
            std::cout << tileCharMap.at(it->hand[i]) << " ";
        }

        std::cout << std::endl;

        //Best word and points
        std::cout << it->word << ":" << it->score << " " << std::endl;
    }

}

void Dealer::SetUpDeck(TileScores tileScores, TileSet tileSet)
{
    for(auto it = tileSet.begin(); it != tileSet.end(); it++)
    {
        for(int i = 0; i < it->second; i++)
        {
            deck_.push_back(it->first);
        }
    }
}
