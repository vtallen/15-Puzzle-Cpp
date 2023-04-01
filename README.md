# 15-Puzzle-Cpp
15 Puzzle - C++ - learncpp.com
---
This is my solution for the chapter 14 project on learncpp.com
---
## Design exercise
---
### A) What are the top-level things that your program needs to do? Here are a few to get you started:
* Display the game board
* Crate a randomized, valid board
* Detect when the board is in a winning state
User things:
* Get commands from the user
* Move the tiles on screen

### What primary classes or namespaces will you use to implement the items outlined in Step 1? Also, what will your main() function do?
#### main()
* Contains the main loop, gets input from the user continuously, then prints the updated board
#### class Board
* Will contain a matrix filled with Tiles
Functions:
* move tile
* randomize
* is_solved

