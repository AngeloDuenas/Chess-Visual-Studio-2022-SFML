#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

const int sidebarWidth = 200;
inline void drawTimers(sf::RenderWindow& window, sf::Font& font, const std::string& whiteTime, const std::string& blackTime) {
    // White timer box
    sf::RectangleShape whiteBox(sf::Vector2f(sidebarWidth - 40, 100));
    whiteBox.setFillColor(sf::Color(220, 220, 220));
    whiteBox.setPosition(boardSize * squareSize + 20, 500);
    window.draw(whiteBox);

    // Black timer box
    sf::RectangleShape blackBox(sf::Vector2f(sidebarWidth - 40, 100));
    blackBox.setFillColor(sf::Color(40, 40, 40));
    blackBox.setPosition(boardSize * squareSize + 20, 20);
    window.draw(blackBox);

    // Draw white time
    sf::Text whiteText;
    whiteText.setFont(font);
    whiteText.setString(whiteTime);
    whiteText.setCharacterSize(50);
    whiteText.setFillColor(sf::Color::Black);
    whiteText.setPosition(boardSize * squareSize + 45.5, 517.5);
    window.draw(whiteText);

    // Draw black time
    sf::Text blackText;
    blackText.setFont(font);
    blackText.setString(blackTime);
    blackText.setCharacterSize(50);
    blackText.setFillColor(sf::Color::White);
    blackText.setPosition(boardSize * squareSize + 45.5, 37.5);
    window.draw(blackText);
}