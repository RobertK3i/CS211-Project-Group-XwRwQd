#ifndef HELPER_2048_H
#define HELPER_2048_H

// Movement functions
void move_left(int board[][5], int numrows, int& score);
void move_right(int board[][5], int numrows, int& score);
void move_up(int board[][5], int numrows, int& score);
void move_down(int board[][5], int numrows, int& score);

// Board functions
void print_board(int board[][5], int numrows = 5);
void insert_random(int board[][5], int numrows = 5);

// Win and loss functions
bool check_win(int board[][5], int numrows = 5);
bool check_loss(int board[][5], int numrows = 5);

// Save and load functions
bool save_game(int board[][5], int score, int moves);
bool load_game(int board[][5], int& score, int& moves);

#endif
