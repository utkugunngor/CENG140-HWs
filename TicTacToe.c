/* Explanations *************************************************************************************************************************************
|
| The Tic-Tac-Toe board has 9 cells. We will assume that the cell numbering is as follows:
|
|   c0 | c1 | c2
|   ------------
|   c3 | c4 | c5
|   ------------
|   c6 | c7 | c8
|
****************************************************************************************************************************************************/




/* Includes ****************************************************************************************************************************************/

#include "Utilities.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>   /* For standard input/output functions */

/***************************************************************************************************************************************************/




/* Definitions *************************************************************************************************************************************/

#define AUTHOR  ( "Utku Gungor" )  /* Author's name                                   */

#define EMPTY   ( ' '             )  /* Label for empty cells                           */
#define PLAYER1 ( 'X'             )  /* Label for player 1 and cells marked by player 1 */
#define PLAYER2 ( 'O'             )  /* Label for player 2 and cells marked by player 2 */

/***************************************************************************************************************************************************/




/* Type Definitions ********************************************************************************************************************************/

typedef unsigned char boolean ;

/***************************************************************************************************************************************************/




/* Global Variables ********************************************************************************************************************************/

char c0 , c1 , c2 , c3 , c4 , c5 , c6 , c7 , c8 ;  /* Cells of the Tic-Tac-Toe board */

/***************************************************************************************************************************************************/




/* Functions ***************************************************************************************************************************************/

/* Initializes the global variables. */

void initializeGlobalVariables ( void )
{
  /* TODO */
  char c11 = c0 = c1 = c2 = c3 = c4 = c5 = c6 = c7 = c8 = ' ' ; 
  
  /* ...  */
}

/*=================================================================================================================================================*/

/* Prints a banner including the author name. */

void printBanner ( void )
{
  printf(                                                                                   "\n"          ) ;
  printf( "*******************************************************************************" "\n"          ) ;
  printf( "* Tic-Tac-Toe                                                                 *" "\n"          ) ;
  printf( "* by %-72s *"                                                                    "\n" , AUTHOR ) ;
  printf( "*******************************************************************************" "\n"          ) ;
}

/*=================================================================================================================================================*/

/* Prints the current board configuration. */

void printBoard ( void )
{
  /* TODO */
  printf("c1 | c2 | c3                              %c | %c | %c              \n", c0,c1,c2);
  printf("------------                           ---------------              \n");
  printf("c4 | c5 | c6                              %c | %c | %c              \n", c3,c4,c5);
  printf("------------                           ---------------              \n");
  printf("c7 | c8 | c9                              %c | %c | %c              \n", c6,c7,c8);
  
  /* ...  */
}

/*=================================================================================================================================================*/

/* Gets the next move of "player", and marks it on the board.                     */
/* Loops (and asks again) if the input is not valid, or if the cell is not empty. */

void getNextMove ( char player )
{
  /* TODO */
  
  
  if (player == PLAYER1){
  	
  	int cell;
  	
  	printf("player1 give me a cell number:");
  	
    scanf("%d",&cell);
  	
  	switch (cell){
  		case 1:
  			if (c0==' ')
  				{c0 = 'X';}
  				
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER1);}
			break;
  		case 2 :
  			if (c1==' ')
  				{c1 = 'X';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER1);}
  			break;
		case 3 :
  			if (c2==' ')
  				{c2 = 'X';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER1);}
  			break;
		case 4 :
  			if (c3==' ')
  				{c3 = 'X';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER1);}
  			break;
		case 5 :
  			if (c4==' ')
  				{c4 = 'X';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER1);}
  			break;
		case 6 :
  			if (c5==' ')
  				{c5 = 'X';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER1);}
  			break;
		case 7 :
  			if (c6==' ')
  				{c6 = 'X';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER1);}
  			break;
		case 8 :
  			if (c7==' ')
  				{c7 = 'X';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER1);}
  			break;
		case 9 :
  			if (c8==' ')
  				{c8 = 'X';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER1);}
  			break;
		default:
			printf("invalid move,try again\n");
			getNextMove(PLAYER1);
  			  
				
	  }
  }
  else if (player == PLAYER2){
  	
  	int cell;
  	
  	printf("player2 give me a cell number:");
  	scanf("%d",&cell);
  	switch(cell){
  		
  		case 1 :
  			if (c0==' ')
  				{c0 = 'O';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER2);}
  			break;
  		case 2 :
  			if (c1==' ')
  				{c1 = 'O';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER2);}
  			break;
		case 3 :
  			if (c2==' ')
  				{c2 = 'O';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER2);}
  			break;
		case 4 :
  			if (c3==' ')
  				{c3 = 'O';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER2);}
  			break;
		case 5 :
  			if (c4==' ')
  				{c4 = 'O';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER2);}
  			break;
		case 6 :
  			if (c5==' ')
  				{c5 = 'O';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER2);}
  			break;
		case 7 :
  			if (c6==' ')
  				{c6 = 'O';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER2);}
  			break;
		case 8 :
  			if (c7==' ')
  				{c7 = 'O';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER2);}
  			break;
		case 9 :
  			if (c8==' ')
  				{c8 = 'O';}
  			else {
  				printf("this box is not empty,try again\n");
				getNextMove(PLAYER2);}
  			break;
		default:
			printf("invalid move,try again\n");
			getNextMove(PLAYER2);		  
				
	  }
  }
  /* ...  */
}

