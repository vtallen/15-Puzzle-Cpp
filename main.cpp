#include <iostream>
#include <limits>

#include "Tile.h"
#include "Board.h"
#include "game_state_constants.h"

namespace UserInput {
    void getInput() {
        bool getting_user_input {true};
        while (getting_user_input) {
            std::cout << ">> ";
            char user_input {};
            std::cin >> user_input;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (user_input) {
                // slide tile up
                case 'w':
                    getting_user_input = false;
                    break;
                // slide tile left
                case 'a':
                    getting_user_input = false;
                    break;
                // slide tile down
                case 's':
                    getting_user_input = false;
                    break;
                // slide tile right
                case 'd':
                    getting_user_input = false;
                    break;
                // quit the game
                case 'q':
                    getting_user_input = false;
                    g_gameRunning = false;
                    break;
                default:
                    std::cout << "Invalid command" << '\n';
            }
            
        }
        
    }
}

int main()
{
    Board game_board{};
    while (g_gameRunning) {
        std::cout << game_board;
        UserInput::getInput();
    }
    return 0;
}