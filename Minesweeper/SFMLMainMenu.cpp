#include "SFMLMainMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>

SFMLMainMenu::SFMLMainMenu(sf::RenderWindow& window, float width, float height)
    : window(window), selectedItemIndex(0), playButtonPressed(false), difficulty(0), menuState(MenuState::MAIN_MENU) {

    if (!font.loadFromFile("C:/Users/Kerem Donmez/Desktop/Minesweeper/assests/ARIAL.TTF")) {
        std::cout << "Error loading font" << std::endl;
    }

    title.setFont(font);
    title.setFillColor(sf::Color::Yellow); 
    title.setString("MINESWEEPER GAME");
    title.setCharacterSize(60);
    title.setPosition(sf::Vector2f(width / 2 - title.getGlobalBounds().width / 2, height / 5));

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setCharacterSize(30);
    menu[0].setPosition(sf::Vector2f(width / 2 - menu[0].getGlobalBounds().width / 2, height / 2));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Credits");
    menu[1].setCharacterSize(30);
    menu[1].setPosition(sf::Vector2f(width / 2 - menu[1].getGlobalBounds().width / 2, height / 2 + 50));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setCharacterSize(30);
    menu[2].setPosition(sf::Vector2f(width / 2 - menu[2].getGlobalBounds().width / 2, height / 2 + 100));

    difficultyTitle.setFont(font);
    difficultyTitle.setFillColor(sf::Color::Yellow); 
    difficultyTitle.setString("Select Difficulty");
    difficultyTitle.setCharacterSize(60);
    difficultyTitle.setPosition(sf::Vector2f(width / 2 - difficultyTitle.getGlobalBounds().width / 2, height / 5));

    difficultyMenu[0].setFont(font);
    difficultyMenu[0].setFillColor(sf::Color::Red);
    difficultyMenu[0].setString("Easy");
    difficultyMenu[0].setCharacterSize(30);
    difficultyMenu[0].setPosition(sf::Vector2f(width / 2 - difficultyMenu[0].getGlobalBounds().width / 2, height / 2));

    difficultyMenu[1].setFont(font);
    difficultyMenu[1].setFillColor(sf::Color::White);
    difficultyMenu[1].setString("Medium");
    difficultyMenu[1].setCharacterSize(30);
    difficultyMenu[1].setPosition(sf::Vector2f(width / 2 - difficultyMenu[1].getGlobalBounds().width / 2, height / 2 + 50));

    difficultyMenu[2].setFont(font);
    difficultyMenu[2].setFillColor(sf::Color::White);
    difficultyMenu[2].setString("Hard");
    difficultyMenu[2].setCharacterSize(30);
    difficultyMenu[2].setPosition(sf::Vector2f(width / 2 - difficultyMenu[2].getGlobalBounds().width / 2, height / 2 + 100));

    creditsMenu[0].setFont(font);
    creditsMenu[0].setFillColor(sf::Color::White);
    creditsMenu[0].setString("Created by Kerem Donmez");
    creditsMenu[0].setCharacterSize(50);
    creditsMenu[0].setPosition(sf::Vector2f(width / 2 - creditsMenu[0].getGlobalBounds().width / 2, height / 2));
}

void SFMLMainMenu::draw() {
    window.clear();
    if (menuState == MenuState::MAIN_MENU) {
        window.draw(title);  
    }
    switch (menuState) {
    case MenuState::MAIN_MENU:
        for (int i = 0; i < 3; i++) {
            window.draw(menu[i]);
        }
        break;
    case MenuState::DIFFICULTY_SELECTION:
        for (int i = 0; i < 3; i++) {
            window.draw(difficultyTitle);
            window.draw(difficultyMenu[i]);
        }
        break;
    case MenuState::CREDITS:
        window.draw(creditsMenu[0]);
        break;
    }
    window.display();
}

void SFMLMainMenu::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::KeyPressed:
            switch (event.key.code) {
            case sf::Keyboard::Up:
                moveUp();
                break;
            case sf::Keyboard::Down:
                moveDown();
                break;
            case sf::Keyboard::Return:
                switch (menuState) {
                case MenuState::MAIN_MENU:
                    switch (getSelectedItemIndex()) {
                    case 0:
                        menuState = MenuState::DIFFICULTY_SELECTION;
                        selectedItemIndex = 0;
                        break;
                    case 1:
                        menuState = MenuState::CREDITS;
                        break;
                    case 2:
                        window.close();
                        break;
                    }
                    break;
                case MenuState::DIFFICULTY_SELECTION:
                    difficulty = selectedItemIndex;
                    playButtonPressed = true;
                    break;
                case MenuState::CREDITS:
                    menuState = MenuState::MAIN_MENU;
                    break;
                }
                break;
            }
            break;
        case sf::Event::Closed:
            window.close();
            break;
        }
    }
}

void SFMLMainMenu::moveUp() {
    if (selectedItemIndex - 1 >= 0) {
        switch (menuState) {
        case MenuState::MAIN_MENU:
            menu[selectedItemIndex].setFillColor(sf::Color::White);
            break;
        case MenuState::DIFFICULTY_SELECTION:
            difficultyMenu[selectedItemIndex].setFillColor(sf::Color::White);
            break;
        case MenuState::CREDITS:
            break;
        }
        selectedItemIndex--;
        switch (menuState) {
        case MenuState::MAIN_MENU:
            menu[selectedItemIndex].setFillColor(sf::Color::Red);
            break;
        case MenuState::DIFFICULTY_SELECTION:
            difficultyMenu[selectedItemIndex].setFillColor(sf::Color::Red);
            break;
        case MenuState::CREDITS:
            break;
        }
    }
}

void SFMLMainMenu::moveDown() {
    if (selectedItemIndex + 1 < 3) {
        switch (menuState) {
        case MenuState::MAIN_MENU:
            menu[selectedItemIndex].setFillColor(sf::Color::White);
            break;
        case MenuState::DIFFICULTY_SELECTION:
            difficultyMenu[selectedItemIndex].setFillColor(sf::Color::White);
            break;
        case MenuState::CREDITS:
            break;
        }
        selectedItemIndex++;
        switch (menuState) {
        case MenuState::MAIN_MENU:
            menu[selectedItemIndex].setFillColor(sf::Color::Red);
            break;
        case MenuState::DIFFICULTY_SELECTION:
            difficultyMenu[selectedItemIndex].setFillColor(sf::Color::Red);
            break;
        case MenuState::CREDITS:
            break;
        }
    }
}

void SFMLMainMenu::update() {
}
