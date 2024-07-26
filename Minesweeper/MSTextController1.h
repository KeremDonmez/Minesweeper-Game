#pragma once

#include "board.h"
#include "MSBoardTextView.h"

class MSTextController1 {
private:
    Board& board;
    MSBoardTextView& view;

public:
    MSTextController1(Board& b, MSBoardTextView& v);
    void play();
};

