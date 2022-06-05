#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "interaction_utilisateur.h"
#include "affichage.h"

int O[4][4]={{0,0,0,0},{0,0,0,0},{1,1,0,0},{1,1,0,0}};
int I1[4][4]={{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
int I2[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,1,1,1}};
int L1[4][4]={{0,0,0,0},{1,0,0,0},{1,0,0,0},{1,1,0,0}};
int L2[4][4]={{0,0,0,0},{0,0,0,0},{0,0,1,0},{1,1,1,0}};
int L3[4][4]={{0,0,0,0},{1,1,0,0},{0,1,0,0},{0,1,0,0}};
int L4[4][4]={{0,0,0,0},{0,0,0,0},{1,1,1,0},{1,0,0,0}};
int J1[4][4]={{0,0,0,0},{0,1,0,0},{0,1,0,0},{1,1,0,0}};
int J2[4][4]={{0,0,0,0},{0,0,0,0},{1,1,1,0},{0,0,1,0}};
int J3[4][4]={{0,0,0,0},{1,1,0,0},{1,0,0,0},{1,0,0,0}};
int J4[4][4]={{0,0,0,0},{0,0,0,0},{1,0,0,0},{1,1,1,0}};
int Z1[4][4]={{0,0,0,0},{0,0,0,0},{1,1,0,0},{0,1,1,0}};
int Z2[4][4]={{0,0,0,0},{0,1,0,0},{1,1,0,0},{1,0,0,0}};
int S1[4][4]={{0,0,0,0},{0,0,0,0},{0,1,1,0},{1,1,0,0}};
int S2[4][4]={{0,0,0,0},{1,0,0,0},{1,1,0,0},{0,1,0,0}};
int T1[4][4]={{0,0,0,0},{0,0,0,0},{1,1,1,0},{0,1,0,0}};
int T2[4][4]={{0,0,0,0},{1,0,0,0},{1,1,0,0},{1,0,0,0}};
int T3[4][4]={{0,0,0,0},{0,0,0,0},{0,1,0,0},{1,1,1,0}};
int T4[4][4]={{0,0,0,0},{0,1,0,0},{1,1,0,0},{0,1,0,0}};

//This function randomly draws a coin and asks the user to choose its orientation
int piece_choice(int turn_piece[4][4]){
  int number_piece=0;
  if(turn_piece==NULL){
    exit(0);
  }
  int selected_piece; 
  int booleen=1;
  int boole;
  srand(time(NULL));
  int draw=rand() %7;
  if (draw==0){
    printf("La pièce est :\n");
    affiche_piece_jeu(O);
    number_piece=1;
    for(int i=0;i<4;i++){  
      for(int j=0;j<4;j++){
        turn_piece[i][j]=O[i][j];
      }
    }
  }
  else{
    printf("Quel orientation voulez vous ?\n");
    if (draw==1){
      printf("1:\n");
      affiche_piece_jeu(I1);
      printf("2:\n");
      affiche_piece_jeu(I2);
      scanf("%d", &selected_piece);
      while((booleen == 0) || (selected_piece<1)|| (selected_piece>2)){
        printf("Erreur: entrez une orientation entre 1 et 2.\nQuelle orientation voulez vous ?");
        boole=scanf("%d", &selected_piece);
        while(fgetc(stdin)!='\n'){};
        if(boole == 1){
          booleen = 1;
        }
      }
      if (selected_piece==1){ 
        number_piece=2;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
            turn_piece[i][j]=I1[i][j];
          }
        }
      }
      else{
        number_piece=3;
        for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
            turn_piece[i][j]=I2[i][j];
          }
        }
        
      }
    }
    else if (draw==2){
      printf("1:\n");
      affiche_piece_jeu(L1);
      printf("2:\n");
      affiche_piece_jeu(L2);
      printf("3:\n");
      affiche_piece_jeu(L3);
      printf("4:\n");
      affiche_piece_jeu(L4);
      scanf("%d", &selected_piece);
      while((booleen == 0) || (selected_piece<1)|| (selected_piece>4)){
        printf("Erreur: entrez une orientation entre 1 et 4.\nQuelle orientation voulez vous ?");
        boole=scanf("%d", &selected_piece);
        while(fgetc(stdin)!='\n'){};
        if(boole == 1){
          booleen = 1;
        }
      }
      if (selected_piece==1){ 
        number_piece=4;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
           turn_piece[i][j]=L1[i][j];
          }
        }
      }
      else if (selected_piece==2){
        number_piece=5;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
            turn_piece[i][j]=L2[i][j];
          }
        }
      }
      else if (selected_piece==3){
        number_piece=6;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
            turn_piece[i][j]=L3[i][j];
          }
        }
      }
      else{
        number_piece=7;
        for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
            turn_piece[i][j]=L4[i][j];
          }
        }
      }
    }
    else if (draw==3){
      printf("1:\n");
      affiche_piece_jeu(J1);
      printf("2:\n");
      affiche_piece_jeu(J2);
      printf("3:\n");
      affiche_piece_jeu(J3);
      printf("4:\n");
      affiche_piece_jeu(J4);
      scanf("%d", &selected_piece);
      while((booleen == 0) || (selected_piece<1)|| (selected_piece>4)){
        printf("Erreur: entrez une orientation entre 1 et 4.\nQuelle orientation voulez vous ?");
        boole=scanf("%d", &selected_piece);
        while(fgetc(stdin)!='\n'){};
        if(boole == 1){
          booleen = 1;
        }
      }
      if (selected_piece==1){
        selected_piece=8;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
            turn_piece[i][j]=J1[i][j];
          }
        }
      }
      else if (selected_piece==2){
        selected_piece=9;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
            turn_piece[i][j]=J2[i][j];
          }
        }
      }
      else if (selected_piece==3){
        selected_piece=10;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
            turn_piece[i][j]=J3[i][j];
          }
        }
      }
      else{
       selected_piece=11;
        for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
            turn_piece[i][j]=J4[i][j];
          }
        }
      }
    }
    else if (draw==4){
      printf("1:\n");
      affiche_piece_jeu(Z1);
      printf("2:\n");
      affiche_piece_jeu(Z2);
      scanf("%d", &selected_piece);
       while((booleen == 0) || (selected_piece<1)|| (selected_piece>2)){
        printf("Erreur: entrez une orientation entre 1 et 2.\nQuelle orientation voulez vous ?");
        boole=scanf("%d", &selected_piece);
        while(fgetc(stdin)!='\n'){};
        if(boole == 1){
          booleen = 1;
        }
      }
      if (selected_piece==1){ 
        number_piece=12;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
           turn_piece[i][j]=Z1[i][j];
          }
        }
       
      }
      else{
       number_piece=13;
        for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
            turn_piece[i][j]=Z2[i][j];
          }
        }
        
      }
    }
    else if (draw==5){
      printf("1:\n");
      affiche_piece_jeu(S1);
      printf("2:\n");
      affiche_piece_jeu(S2);
      scanf("%d", &selected_piece);
      while((booleen == 0) || (selected_piece<1)|| (selected_piece>2)){
        printf("Erreur: entrez une orientation entre 1 et 2.\nQuelle orientation voulez vous ?");
        boole=scanf("%d", &selected_piece);
        while(fgetc(stdin)!='\n'){};
        if(boole == 1){
          booleen = 1;
        }
      }
      if (selected_piece==1){ 
        number_piece=14;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
            turn_piece[i][j]=S1[i][j];
          }
        }
       
      }
      else{
        number_piece=15;
        for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
            turn_piece[i][j]=S2[i][j];
          }
        }
        
      }
    }
    else{
      printf("1:\n");
      affiche_piece_jeu(T1);
      printf("2:\n");
      affiche_piece_jeu(T2);
      printf("3:\n");
      affiche_piece_jeu(T3);
      printf("4:\n");
      affiche_piece_jeu(T4);
      scanf("%d", &selected_piece);
      while((booleen == 0) || (selected_piece<1)|| (selected_piece>4)){
        printf("Erreur: entrez une orientation entre 1 et 4.\nQuelle orientation voulez vous ?");
        boole=scanf("%d", &selected_piece);
        while(fgetc(stdin)!='\n'){};
        if(boole == 1){
          booleen = 1;
        }
      }
       if (selected_piece==1){ 
        number_piece=16;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
            turn_piece[i][j]=T1[i][j];
          }
        }
      }
      else if (selected_piece==2){
        number_piece=17;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
            turn_piece[i][j]=T2[i][j];
          }
        }
      }
      else if (selected_piece==3){
        number_piece=18;
        for(int i=0;i<4;i++){  
          for(int j=0;j<4;j++){
           turn_piece[i][j]=T3[i][j];
          }
        }
      }
      else{
        number_piece=19;
        for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
           turn_piece[i][j]=T4[i][j];
          }
        }
      }
    }
  }
  return (number_piece);
}

