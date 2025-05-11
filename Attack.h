#pragma once
#include "PositionArray.h"
#include "Movement.h"
#include "AttackArray.h"

extern int turn;

void updateAttackArray(){
    for (int r = 0; r < boardSize; r = r + 1) { // Resets
        for (int c = 0; c < boardSize; c = c + 1) {
            whiteAttackBoard[r][c] = "  ";
        }
    }
    for (int r = 0; r < boardSize; r = r + 1) { // Resets
        for (int c = 0; c < boardSize; c = c + 1) {
            blackAttackBoard[r][c] = "  ";
        }
    }
    if (turn % 2 == 1) { // White Turn
        for (int r = 0; r < boardSize; r = r + 1) { // White Attack Board
            for (int c = 0; c < boardSize; c = c + 1) {
                if (board[r][c] == "WP") { // White pawn
                    if (c == 0) {
                        whiteAttackBoard[r - 1][c + 1] = "WA";
                    }
                    else if (c == 7) {
                        whiteAttackBoard[r - 1][c - 1] = "WA";
                    }
                    else {
                        whiteAttackBoard[r - 1][c + 1] = "WA";
                        whiteAttackBoard[r - 1][c - 1] = "WA";
                    }
                }
                else if (board[r][c] == "WR") { // White rook
                    for (int q = r - 1; q >= 0; q--) { // Up
                        if (board[q][c] != "  ") {
                            whiteAttackBoard[q][c] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[q][c] = "WA";
                        }
                    }
                    for (int q = r + 1; q <= 7; q++) { // Down
                        if (board[q][c] != "  ") {
                            whiteAttackBoard[q][c] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[q][c] = "WA";
                        }
                    }
                    for (int q = c - 1; q >= 0; q = q - 1) { // Left
                        if (board[r][q] != "  ") {
                            whiteAttackBoard[r][q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r][q] = "WA";
                        }
                    }
                    for (int q = c + 1; q <= 7; q = q + 1) { // Right
                        if (board[r][q] != "  ") {
                            whiteAttackBoard[r][q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r][q] = "WA";
                        }
                    }
                }
                else if (board[r][c] == "WN") { // White knight
                    if (c == 0) {
                        if (r == 0) {
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                        }
                        else if (r == 1) {
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                        }
                        else if (r == 6) {
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                        }
                        else if (r == 7) {
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                        }
                        else {
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                        }
                    }
                    else if (c == 1) {
                        if (r == 0) {
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                        }
                        else if (r == 1) {
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                        }
                        else if (r == 6) {
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                        }
                        else if (r == 7) {
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                        }
                        else {
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                        }
                    }
                    else if (c == 6) {
                        if (r == 0){
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                        }
                        if (r == 1) {
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                            whiteAttackBoard[r - 1][c - 2] = "WA";

                        }
                        if (r == 6) {
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                            whiteAttackBoard[r - 1][c - 2] = "WA";
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                        }
                        if (r == 7) {
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                            whiteAttackBoard[r - 1][c - 2] = "WA";
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                        }
                        else {
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                            whiteAttackBoard[r - 1][c - 2] = "WA";
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                        }
                    }
                    else if (c == 7) {
                        if (r == 0) {
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                        }
                        if (r == 1) {
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                            whiteAttackBoard[r - 1][c - 2] = "WA";
                        }
                        if (r == 6) {
                            whiteAttackBoard[r - 1][c - 2] = "WA";
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                        }
                        if (r == 7) {
                            whiteAttackBoard[r - 1][c - 2] = "WA";
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                        }
                        else {
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                            whiteAttackBoard[r - 1][c - 2] = "WA";
                        }
                    }
                    else {
                        if (r == 0) {
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                        }
                        if (r == 1) {
                            whiteAttackBoard[r - 1][c - 2] = "WA";
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                        }
                        if (r == 6) {
                            whiteAttackBoard[r - 1][c - 2] = "WA"; // Add if statements for around the edges
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                        }
                        if (r == 7) {
                            whiteAttackBoard[r - 1][c - 2] = "WA"; // Add if statements for around the edges
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                        }
                        else {
                            whiteAttackBoard[r - 1][c - 2] = "WA"; // Add if statements for around the edges
                            whiteAttackBoard[r - 1][c + 2] = "WA";
                            whiteAttackBoard[r + 1][c - 2] = "WA";
                            whiteAttackBoard[r + 1][c + 2] = "WA";
                            whiteAttackBoard[r - 2][c - 1] = "WA";
                            whiteAttackBoard[r - 2][c + 1] = "WA";
                            whiteAttackBoard[r + 2][c - 1] = "WA";
                            whiteAttackBoard[r + 2][c + 1] = "WA";
                        }
                    }
                }
                else if (board[r][c] == "WB") { // White bishop (add for statements)
                    for (int q = 1; q <= std::min(r, c); q++) { // Up Left
                        if (board[r - q][c - q] != "  ") {
                            whiteAttackBoard[r - q][c - q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r - q][c - q] = "WA";
                        }
                    }
                    for (int q = 1; q <= std::min(r, 7 - c); q = q + 1) { // Up Right
                        if (board[r - q][c + q] != "  ") {
                            whiteAttackBoard[r - q][c + q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r - q][c + q] = "WA";
                        }
                    }
                    for (int q = 1; q <= (std::min(7 - r, c)); q = q + 1) { // Down Left
                        if (board[r + q][c - q] != "  ") {
                            whiteAttackBoard[r + q][c - q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r + q][c - q] = "WA";
                        }
                    }
                    for (int q = 1; q <= std::min(7 - r, 7 - c); q = q + 1) { // Down Right
                        if (board[r + q][c + q] != "  ") {
                            whiteAttackBoard[r + q][c + q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r + q][c + q] = "WA";
                        }
                    }
                }
                else if (board[r][c] == "WQ") { // White queen (add for statements)
                    for (int q = r - 1; q >= 0; q--) { // Up
                        if (board[q][c] != "  ") {
                            whiteAttackBoard[q][c] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[q][c] = "WA";
                        }
                    }
                    for (int q = r + 1; q <= 7; q++) { // Down
                        if (board[q][c] != "  ") {
                            whiteAttackBoard[q][c] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[q][c] = "WA";
                        }
                    }
                    for (int q = c - 1; q >= 0; q = q - 1) { // Left
                        if (board[r][q] != "  ") {
                            whiteAttackBoard[r][q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r][q] = "WA";
                        }
                    }
                    for (int q = c + 1; q <= 7; q = q + 1) { // Right
                        if (board[r][q] != "  ") {
                            whiteAttackBoard[r][q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r][q] = "WA";
                        }
                    }
                    for (int q = 1; q <= std::min(r, c); q++) { // Up Left
                        if (board[r - q][c - q] != "  ") {
                            whiteAttackBoard[r - q][c - q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r - q][c - q] = "WA";
                        }
                    }
                    for (int q = 1; q <= std::min(r, 7 - c); q = q + 1) { // Up Right
                        if (board[r - q][c + q] != "  ") {
                            whiteAttackBoard[r - q][c + q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r - q][c + q] = "WA";
                        }
                    }
                    for (int q = 1; q <= (std::min(7 - r, c)); q = q + 1) { // Down Left
                        if (board[r + q][c - q] != "  ") {
                            whiteAttackBoard[r + q][c - q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r + q][c - q] = "WA";
                        }
                    }
                    for (int q = 1; q <= std::min(7 - r, 7 - c); q = q + 1) { // Down Right
                        if (board[r + q][c + q] != "  ") {
                            whiteAttackBoard[r + q][c + q] = "WA";
                            break;
                        }
                        else {
                            whiteAttackBoard[r + q][c + q] = "WA";
                        }
                    }
                }
                else if (board[r][c] == "WK") { // White king
                    if (c == 0) {
                        if (r == 0) {
                            whiteAttackBoard[r][c + 1] = "WA";
                            whiteAttackBoard[r + 1][c] = "WA";
                            whiteAttackBoard[r + 1][c + 1] = "WA";
                        }
                        else if (r == 7) {
                            whiteAttackBoard[r - 1][c] = "WA";
                            whiteAttackBoard[r - 1][c + 1] = "WA";
                            whiteAttackBoard[r][c + 1] = "WA";
                        }
                        else {
                            whiteAttackBoard[r - 1][c] = "WA";
                            whiteAttackBoard[r - 1][c + 1] = "WA";
                            whiteAttackBoard[r][c + 1] = "WA";
                            whiteAttackBoard[r + 1][c] = "WA";
                            whiteAttackBoard[r + 1][c + 1] = "WA";
                        }
                    }
                    else if (c == 7) {
                        if (r == 0) {
                            whiteAttackBoard[r][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c] = "WA";
                        }
                        else if (r == 7) {
                            whiteAttackBoard[r - 1][c - 1] = "WA"; // Add if statements for around the edges
                            whiteAttackBoard[r - 1][c] = "WA";
                            whiteAttackBoard[r][c - 1] = "WA";
                        }
                        else {
                            whiteAttackBoard[r - 1][c - 1] = "WA"; // Add if statements for around the edges
                            whiteAttackBoard[r - 1][c] = "WA";
                            whiteAttackBoard[r][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c] = "WA";
                        }
                    }
                    else if (r == 0) {
                        if (c == 0) {
                            whiteAttackBoard[r][c + 1] = "WA";
                            whiteAttackBoard[r + 1][c] = "WA";
                            whiteAttackBoard[r + 1][c + 1] = "WA";
                        }
                        else if (c == 7) {
                            whiteAttackBoard[r][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c] = "WA";

                        }
                        else {
                            whiteAttackBoard[r][c - 1] = "WA";
                            whiteAttackBoard[r][c + 1] = "WA";
                            whiteAttackBoard[r + 1][c - 1] = "WA";
                            whiteAttackBoard[r + 1][c] = "WA";
                            whiteAttackBoard[r + 1][c + 1] = "WA";
                        }
                    }
                    else if (r == 7) {
                        if (c == 0) {
                            whiteAttackBoard[r - 1][c] = "WA";
                            whiteAttackBoard[r - 1][c + 1] = "WA";
                            whiteAttackBoard[r][c + 1] = "WA";
                        }
                        else if (c == 7) {
                            whiteAttackBoard[r - 1][c] = "WA";
                            whiteAttackBoard[r - 1][c - 1] = "WA";
                            whiteAttackBoard[r][c - 1] = "WA";
                        }
                        else {
                            whiteAttackBoard[r - 1][c - 1] = "WA"; // Add if statements for around the edges
                            whiteAttackBoard[r - 1][c] = "WA";
                            whiteAttackBoard[r - 1][c + 1] = "WA";
                            whiteAttackBoard[r][c - 1] = "WA";
                            whiteAttackBoard[r][c + 1] = "WA";
                        }
                    }
                    else {
                        whiteAttackBoard[r - 1][c - 1] = "WA"; // Add if statements for around the edges
                        whiteAttackBoard[r - 1][c] = "WA";
                        whiteAttackBoard[r - 1][c + 1] = "WA";
                        whiteAttackBoard[r][c - 1] = "WA";
                        whiteAttackBoard[r][c + 1] = "WA";
                        whiteAttackBoard[r + 1][c - 1] = "WA";
                        whiteAttackBoard[r + 1][c] = "WA";
                        whiteAttackBoard[r + 1][c + 1] = "WA";
                    }
                }
            }
        }
    }
    else { // Black Turn
        for (int r = 0; r < boardSize; r = r + 1) { // Black Attack Board
            for (int c = 0; c < boardSize; c = c + 1) {
                if (board[r][c] == "BP") {
                    if (c == 0) {
                        blackAttackBoard[r + 1][c + 1] = "BA";
                    }
                    if (c == 7) {
                        blackAttackBoard[r + 1][c - 1] = "BA";
                    }
                    else if (c != 0 && c != 7) {
                        blackAttackBoard[r + 1][c + 1] = "BA";
                        blackAttackBoard[r + 1][c - 1] = "BA";
                    }
                }
                else if (board[r][c] == "BR") {
                    for (int q = r - 1; q >= 0; q--) { // Up
                        if (board[q][c] != "  ") {
                            blackAttackBoard[q][c] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[q][c] = "BA";
                        }
                    }
                    for (int q = r + 1; q <= 7; q++) { // Down
                        if (board[q][c] != "  ") {
                            blackAttackBoard[q][c] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[q][c] = "BA";
                        }
                    }
                    for (int q = c - 1; q >= 0; q = q - 1) { // Left
                        if (board[r][q] != "  ") {
                            blackAttackBoard[r][q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r][q] = "BA";
                        }
                    }
                    for (int q = c + 1; q <= 7; q = q + 1) { // Right
                        if (board[r][q] != "  ") {
                            blackAttackBoard[r][q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r][q] = "BA";
                        }
                    }
                }
                else if (board[r][c] == "BN") {
                    if (c == 0) {
                        if (r == 0) {
                            blackAttackBoard[r + 2][c + 1] = "BA";
                            blackAttackBoard[r + 1][c + 2] = "BA";
                        }
                        else if (r == 1) {
                            blackAttackBoard[r + 2][c + 1] = "BA";
                            blackAttackBoard[r + 1][c + 2] = "BA";
                            blackAttackBoard[r - 1][c + 2] = "BA";
                        }
                        else if (r == 6) {
                            blackAttackBoard[r - 2][c + 1] = "BA";
                            blackAttackBoard[r - 1][c + 2] = "BA";
                            blackAttackBoard[r + 1][c + 2] = "BA";
                        }
                        else if (r == 7) {
                            blackAttackBoard[r - 2][c + 1] = "BA";
                            blackAttackBoard[r - 1][c + 2] = "BA";
                        }
                        else {
                            blackAttackBoard[r + 2][c + 1] = "BA";
                            blackAttackBoard[r - 2][c + 1] = "BA";
                            blackAttackBoard[r + 1][c + 2] = "BA";
                            blackAttackBoard[r - 1][c + 2] = "BA";
                        }
                    }
                    else if (c == 1) {
                        if (r == 0) {
                            blackAttackBoard[r + 2][c + 1] = "BA";
                            blackAttackBoard[r + 1][c + 2] = "BA";
                            blackAttackBoard[r + 2][c - 1] = "BA";
                        }
                        else if (r == 1) {
                            blackAttackBoard[r + 2][c + 1] = "BA";
                            blackAttackBoard[r + 1][c + 2] = "BA";
                            blackAttackBoard[r + 2][c - 1] = "BA";
                            blackAttackBoard[r - 1][c + 2] = "BA";
                        }
                        else if (r == 6) {
                            blackAttackBoard[r + 1][c + 2] = "BA";
                            blackAttackBoard[r - 2][c + 1] = "BA";
                            blackAttackBoard[r - 1][c + 2] = "BA";
                            blackAttackBoard[r - 2][c - 1] = "BA";
                        }
                        else if (r == 7) {
                            blackAttackBoard[r - 2][c + 1] = "BA";
                            blackAttackBoard[r - 1][c + 2] = "BA";
                            blackAttackBoard[r - 2][c - 1] = "BA";
                        }
                        else {
                            blackAttackBoard[r + 2][c + 1] = "BA";
                            blackAttackBoard[r - 2][c + 1] = "BA";
                            blackAttackBoard[r + 1][c + 2] = "BA";
                            blackAttackBoard[r - 1][c + 2] = "BA";
                            blackAttackBoard[r + 2][c - 1] = "BA";
                            blackAttackBoard[r - 2][c - 1] = "BA";
                        }
                    }
                    else if (c == 6) {
                        if (r == 0) {
                            blackAttackBoard[r + 2][c - 1] = "BA";
                            blackAttackBoard[r + 1][c - 2] = "BA";
                            blackAttackBoard[r + 2][c + 1] = "BA";
                        }
                        if (r == 1) {
                            blackAttackBoard[r + 2][c - 1] = "BA";
                            blackAttackBoard[r + 1][c - 2] = "BA";
                            blackAttackBoard[r + 2][c + 1] = "BA";
                            blackAttackBoard[r - 1][c - 2] = "BA";

                        }
                        if (r == 6) {
                            blackAttackBoard[r - 2][c - 1] = "BA";
                            blackAttackBoard[r - 1][c - 2] = "BA";
                            blackAttackBoard[r - 2][c + 1] = "BA";
                            blackAttackBoard[r + 1][c - 2] = "BA";
                        }
                        if (r == 7) {
                            blackAttackBoard[r - 2][c - 1] = "BA";
                            blackAttackBoard[r - 1][c - 2] = "BA";
                            blackAttackBoard[r - 2][c + 1] = "BA";
                        }
                        else {
                            blackAttackBoard[r + 2][c - 1] = "BA";
                            blackAttackBoard[r - 2][c - 1] = "BA";
                            blackAttackBoard[r + 1][c - 2] = "BA";
                            blackAttackBoard[r - 1][c - 2] = "BA";
                            blackAttackBoard[r + 2][c + 1] = "BA";
                            blackAttackBoard[r - 2][c + 1] = "BA";
                        }
                    }
                    else if (c == 7) {
                        if (r == 0) {
                            blackAttackBoard[r + 2][c - 1] = "BA";
                            blackAttackBoard[r + 1][c - 2] = "BA";
                        }
                        if (r == 1) {
                            blackAttackBoard[r + 2][c - 1] = "BA";
                            blackAttackBoard[r + 1][c - 2] = "BA";
                            blackAttackBoard[r - 1][c - 2] = "BA";
                        }
                        if (r == 6) {
                            blackAttackBoard[r - 1][c - 2] = "BA";
                            blackAttackBoard[r - 2][c - 1] = "BA";
                            blackAttackBoard[r + 1][c - 2] = "BA";
                        }
                        if (r == 7) {
                            blackAttackBoard[r - 1][c - 2] = "BA";
                            blackAttackBoard[r - 2][c - 1] = "BA";
                        }
                        else {
                            blackAttackBoard[r + 2][c - 1] = "BA";
                            blackAttackBoard[r - 2][c - 1] = "BA";
                            blackAttackBoard[r + 1][c - 2] = "BA";
                            blackAttackBoard[r - 1][c - 2] = "BA";
                        }
                    }
                    else {
                        if (r == 0) {
                            blackAttackBoard[r + 1][c - 2] = "BA";
                            blackAttackBoard[r + 1][c + 2] = "BA";
                            blackAttackBoard[r + 2][c - 1] = "BA";
                            blackAttackBoard[r + 2][c + 1] = "BA";
                        }
                        if (r == 1) {
                            blackAttackBoard[r - 1][c - 2] = "BA";
                            blackAttackBoard[r - 1][c + 2] = "BA";
                            blackAttackBoard[r + 1][c - 2] = "BA";
                            blackAttackBoard[r + 1][c + 2] = "BA";
                            blackAttackBoard[r + 2][c - 1] = "BA";
                            blackAttackBoard[r + 2][c + 1] = "BA";
                        }
                        if (r == 6) {
                            blackAttackBoard[r - 1][c - 2] = "BA"; // Add if statements for around the edges
                            blackAttackBoard[r - 1][c + 2] = "BA";
                            blackAttackBoard[r + 1][c - 2] = "BA";
                            blackAttackBoard[r + 1][c + 2] = "BA";
                            blackAttackBoard[r - 2][c - 1] = "BA";
                            blackAttackBoard[r - 2][c + 1] = "BA";
                        }
                        if (r == 7) {
                            blackAttackBoard[r - 1][c - 2] = "BA"; // Add if statements for around the edges
                            blackAttackBoard[r - 1][c + 2] = "BA";
                            blackAttackBoard[r - 2][c - 1] = "BA";
                            blackAttackBoard[r - 2][c + 1] = "BA";
                        }
                        else {
                            blackAttackBoard[r - 1][c - 2] = "BA"; // Add if statements for around the edges
                            blackAttackBoard[r - 1][c + 2] = "BA";
                            blackAttackBoard[r + 1][c - 2] = "BA";
                            blackAttackBoard[r + 1][c + 2] = "BA";
                            blackAttackBoard[r - 2][c - 1] = "BA";
                            blackAttackBoard[r - 2][c + 1] = "BA";
                            blackAttackBoard[r + 2][c - 1] = "BA";
                            blackAttackBoard[r + 2][c + 1] = "BA";
                        }
                    }
                }
                else if (board[r][c] == "BB") {
                    for (int q = 1; q <= std::min(r, c); q++) { // Up Left
                        if (board[r - q][c - q] != "  ") {
                            blackAttackBoard[r - q][c - q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r - q][c - q] = "BA";
                        }
                    }
                    for (int q = 1; q <= std::min(r, 7 - c); q = q + 1) { // Up Right
                        if (board[r - q][c + q] != "  ") {
                            blackAttackBoard[r - q][c + q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r - q][c + q] = "BA";
                        }
                    }
                    for (int q = 1; q <= (std::min(7 - r, c)); q = q + 1) { // Down Left
                        if (board[r + q][c - q] != "  ") {
                            blackAttackBoard[r + q][c - q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r + q][c - q] = "BA";
                        }
                    }
                    for (int q = 1; q <= std::min(7 - r, 7 - c); q = q + 1) { // Down Right
                        if (board[r + q][c + q] != "  ") {
                            blackAttackBoard[r + q][c + q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r + q][c + q] = "BA";
                        }
                    }
                }
                else if (board[r][c] == "BK") {
                    if (c == 0) {
                        if (r == 0) {
                            blackAttackBoard[r][c + 1] = "BA";
                            blackAttackBoard[r + 1][c] = "BA";
                            blackAttackBoard[r + 1][c + 1] = "BA";
                        }
                        else if (r == 7) {
                            blackAttackBoard[r - 1][c] = "BA";
                            blackAttackBoard[r - 1][c + 1] = "BA";
                            blackAttackBoard[r][c + 1] = "BA";
                        }
                        else {
                            blackAttackBoard[r - 1][c] = "BA";
                            blackAttackBoard[r - 1][c + 1] = "BA";
                            blackAttackBoard[r][c + 1] = "BA";
                            blackAttackBoard[r + 1][c] = "BA";
                            blackAttackBoard[r + 1][c + 1] = "BA";
                        }
                    }
                    else if (c == 7) {
                        if (r == 0) {
                            blackAttackBoard[r][c - 1] = "BA";
                            blackAttackBoard[r + 1][c - 1] = "BA";
                            blackAttackBoard[r + 1][c] = "BA";
                        }
                        else if (r == 7) {
                            blackAttackBoard[r - 1][c - 1] = "BA"; // Add if statements for around the edges
                            blackAttackBoard[r - 1][c] = "BA";
                            blackAttackBoard[r][c - 1] = "BA";
                        }
                        else {
                            blackAttackBoard[r - 1][c - 1] = "BA"; // Add if statements for around the edges
                            blackAttackBoard[r - 1][c] = "BA";
                            blackAttackBoard[r][c - 1] = "BA";
                            blackAttackBoard[r + 1][c - 1] = "BA";
                            blackAttackBoard[r + 1][c] = "BA";
                        }
                    }
                    else if (r == 0) {
                        if (c == 0) {
                            blackAttackBoard[r][c + 1] = "BA";
                            blackAttackBoard[r + 1][c] = "BA";
                            blackAttackBoard[r + 1][c + 1] = "BA";
                        }
                        else if (c == 7) {
                            blackAttackBoard[r][c - 1] = "BA";
                            blackAttackBoard[r + 1][c - 1] = "BA";
                            blackAttackBoard[r + 1][c] = "BA";

                        }
                        else {
                            blackAttackBoard[r][c - 1] = "BA";
                            blackAttackBoard[r][c + 1] = "BA";
                            blackAttackBoard[r + 1][c - 1] = "BA";
                            blackAttackBoard[r + 1][c] = "BA";
                            blackAttackBoard[r + 1][c + 1] = "BA";
                        }
                    }
                    else if (r == 7) {
                        if (c == 0) {
                            blackAttackBoard[r - 1][c] = "BA";
                            blackAttackBoard[r - 1][c + 1] = "BA";
                            blackAttackBoard[r][c + 1] = "BA";
                        }
                        else if (c == 7) {
                            blackAttackBoard[r - 1][c] = "BA";
                            blackAttackBoard[r - 1][c - 1] = "BA";
                            blackAttackBoard[r][c - 1] = "BA";
                        }
                        else {
                            blackAttackBoard[r - 1][c - 1] = "BA"; // Add if statements for around the edges
                            blackAttackBoard[r - 1][c] = "BA";
                            blackAttackBoard[r - 1][c + 1] = "BA";
                            blackAttackBoard[r][c - 1] = "BA";
                            blackAttackBoard[r][c + 1] = "BA";
                        }
                    }
                    else {
                        blackAttackBoard[r - 1][c - 1] = "BA"; // Add if statements for around the edges
                        blackAttackBoard[r - 1][c] = "BA";
                        blackAttackBoard[r - 1][c + 1] = "BA";
                        blackAttackBoard[r][c - 1] = "BA";
                        blackAttackBoard[r][c + 1] = "BA";
                        blackAttackBoard[r + 1][c - 1] = "BA";
                        blackAttackBoard[r + 1][c] = "BA";
                        blackAttackBoard[r + 1][c + 1] = "BA";
                    }
                }
                else if (board[r][c] == "BQ") {
                    for (int q = r - 1; q >= 0; q--) { // Up
                        if (board[q][c] != "  ") {
                            blackAttackBoard[q][c] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[q][c] = "BA";
                        }
                    }
                    for (int q = r + 1; q <= 7; q++) { // Down
                        if (board[q][c] != "  ") {
                            blackAttackBoard[q][c] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[q][c] = "BA";
                        }
                    }
                    for (int q = c - 1; q >= 0; q = q - 1) { // Left
                        if (board[r][q] != "  ") {
                            blackAttackBoard[r][q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r][q] = "BA";
                        }
                    }
                    for (int q = c + 1; q <= 7; q = q + 1) { // Right
                        if (board[r][q] != "  ") {
                            blackAttackBoard[r][q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r][q] = "BA";
                        }
                    }
                    for (int q = 1; q <= std::min(r, c); q++) { // Up Left
                        if (board[r - q][c - q] != "  ") {
                            blackAttackBoard[r - q][c - q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r - q][c - q] = "BA";
                        }
                    }
                    for (int q = 1; q <= std::min(r, 7 - c); q = q + 1) { // Up Right
                        if (board[r - q][c + q] != "  ") {
                            blackAttackBoard[r - q][c + q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r - q][c + q] = "BA";
                        }
                    }
                    for (int q = 1; q <= (std::min(7 - r, c)); q = q + 1) { // Down Left
                        if (board[r + q][c - q] != "  ") {
                            blackAttackBoard[r + q][c - q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r + q][c - q] = "BA";
                        }
                    }
                    for (int q = 1; q <= std::min(7 - r, 7 - c); q = q + 1) { // Down Right
                        if (board[r + q][c + q] != "  ") {
                            blackAttackBoard[r + q][c + q] = "BA";
                            break;
                        }
                        else {
                            blackAttackBoard[r + q][c + q] = "BA";
                        }
                    }
                }
            }
        }
    }
}