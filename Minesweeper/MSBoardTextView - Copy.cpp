#include "MSBoardTextView.h"
#include <iomanip>
#include <iostream>
using namespace std;

MSBoardTextView::MSBoardTextView() : board(nullptr) {}

MSBoardTextView::MSBoardTextView(const Board& b) : board(&b) {}

void MSBoardTextView::display() const {
    if (!board) {
        cout << "Board not initialized.\n";
        return;
    }

    cout << " ";
    for (int j = 0; j < board->getBoardWidth(); ++j) {
        cout << setw(4) << j + 1;
    }
    cout << endl;

    for (int i = 0; i < board->getBoardHeight(); ++i) {
        cout << setw(3) << i + 1;
        for (int j = 0; j < board->getBoardWidth(); ++j) {
            char fieldInfo = board->getFieldInfo(i, j);
            cout << '[' << fieldInfo << ']' << ' ';
        }
        cout << endl;
    }
}

void MSBoardTextView::displayMenu() const {
    cout << "=== Minesweeper Menu ===\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "4. Debug\n";
    cout << "5. Exit\n";
}

int MSBoardTextView::handleUserInput() const {
    int choice;
    cout << "Please make a choice: ";
    cin >> choice;
    while (choice < 1 || choice > 5) {
        cout << "Invalid choice. Please enter a number between 1 and 5: ";
        cin >> choice;
    }
    return choice;
}

void MSBoardTextView::getBoardDimensions(int& x, int& y) const {
    cout << "Please enter row and column values for the game board: ";
    cin >> x >> y;
}


