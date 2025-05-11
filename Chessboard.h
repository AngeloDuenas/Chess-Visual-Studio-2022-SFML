#pragma once
#include <SFML/Graphics.hpp>
#include "PositionArray.h"
#include "Textures.h"
#include <string>

int row, col;
const int squareSize = 80;

inline void drawBoard(sf::RenderWindow& window) {
    for (row = 0; row < boardSize; row = row + 1) {
        for (col = 0; col < boardSize; col = col + 1) {
            sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
            square.setPosition(col * squareSize, row * squareSize);

            if ((row + col) % 2 == 0) {
                square.setFillColor(sf::Color::White); // White squares
            }
            else {
                square.setFillColor(sf::Color(118, 150, 86)); // Green squares
            }
            window.draw(square);
        }
    }
}

inline void drawPieces(sf::RenderWindow& window) {
    for (row = 0; row < boardSize; row = row + 1) {
        for (col = 0; col < boardSize; col = col + 1) {
            std::string piece = board[row][col];
            if (piece != "  ") {
                sf::Sprite sprite;
                sprite.setTexture(pieceTextures[piece]);
                sprite.setPosition(col * squareSize, row * squareSize);
                sprite.setScale(
                    squareSize / (float)pieceTextures[piece].getSize().x,
                    squareSize / (float)pieceTextures[piece].getSize().y
                );
                window.draw(sprite);
            }
        }
    }
}