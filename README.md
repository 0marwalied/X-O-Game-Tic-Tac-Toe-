# X O Game (Tic Tac Toe)

This is a simple **Tic Tac Toe** game implemented in C++. It allows two players to play against each other on a 3x3 grid. The game alternates between players (X and O) until one player wins or the game ends in a draw.

## Features
- **Two-player mode**: Play with a friend on the same device.
- **Interactive interface**: The game displays the grid and prompts players for their moves.
- **Win/draw detection**: The game automatically detects when a player wins or if the game ends in a draw.
- **Play again option**: After the game ends, players can choose to play again or exit.

## How to Play
1. **Choose your symbol**: At the start, you can choose to play as **X** or **O**.
2. **Make your move**: When it's your turn, enter the number corresponding to the position on the grid where you want to place your symbol.
3. **Win or draw**: The game will announce the winner if a player gets three of their symbols in a row (horizontally, vertically, or diagonally). If all positions are filled without a winner, the game ends in a draw.
4. **Play again**: After the game ends, you can choose to play again or exit.

## Game Grid Layout
The grid is numbered from **1 to 9** as follows:

| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |

To make a move, enter the number of the position where you want to place your symbol.

## How to Run the Game
1. **Compile the code**: Use a C++ compiler (e.g., `g++`) to compile the program:
   ```bash
   g++ -o xo_game xo_game.cpp
