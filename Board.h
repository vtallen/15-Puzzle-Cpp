//
// Created by Vincent Allen on 4/1/23.
//
/*
 * Goal: Create a solved board (4×4 grid of tiles) and display it on the screen.

Define a Board class that will represent 4×4 grid of tiles. A newly created Board object should be in the solved state. To display the board, first print g_consoleLines (defined in code snippet below) empty lines and then print the board itself. Doing so will ensure that any prior output is pushed out of view so that only the current board is visible on the console.

Why initiate the board in the solved state? When you buy a physical version of these puzzles, the puzzles typically start in the solved state -- you have to manually mix them up (by sliding tiles around) before trying to solve them. We will mimic that process in our program (we’ll do the mixing up in a future step).

 */
#ifndef INC_15PUZZLE_BOARD_H
#define INC_15PUZZLE_BOARD_H


#include "Tile.h"

class Board {
private:
    Tile m_game_board[4][4] = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 0}};
public:
    Board() = default;

    friend std::ostream& operator<<(std::ostream& out, Board board);
};


#endif //INC_15PUZZLE_BOARD_H
