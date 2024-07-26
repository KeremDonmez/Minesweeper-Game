cmake_minimum_required(VERSION 3.27)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Minesweeper
        board.cpp
        board.h
        game.cpp
        game.h
        main.cpp
        MSSFMLController.cpp
        SFMLGECICI.cpp
        sfmlMain.cpp
        SFMLGECICI.cpp)
