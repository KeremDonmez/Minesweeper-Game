#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "board.h"

using namespace std;

Board::Board(int width, int height, GameMode mode) : width(width), height(height), mode(mode), gameState(RUNNING), firstAction(true) {
    board.resize(height, vector<cell>(width));
    srand(time(0));
    int mines = 0;

    switch (mode) {
    case EASY:
        mines = (width * height) * 0.1;
        break;
    case MEDIUM:
        mines = (width * height) * 0.2;
        break;
    case HARD:
        mines = (width * height) * 0.3;
        break;
    case DEBUG:
        // All fields on the diagonal should have a mine
        for (int i = 0; i < min(width, height); i++) {
            board[i][i].isMine = true;
        }
        // All fields in the first row should have a mine
        for (int j = 0; j < width; j++) {
            board[0][j].isMine = true;
            board[0][j].isRevealed = true; // Reveal the mine in the first row
        }
        // Every second field in the first column should have a mine
        for (int i = 0; i < height; i += 2) {
            board[i][0].isMine = true;
            board[i][0].isRevealed = true; // Reveal the mine in every second field of the first column
        }
        // Initialize remaining cell properties
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                board[i][j].isFlagged = false;
                if (!board[i][j].isRevealed) {
                    board[i][j].isRevealed = false;
                }
            }
        }
        return;
    }

    while (mines > 0) {
        int i = rand() % height;
        int j = rand() % width;
        if (!board[i][j].isMine) {
            board[i][j].isMine = true;
            mines--;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j].isFlagged = false;
            board[i][j].isRevealed = false;
        }
    }
}

int Board::getBoardHeight() const {
    return height;
}

int Board::getBoardWidth() const {
    return width;
}

int Board::countMines(int row, int col) const {
    if (row < 0 || row >= height || col < 0 || col >= width || !board[row][col].isRevealed) {
        return -1;
    }

    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width && board[newRow][newCol].isMine) {
                count++;
            }
        }
    }

    return count;
}

void Board::debug_display() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << "[";
            cout << (board[i][j].isMine ? "M" : ".");
            cout << (board[i][j].isFlagged ? "F" : ".");
            cout << (board[i][j].isRevealed ? "R" : ".");
            cout << "]";
        }
        cout << "\n";
    }
}

bool Board::hasFlag(int row, int col) const {
    if (row < 0 || row >= height || col < 0 || col >= width) {
        return false;
    }
    return board[row][col].isFlagged;
}

void Board::toggleFlag(int row, int col) {
    if (row < 0 || row >= height || col < 0 || col >= width) {
        return;
    }
    if (board[row][col].isRevealed) {
        return;
    }
    board[row][col].isFlagged = !board[row][col].isFlagged;
}

void Board::revealField(int row, int col) {
    if (row < 0 || row >= height || col < 0 || col >= width) {
        return;
    }

    if (board[row][col].isRevealed) {
        return;
    }

    if (gameState == FINISHED_WIN || gameState == FINISHED_LOSS) {
        return;
    }

    if (board[row][col].isFlagged) {
        return;
    }

    board[row][col].isRevealed = true;

    if (board[row][col].isMine) {
        if (firstAction && mode != DEBUG) {
            int newRow, newCol;
            do {
                newRow = rand() % height;
                newCol = rand() % width;
            } while (board[newRow][newCol].isMine || (newRow == row && newCol == col));

            board[newRow][newCol].isMine = true;
            board[row][col].isMine = false;
            firstAction = false;
        }
        else {
            gameState = FINISHED_LOSS;
        }
    }
    else {
        firstAction = false;
        int mineCount = countMines(row, col);

        if (mineCount == 0) {
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int newRow = row + i;
                    int newCol = col + j;
                    if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width && !board[newRow][newCol].isRevealed) {
                        revealField(newRow, newCol);
                    }
                }
            }
        }
    }
}

bool Board::isRevealed(int row, int col) const {
    if (row < 0 || row >= height || col < 0 || col >= width) {
        return false;
    }
    return board[row][col].isRevealed;
}

GameState Board::getGameState() const {
    if (gameState == FINISHED_LOSS) {
        return FINISHED_LOSS;
    }
    if (gameState == FINISHED_WIN) {
        return FINISHED_WIN;
    }
    return RUNNING;
}

char Board::getFieldInfo(int row, int col) const {
    if (row < 0 || row >= height || col < 0 || col >= width) {
        return '#';
    }
    if (!board[row][col].isRevealed) {
        return board[row][col].isFlagged ? 'F' : '_';
    }
    if (board[row][col].isMine) {
        return 'x';
    }
    int mineCount = countMines(row, col);
    return mineCount == 0 ? ' ' : '0' + mineCount;
}
