#pragma once
#include "PositionArray.h"
#include "Movement.h"
#include "AttackArray.h"
#include "Attack.h"

int legal = 1;
int temp1, temp2, temp3, temp4;
int rowdiff, coldiff;
int whiteRow = 6;
int blackRow = 1;
extern int turn;
int firstWhiteKingMove = 1;
int firstBlackKingMove = 1;
int queenSideWhiteRook = 1;
int queenSideBlackRook = 1;
int kingSideWhiteRook = 1;
int kingSideBlackRook = 1;
int gap = 0;
int whiteenpassant, blackenpassant = 0;
int dpmcol; // double pawn move column

void checkLegal() {
	rowdiff = temp3 - temp1;
	coldiff = temp4 - temp2;
	std::string piece = board[temp1][temp2];
	std::string capture = board[temp3][temp4];

	if (rowdiff == 0 && coldiff == 0) { // Clicked on self
		legal = 0;
	}
	else {
		if (piece == "WP") { // White Pawn
			if (coldiff == 0 && (rowdiff == -1 || rowdiff == -2) && temp1 == whiteRow && capture == "  " && (temp3 <= 7) && (temp4 <= 7) && board[temp1 - 1][temp2] == "  ") { // First turn double square
				legal = 1;
				whiteenpassant = 1;
			}
			else if (coldiff == 0 && rowdiff == -1 && capture == "  " && (temp3 <= 7) && (temp4 <= 7)) { // Single square
				legal = 1;
			}
			else if (capture != "  " && rowdiff == -1 && abs(coldiff) == 1 && (temp3 <= 7) && (temp4 <= 7)) { // Capture
				legal = 1;
			}
			else if (board[temp3 + 1][temp4] == "BP" && blackenpassant == 1 && temp4 == dpmcol && (temp3 <= 7) && (temp4 <= 7)) { // En Passant
				legal = 1;
				std::cout << board[temp3 + 1][temp4] << std::endl;
				board[temp3 + 1][temp4] = "  ";
			}
			else if (board[temp3 + 1][temp4] == "BP" && blackenpassant == 1 && temp4 == dpmcol && (temp3 <= 7) && (temp4 <= 7)) { // En Passant
				legal = 1;
				board[temp3 + 1][temp4] = "  ";
			}
			else {
				legal = 0;
			}

		}
		if (piece == "BP") { // Black Pawn
			if (coldiff == 0 && (rowdiff == 1 || rowdiff == 2) && temp1 == blackRow && capture == "  " && (temp3 <= 7) && (temp4 <= 7) && board[temp1 + 1][temp2] == "  ") {
				legal = 1;
				blackenpassant = 1;
				dpmcol = temp4;
			}
			else if (coldiff == 0 && rowdiff == 1 && capture == "  " && (temp3 <= 7) && (temp4 <= 7)) {
				legal = 1;
			}
			else if (capture != "  " && rowdiff == 1 && abs(coldiff) == 1 && (temp3 <= 7) && (temp4 <= 7)) { // Capture
				legal = 1;
			}
			else if (board[temp3 - 1][temp4] == "WP" && whiteenpassant == 1 && temp4 == dpmcol && (temp3 <= 7) && (temp4 <= 7)) {
				legal = 1;
				board[temp3 - 1][temp4] = "  ";
			}
			else if (board[temp3 - 1][temp4] == "WP" && whiteenpassant == 1 && temp4 == dpmcol && (temp3 <= 7) && (temp4 <= 7)) {
				legal = 1;
				board[temp3 - 1][temp4] = "  ";
			}
			else {
				legal = 0;
			}
		}
		if (piece == "WN" || piece == "BN") { // White Knight and Black Knight
			if ((abs(coldiff) == 1 && abs(rowdiff) == 2) || (abs(coldiff) == 2 && abs(rowdiff) == 1) && (temp3 <= 7) && (temp4 <= 7)) {
				legal = 1;
			}
			else {
				legal = 0;
			}
		}
		if (piece == "WB" || piece == "BB") { // White Bishop and Black Bishop
			gap = 0;
			if (abs(coldiff) == abs(rowdiff) && (temp3 <= 7) && (temp4 <= 7)) {
				for (int i = 1; i < abs(rowdiff); i++) { // i is the rows between newrow and oldrow
					gap = 1;
					// I'm thinking if oldcol > newcol, then read from left to right increasing. Same for row. Reverse. Sequence should be until gap = 0;
					if (temp3 > temp1 && temp4 > temp2) { // Down Right
						if (board[temp1 + i][temp2 + i] == "  ") { //Read if space between if empty
							legal = 1;
						}
						else { // If space is not empty, then declare illegal
							legal = 0; // .. but what about capturing? lol
							break;
						}
					}
					else if (temp3 > temp1 && temp2 > temp4) { // Down Left
						if (board[temp1 + i][temp2 - i] == "  ") { //Read if space between if empty
							legal = 1;
						}
						else { // If space is not empty, then declare illegal
							legal = 0;
							break;
						}
					}
					else if (temp1 > temp3 && temp4 > temp2) { // Up Right
						if (board[temp1 - i][temp2 + i] == "  ") { //Read if space between if empty
							legal = 1;
						}
						else { // If space is not empty, then declare illegal
							legal = 0;
							break;
						}
					}
					else if (temp1 > temp3 && temp2 > temp4) { // Up Left
						if (board[temp1 - i][temp2 - i] == "  ") { //Read if space between if empty
							legal = 1;
						}
						else { // If space is not empty, then declare illegal
							legal = 0;
							break;
						}
					}
				}
				if (gap == 0) { // No gap, for loop was skipped
					legal = 1;
				}
			}
			else {
				legal = 0;
			}
		}
		if (piece == "WQ" || piece == "BQ") {
			if (abs(coldiff) == abs(rowdiff) && (temp3 <= 7) && (temp4 <= 7)) { // Bishop behavior
				gap = 0;
				for (int i = 1; i < abs(rowdiff); i++) { // i is the rows between newrow and oldrow
					gap = 1;
					// I'm thinking if oldcol > newcol, then read from left to right increasing. Same for row. Reverse. Sequence should be until gap = 0;
					if (temp3 > temp1 && temp4 > temp2) { // Down Right
						if (board[temp1 + i][temp2 + i] == "  ") { //Read if space between if empty
							legal = 1;
						}
						else { // If space is not empty, then declare illegal
							legal = 0;
							break;
						}
					}
					else if (temp3 > temp1 && temp2 > temp4) { // Down Left
						if (board[temp1 + i][temp2 - i] == "  ") { //Read if space between if empty
							legal = 1;
						}
						else { // If space is not empty, then declare illegal
							legal = 0;
							break;
						}
					}
					else if (temp1 > temp3 && temp4 > temp2) { // Up Right
						if (board[temp1 - i][temp2 + i] == "  ") { //Read if space between if empty
							legal = 1;
						}
						else { // If space is not empty, then declare illegal
							legal = 0;
							break;
						}
					}
					else if (temp1 > temp3 && temp2 > temp4) { // Up Left
						std::cout << board[temp1 - i][temp2 - i] << std::endl;
						if (board[temp1 - i][temp2 - i] == "  ") { //Read if space between if empty
							legal = 1;
						}
						else { // If space is not empty, then declare illegal
							legal = 0;
							break;
						}
					}
				}
				if (gap == 0) { // No gap, for loop was skipped
					legal = 1;
				}
			}
			else if ((coldiff == 0 || rowdiff == 0) && (temp3 <= 7) && (temp4 <= 7)) { // Rook behavior
				gap = 0;
				for (int i = 1; i < abs(rowdiff); i++) { // Vertical
					gap = 1;
					if (temp1 > temp3 && board[temp1 - i][temp2] == "  ") { // Up
						legal = 1;
					}
					else if (temp3 > temp1 && board[temp1 + i][temp2] == "  ") { // Down
						legal = 1;
					}
					else {
						legal = 0;
						break;
					}
				}
				for (int i = 1; i < abs(coldiff); i++) { // Horizontal
					gap = 1;
					if (temp2 > temp4 && board[temp1][temp2 - i] == "  ") { // Left
						legal = 1;
					}
					else if (temp4 > temp2 && board[temp1][temp2 + i] == "  ") { // Right
						legal = 1;
					}
					else {
						legal = 0;
						break;
					}
				}
				if (gap == 0) { // No gap, for loop was skipped
					legal = 1;
				}
				if (temp1 == 7 && temp2 == 0 && board[7][0] == "WR") { // Queen Side White Rook
					queenSideWhiteRook = 0;
				}
				else if (temp1 == 7 && temp2 == 7 && board[7][7] == "WR") { // King Side White Rook
					kingSideWhiteRook = 0;
				}
				else if (temp1 == 0 && temp2 == 0 && board[0][0] == "BR") { // Queen Side White Rook
					queenSideBlackRook = 0;
				}
				else if (temp1 == 0 && temp2 == 7 && board[0][7] == "BR") { // King Side White Rook
					kingSideBlackRook = 0;
				}
			}
			else {
				legal = 0;
			}

		}
		if (piece == "WR" || piece == "BR") {
			if ((coldiff == 0 || rowdiff == 0) && (temp3 <= 7) && (temp4 <= 7)) {
				gap = 0;
				for (int i = 1; i < abs(rowdiff); i++) { // Vertical
					gap = 1;
					if (temp1 > temp3 && board[temp1 - i][temp2] == "  ") { // Up
						legal = 1;
					}
					else if (temp3 > temp1 && board[temp1 + i][temp2] == "  ") { // Down
						legal = 1;
					}
					else {
						legal = 0;
						break;
					}
				}
				for (int i = 1; i < abs(coldiff); i++) { // Horizontal
					gap = 1;
					if (temp2 > temp4 && board[temp1][temp2 - i] == "  ") { // Left
						legal = 1;
					}
					else if (temp4 > temp2 && board[temp1][temp2 + i] == "  ") { // Right
						legal = 1;
					}
					else {
						legal = 0;
						break;
					}
				}
				if (gap == 0) { // No gap, for loop was skipped
					legal = 1;
				}
				if (temp1 == 7 && temp2 == 0 && board[7][0] == "WR") { // Queen Side White Rook
					queenSideWhiteRook = 0;
				}
				else if (temp1 == 7 && temp2 == 7 && board[7][7] == "WR") { // King Side White Rook
					kingSideWhiteRook = 0;
				}
				else if (temp1 == 0 && temp2 == 0 && board[0][0] == "BR") { // Queen Side White Rook
					queenSideBlackRook = 0;
				}
				else if (temp1 == 0 && temp2 == 7 && board[0][7] == "BR") { // King Side White Rook
					kingSideBlackRook = 0;
				}
			}
			else {
				legal = 0;
			}
		}
		if (piece == "WK" || piece == "BK") {
			if ((abs(coldiff) <= 1 && abs(rowdiff) <= 1) && (temp3 <= 7) && (temp4 <= 7)) {
				legal = 1;
			}
			else {
				legal = 0;
			}
			if (temp3 == 7 && temp4 == 2 && firstWhiteKingMove == 1 && queenSideWhiteRook == 1 && board[7][1] == "  " && board[7][2] == "  " && board[7][3] == "  ") { // White Queen Side Castling
				legal = 1;
				board[7][3] = "WR";
				board[7][0] = "  ";
			}
			if (temp3 == 7 && temp4 == 6 && firstWhiteKingMove == 1 && kingSideWhiteRook == 1 && board[7][5] == "  " && board[7][6] == "  ") { // White King Side Castling
				legal = 1;
				board[7][5] = "WR";
				board[7][7] = "  ";
			}
			if (temp3 == 0 && temp4 == 2 && firstBlackKingMove == 1 && queenSideBlackRook == 1 && board[0][1] == "  " && board[0][2] == "  " && board[0][3] == "  ") { // Black Queen Side Castling
				legal = 1;
				board[0][3] = "BR";
				board[0][0] = "  ";
			}
			if (temp3 == 0 && temp4 == 6 && firstBlackKingMove == 1 && kingSideBlackRook == 1 && board[0][5] == "  " && board[0][6] == "  ") { // Black King Side Castling
				legal = 1;
				board[0][5] = "BR";
				board[0][7] = "  ";
			}
		}
		if (turn % 2 == 1) { // White Turn
			if (piece == "BN" || piece == "BB" || piece == "BQ" || piece == "BR" || piece == "BK" || piece == "BP") {
				legal = 0;
			}
			if (capture == "WN" || capture == "WB" || capture == "WQ" || capture == "WR" || capture == "WK" || capture == "WP") {
				legal = 0;
			}
		}
		else { // Black Turn
			if (piece == "WN" || piece == "WB" || piece == "WQ" || piece == "WR" || piece == "WK" || piece == "WP") {
				legal = 0;
			}
			if (capture == "BN" || capture == "BB" || capture == "BQ" || capture == "BR" || capture == "BK" || capture == "BP") {
				legal = 0;
			}
		}
		if (board[temp3][temp4] == "WP" || board[temp3][temp4] == "BP" && legal == 1) {
			dpmcol = temp4;
		}
		if (whiteenpassant == 1 && legal == 1 && turn % 2 == 0) { // Black's turn
				whiteenpassant = 0; // Black does not perform en passant
		}
		else if (blackenpassant == 1 && legal == 1 && turn % 2 == 1) {
				blackenpassant = 0; // White does not perform en passant
		}
		
	}
}