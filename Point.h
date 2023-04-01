//
// Created by Vincent Allen on 4/1/23.
//

#ifndef INC_15PUZZLE_POINT_H
#define INC_15PUZZLE_POINT_H

#include "Direction.h"

class Point {
private:
    int m_x {};
    int m_y {};
public:
    Point(int x, int y): m_x{x}, m_y{y} {}

    bool operator==(const Point& point) const;
    bool operator!=(const Point& point) const;

    int getX() const;
    int getY() const;

    Point getAdjacentPoint(Direction::Type direction) const;
};


#endif //INC_15PUZZLE_POINT_H
