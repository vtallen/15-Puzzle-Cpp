#ifndef INC_15PUZZLE_TILE_H
#define INC_15PUZZLE_TILE_H

#include <iostream>

class Tile {
private:
    int m_number {0};
    bool m_is_missing_tile {false};
public:
    Tile(int number) : m_number{number}, m_is_missing_tile{(number == 0)} {} //NOLINT

    bool operator==(const Tile& tile) const;
    bool operator!=(const Tile& tile) const;
    friend std::ostream& operator<<(std::ostream& out, Tile tile);

    bool isEmpty() const;
    int getNum() const;

};


#endif //INC_15PUZZLE_TILE_H
