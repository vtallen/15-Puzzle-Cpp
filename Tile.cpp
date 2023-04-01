//
// Created by Vincent Allen on 4/1/23.
//

#include "Tile.h"

bool Tile::isEmpty() const {
    return m_is_missing_tile;
}

int Tile::getNum() const {
    return m_number;
}

std::ostream &operator<<(std::ostream &out, Tile tile) {
    if (tile.m_number == 0) {
        std::cout << "    ";
    } else if (tile.m_number <= 9) {
        std::cout << "  " << tile.m_number << " ";
    } else if (tile.m_number >= 10){
        std::cout << " " << tile.m_number << " ";
    }

    return out;
}
