#ifndef MECHANICS_H
#define MECHANICS_H

#include <fstream>
#include <vector>

#include "Constants.h"

//std::ifstream infile();

long HighestScore(std::vector<Tile> tiles, std::string &bestWord);
long CanMakeWord(std::vector<Tile> tiles, std::string word);
long WordScore(std::vector<Tile> tiles);

#endif // MECHANICS_H
