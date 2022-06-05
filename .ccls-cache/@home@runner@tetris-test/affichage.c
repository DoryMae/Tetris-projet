#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "gestion_jeu.h"

//this function displays a 14*10 2D table (the game grid)
void affiche_grille_jeu(int tab[14][10]){
  if(tab==NULL){
    exit(0);
  }
  printf(" ");
	for(int i=1; i<=10; i++){
		printf("%c ", i+'A'-1);
	
	}
	printf("\n");
  for (int x=4;x<14;x++){
    for (int y=0;y<10;y++){
      if (tab[x][y]==0){
        printf("| "); 
      }
      else{
        printf("|#"); 
      }
    }
    printf("|");
  printf("\n");
  }
}

//this function displays a 4*4 2D table (a piece)
void affiche_piece_jeu(int tab[4][4]){
  if(tab==NULL){
    exit(0);
  }
  for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
      if (tab[i][j]==0){
        printf("| "); 
      }
      else{
        printf("|#"); 
      }
    }
  printf("|");
  printf("\n");
  }
}