//This function asks the player to choose a column
int column_choice(int piece[4][4], int number_piece){
  if (piece == NULL) {
    exit(0);
  }
  if ((number_piece <1) || (number_piece>19)){
    exit(0);
  }
  char selected_column;
  int column;
  int booleen=1;
  int boole;
  printf("Saisir la column souhaitée.");
  scanf("%s", &selected_column);
  if(number_piece == 2){
    while((booleen == 0) || ((selected_column<65) || (selected_column>74)) && ((selected_column<97) ||(selected_column>106))){
      printf("Erreur: entrez une column entre A et J .\nQuelle column voulez vous ?\n");
      boole=scanf("%s", &selected_column);
      while(fgetc(stdin)!='\n'){};
        if(boole == 1){
          booleen = 1;
      }
    }
  }


  else if((number_piece == 1) || (number_piece == 4) || (number_piece == 6) || (number_piece == 8) || (number_piece == 10) || (number_piece == 13) || (number_piece == 15) || (number_piece == 17) || (number_piece == 19)){
    while((booleen == 0) || ((selected_column<65) || (selected_column>73)) && ((selected_column<97) ||(selected_column>105))){
      printf("Erreur: entrez une column entre A et I .\nQuelle column voulez vous ?\n");
      boole=scanf("%s", &selected_column);
      while(fgetc(stdin)!='\n'){};
        if(boole == 1){
          booleen = 1;
      }
    }  
  }


  else if ((number_piece == 5) || (number_piece == 7) || (number_piece == 9) || (number_piece == 11) || (number_piece == 12) || (number_piece == 14) || (number_piece == 16) || (number_piece == 18)){
    while((booleen == 0) || ((selected_column<65) || (selected_column>72)) && ((selected_column<97) ||(selected_column>104))){
      printf("Erreur: entrez une column entre A et H .\nQuelle column voulez vous ?\n");
      boole=scanf("%s", &selected_column);
      while(fgetc(stdin)!='\n'){};
        if(boole == 1){
          booleen = 1;
      }
    }  
  }
    
  else {
    while((booleen == 0) || ((selected_column<65) || (selected_column>71)) && ((selected_column<97) ||(selected_column>103))){
      printf("Erreur: entrez une column entre A et G .\nQuelle column voulez vous ?\n");
      boole=scanf("%s", &selected_column);
      while(fgetc(stdin)!='\n'){};
        if(boole == 1){
          booleen = 1;
      }
    }
  }

  if((selected_column=='A') || (selected_column=='a')){
    column=0;
  }
  else if((selected_column=='B') || (selected_column=='b')){
    column=1;
  }
  else if((selected_column=='C') || (selected_column=='c')){
     column=2;
   }
  else if((selected_column=='D') || (selected_column=='d')){
    column=3;
   }
   else if((selected_column=='E') || (selected_column=='e')){
     column=4;
   }
   else if((selected_column=='F') || (selected_column=='f')){
     column=5;
   }
   else if((selected_column=='G') || (selected_column=='g')){
    column=6;
  }
   else if((selected_column=='H') || (selected_column=='h')){
     column=7;
   }
   else if((selected_column=='I') || (selected_column=='i')){
    column=8;
   }
    else{
    column=9;
  }
return column;
}

