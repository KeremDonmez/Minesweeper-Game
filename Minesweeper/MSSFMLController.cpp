#include "MSSFMLController.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include <iostream>

using namespace std;


MSSFMLController::MSSFMLController(Board& b, MSSFMLView& v) : board(b), view(v) {}


void MSSFMLController::play() {
    sf::RenderWindow& window = view.getWindow();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                int tileX = (x - view.getOffsetX()) / view.getCellSize();
                int tileY = (y - view.getOffsetY()) / view.getCellSize();

                if (tileX >= 0 && tileX < board.getBoardWidth() && tileY >= 0 && tileY < board.getBoardHeight()) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        board.revealField(tileY, tileX);
                    }
                    else if (event.mouseButton.button == sf::Mouse::Right) {
                        board.toggleFlag(tileY, tileX);
                    }
                }

                GameState state = board.getGameState();
                if (state == FINISHED_WIN || state == FINISHED_LOSS) {
                    window.close();
                }
            }
        }

        window.clear();
        view.displayBoard(board);
        window.display();
    }
}


