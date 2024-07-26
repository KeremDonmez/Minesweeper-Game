#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


MSSFMLView::MSSFMLView(Board& b) : board(b)
{
    window.create(sf::VideoMode(608, 608), "Minesweeper");
    window.setFramerateLimit(60);

    if (!spriteSheet.loadFromFile("C:/Users/Kerem Donmez/Desktop/Minesweeper/assests/19849.png"))
    {
        cout << "Could not load sprite sheet" << std::endl;
    }

    clockDigit1.setTexture(spriteSheet);
    clockDigit1.setTextureRect(sf::IntRect(0, 0, 13, 23));

    clockDigit2.setTexture(spriteSheet);
    clockDigit2.setTextureRect(sf::IntRect(14, 0, 13, 23));

    clockDigit3.setTexture(spriteSheet);
    clockDigit3.setTextureRect(sf::IntRect(28, 0, 13, 23));

    clockDigit4.setTexture(spriteSheet);
    clockDigit4.setTextureRect(sf::IntRect(42, 0, 13, 23));

    clockDigit5.setTexture(spriteSheet);
    clockDigit5.setTextureRect(sf::IntRect(57, 0, 13, 23));

    clockDigit6.setTexture(spriteSheet);
    clockDigit6.setTextureRect(sf::IntRect(71, 0, 13, 23));

    clockDigit7.setTexture(spriteSheet);
    clockDigit7.setTextureRect(sf::IntRect(85, 0, 13, 23));

    clockDigit8.setTexture(spriteSheet);
    clockDigit8.setTextureRect(sf::IntRect(98, 0, 13, 23));

    clockDigit9.setTexture(spriteSheet);
    clockDigit9.setTextureRect(sf::IntRect(114, 0, 13, 23));

    clockDigit0.setTexture(spriteSheet);
    clockDigit0.setTextureRect(sf::IntRect(117, 0, 13, 23));

    clockColon.setTexture(spriteSheet);
    clockColon.setTextureRect(sf::IntRect(140, 0, 13, 23));

    clockBackground.setTexture(spriteSheet);
    clockBackground.setTextureRect(sf::IntRect(140, 0, 13, 23));

    happyFaceSprite.setTexture(spriteSheet);
    happyFaceSprite.setTextureRect(sf::IntRect(0, 23, 24, 24));

    pressedHappyFaceSprite.setTexture(spriteSheet);
    pressedHappyFaceSprite.setTextureRect(sf::IntRect(25, 23, 26.9, 26));

    suprisedFaceSprite.setTexture(spriteSheet);
    suprisedFaceSprite.setTextureRect(sf::IntRect(50, 23, 25, 24));

    winFaceSprite.setTexture(spriteSheet);
    winFaceSprite.setTextureRect(sf::IntRect(75, 23, 24, 24));

    loseFaceSprite.setTexture(spriteSheet);
    loseFaceSprite.setTextureRect(sf::IntRect(100, 23, 25, 24));

    hiddenSprite.setTexture(spriteSheet);
    hiddenSprite.setTextureRect(sf::IntRect(1, 49, 16, 18));

    revealedSprite.setTexture(spriteSheet);
    revealedSprite.setTextureRect(sf::IntRect(17, 49, 17, 17));

    flagSprite.setTexture(spriteSheet);
    flagSprite.setTextureRect(sf::IntRect(34, 50, 16, 16));

    questionMarkSprite.setTexture(spriteSheet);
    questionMarkSprite.setTextureRect(sf::IntRect(51, 50, 16, 16));

    pressedQuestionMarkSprite.setTexture(spriteSheet);
    pressedQuestionMarkSprite.setTextureRect(sf::IntRect(69, 51, 17, 16));

    mineSprite.setTexture(spriteSheet);
    mineSprite.setTextureRect(sf::IntRect(85, 51, 17, 16));

    redMineSprite.setTexture(spriteSheet);
    redMineSprite.setTextureRect(sf::IntRect(103, 51, 17, 16));

    crossedMineSprite.setTexture(spriteSheet);
    crossedMineSprite.setTextureRect(sf::IntRect(120, 51, 16, 16));

    numbersprite1.setTexture(spriteSheet);
    numbersprite1.setTextureRect(sf::IntRect(1, 67, 17, 16));

    numbersprite2.setTexture(spriteSheet);
    numbersprite2.setTextureRect(sf::IntRect(17, 67, 17, 16));

    numbersprite3.setTexture(spriteSheet);
    numbersprite3.setTextureRect(sf::IntRect(34, 67, 17, 16));

    numbersprite4.setTexture(spriteSheet);
    numbersprite4.setTextureRect(sf::IntRect(51, 67, 17, 16));

    numbersprite5.setTexture(spriteSheet);
    numbersprite5.setTextureRect(sf::IntRect(68, 67, 17, 16));

    numbersprite6.setTexture(spriteSheet);
    numbersprite6.setTextureRect(sf::IntRect(85, 67, 17, 16));

    numbersprite7.setTexture(spriteSheet);
    numbersprite7.setTextureRect(sf::IntRect(103, 67, 17, 16));

    numbersprite8.setTexture(spriteSheet);
    numbersprite8.setTextureRect(sf::IntRect(120, 67, 17, 16));
}
    




