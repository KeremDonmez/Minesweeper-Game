#ifndef SFMLMAINMENU_H
#define SFMLMAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

enum class MenuState {
    MAIN_MENU,
    DIFFICULTY_SELECTION,
    CREDITS
};

class SFMLMainMenu {
public:
    SFMLMainMenu(sf::RenderWindow& window, float width, float height);

    bool getPlayButtonState() const { return this->playButtonPressed; }
    int getDifficulty() const { return this->difficulty; }

    void handleInput();
    void update();
    void draw();

    int getSelectedItemIndex() const { return selectedItemIndex; }
    void moveUp();
    void moveDown();

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text menu[3];
    sf::Text title; 
    sf::Text difficultyTitle; 
    sf::Text difficultyMenu[3];
    sf::Text creditsMenu[1];
    int selectedItemIndex;
    bool playButtonPressed;
    int difficulty;
    MenuState menuState;
};

#endif 