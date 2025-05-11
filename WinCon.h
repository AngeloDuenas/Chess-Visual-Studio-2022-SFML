#pragma once
#include "PositionArray.h"
int blackKingAlive = 1;
int whiteKingAlive = 1;
int whiteVictory = 0;
int blackVictory = 0;

void whiteWin() {
    for (int r = 0; r < boardSize; r = r + 1) { // Resets
        for (int c = 0; c < boardSize; c = c + 1) {
            if (board[r][c] == "BK") {
                blackKingAlive = 1;
                break;
            }
        }
    }
    if (blackKingAlive != 1) {
        std::cout << "The game is over! White wins!" << std::endl;
        whiteVictory = 1;
    }
    blackKingAlive = 0;
}

void blackWin() {
    for (int r = 0; r < boardSize; r = r + 1) { // Resets
        for (int c = 0; c < boardSize; c = c + 1) {
            if (board[r][c] == "WK") {
                whiteKingAlive = 1;
                break;
            }
        }
    }
    if (whiteKingAlive != 1) {
        std::cout << "The game is over! Black wins!" << std::endl;
        blackVictory = 1;
    }
    whiteKingAlive = 0;
}

void drawWinScreen(sf::RenderWindow& window, sf::Font& font) {
    if (blackVictory == 1 || whiteVictory == 1) {
        sf::Vector2u winSize = window.getSize();
        sf::RectangleShape winScreen;
        winScreen.setSize({ float(winSize.x), float(winSize.y) });
        winScreen.setPosition(0.f, 0.f);
        winScreen.setFillColor(sf::Color(128, 128, 128, 128));
        window.draw(winScreen);
    }

    if (blackVictory == 1) {
        sf::Text winScreenText;
        sf::Vector2u winSize = window.getSize();
        winScreenText.setFont(font);
        winScreenText.setString("BLACK VICTORY");
        winScreenText.setCharacterSize(100);
        winScreenText.setFillColor(sf::Color::Black);
        winScreenText.setPosition({ float(winSize.x) / 3 - 120, float(winSize.y) / 3 + 20 });
        window.draw(winScreenText);
    }
    else if (whiteVictory == 1) {
        sf::Text winScreenText;
        sf::Vector2u winSize = window.getSize();
        winScreenText.setFont(font);
        winScreenText.setString("WHITE VICTORY");
        winScreenText.setCharacterSize(100);
        winScreenText.setFillColor(sf::Color::White);
        winScreenText.setPosition({ float(winSize.x) / 3 - 120, float(winSize.y) / 3 + 20 });
        window.draw(winScreenText);
    }
}