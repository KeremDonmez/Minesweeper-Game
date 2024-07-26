    #pragma once

    #include <vector>
    using namespace std;

    enum GameMode {
        EASY,
        MEDIUM,
        HARD,
        DEBUG
    };

    enum GameState {
        RUNNING,
        FINISHED_WIN,
        FINISHED_LOSS
    };

    struct cell {
        bool isMine;
        bool isFlagged;
        bool isRevealed;
    };

    class Board {
    private:
        int width;
        int height;
        GameMode mode;
        GameState gameState;
        bool firstAction;
        vector<vector<cell>> board;

    public:
        Board(int width, int height, GameMode mode);
        void debug_display() const;
        int getBoardWidth() const;
        int getBoardHeight() const;
        int countMines(int row, int col) const;
        bool hasFlag(int row, int col) const;
        void toggleFlag(int row, int col);
        void revealField(int row, int col);
        bool isRevealed(int row, int col) const;
        GameState getGameState() const;
        char getFieldInfo(int row, int col) const;


    };
