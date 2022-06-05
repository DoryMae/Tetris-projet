#ifndef GESTION_JEU_H
#define GESTION_JEU_H

int add_piece(int piece[4][4], int column, int line, int game_board[14][10]);
void subtract_piece(int piece[4][4], int column, int line, int game_board[14][10]);
int suppression_line(int game_board[14][10]);
void go_down_piece(int piece[4][4], int column, int game_board[14][10]);
int game_over(int game_board[14][10]);

#endif