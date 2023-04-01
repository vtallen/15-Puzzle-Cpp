#include <iostream>
#include <limits>

#include "Tile.h"
#include "Board.h"
#include "Direction.h"
#include "Point.h"
#include "game_state_constants.h"

namespace UserInput
{
    bool isValidCommand(char ch)
    {
        return ch == 'w'
               || ch == 'a'
               || ch == 's'
               || ch == 'd'
               || ch == 'q';
    }

    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char getCharacter()
    {
        char operation{};
        std::cin >> operation;
        ignoreLine(); // remove any extraneous input
        return operation;
    }

    char getCommandFromUser()
    {
        char ch{};
        while (!isValidCommand(ch))
            ch = getCharacter();

        return ch;
    }

    Direction charToDirection(char ch)
    {
        switch (ch)
        {
            case 'w': return Direction{ Direction::up };
            case 's': return Direction{ Direction::down };
            case 'a': return Direction{ Direction::left };
            case 'd': return Direction{ Direction::right };
            default: break;
        }

        assert(0 && "Unsupported direction was passed!");
    }
};

int main()
{
    Board board{};
    board.shuffle();
    std::cout << board;

    std::cout << ">> ";
    while (true)
    {
        char ch{ UserInput::getCommandFromUser() };

        // Handle non-direction commands
        if (ch == 'q')
        {
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        // Handle direction commands
//        Direction dir{ UserInput::charToDirection(ch) };
        board.moveTile(UserInput::charToDirection(ch));

        std::cout << board;

        if (board.isSolved()) break;
    }

    std::cout << "\n\nYOU WON!";

    return 0;
}
