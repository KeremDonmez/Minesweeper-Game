#pragma once

#include "board.h"
#include <iostream>
using namespace std;

class MSBoardTextView {
private:
    const Board* board;

public:
    MSBoardTextView();
    MSBoardTextView(const Board& b);
    void display() const;

    void displayMenu() const;
    int handleUserInput() const;
    void getBoardDimensions(int& x, int& y) const;
};


