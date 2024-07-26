/*


/#include <iostream>
#include "board.h"
#include "MSBoardTextView.h"
#include "MSTextController1.h"

int main() {
    MSBoardTextView menuView;
    menuView.displayMenu(); // Menü fonksiyonunu çağırıyoruz
    int choice = menuView.handleUserInput(); // Kullanıcı girişini alıyoruz

    if (choice == 5) {
        std::cout << "Exiting the game.\n";
        return 0;
    }

    int x, y;
    menuView.getBoardDimensions(x, y); // Kullanıcıdan tahta boyutlarını alıyoruz

    GameMode mode;
    switch (choice) {
    case 1: mode = GameMode::EASY; break;
    case 2: mode = GameMode::MEDIUM; break;
    case 3: mode = GameMode::HARD; break;
    case 4: mode = GameMode::DEBUG; break;
    default:
        std::cout << "Invalid choice. Exiting the game.\n";
        return 0;
    }

    // Oyun tahtası ve oyun görünümünü oluşturuyoruz
    Board board(x, y, mode);
    MSBoardTextView gameView(board);
    MSTextController1 controller(board, gameView);

    // Oyunu başlatıyoruz
    controller.play();

    return 0;
}




*/





