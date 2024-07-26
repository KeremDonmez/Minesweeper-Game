
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include "board.h"
#include "MSSFMLController.h"
#include "SFMLMainMenu.h"

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");
    SFMLMainMenu mainMenu(window, window.getSize().x, window.getSize().y);

    bool playGame = false;
    while (window.isOpen()) {
        mainMenu.handleInput();
        if (mainMenu.getPlayButtonState()) {
            playGame = true;
            window.clear();
            break;
        }

        mainMenu.update();
        mainMenu.draw();
    }

    if (playGame) {
        Board board(19, 19, EASY);
        MSSFMLView view(board);
        MSSFMLController controller(board, view);
        controller.play();
    }

    return 0;
}



