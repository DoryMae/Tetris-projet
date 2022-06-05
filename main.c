#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "affichage.h"
#include "gestion_jeu.h"
#include "interaction_utilisateur.h"
#include "score.h"


unsigned long getTimeMicroSec() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (1000000 * tv.tv_sec) + tv.tv_usec;
}

int main() {
  int game_board[14][10] = {0};
  int column;
  int piece[4][4];
  int result = 0;
  int number_piece = 0;
  int number_line_deleted = 0;
  int difficulty;
  int booleen=1;
  int boole;
  Players gamer;
  //We first ask for the player's name and the difficulty he/she wishes to play
  printf("Quel est ton nom ?\n");
  scanf("%s", gamer.name);
  printf("Quel difficulté voulez_vous \n1:facile \n2:moyen \n3:difficile\n");
  scanf("%d", &difficulty);
  while((booleen == 0) || (difficulty<1)|| (difficulty>3)){
        printf("Erreur: entrez une difficultée entre 1 et 3.\nQuelle orientation voulez vous ?");
        boole=scanf("%d", &difficulty);
        while(fgetc(stdin)!='\n'){};
        if(boole == 1){
          booleen = 1;
        }
      }
  printf("Voici la grille de jeu :\n");
  affiche_grille_jeu(game_board);
  //The while loop allows the player to choose the desired room orientations and columns
  while (result == 0) { 
    unsigned long time1 = getTimeMicroSec();
    number_piece = piece_choice(piece);
    column = column_choice(piece, number_piece);
    unsigned long time2 = getTimeMicroSec();
    unsigned long gap = (time2 - time1) / 1000000;
    printf("Vous avez passé %ld secondes pour choisir\n", gap);
    //the if's allow you to randomly draw the direction and the column if the game time has elapsed and this according to the difficulty
    if (difficulty==1){ 
      if (gap > 30) {
        number_piece=draw_piece(number_piece);
        column=draw_column(column, number_piece);
        }
    }
    else if (difficulty==2){
      if (gap > 20) {
        number_piece=draw_piece(number_piece);
        column=draw_column(column, number_piece);
        }
    }
    else {
      if (gap > 10) {
        number_piece=draw_piece(number_piece);
        column=draw_column(column, number_piece);
        }
    }
    go_down_piece(piece, column, game_board);
    number_line_deleted = suppression_line(game_board);
    affiche_grille_jeu(game_board);
    result = game_over(game_board);
    gamer.player_score = score_joueur(number_line_deleted, gamer.player_score);
    printf("%d \n ", gamer.player_score);
  }
  printf("Game over !");
  classement(gamer);
  return 0;
}