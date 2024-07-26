#pragma once
#include "board.h"
#include <iostream>
#include "MSBoardTextView.h"

class MSTextController {   
    private:
	Board& board;
	MSBoardTextView& view;
    public:
        MSTextController(Board& b, MSBoardTextView& v);
        void play();
};