/*=================================================================================================================================================*/

/* Checks if one of the players wins the game, or if the board is full and the game ended with a draw. Prints how the game ended. */
/* Returns TRUE if the game ended, otherwise, does not print anything and just returns FALSE.                                     */

boolean checkAndPrintGameResult ( void )
{
  /* TODO */
  if(c0 == 'X'&&c1 =='X' &&c2 == 'X'){
  	printf("\nplayer1 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c3 =='X'&&c4 == 'X' &&c5 == 'X'){
  	printf("\nplayer1 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c6 == 'X'&&c7 =='X'&& c8 == 'X'){
  	printf("\nplayer1 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c0 == 'X'&&c3 == 'X'&&c6 == 'X'){
  	printf("\nplayer1 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c1 == 'X'&&c4 =='X'&& c7 == 'X'){
  	printf("\nplayer1 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c2 == 'X'&&c5 == 'X'&&c8 == 'X'){
  	printf("\nplayer1 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c0 == 'X'&&c4 == 'X'&&c8 == 'X'){
  	printf("\nplayer1 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c2 == 'X'&&c4 =='X'&& c6 == 'X'){
  	printf("\nplayer1 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  if(c0 == 'O'&&c1 =='O'&& c2 == 'O'){
  	printf("\nplayer2 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c3 =='O'&& c4 =='O'&& c5 == 'O'){
  	printf("\nplayer2 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c6 == 'O'&&c7 == 'O'&&c8 == 'O'){
  	printf("\nplayer2 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c0 == 'O'&&c3 =='O'&& c6 == 'O'){
  	printf("\nplayer2 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c1 =='O'&& c4 =='O'&& c7 == 'O'){
  	printf("\nplayer2 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c2 =='O'&& c5 =='O'&& c8 == 'O'){
  	printf("\nplayer2 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c0 == 'O'&&c4 == 'O'&&c8 == 'O'){
  	printf("\nplayer2 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else if(c2 =='O'&& c4 == 'O'&&c6 == 'O'){
  	printf("\nplayer2 wins\n\n");
  	printBoard();
  	return TRUE;
  }
  else {
  	return FALSE;
  }
  
  /* ...  */
}

/***************************************************************************************************************************************************/




/* Main Function ***********************************************************************************************************************************/

/* Initializes the global variables.                                                                                                          */
/* Prints banner.                                                                                                                             */
/* Randomly chooses one of the players to start first.                                                                                        */
/* Asks each player to make a move in turn until the game finishes (prints the board configuration each time before a player makes her move). */
/* Prints the game result.                                                                                                                    */
/* Prints a goodbye message.                                                                                                                  */
/* Prints the number of random numbers that were generated during the game play.                                                              */

int main ( void )
{
  char currentPlayer = ( ( randomIntegerMinMaxUnBiased( 0 , 1 ) == 0 ) ? PLAYER1 : PLAYER2 ) ;

  initializeGlobalVariables() ;
  printBanner              () ;
  printBoard               () ;

  do
  {
    getNextMove( currentPlayer ) ;
    printBoard ();
    

    if   ( currentPlayer == PLAYER1 )  { currentPlayer = PLAYER2 ; }
    else                               { currentPlayer = PLAYER1 ; }
  }
  while ( checkAndPrintGameResult() == FALSE ) ;

  printf( "\nGood game. Have a nice day!\n" ) ;

  printf( "\n%d random numbers were generated during the game play.\n\n" , numberOfRandomNumbersGenerated ) ;

  return 0 ;
}

/***************************************************************************************************************************************************/