void MSSFMLView::displayBoard(const Board& board) {
    const int cellSize = 32;
    int offsetX = 0;
    int offsetY = 0;

    for (int i = 0; i < board.getBoardHeight(); ++i) {
        for (int j = 0; j < board.getBoardWidth(); ++j) {
            char cellInfo = board.getFieldInfo(i, j);

            int cellX = offsetX + j * cellSize;
            int cellY = offsetY + i * cellSize;

            switch (cellInfo) {
            case '_':
                hiddenSprite.setScale(2, 2);
                hiddenSprite.setPosition(cellX, cellY);
                window.draw(hiddenSprite);
                break;
            case 'x':
                mineSprite.setScale(2, 2);
                mineSprite.setPosition(cellX, cellY);
                window.draw(mineSprite);
                break;
            case ' ':
                revealedSprite.setScale(2, 2);
                revealedSprite.setPosition(cellX, cellY);
                window.draw(revealedSprite);
                break;
            case '1':
                numbersprite1.setScale(2, 2);
                numbersprite1.setPosition(cellX, cellY);
                window.draw(numbersprite1);
                break;
            case '2':
                numbersprite2.setScale(2, 2);
                numbersprite2.setPosition(cellX, cellY);
                window.draw(numbersprite2);
                break;
            case '3':
                numbersprite3.setScale(2, 2);
                numbersprite3.setPosition(cellX, cellY);
                window.draw(numbersprite3);
                break;
            case '4':
                numbersprite4.setScale(2, 2);
                numbersprite4.setPosition(cellX, cellY);
                window.draw(numbersprite4);
                break;
            case '5':
                numbersprite5.setScale(2, 2);
                numbersprite5.setPosition(cellX, cellY);
                window.draw(numbersprite5);
                break;
            case '6':
                numbersprite6.setScale(2, 2);
                numbersprite6.setPosition(cellX, cellY);
                window.draw(numbersprite6);
                break;
            case '7':
                numbersprite7.setScale(2, 2);
                numbersprite7.setPosition(cellX, cellY);
                window.draw(numbersprite7);
                break;
            case '8':
                numbersprite8.setScale(2, 2);
                numbersprite8.setPosition(cellX, cellY);
                window.draw(numbersprite8);
                break;
            case 'F':
                flagSprite.setScale(2, 2);
                flagSprite.setPosition(cellX, cellY);
				window.draw(flagSprite);
				break;


            }
            float scale = (cellSize - 1) / static_cast<float>(hiddenSprite.getTextureRect().width);
            hiddenSprite.setScale(scale, scale);

            hiddenSprite.setPosition(cellX, cellY);
        }
    }
}
sf::RenderWindow& MSSFMLView::getWindow() {
    return window;
}

int MSSFMLView::getOffsetX() const {
    return offsetX;
}

int MSSFMLView::getOffsetY() const {
    return offsetY;
}

int MSSFMLView::getCellSize() const {
    return cellSize;
}