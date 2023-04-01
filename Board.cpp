//
// Created by Vincent Allen on 4/1/23.
//

#include "Board.h"
#include "Point.h"
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

bool Board::moveTile(Direction direction) {
    bool empty_tile_found {false};
    bool is_valid_swap {false};
    for (int y{}; y < 4; ++y) {
        for (int x{}; x < 4; ++x) {
            if (m_game_board[y][x].isEmpty()) {
                Point empty_tile_point {x, y};
                Point adjacent_tile_point {empty_tile_point.getAdjacentPoint(direction.getType())};
                if ((adjacent_tile_point.getX() <= 3) && (adjacent_tile_point.getX() >= 0) && (adjacent_tile_point.getY() <= 3) && (adjacent_tile_point.getY() >= 0)) {
                    std::swap(m_game_board[y][x], m_game_board[adjacent_tile_point.getY()][adjacent_tile_point.getX()]);
                    is_valid_swap = true;
                }
                empty_tile_found = true;
                break;
            }
        }
        if (empty_tile_found) break;
    }
    return is_valid_swap;
}

void Board::shuffle() {
    constexpr int num_moves {1000};
    int accumulator {};
    for (int i {0}; i < num_moves; ++i) {
        accumulator++;
        if (!(moveTile(Direction::getRandomDirection()))) {
            --i;
        }
    }
    std::cout << accumulator;
}

bool Board::isSolved() {
    bool is_solved {true};
    for (int y{}; y < 4; ++y) {
        for (int x{}; x < 4; ++x) {
            if (m_game_board[y][x] != m_solved_board[y][x]) {
                is_solved = false;
            }
        }
    }

    return is_solved;
}
