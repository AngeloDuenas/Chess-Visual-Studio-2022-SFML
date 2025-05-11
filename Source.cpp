#include <SFML/Graphics.hpp>
#include "ChessBoard.h"
#include "Timer.h"
#include "Textures.h"
#include "Movement.h"
#include "Legality.h"
#include "Check.h"
#include "WinCon.h"
#include "Display.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const int windowWidth = 200;
int turn = 1;
int start = 0;
int startTime = 0;
int s = 0; // settings
int c = 99; // customize
int t = 99; // time
int z = 0;
int timer = 1;
string cheat;
extern int whiteVictory;
extern int blackVictory;
extern int blackCheck;
extern int whiteCheck;
int readIntro = 0;

int main() {
    while (start == 0) {
        while (c == 99) {
            while (readIntro == 0) {
                std::cout << "Welcome to the game of Chess!" << std::endl << std::endl << "Here are the rules!" << std::endl;
                std::cout << "1. Capture the opponent's king to win the game!" << std::endl;
                std::cout << "   a. You will be notified if your opponent performs check, but your moves will NOT be restricted." << std::endl;
                std::cout << "   b. Click on the piece you want to move and click on the tile you want to place your piece." << std::endl;
                std::cout << "2. Running out of time will result in a loss." << std::endl;
                std::cout << "   a. Standard Timer: 15 minutes" << std::endl;
                std::cout << "3. You and your opponent are taking turns moving pieces, with WHITE side making the first move." << std::endl;
                std::cout << std::endl << "Would you like to modify the timer?" << std::endl;
                std::cout << "0 --> Yes" << std::endl << "1 --> No" << std::endl;
                readIntro = 1;
            }
            cin >> c;
            if (c == 0) {
                std::cout << "You have selected 'Yes'. Customizing timer." << std::endl;
                c = 1;
                break;
            }
            else if (c == 1) {
                std::cout << "You have selected 'No'. Standard rules have been applied." << std::endl;
                c = 1;
                startTime = 1;
                break;
            }
            else {
                std::cout << "Invalid argument. Try again." << std::endl;
                c = 99;
            }
        }
        while (startTime == 0) {
            std::cout << "Select a time limit." << std::endl;
            std::cout << "0 --> 5 Minutes" << std::endl << "1 --> 10 Minutes" << std::endl << "2 --> 15 Minutes" << std::endl;
            while (t == 99) {
                cin >> t;
                if (t == 0) {
                    std::cout << "You have selected 5 Minutes!" << std::endl;
                    startTime = 1;
                    z = 600; // z is time subtracted
                    break;
                }
                else if (t == 1) {
                    std::cout << "You have selected 10 Minutes!" << std::endl;
                    startTime = 1;
                    z = 300; // z is time subtracted
                    break;
                }
                else if (t == 2) {
                    std::cout << "You have selected 15 Minutes!" << std::endl;
                    startTime = 1;
                    z = 0;
                    break;
                }
                else {
                    std::cout << "Invalid argument. Try again." << std::endl;
                }
            }
        }
        std::cout << "Type anything to start game!" << std::endl;
        cin >> cheat;
        if (cheat == "whitecheat") {
            std::cout << "White cheat code activated!" << std::endl;
            for (int r = 6; r < boardSize; r = r + 1) { // Resets
                for (int c = 0; c < boardSize; c = c + 1) {
                    if (board[r][c] != "WK") {
                        board[r][c] = "WQ";
                    }
                }
            }
            std::cout << "The game has begun!" << std::endl;
            start = 1;
        }
        else if (cheat == "blackcheat") {
            std::cout << "Black cheat code activated!" << std::endl;
            for (int r = 0; r < boardSize - 6; r = r + 1) { // Resets
                for (int c = 0; c < boardSize; c = c + 1) {
                    if (board[r][c] != "BK") {
                        board[r][c] = "BQ";
                    }
                }
            }
            std::cout << "The game has begun!" << std::endl;
            start = 1;
        }
        else if (cheat == "omnicheat") {
            std::cout << "Omni cheat code activated!" << std::endl;
            for (int r = 0; r < boardSize - 6; r = r + 1) { // Resets
                for (int c = 0; c < boardSize; c = c + 1) {
                    if (board[r][c] != "BK") {
                        board[r][c] = "BQ";
                    }
                }
            }
            for (int r = 6; r < boardSize; r = r + 1) { // Resets
                for (int c = 0; c < boardSize; c = c + 1) {
                    if (board[r][c] != "WK") {
                        board[r][c] = "WQ";
                    }
                }
            }
            std::cout << "The game has begun!" << std::endl;
            start = 1;
        }
        else {
            std::cout << "The game has begun!" << std::endl;
            start = 1;
        }
    }
    while (start == 1) {
        sf::RenderWindow window(sf::VideoMode(boardSize * squareSize + windowWidth, boardSize * squareSize), "Chess");

        loadPieceTextures();

        sf::Font font;
        if (!font.loadFromFile("digital-7.ttf")) {
            cerr << "Missing font.\n";
            return -1;
        }

        vector<string> time;
        ifstream Time("time.txt");
        string str;
        while (Time >> str) {
            time.push_back(str);
        }
        Time.close();

        size_t whiteIndex = 0 + z;
        size_t blackIndex = 0 + z;

        sf::Clock clock;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed && (whiteVictory | blackVictory) == 1) { // Window cannot close until game is won
                    window.close();
                }
                else if (event.type == sf::Event::Closed) {
                    if (turn % 2 == 1) {
                        std::cout << "White has forfeited the match. Black wins!" << std::endl;
                    }
                    else {
                        std::cout << "Black has forfeited the match. White wins!" << std::endl;
                    }
                    window.close();
                }
                Movement(event, window, font);
            }

            if (clock.getElapsedTime().asSeconds() >= 1.f) {
                clock.restart(); // Refreshes event
                if (turn % 2 == 1 && timer == 1) {
                    if (whiteIndex + 1 < (time.size())) {
                        whiteIndex = whiteIndex + 1;
                    }
                    else {
                        cout << "White has run out of time!" << endl << "Black Wins!" << endl;
                        system("pause");
                        window.close();
                    }
                }
                else if (timer == 1) {
                    if (blackIndex + 1 < (time.size())) {
                        blackIndex = blackIndex + 1;
                    }
                    else {
                        cout << "Black has run out of time!" << endl << "White Wins!" << endl;
                        system("pause");
                        window.close();
                    }
                }
            }
            checkWhiteCheck();
            checkBlackCheck();

            window.clear(sf::Color(189, 174, 152)); // Background color
            drawBoard(window);
            drawTimers(window, font, time[whiteIndex], time[blackIndex]);  // Pass both times
            drawPieces(window);
            pieceIndicator(window, font);
            blackCheckBox(window, font);
            whiteCheckBox(window, font);
            drawWinScreen(window, font);
            window.display();

            if (whiteVictory == 1) {
                system("pause");
                window.close(); // Instead of window close, make the game pause
            }
            if (blackVictory == 1) {
                system("pause");
                window.close();
            }
        }
        return 0;
    }
}

