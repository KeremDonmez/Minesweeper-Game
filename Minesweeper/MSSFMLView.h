#ifndef MSSFMLVIEW_H
#define MSSFMLVIEW_H

#include "Board.h"
#include <SFML/Graphics.hpp>

class MSSFMLView {
public:
    MSSFMLView(Board& b);

    void display(const bool& debug);
    void displayBoard(const Board& board);

    sf::RenderWindow& getWindow();
    int getOffsetX() const;
    int getOffsetY() const;
    int getCellSize() const;

private:
    Board& board;
    sf::RenderWindow window;
    sf::Texture spriteSheet;
    sf::Sprite mineSprite;
    sf::Sprite redMineSprite;
    sf::Sprite crossedMineSprite;
    sf::Sprite questionMarkSprite;
    sf::Sprite pressedQuestionMarkSprite;
    sf::Sprite flagSprite;
    sf::Sprite hiddenSprite;
    sf::Sprite revealedSprite;
    sf::Sprite debugSprite;
    sf::Sprite backgroundSprite;
    sf::Sprite numbersprite1;
    sf::Sprite numbersprite2;
    sf::Sprite numbersprite3;
    sf::Sprite numbersprite4;
    sf::Sprite numbersprite5;
    sf::Sprite numbersprite6;
    sf::Sprite numbersprite7;
    sf::Sprite numbersprite8;
    sf::Sprite happyFaceSprite;
    sf::Sprite pressedHappyFaceSprite;
    sf::Sprite suprisedFaceSprite;
    sf::Sprite winFaceSprite;
    sf::Sprite loseFaceSprite;
    sf::Sprite clockDigit0;
    sf::Sprite clockDigit1;
    sf::Sprite clockDigit2;
    sf::Sprite clockDigit3;
    sf::Sprite clockDigit4;
    sf::Sprite clockDigit5;
    sf::Sprite clockDigit6;
    sf::Sprite clockDigit7;
    sf::Sprite clockDigit8;
    sf::Sprite clockDigit9;
    sf::Sprite clockColon;
    sf::Sprite clockBackground;

    void loadSprites();

    int offsetX=0;

    int offsetY = 0;
    const int cellSize = 32;
};
#endif 