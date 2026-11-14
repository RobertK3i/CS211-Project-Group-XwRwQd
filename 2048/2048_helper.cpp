#include "2048_helper.h"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Slide and merge a row or column
void slide_and_merge(int line[5], int& score)
{
    int nonzero[5] = {0};
    int count = 0;

    // Move numbers together
    for (int i = 0; i < 5; i++)
    {
        if (line[i] != 0)
            nonzero[count++] = line[i];
    }

    // Merge matching numbers
    int merged[5] = {0};
    int pos = 0;

    for (int i = 0; i < count; i++)
    {
        if (i + 1 < count &&
            nonzero[i] == nonzero[i + 1])
        {
            merged[pos] = nonzero[i] * 2;

            // Increase score
            score += merged[pos];

            pos++;
            i++;
        }
        else
        {
            merged[pos++] = nonzero[i];
        }
    }

    // Copy values back
    for (int i = 0; i < 5; i++)
        line[i] = merged[i];
}

// MOVE LEFT
void move_left(int board[][5], int numrows, int& score)
{
    for (int r = 0; r < numrows; r++)
    {
        int line[5];

        for (int c = 0; c < 5; c++)
            line[c] = board[r][c];

        slide_and_merge(line, score);

        for (int c = 0; c < 5; c++)
            board[r][c] = line[c];
    }
}

// MOVE RIGHT
void move_right(int board[][5], int numrows, int& score)
{
    for (int r = 0; r < numrows; r++)
    {
        int line[5];

        for (int c = 0; c < 5; c++)
            line[c] = board[r][4 - c];

        slide_and_merge(line, score);

        for (int c = 0; c < 5; c++)
            board[r][4 - c] = line[c];
    }
}

// MOVE UP
void move_up(int board[][5], int numrows, int& score)
{
    for (int c = 0; c < 5; c++)
    {
        int line[5];

        for (int r = 0; r < numrows; r++)
            line[r] = board[r][c];

        slide_and_merge(line, score);

        for (int r = 0; r < numrows; r++)
            board[r][c] = line[r];
    }
}

// MOVE DOWN
void move_down(int board[][5], int numrows, int& score)
{
    for (int c = 0; c < 5; c++)
    {
        int line[5];

        for (int r = 0; r < numrows; r++)
            line[r] = board[numrows - 1 - r][c];

        slide_and_merge(line, score);

        for (int r = 0; r < numrows; r++)
            board[numrows - 1 - r][c] = line[r];
    }
}

// PRINT BOARD
void print_board(int board[][5], int numrows)
{
    cout << "\n-----------------------------------------\n";

    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            cout << "|" << setw(7);

            if (board[r][c] == 0)
                cout << " ";
            else
                cout << board[r][c];
        }

        cout << "|\n-----------------------------------------\n";
    }

    cout << endl;
}

// INSERT RANDOM TILE
void insert_random(int board[][5], int numrows)
{
    int emptyCount = 0;

    // Count empty cells
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] == 0)
                emptyCount++;
        }
    }

    if (emptyCount == 0)
        return;

    // Choose a random empty position
    int chosen = rand() % emptyCount;

    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] == 0)
            {
                if (chosen == 0)
                {
                    board[r][c] = 2;
                    return;
                }

                chosen--;
            }
        }
    }
}

// WIN CONDITION
bool check_win(int board[][5], int numrows)
{
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] >= 2048)
                return true;
        }
    }

    return false;
}

// LOSS CONDITION
bool check_loss(int board[][5], int numrows)
{
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            // Empty cell exists
            if (board[r][c] == 0)
                return false;

            // Horizontal merge possible
            if (c < 4 &&
                board[r][c] == board[r][c + 1])
                return false;

            // Vertical merge possible
            if (r + 1 < numrows &&
                board[r][c] == board[r + 1][c])
                return false;
        }
    }

    return true;
}

// SAVE GAME
bool save_game(int board[][5], int score, int moves)
{
    ofstream file("savegame.txt");

    if (!file)
        return false;

    file << "CS211_2048_V1\n";
    file << score << ' ' << moves << '\n';

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (c > 0)
                file << ' ';

            file << board[r][c];
        }

        file << '\n';
    }

    file.close();

    return !file.fail();
}

// LOAD GAME
bool load_game(int board[][5], int& score, int& moves)
{
    ifstream file("savegame.txt");

    if (!file)
        return false;

    // Check file version
    string marker;

    if (!(file >> marker) ||
        marker != "CS211_2048_V1")
        return false;

    // Read score and moves
    int newScore, newMoves;

    if (!(file >> newScore >> newMoves) ||
        newScore < 0 || newMoves < 0)
        return false;

    // Read into temporary board
    int temp[5][5];

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (!(file >> temp[r][c]))
                return false;

            int tile = temp[r][c];

            // Reject negative values and invalid tiles
            if (tile < 0 ||
                (tile != 0 &&
                (tile < 2 ||
                (tile & (tile - 1)) != 0)))
                return false;
        }
    }

    // Reject extra content
    string extra;

    if (file >> extra)
        return false;

    if (file.bad())
        return false;

    // Restore values only after validation succeeds
    score = newScore;
    moves = newMoves;

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            board[r][c] = temp[r][c];
        }
    }

    return true;
}
