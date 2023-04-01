//
// Created by Vincent Allen on 4/1/23.
//

#include "Board.h"
#include "game_state_constants.h"

std::ostream& operator<<(std::ostream& out, Board board) {
    // Wipe the screen
    for (int i {}; i < g_consoleLines; ++i) {
        std::cout << '\n';
    }

    for (int i {}; i <= 3; ++i) {
        for (int j {}; j <= 3; j++) {
            std::cout << board.m_game_board[i][j];
        }
        std::cout << '\n';
    }
    return out;
}