cmake_minimum_required(VERSION 3.5)

project(ScrabblePoker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ScrabblePoker main.cpp Constants.h Dealer.cpp Dealer.h Player.cpp Player.h Mechanics.cpp Mechanics.h)
