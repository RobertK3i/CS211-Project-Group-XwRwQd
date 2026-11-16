# CS211-Project-Group-XwRwQd

CS 211 Group Project - 2048 Game and Luhn Validation

## About the Project

For this project we made two programs in C++. One is a playable 2048 game and the other checks 16-digit numbers using the Luhn algorithm.

The 2048 game uses a 5x5 board where you move tiles around and combine matching numbers to try and reach 2048. We added all four movement directions, scoring, a move counter, random tiles, and the ability to save and load a game. It also checks when you've won or when there aren't any moves left.

The Luhn program takes a 16-digit number and checks if it passes the checksum. It checks for the correct length and makes sure there aren't any letters, spaces, or symbols before doing the math. You can keep entering numbers until you decide to quit.

Passing the Luhn check doesn't mean the card number is real, just that it passes the calculation.

## Group Members

- Robert Killough - RobertK3i
- Kaden McKinley - Kaden121
- Trey Jones - Regentaniken23

Class: CS 211, Monday/Wednesday

## Running the Programs

Both programs were written in C++17 and can be compiled using g++.

### 2048

The game uses `main.cpp`, `2048_helper.cpp`, and `2048_helper.h`.

Open a terminal in the folder containing those files.

Compile:

`g++ -std=c++17 main.cpp 2048_helper.cpp -o game2048.exe`

Run:

`.\game2048.exe`

The controls are pretty simple:

- `u` - Up
- `d` - Down
- `l` - Left
- `r` - Right
- `s` - Save
- `o` - Load
- `n` - New game
- `h` - Help
- `e` - Exit

The game keeps track of your score and successful moves. Saving creates a `savegame.txt` file in the working directory with the board, score, and move count. Saving again overwrites the previous file.

### Luhn

The Luhn files are in the `luhn` folder: `main.cpp`, `luhn.cpp`, and `luhn.h`.

Open a terminal in that folder.

Compile:

`g++ -std=c++17 main.cpp luhn.cpp -o luhn.exe`

Run:

`.\luhn.exe`

Enter a 16-digit number and the program will tell you whether it passes or fails the checksum. It also shows the calculated sum. Enter `q` to quit.

## Testing

We tested both programs using OnlineGDB.

For 2048, we tested moving in all four directions, merging, scoring, saving/loading, starting new games, invalid commands, and exiting. All 10 basic gameplay tests passed.

For Luhn, we tested numbers that should pass and fail, leading zeros, incorrect lengths, letters, spaces, and quitting. All 8 tests passed.

We put the testing results in `tests.md`.

## Who Did What

We split the project into six checkpoints, with each of us taking two.

- Robert - Repository setup and save/load (1 and 4)
- Kaden - Left movement and Luhn validation (2 and 5)
- Trey - Remaining 2048 movement, game controls, and final documentation/testing (3 and 6)

We also helped test and review the programs as we went. GitHub was used to keep track of our changes and combine everything into the final project.

More details about contributions are in `contributions.md`.

## Notes

The 2048 game is console-based, so there's no graphical interface. Random tiles currently spawn as 2, and the save system only keeps one game at a time.

Both programs are separate and can be compiled and run on their own.
