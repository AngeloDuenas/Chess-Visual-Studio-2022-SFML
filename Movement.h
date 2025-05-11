#pragma once
#include "Legality.h"
#include "AttackArray.h"
#include <iostream>
#include "Chessboard.h"
#include "Check.h"
#include "WinCon.h"
#include "Display.h"

int a, b;
bool selecting = false;
int selectRow = -1, selectCol = -1;
extern int turn;
int tester = 0;
int blackpawnPro = 0;
int whitepawnPro = 0;

bool movePiece(int oldr, int oldc, int newr, int newc) {
    system("cls");
    temp1 = oldr; temp2 = oldc;
    temp3 = newr; temp4 = newc;
    checkLegal();
    if (legal == 0) { // If move is illegal, then revert move
        std::cout << "Move was not legal. " << board[oldr][oldc] << " on Row " << temp1 + 1 << " Col " << temp2 + 1 <<  " cannot move to Row " << temp3 + 1 << " Col " << temp4 + 1 << "." << std::endl;
        if (turn % 2 == 1) {
            std::cout << "It is currently White's Turn." << std::endl;
        }
        else {
            std::cout << "It is currently Black's Turn." << std::endl;
        }
    }
    if (board[oldr][oldc] == "  ") { // nothing to move
        return false;
    }
    else if (legal == 1) {
        board[newr][newc] = board[oldr][oldc]; // place it at the target
        board[oldr][oldc] = "  "; // clear the old square
        return true;
    }
}

void Movement(const sf::Event& event, sf::RenderWindow& window, sf::Font& font) {
    if (event.type == sf::Event::MouseButtonPressed&& event.mouseButton.button == sf::Mouse::Left)
    {
        int c = event.mouseButton.x / squareSize;
        int r = event.mouseButton.y / squareSize;
        if (!selecting && board[r][c] != "  ") { // Select a piece
            selecting = true;
            selectRow = r;
            selectCol = c;
            pieceIndicator(window, font);
            window.display();
        }
        else if (selecting) { // Select a destination
            movePiece(selectRow, selectCol, r, c);
            if (legal == 1) {
                if (board[temp3][temp4] == "WP" && temp3 == 0) { // White pawn promotion
                    std::cout << "Select a Chess Piece:" << std::endl;
                    std::cout << "0: Bishop" << std::endl;
                    std::cout << "1: Knight" << std::endl;
                    std::cout << "2: Queen" << std::endl;
                    std::cout << "3: Rook" << std::endl;
                    std::cin >> a;
                    whitepawnPro = 1;
                    while (whitepawnPro == 1) {
                        if (a == 0) {
                            board[temp3][temp4] = "WB";
                            whitepawnPro = 0;
                            break;
                        }
                        else if (a == 1) {
                            board[temp3][temp4] = "WN";
                            whitepawnPro = 0;
                            break;
                        }
                        else if (a == 2) {
                            board[temp3][temp4] = "WQ";
                            whitepawnPro = 0;
                            break;
                        }
                        else if (a == 3) {
                            board[temp3][temp4] = "WR";
                            whitepawnPro = 0;
                            break;
                        }
                        else {
                            std::cout << "Invalid number. Try again." << std::endl;
                        }
                    }
                }
                
                if (board[temp3][temp4] == "BP" && temp3 == 7) { // Black pawn promotion
                    std::cout << "Select a Chess Piece:" << std::endl;
                    std::cout << "0: Bishop" << std::endl;
                    std::cout << "1: Knight" << std::endl;
                    std::cout << "2: Queen" << std::endl;
                    std::cout << "3: Rook" << std::endl;
                    blackpawnPro = 1;
                    while (blackpawnPro == 1) {
                        std::cin >> b;
                        if (b == 0) {
                            board[temp3][temp4] = "BB";
                            blackpawnPro = 0;
                            break;
                        }
                        else if (b == 1) {
                            board[temp3][temp4] = "BN";
                            blackpawnPro = 0;
                            break;
                        }
                        else if (b == 2) {
                            board[temp3][temp4] = "BQ";
                            blackpawnPro = 0;
                            break;
                        }
                        else if (b == 3) {
                            board[temp3][temp4] = "BR";
                            blackpawnPro = 0;
                            break;
                        }
                        else {
                            std::cout << "Invalid number. Try again." << std::endl;
                        }
                    }
                }

                updateAttackArray(); // Threaten Check
                system("cls");
                std::cout << "Turn " << turn << ":" << std::endl;
                turn = turn + 1;
                std::cout << board[temp3][temp4] << " moved from Row " << temp1 + 1 << " Col " << temp2 + 1 << " to Row " << temp3 +1 << " Col " << temp4 +1 << "!" << std::endl;
                std::cout << "Position Array:" << std::endl;
                for (int r = 0; r < boardSize; r = r + 1) {
                    for (int c = 0; c < boardSize; c = c + 1) {
                        std::cout << board[r][c] << " | ";
                    }
                    std::cout << '\n' << "---------------------------------------" << '\n';
                }
                if (turn % 2 == 0) {
                    std::cout << "White Attack Array:" << std::endl;
                    for (int r = 0; r < boardSize; r = r + 1) {
                        for (int c = 0; c < boardSize; c = c + 1) {
                            std::cout << whiteAttackBoard[r][c] << " | ";
                        }
                        std::cout << '\n' << "---------------------------------------" << '\n';
                    }
                }
                else {
                    std::cout << "Black Attack Array:" << std::endl;
                    for (int r = 0; r < boardSize; r = r + 1) {
                        for (int c = 0; c < boardSize; c = c + 1) {
                            std::cout << blackAttackBoard[r][c] << " | ";
                        }
                        std::cout << '\n' << "---------------------------------------" << '\n';
                    }
                }
                if (board[temp1][temp2] == "WK") {
                    firstWhiteKingMove = 0; // Turn off after first move
                }
                else if (board[temp1][temp2] == "BK") {
                    firstBlackKingMove = 0; // Turn off after first move
                }
                whiteWin();
                blackWin();
            }
            selecting = false;
        }
    }
}