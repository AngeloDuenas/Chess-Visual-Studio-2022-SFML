#pragma once
#include "PositionArray.h"
#include "AttackArray.h"
#include "Movement.h"
#include "Textures.h"

int whiteCheck; // White is UNDER check
int blackCheck; // Black is UNDER check

void checkWhiteCheck() {
	whiteCheck = 0;
	for (int r = 0; r < boardSize; ++r) {
		for (int c = 0; c < boardSize; ++c) {
			if (board[r][c] == "WK" && blackAttackBoard[r][c] == "BA") {
				whiteCheck = 1;
				return;
			}
		}
	}
}

void whiteCheckBox(sf::RenderWindow& window, sf::Font& font) { // Notifies that white is in check
	if (whiteCheck == 1) {
		sf::RectangleShape whiteCheckBox(sf::Vector2f(sidebarWidth - 40, 50));
		whiteCheckBox.setFillColor(sf::Color::White);
		whiteCheckBox.setPosition(boardSize * squareSize + 20, 442.5); // Works
		window.draw(whiteCheckBox);

		sf::Text whiteCheckText;
		whiteCheckText.setFont(font);
		whiteCheckText.setString("CHECK");
		whiteCheckText.setCharacterSize(50);
		whiteCheckText.setFillColor(sf::Color::Black);
		whiteCheckText.setPosition(boardSize * squareSize + 42, 435);
		window.draw(whiteCheckText);
	}
}

void checkBlackCheck() {
	for (int r = 0; r < boardSize; ++r) {
		for (int c = 0; c < boardSize; ++c) {
			if (board[r][c] == "BK" && whiteAttackBoard[r][c] == "WA") {
				blackCheck = 1;
				return;
			}
		}
	}
	blackCheck = 0;
}

void blackCheckBox(sf::RenderWindow& window, sf::Font& font) { // Notifies that black is in check
	if (blackCheck == 1) {
		sf::RectangleShape blackCheckBox(sf::Vector2f(sidebarWidth - 40, 50));
		blackCheckBox.setFillColor(sf::Color::Black);
		blackCheckBox.setPosition(boardSize * squareSize + 20, 130);
		window.draw(blackCheckBox);

		sf::Text blackCheckText;
		blackCheckText.setFont(font);
		blackCheckText.setString("CHECK");
		blackCheckText.setCharacterSize(50);
		blackCheckText.setFillColor(sf::Color::White);
		blackCheckText.setPosition(boardSize * squareSize + 42, 120.5);
		window.draw(blackCheckText);
	}
}