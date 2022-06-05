#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gestion_jeu.h"
#include "interaction_utilisateur.h"
#include "affichage.h"

//this function allows you to add a piece to the game board
int add_piece(int piece[4][4], int column, int line, int game_board[14][10]){
 if(piece == NULL){
   exit(0);
 }
 if ((column > 9)||(column < 0)){
   exit(0);
  }
 if ((line > 13)||(line < 0)){
   exit(0);
  }
  if (game_board == NULL) {
    exit (0);
  }
  int i,j;
  int collision=0;
  i=0;
  j=0;
  for(int x=line;x<line+4;x++){
  j=0;
   for(int y=column;y<column+4;y++){
      game_board[x][y]=game_board[x][y]+piece[i][j];
      j=j+1;
      if(game_board[x][y]==2){
        collision=1;
      }
    }
    i=i+1;
  }
  return collision;
}

//this function allows to remove a piece from the grid, to subtract it (if there is a collision the 2 will become 1 on the grid at the place of the collision)
void subtract_piece(int piece[4][4], int column, int line, int game_board[14][10]){
  if (piece == NULL){
    exit(0);
  }
 if ((column > 9)||(column < 0)){
   exit(0);
  }
 if ((line > 13)||(line < 0)){
   exit(0);
  }
  if (game_board == NULL){
    exit(0);
  }
int i,j;
  i=0;
  j=0;
  for(int x=line;x<line+4;x++){
  j=0;
   for(int y=column;y<column+4;y++){
      if(piece[i][j]!=0){
        game_board[x][y]=game_board[x][y]-piece[i][j];
      }
      else{
        game_board[x][y]=game_board[x][y];
      }
    j=j+1;
    }
  i=i+1;
  }
}

//this function deletes a full line and brings the table back down
int suppression_line(int game_board[14][10]){
  if(game_board == NULL){
    exit(0);
  }
  int result;
  int a;
  int number_line_deleted =0;
  for(int x=4;x<14;x++){
    result=0;
    for(int y=0;y<10;y++){
      result=result+game_board[x][y];
    }
    if (result==10){
      number_line_deleted= number_line_deleted +1;
      for(int y=0;y<10;y++){
        game_board[x][y]=0;
      }
      a=x;
      for(int b=x-1;b>=0;b--){
        for(int y=0;y<10;y++){
          game_board[a][y]=game_board[b][y];
	        game_board[b][y]=0;
        }
      a--;
      }
    }
  }
  return(number_line_deleted);
}

//This function allows you to move a piece down until it meets another piece or reaches the bottom of the grid
void go_down_piece(int piece[4][4], int column, int game_board[14][10]){
int c;
int line=0;
  if(piece == NULL){
    exit(0);
  }
 if ((column > 9)||(column < 0)){
   exit(0);
  }
  if(game_board == NULL){
    exit(0);
  }
  c=add_piece(piece, column, line, game_board);
  while((c!=1)&&(line!=11)){
    subtract_piece(piece, column, line, game_board);
    line=line+1;
    c=add_piece(piece, column, line, game_board);
  }
  subtract_piece(piece, column, line, game_board);
  line=line-1;
  add_piece(piece, column, line, game_board);

} 

//this function looks if on a line the game grid is exceeded and if the player has lost
int game_over(int game_board[14][10]){
  if (game_board == NULL){
    exit(0);
  }
  int result=0;
  for(int x=0;x<4;x++){
    for(int y=0;y<10;y++){
      if (game_board[x][y]!=0){
        result = 1;
      } 
    }
  }
return result;
}