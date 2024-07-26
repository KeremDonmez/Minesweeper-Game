#include "board.h"
#include "game.h"
#include "MSBoardTextView.h"


MSTextController::MSTextController(Board& b, MSBoardTextView& v) : board(b), view(v) {}

void MSTextController::play() {
	view.display();
	while (board.getGameState() == RUNNING) {
		int x, y;
		std::cout << "Enter x and y: ";
		std::cin >> x >> y;
		board.revealField(x, y);
		view.display();
	}
	if (board.getGameState() == FINISHED_LOSS) {
		std::cout << "You lost!" << std::endl;
	} else {
		std::cout << "You won!" << std::endl;
	}
}