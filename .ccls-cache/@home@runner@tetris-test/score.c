#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "score.h"

//This function adds the score the player has made in this round to the score he has made since the beginning of the game.
int score_joueur(int numbre_lines_delected,int a){
  if(numbre_lines_delected==1){
    a=a+40;
  }
  else if(numbre_lines_delected==2){
    a=a+100;
  }
  else if(numbre_lines_delected==3){
    a=a+300;
  }
  else if(numbre_lines_delected==4){
    a=a+1200;
  }
  return a;
}

//This function saves the best score and the name of the player who made it in text files
void classement(Players player1){
  int a;
  char tab_score[1000];
  char tab_name[100];
  char name_best_player[1000];
  char tab[1000];
  FILE *name=NULL;
  name=fopen("name.txt","r+");
  if (name==NULL){
    printf("Ouverture du fichier impossible\n");
    printf("Code d'erreur =%d \n", errno);
    printf("Message d'erreur = %s \n", strerror(errno));
    exit(1);
  }
  FILE *high_score=NULL;
  high_score = fopen("best_player.txt","r+");
  if (high_score==NULL){
    printf("Ouverture du fichier impossible\n");
    printf("Code d'erreur =%d \n", errno);
    printf("Message d'erreur = %s \n", strerror(errno));
    exit(1);
  }
  fgets(tab, 999, high_score);
  a = atoi(tab);
  if(player1.player_score > a){
    high_score = fopen("best_player.txt","w");
    name = fopen("name.txt","w");
    sprintf(tab_score,"%d", player1.player_score);
    sprintf(tab_name, "%s", player1.name);
    fputs(tab_score, high_score);
    fputs(tab_name, name);
    printf("Le meilleur score est de %d et il a été fait par %s",player1.player_score, player1.name);
  }
  else{
    fscanf(name,"%s", name_best_player);
    printf("Le meilleur score est toujours celui de %s avec %d", name_best_player, a);
  }
  fclose(high_score);
  fclose(name);
}
