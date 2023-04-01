//
// Created by Vincent Allen on 4/1/23.
//

#include <cassert>

#include "Point.h"
#include "Direction.h"

bool Point::operator==(const Point& point) const{
    return (m_x == point.m_x) && (m_y == point.m_y);
}

bool Point::operator!=(const Point &point) const {
    return !(operator==(point));
}

int Point::getX() const {
    return m_x;
}

int Point::getY() const {
    return m_y;
}

Point Point::getAdjacentPoint(Direction::Type direction) const{
    switch (direction) {
        case Direction::up: return Point{m_x, m_y + 1};
        case Direction::down: return Point{m_x, m_y - 1};
        case Direction::left: return Point{m_x + 1, m_y};
        case Direction::right: return Point{m_x - 1, m_y};
        default: assert(0 && "An invalid direction was passed in");
    }
}


