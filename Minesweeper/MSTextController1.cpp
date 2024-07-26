#include "MSTextController1.h"
#include <iostream>

MSTextController1::MSTextController1(Board& b, MSBoardTextView& v) : board(b), view(v) {}

void MSTextController1::play() {
    view.display();
    while (board.getGameState() == RUNNING) {
        int x, y;
        char action;
        std::cout << "Enter x and y (1-based) and action (o for open, f for flag): ";
        std::cin >> x >> y >> action;

        x--;
        y--;

        if (action == 'o') {
            board.revealField(x, y);
        }
        else if (action == 'f') {
            board.toggleFlag(x, y);
        }
        else {
            std::cout << "Invalid action. Please enter 'o' to open or 'f' to flag.\n";
            continue;
        }

        view.display();
    }

    if (board.getGameState() == FINISHED_LOSS) {
        std::cout << "You lost!" << std::endl;
    }
    else {
        std::cout << "You won!" << std::endl;
    }
}
