#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>
#include <string>

enum Tile
{
    blank = 0,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z
};

const std::map<Tile, char> tileCharMap {
    {Tile::blank, '#'},
    {Tile::A, 'A'},
    {Tile::B, 'B'},
    {Tile::C, 'C'},
    {Tile::D, 'D'},
    {Tile::E, 'E'},
    {Tile::F, 'F'},
    {Tile::G, 'G'},
    {Tile::H, 'H'},
    {Tile::I, 'I'},
    {Tile::J, 'J'},
    {Tile::K, 'K'},
    {Tile::L, 'L'},
    {Tile::M, 'M'},
    {Tile::N, 'N'},
    {Tile::O, 'O'},
    {Tile::P, 'P'},
    {Tile::Q, 'Q'},
    {Tile::R, 'R'},
    {Tile::S, 'S'},
    {Tile::T, 'T'},
    {Tile::U, 'U'},
    {Tile::V, 'V'},
    {Tile::W, 'W'},
    {Tile::X, 'X'},
    {Tile::Y, 'Y'},
    {Tile::Z, 'Z'}
};

typedef std::map<Tile, long> TileSet;
typedef std::map<char, long> TileScores;

const long englishTileNum = 100;

const TileScores englishScores {
    {'A', 1},
    {'B', 3},
    {'C', 3},
    {'D', 2},
    {'E', 1},
    {'F', 4},
    {'G', 2},
    {'H', 4},
    {'I', 1},
    {'J', 8},
    {'K', 5},
    {'L', 1},
    {'M', 3},
    {'N', 1},
    {'O', 1},
    {'P', 3},
    {'Q', 10},
    {'R', 1},
    {'S', 1},
    {'T', 1},
    {'U', 1},
    {'V', 4},
    {'W', 4},
    {'X', 8},
    {'Y', 4},
    {'Z', 10}
};

const TileSet englishSet {
    {Tile::blank, 2},
    {Tile::A, 9},
    {Tile::B, 2},
    {Tile::C, 2},
    {Tile::D, 4},
    {Tile::E, 12},
    {Tile::F, 2},
    {Tile::G, 3},
    {Tile::H, 2},
    {Tile::I, 9},
    {Tile::J, 1},
    {Tile::K, 1},
    {Tile::L, 4},
    {Tile::M, 2},
    {Tile::N, 6},
    {Tile::O, 8},
    {Tile::P, 2},
    {Tile::Q, 1},
    {Tile::R, 6},
    {Tile::S, 4},
    {Tile::T, 6},
    {Tile::U, 4},
    {Tile::V, 2},
    {Tile::W, 2},
    {Tile::X, 1},
    {Tile::Y, 2},
    {Tile::Z, 1}
};

const std::string englishDictFileName = "/home/sean/ScrabblePoker/englishDict.txt";

#endif // CONSTANTS_H