//This function randomly draws the orientation of a part set in parameter
int draw_piece(int number_piece){
  printf("Vous avez mis trop de temps pour choisir. La piece est donc placée dans une column et une orientation au hasard. \n");
  srand(time(NULL));
  if ((number_piece == 2) || (number_piece == 3)) {
    number_piece = rand() % 1 + 2;
  } 
  else if ((number_piece > 5) && (number_piece < 7)) {
    number_piece = rand() % 3 + 4;
  } 
  else if ((number_piece > 8) && (number_piece < 11)) {
    number_piece = rand() % 3 + 8;
  } 
  else if ((number_piece == 12) || (number_piece == 13)) {
    number_piece = rand() % 1 + 12;
      } 
  else if ((number_piece = 14) || (number_piece = 15)) {
    number_piece = rand() % 1 + 14;
  } 
  else{
    number_piece = rand() % 3 + 16;
  }
  return(number_piece);
}

//This function randomly draws a column to put the piece
int draw_column(int column, int number_piece){
  if (number_piece == 2) {
    column = rand() % 9;
  } 
   else if ((number_piece == 1) || (number_piece == 4) || (number_piece == 6) || (number_piece == 8) || (number_piece == 10) || (number_piece == 13) || (number_piece == 15) || (number_piece == 17) || (number_piece == 19)) {
        column = rand() % 8;
    } 
   else if ((number_piece == 5) || (number_piece == 7) || (number_piece == 9) || (number_piece == 11) || (number_piece == 12) || (number_piece == 14) || (number_piece == 16) || (number_piece == 18)) {
        column = rand() % 7;
     } 
    else {
        column = rand() % 6;
     }
  return(column);
}