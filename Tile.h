#ifndef INC_15PUZZLE_TILE_H
#define INC_15PUZZLE_TILE_H

/*
 * Goal: Be able to display individual tiles on the screen.

Our game board is a 4×4 grid of tiles that can slide around.
 Therefore, it will be useful to have a Tile class that represents one of the numbered tiles on our 4×4 grid or the missing tile. Each tile should be able to:

    Be given a number or be set as the missing tile
    Determine whether it is the missing tile.
    Draw to the console with the appropriate spacing (so the tiles will line up when the board is displayed).
    See the sample output below for an example indicating how tiles should be spaced.
 */
#include <iostream>

class Tile {
private:
    int m_number {0};
    bool m_is_missing_tile {false};
public:
    Tile() = delete;
    explicit Tile(int number) : m_number{number}, m_is_missing_tile{(number == 0)} {}

    bool isEmpty() const;
    int getNum() const;
    friend std::ostream& operator<<(std::ostream& out, Tile tile);


};


#endif //INC_15PUZZLE_TILE_H
