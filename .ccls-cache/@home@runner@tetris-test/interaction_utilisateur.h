#ifndef INTERACTION_UTILISATEUR_H
#define INTERACTION_UTILISATEUR_H

int piece_choice(int turn_piece[4][4]);
int column_choice(int piece[4][4], int number_piece);
int draw_piece(int number_piece);
int draw_column(int column, int number_piece);
  
#endif