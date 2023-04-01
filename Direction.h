//
// Created by Vincent Allen on 4/1/23.
//

#ifndef INC_15PUZZLE_DIRECTION_H
#define INC_15PUZZLE_DIRECTION_H


#include <cassert>
#include <iostream>

#include "Random.h"

class Direction {
public:
    enum Type {
        up,
        down,
        left,
        right,
        max_directions,
    };

private:
    Type m_type {};
public:
    explicit Direction(Type type) : m_type{type} {}

    Type getType() {
        return m_type;
    }

    Direction operator-() const {
        switch(m_type) {
            case up: return Direction{down};
            case down: return Direction{up};
            case left: return Direction{right};
            case right: return Direction{left };
        }
        assert(0 && "unsupported direction was passed");
        return Direction{up};
    }

    friend std::ostream& operator<<(std::ostream& out, Direction dir) {
        switch (dir.getType()) {
            case Direction::up: return (out << "up");
            case Direction::down: return (out << "down");
            case Direction::left: return (out << "left");
            case Direction::right: return (out << "right");
            default: return (out << "Unknown direction");
        }
    }

    static Direction getRandomDirection() {
        Type direction {static_cast<Type>(Random::get(1, Type::max_directions - 1))};
        return Direction{direction};
    }
};


#endif //INC_15PUZZLE_DIRECTION_H
