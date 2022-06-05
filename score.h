#ifndef SCORE_H
#define SCORE_H

typedef struct {
  char name[256];
  int player_score;
}Players;
int score_joueur(int nmbre_ligne_effacees, int a);
void classement(Players player1);
#endif