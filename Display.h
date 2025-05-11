#pragma once
#include "PositionArray.h"
#include "Legality.h"
extern bool selecting;
extern int  selectRow, selectCol;

void pieceIndicator(sf::RenderWindow& window, sf::Font& font) {
    sf::RectangleShape indicatorBox({ sidebarWidth - 40, 180 });
    indicatorBox.setFillColor(sf::Color(118, 150, 86));
    indicatorBox.setPosition(boardSize * squareSize + 20, 225);
    window.draw(indicatorBox);

    if (turn % 2 == 1) { // White
        sf::Text title("Selected Piece", font, 27);
        title.setFillColor(sf::Color::White);
        title.setPosition(boardSize * squareSize + 21.5f, 225);
        window.draw(title);
    }
    else { // Black
        sf::Text title("Selected Piece", font, 27);
        title.setFillColor(sf::Color::Black);
        title.setPosition(boardSize * squareSize + 21.5f, 225);
        window.draw(title);
    }

    if (turn % 2 == 1) { // White's turn
        sf::Text whiteTurn("White's Turn", font, 27);
        whiteTurn.setFillColor(sf::Color::White);
        whiteTurn.setPosition(boardSize * squareSize + 34.5f, 367.5);
        window.draw(whiteTurn);
    }
    else { // Black's turn
        sf::Text whiteTurn("Black's Turn", font, 27);
        whiteTurn.setFillColor(sf::Color::Black);
        whiteTurn.setPosition(boardSize * squareSize + 34.5f, 367.5);
        window.draw(whiteTurn);
    }

    if (!selecting) {
        return;
    }

    const std::string& piece = board[selectRow][selectCol];

    if (piece != "  ") {
        sf::Texture texture;
        if (!texture.loadFromFile("assets/" + piece + ".png")) {
            std::cerr << "Could not load " << piece << ".png\n";
            return;
        }

        sf::Sprite display(texture);
        display.setPosition(boardSize * squareSize + 59, 265);
        float scale = squareSize / float(texture.getSize().x);
        display.setScale(scale, scale);
        window.draw(display);
    }
}