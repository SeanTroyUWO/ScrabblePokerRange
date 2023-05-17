#include <iostream>
#include <fstream>
#include <map>
#include <utility>

#include "Constants.h"
#include "Dealer.h"

int main()
{
    Dealer dealer(4);
    long maxScore = 0;
    long argMaxScore = 0;
    long playerNum = 0;

    long timesPlayed[27][27] = {0};
    long timesWon[27][27] = {0};

//    std::cout << system("pwd");
    for(int i = 0; i < 1500000; i++)
    {
        dealer.Deal();
        dealer.Scores();
//        dealer.Print();

        maxScore = 0;
        playerNum = 0;
        for(auto it = dealer.players_.begin(); it < dealer.players_.end(); it++)
        {
            timesPlayed[it->hand[0]][it->hand[1]] += 1;

            if(it->score > maxScore)
            {
                maxScore = it->score;
                argMaxScore = playerNum;
            }

            playerNum += 1;
        }
        timesWon[dealer.players_[argMaxScore].hand[0]][dealer.players_[argMaxScore].hand[1]] += 1;

        dealer.ReturnTiles();
        dealer.Shuffle();
    }

    std::ofstream winsFile("wins.csv");
    std::ofstream gamesFile("games.csv");

    for (auto& row : timesWon) {
      for (auto col : row)
        winsFile << col <<',';
      winsFile << '\n';
    }

    for (auto& row : timesPlayed) {
      for (auto col : row)
        gamesFile << col <<',';
      gamesFile << '\n';
    }

    return 0;
}



//class TileSet
//{

//};

