#include <iostream>
#include <algorithm>
#include <string>

#include "Mechanics.h"

long HighestScore(std::vector<Tile> tiles, std::string& bestWord)
{
    std::ifstream infile(englishDictFileName); //maybe assert or something idk
    std::string line;

    long maxScore = 0;
    long currentScore = 0;

    while (std::getline(infile, line))
    {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.cend());
        currentScore = CanMakeWord(tiles, line);
        if(currentScore > maxScore)
        {
            maxScore = currentScore;
            bestWord = line;
        }
    }
    return maxScore;
}

long CanMakeWord(std::vector<Tile> tiles, std::string word)
{
    std::vector<char> tempLetters;
    long hasBlanks = 0;
    long currentScore = 0;

    for(auto it = tiles.begin(); it < tiles.end(); it++)
    {
        if(*it == Tile::blank)
        {
            hasBlanks += 1;
        }
        else
        {
            tempLetters.push_back(tileCharMap.at(*it));
        }
    }

    for (auto& letter : word)
    {
        auto pos = std::find(tempLetters.begin(), tempLetters.end(), letter);
        if (pos == tempLetters.end())
        {
            if(hasBlanks)
            {
                hasBlanks -=1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            currentScore += englishScores.at(*pos);
            tempLetters.erase(pos);
        }
    }
    return currentScore;
}

long WordScore(std::vector<Tile> tiles)
{
    return 1;
}
