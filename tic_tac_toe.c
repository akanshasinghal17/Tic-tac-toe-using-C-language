#include <stdio.h>
char board[3][3];
const char PLAYER1='X';
const char COMPUTER='O';
const char PLAYER2='O';

void resetBoard();
void printBoard();
int  checkFreeSpaces();
void playerMove();
void secondPlayerMove();
void computerMove();
char checkWinner();
void printWinner(char);

void playerComputerMode(){
  char winner=' ';
    resetBoard();
    printBoard();
  while(winner== ' ' && checkFreeSpaces()!=0){
   playerMove(); 
  winner=checkWinner();
    if(winner !=' ' || checkFreeSpaces()==0){
      break;
    }
  computerMove(); 
  winner=checkWinner();
    if(winner !=' ' || checkFreeSpaces()==0){
      break;
    }
  }
printWinner(winner);
}

void twoPlayerMode(){
char winner=' ';
  resetBoard();
    printBoard();
  while(winner== ' ' && checkFreeSpaces()!=0){
   playerMove(); 
  winner=checkWinner();
    if(winner !=' ' || checkFreeSpaces()==0){
      break;
    }
  secondPlayerMove(); 
  winner=checkWinner();
    if(winner !=' ' || checkFreeSpaces()==0){
      break;
    }
  }
printWinner(winner);  
}
int main(void) {
  int response;
  do{
  int x;
  printf("Press 1 for One Player Mode:\n");
  printf("Press 2 for Two Player Mode:\n");
  scanf("%d",&x);
  switch(x){
    case 1: playerComputerMode();
            break;
    case 2: twoPlayerMode();
            break;
    default:printf("INVALID CHOICE\n");
  }
  printf("\nWould you want to play again? (1/0):");
scanf("%d",&response);
    printf("Thanks for playing!");
  }while(response==1);

  return 0;
}

void resetBoard(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      board[i][j]=' ';
    }
  }
  
}

void printBoard(){
  printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
  printf("\n---|---|---");
  printf("\n %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
  printf("\n---|---|---");
   printf("\n %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
  printf("\n");
}

int checkFreeSpaces(){
  int freeSpaces=9;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(board[i][j]!=' ')
        freeSpaces--;
    }
  }
  return freeSpaces;
}

void playerMove(){
  int x;
  int y;
  do{
    printf("Player 1:\n");
  printf("Enter row number(1-3):");
  scanf("%d",&x);
  x--;
  printf("Enter column number(1-3):");
  scanf("%d",&y);
  y--;
  if(board[x][y]!=' ')
    printf("INVALID MOVE\n");
  else{
    board[x][y]=PLAYER1;
    printBoard();
    break;
  }
}while(board[x][y]!=' ');
    }

void secondPlayerMove(){
  int x;
  int y;
  do{
    printf("Player 2:\n");
  printf("Enter row number(1-3):");
  scanf("%d",&x);
  x--;
  printf("Enter column number(1-3):");
  scanf("%d",&y);
  y--;
  if(board[x][y]!=' ')
    printf("INVALID MOVE\n");
  else{
    board[x][y]=PLAYER2;
    printBoard();
    break;
  }
}while(board[x][y]!=' ');
    }

char checkWinner(){
  //check rows
  for(int i=0;i<3;i++){
    if(board[i][0]==board[i][1] && board[i][0]==board[i][2])
      return board[i][0];
  }
//check columns
  for(int i=0;i<3;i++){
    if(board[0][i]==board[1][i] && board[0][i]==board[2][i])
      return board[0][i];
      }
  //check left diagonal
  for(int i=0;i<3;i++){
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2])
      return board[0][0];
  }
//check right diagonal
  for(int i=0;i<3;i++){
    if(board[0][2]==board[1][1] && board[0][2]==board[2][0])
      return board[0][2];
  }
return ' ';
  }

void printWinner(char winner){
  if(winner==PLAYER1)
    printf("PLAYER 1 WIN!");
  else if(winner== COMPUTER)
    printf("YOU LOSE!");
  else if(winner== PLAYER2)
  printf("PLAYER 2 WIN!");
    else
    printf("IT'S A TIE");
}


void computerMove(){
  srand(time(0));
  int x;
  int y;
  if(checkFreeSpaces() >0){
    do{
      x=rand()%3;
      y=rand()%3;
    }while(board[x][y]!=' ');
    printf("Computer:\n");
    board[x][y]=COMPUTER;
    printBoard();
  }
   else{
     printWinner(' ');
   } 
}