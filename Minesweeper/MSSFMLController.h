#pragma once

#include "Board.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>

class MSSFMLController {
public:
    MSSFMLController(Board& board, MSSFMLView& view);  
    void play();  
    void handleEvent(sf::Event& event);

private:
    Board& board;
    MSSFMLView& view;
};