//Code Tested And Verified! 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "2048_helper.h"
using namespace std;

// Display the scoreboard and game board
void display_game(int board[][5], int score, int moves)
{
    int highest = 0;

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] > highest)
                highest = board[r][c];
        }
    }

    cout << "Score: " << score << endl;
    cout << "Successful moves: " << moves << endl;
    cout << "Highest tile: " << highest << endl;

    print_board(board);
}

// Start a new game
void new_game(int board[][5], int& score, int& moves)
{
    score = 0;
    moves = 0;

    // Clear the board
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
            board[r][c] = 0;
    }

    // Add two starting tiles
    insert_random(board);
    insert_random(board);
}

// Display instructions
void print_help()
{
    cout << "\nCommands:\n";
    cout << "  u = Up         d = Down\n";
    cout << "  l = Left       r = Right\n";
    cout << "  s = Save       o = Open/load\n";
    cout << "  n = New game   h = Help\n";
    cout << "  e = Exit\n";

    cout << "Combine equal tiles to reach 2048.\n";
    cout << "Only moves that change the board count.\n";
    cout << "Saving overwrites savegame.txt ";
    cout << "in the working directory.\n\n";
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int size = 5;
    int board[5][5] = {};
    int score = 0;
    int moves = 0;
    bool winAnnounced = false;

    // Create starting board
    new_game(board, score, moves);

    cout << "2048 - 5x5\n";
    cout << "Load saved game? (y/n): ";

    char loadChoice;

    if (!(cin >> loadChoice))
        return 0;

    // Load a previous game
    if (loadChoice == 'y' || loadChoice == 'Y')
    {
        if (load_game(board, score, moves))
        {
            cout << "Game loaded successfully!\n";
            winAnnounced = check_win(board, size);
        }
        else
        {
            cout << "Load failed. Starting game unchanged.\n";
        }
    }

    // Initial display
    display_game(board, score, moves);

    if (winAnnounced)
    {
        cout << "You reached 2048! ";
        cout << "You may continue playing.\n";
    }

    if (check_loss(board, size))
    {
        cout << "GAME OVER! No moves remain.\n";
        cout << "Use s, o, n, h, or e.\n";
    }

    char choice;

    // Main game loop
    while (true)
    {
        cout << "Enter command (u,d,l,r,s,o,n,h,e): ";

        if (!(cin >> choice))
            break;

        // EXIT
        if (choice == 'e')
            break;

        // HELP
        if (choice == 'h')
        {
            print_help();
            continue;
        }

        // SAVE
        if (choice == 's')
        {
            if (save_game(board, score, moves))
                cout << "Saved to savegame.txt.\n";
            else
                cout << "Save failed: could not write savegame.txt.\n";

            continue;
        }

        // LOAD
        if (choice == 'o')
        {
            if (load_game(board, score, moves))
            {
                cout << "Game loaded successfully!\n";

                winAnnounced = check_win(board, size);

                display_game(board, score, moves);

                if (winAnnounced)
                {
                    cout << "You reached 2048! ";
                    cout << "You may continue playing.\n";
                }

                if (check_loss(board, size))
                {
                    cout << "GAME OVER! No moves remain.\n";
                    cout << "Use s, o, n, h, or e.\n";
                }
            }
            else
            {
                cout << "Load failed. Current game unchanged.\n";
            }

            continue;
        }

        // NEW GAME
        if (choice == 'n')
        {
            cout << "Start a new game and lose ";
            cout << "unsaved progress? (y/n): ";

            char confirm;

            if (!(cin >> confirm))
                break;

            if (confirm == 'y' || confirm == 'Y')
            {
                new_game(board, score, moves);
                winAnnounced = false;

                display_game(board, score, moves);
            }
            else
            {
                cout << "New game canceled.\n";
            }

            continue;
        }

        // CHECK VALID DIRECTION
        if (choice != 'u' && choice != 'd' &&
            choice != 'l' && choice != 'r')
        {
            cout << "Invalid command. Press h for help.\n";
            continue;
        }

        // CHECK FOR GAME OVER
        if (check_loss(board, size))
        {
            cout << "GAME OVER! No more movements.\n";
            cout << "Use s, o, n, h, or e.\n";
            continue;
        }

        // SAVE BOARD BEFORE MOVING
        int oldBoard[5][5];

        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                oldBoard[r][c] = board[r][c];
            }
        }

        // MOVE TILES
        if (choice == 'u')
            move_up(board, size, score);
        else if (choice == 'd')
            move_down(board, size, score);
        else if (choice == 'l')
            move_left(board, size, score);
        else
            move_right(board, size, score);

        // CHECK IF BOARD CHANGED
        bool changed = false;

        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                if (oldBoard[r][c] != board[r][c])
                {
                    changed = true;
                }
            }
        }

        // COUNT SUCCESSFUL MOVE
        if (changed)
        {
            moves++;

            // Add exactly one random tile
            insert_random(board, size);
        }
        else
        {
            cout << "No tiles moved.\n";
        }

        // DISPLAY UPDATED GAME
        display_game(board, score, moves);

        // WIN CONDITION
        if (!winAnnounced && check_win(board, size))
        {
            cout << "YOU WIN! You reached 2048!\n";
            cout << "You may continue playing.\n";

            winAnnounced = true;
        }

        // LOSS CONDITION
        if (check_loss(board, size))
        {
            cout << "GAME OVER! No moves remain.\n";
            cout << "Use s, o, n, h, or e.\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
