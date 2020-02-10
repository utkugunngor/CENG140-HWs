/* Explanations *************************************************************************************************************************************
|
| This file implements CengBook, which is a realistic simulation of a mini social-media application.
|
****************************************************************************************************************************************************/




/* Includes ****************************************************************************************************************************************/

#include "Utilities.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************************************************************************************************************/




/* Macro Definitions *******************************************************************************************************************************/

#define AUTHOR ( "Selim Temizer" )  /* Author's name */  /* TODO: Replace with your name */

/***************************************************************************************************************************************************/




/* Global Variable Definitions *********************************************************************************************************************/

BookPtr bookPtr ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#if   defined(_WIN16) || defined(_WIN32) || defined(_WIN64)

  char operatingSystem[] = "Windows" ;  /* This is a Windows environment.                            */

#elif defined(__linux__)

  char operatingSystem[] = "Linux"   ;  /* This is a Linux environment (any GNU/Linux distribution). */

#elif defined(__APPLE__)

  char operatingSystem[] = "MacOSX"  ;  /* This is a Mac OS X environment.                           */

#endif

/***************************************************************************************************************************************************/




/* Functions ***************************************************************************************************************************************/

void printUsage ( String applicationName )
{
  NL ;

  printf( "Usage: %s <MaxNumberOfUsers> <MaxUserNameLength> <MaxNumberOfFriendsPerUser>\n\n" , applicationName ) ;
}

/*=================================================================================================================================================*/

void printBanner ( void )
{
  NL ;

  printf( "*******************************************************************************" "\n"          ) ;
  printf( "* CengBook                                                                    *" "\n"          ) ;
  printf( "* by %-72s *"                                                                    "\n" , AUTHOR ) ;
  printf( "*******************************************************************************" "\n"          ) ;
}

/*=================================================================================================================================================*/

void printMenu ( void )
{
  NL ;

  printf( "*******************************************************************************" "\n" ) ;
  printf( "Help                       : Print this menu"                                    "\n" ) ;
  printf( "List                       : List all users"                                     "\n" ) ;
  printf( "Plot                       : Create a plot of CengBook (requires GraphViz)"      "\n" ) ;
  printf( "Quit                       : Exit application"                                   "\n" ) ;
  printf( "-------------------------------------------------------------------------------" "\n" ) ;
  printf( "Register   <user>          : Create a new user and add it to CengBook"           "\n" ) ;
  printf( "Delete     <user>          : Delete user from CengBook"                          "\n" ) ;
  printf( "Find       <user>          : Search CengBook for user, display user information" "\n" ) ;
  printf( "Connect    <user1> <user2> : Add a connection from user1 to user2"               "\n" ) ;
  printf( "Disconnect <user1> <user2> : Remove connection from user1 to user2"              "\n" ) ;
  printf( "Path       <user1> <user2> : Find shortest path from user1 to user2"             "\n" ) ;
  printf( "-------------------------------------------------------------------------------" "\n" ) ;
  printf( "Sort <abc|pop> <asc|desc>  : Sort all users (alphabetically or by popularity)"   "\n" ) ;
  printf( "*******************************************************************************" "\n" ) ;
}

/*=================================================================================================================================================*/

void commandHelp ( void )
{
  /* TODO */
  printf("\n");
  printf( "*******************************************************************************" "\n" ) ;
  printf( "Help                       : Print this menu"                                    "\n" ) ;
  printf( "List                       : List all users"                                     "\n" ) ;
  printf( "Plot                       : Create a plot of CengBook (requires GraphViz)"      "\n" ) ;
  printf( "Quit                       : Exit application"                                   "\n" ) ;
  printf( "-------------------------------------------------------------------------------" "\n" ) ;
  printf( "Register   <user>          : Create a new user and add it to CengBook"           "\n" ) ;
  printf( "Delete     <user>          : Delete user from CengBook"                          "\n" ) ;
  printf( "Find       <user>          : Search CengBook for user, display user information" "\n" ) ;
  printf( "Connect    <user1> <user2> : Add a connection from user1 to user2"               "\n" ) ;
  printf( "Disconnect <user1> <user2> : Remove connection from user1 to user2"              "\n" ) ;
  printf( "Path       <user1> <user2> : Find shortest path from user1 to user2"             "\n" ) ;
  printf( "-------------------------------------------------------------------------------" "\n" ) ;
  printf( "Sort <abc|pop> <asc|desc>  : Sort all users (alphabetically or by popularity)"   "\n" ) ;
  printf( "*******************************************************************************" "\n" ) ;
  /* ...  */
}

/*=================================================================================================================================================*/

void commandList ( void )
{
  /* TODO */
	int i;
	
	for(i = 0 ; i < getMaxNumberOfUsers() ; i++){
		if(bookPtr->userPointers[i] != NULL){
			printf("  %s          : %u Follower(s) , %u Friend(s)\n" , bookPtr->userPointers[i]->name , bookPtr->userPointers[i]->numberOfFollowers , bookPtr->userPointers[i]->numberOfFriends);
		}
	}
  /* ...  */
}

/*=================================================================================================================================================*/

void commandPlot ( void )
{
  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  UserPtr   userPtr             , friendPtr              ;
  int       userIndex           , friendIndex            ;
  String    runDotSystemCommand , openImageSystemCommand ;

  FILE    * file = fopen( "CengBook.dot" , "w" )         ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  fprintf( file , "digraph CengBook"                                                       "\n"                            ) ;
  fprintf( file , "{"                                                                      "\n"                            ) ;
  fprintf( file , "  graph [label=\"CengBook\\nNumber of users = %d\" , labelloc=t] ;"     "\n\n" , bookPtr->numberOfUsers ) ;
  fprintf( file , "  node  [shape=ellipse , fontcolor=black , color=red , penwidth=2.0] ;" "\n\n"                          ) ;
  fprintf( file , "  edge  [color=blue , penwidth=2.0] ;"                                  "\n\n"                          ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  for ( userIndex = 0 ; userIndex < bookPtr->numberOfUsers ; userIndex++ )
  {
    userPtr = bookPtr->userPointers[ userIndex ] ;

    fprintf( file , "  %s [label=\"%s\\n%d Friend(s)\\n%d Follower(s)\"] ;\n" ,
             userPtr->name                                                    ,
             userPtr->name                                                    ,
             userPtr->numberOfFriends                                         ,
             userPtr->numberOfFollowers                                       ) ;
  }

  if ( bookPtr->numberOfUsers > 0 )  { fprintf( file , "\n" ) ; }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  for ( userIndex = 0 ; userIndex < bookPtr->numberOfUsers ; userIndex++ )
  {
    userPtr = bookPtr->userPointers[ userIndex ] ;

    for ( friendIndex = 0 ; friendIndex < userPtr->numberOfFriends ; friendIndex++ )
    {
      friendPtr = userPtr->friendPointers[ friendIndex ] ;

      fprintf( file , "  %s -> %s ;\n" , userPtr->name , friendPtr->name ) ;
    }
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  fprintf( file , "}\n" ) ;
  fclose ( file         ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  if ( strcmp( operatingSystem , "Windows" ) == 0 )
  {
    runDotSystemCommand    = "CMD /C dot -Tgif CengBook.dot -o CengBook.gif" ;
    openImageSystemCommand = "CMD /C START CengBook.gif"                     ;
  }
  else  /* Assumption: Linux */
  {
    runDotSystemCommand    = "dot -Tgif CengBook.dot -o CengBook.gif"        ;
    openImageSystemCommand = "xdg-open CengBook.gif &"                       ;
  }

  if ( system( runDotSystemCommand    ) ) ;  /* "if" statement is used to eliminate warning about unused return value of "system" call */
  if ( system( openImageSystemCommand ) ) ;  /* "if" statement is used to eliminate warning about unused return value of "system" call */

  NL ;  I2 ;  printf( "Plot prepared\n" ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/
}

/*=================================================================================================================================================*/

void commandQuit ( void )
{
  /* TODO */
	printf("\n");
	printf("Have a nice day!\n");
	printf("\n");
	exit(0);
	
  /* ...  */
}

/*=================================================================================================================================================*/

void commandRegister ( String userName )
{
  /* TODO */
	int i;
	UserPtr userPtr;
	userPtr = allocateUser(userName);
	
	if(strlen(userName) <= getMaxUserNameLength()){
	
		if(bookPtr->numberOfUsers<getMaxNumberOfUsers()){

			for(i = 0; i < getMaxNumberOfUsers() ;i++){
			
				if(bookPtr->userPointers[i] == NULL){

					bookPtr->userPointers[i] = userPtr;
					bookPtr->numberOfUsers++;
					printf("\n  User '%s' registered successfully\n",userName);
					
					break;
				}
			}
		}

		else{
			printf("\n  CengBook is full, cannot register any new users!\n");
			}
	}
	else{
		printf("\n  User name is longer than %d characters!\n",getMaxUserNameLength());
	}
	
  /* ...  */
}

/*=================================================================================================================================================*/

void commandDelete ( String userName )
{
  /* TODO */
	UserPtr userPtr = getUserPtrByName ( bookPtr , userName );
	int i;
	int j;
	if(userPtr){
		for( j=0 ; j<getMaxNumberOfUsers () ; j++){
			if (isConnected (  bookPtr->userPointers[j] , userPtr  )){
				bookPtr->userPointers[j]->numberOfFriends--;
			}
		break;
		}
		for ( i=0 ; i < getMaxNumberOfFriendsPerUser() ;i++){
			if(userPtr->friendPointers[i]){
				userPtr->friendPointers[i]->numberOfFollowers--;
			}
		}
	
	deallocateUser ( userPtr );
	/*bookPtr->userPointers[j] = NULL;*/
	bookPtr->numberOfUsers--;
	
	printf("\n  User '%s' is deleted from CengBook\n",userName);
		
	}
	
	else {
	printf("\n  User '%s' not found in CengBook!\n",userName);
	}
	
  /* ...  */
}

/*=================================================================================================================================================*/

void commandFind ( String userName )
{
  /* TODO */
	UserPtr userPtr = getUserPtrByName ( bookPtr , userName );
	
	if(userPtr){
		printf("\n");
		printUser (  userPtr );
	}
	else{
		printf("\n  User '%s' not found in CengBook!\n",userName);
	}


  /* ...  */
}

/*=================================================================================================================================================*/

void commandConnect ( String userName1 , String userName2 )
{
  /* TODO */
	 
	UserPtr userPtr1 = getUserPtrByName ( bookPtr , userName1 );
	UserPtr userPtr2 = getUserPtrByName ( bookPtr , userName2 );
	int i;
	if(userPtr1 && userPtr2){

	if(userPtr1->numberOfFriends<getMaxNumberOfFriendsPerUser()){

			for(i = 0; i < getMaxNumberOfFriendsPerUser() ;i++){
			
				if(userPtr1->friendPointers[i] == NULL){

					userPtr1->friendPointers[i] = userPtr2;
					
					break;
				}
			
			}
		}

	printf("\n  User '%s' successfully connected to user '%s'\n",userName1,userName2);	
	userPtr1->numberOfFriends++;
	userPtr2->numberOfFollowers++;
	}
	else {
		if(userPtr1 == NULL){
			printf("\n  User '%s' not found in CengBook!",userName1);
		}
		if(userPtr2 == NULL){
			printf("\n  User '%s' not found in CengBook!\n",userName2);
		
		}
	}
	 
  /* ...  */
}

/*=================================================================================================================================================*/

void commandDisconnect ( String userName1 , String userName2 )
{
  /* TODO */
	UserPtr userPtr1 = getUserPtrByName ( bookPtr , userName1 );
	UserPtr userPtr2 = getUserPtrByName ( bookPtr , userName2 );
	int i;
	if(userPtr1 && userPtr2){

	if(userPtr1->numberOfFriends<getMaxNumberOfFriendsPerUser()){

			for(i = 0; i < getMaxNumberOfFriendsPerUser() ;i++){
			
				if(userPtr1->friendPointers[i] == userPtr2){
					
					userPtr2->numberOfFollowers--;
					userPtr1->numberOfFriends--;
					userPtr1->friendPointers[i] = NULL;
					printf("\n  User '%s' successfully disconnected to user '%s'\n",userName1,userName2);
					break;
				}
			
			}
		}
	
	}
	else {
		if(userPtr1 == NULL){
			printf("\n  User '%s' not found in CengBook!",userName1);
		}
		if(userPtr2 == NULL){
			printf("\n  User '%s' not found in CengBook!\n",userName2);
		
		}
	}
  /* ...  */
}

/*=================================================================================================================================================*/

void commandPath ( String userName1 , String userName2 )
{
  /* TODO */
	UserPtr startUserPtr = getUserPtrByName ( bookPtr , userName1 );
	UserPtr targetUserPtr = getUserPtrByName ( bookPtr , userName2 );
	UserPtrArray friendPtrChainArray = shortestPath ( bookPtr , startUserPtr , targetUserPtr );
  /* ...  */
}

/*=================================================================================================================================================*/

void commandSort ( String criterion , String order )
{
  /* TODO */
	int i;
	if((*criterion) == *"abc"){
		if(*order == *"asc"){
			printf("\n  CengBook sorted 'alphabetically' in 'ascending' order\n");
			for(i = 0 ; i < getMaxNumberOfUsers() ; i++){
				if(bookPtr->userPointers[i]->name < bookPtr->userPointers[i+1]->name){
					compareByName (  bookPtr->userPointers[i] , bookPtr->userPointers[i+1]  );
					/*sortBook ( bookPtr , &compareByName , 1 );*/
				}
			
			}
		}
		if(*order == *"desc"){
			printf("\n  CengBook sorted 'alphabetically' in 'descending' order\n");
			for(i = 0 ; i < getMaxNumberOfUsers() ; i++){
				if(bookPtr->userPointers[i] < bookPtr->userPointers[i+1]){
					compareByName (  bookPtr->userPointers[i] , bookPtr->userPointers[i+1]  );}
				}
		}
	}
	/*Sort <abc|pop> <asc|desc>  : Sort all users (alphabetically or by popularity)*/
  /* ...  */
}

/*=================================================================================================================================================*/

void processInput ( String input )
{
  int         i                                                    ;
  int         numberOfTokens = 0                                   ;
  StringArray tokens         = tokenize( input , &numberOfTokens ) ;
  String      command                                              ;

  if ( numberOfTokens < 1 )  { return ; }

  command = tokens[0] ;

  for ( i = 0 ; i < strlen( command ) ; i++ )  { if ( ( command[i] >= 'A' ) && ( command[i] <= 'Z' ) )  { command[i] += 'a' - 'A' ; } }

  if      ( strcmp( command , "help"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandHelp      (                       ) ;  return ; } }
  else if ( strcmp( command , "list"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandList      (                       ) ;  return ; } }
  else if ( strcmp( command , "plot"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandPlot      (                       ) ;  return ; } }
  else if ( strcmp( command , "quit"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandQuit      (                       ) ;  return ; } }
  else if ( strcmp( command , "register"   ) == 0 )  { if ( numberOfTokens == 2 ) { commandRegister  ( tokens[1]             ) ;  return ; } }
  else if ( strcmp( command , "delete"     ) == 0 )  { if ( numberOfTokens == 2 ) { commandDelete    ( tokens[1]             ) ;  return ; } }
  else if ( strcmp( command , "find"       ) == 0 )  { if ( numberOfTokens == 2 ) { commandFind      ( tokens[1]             ) ;  return ; } }
  else if ( strcmp( command , "connect"    ) == 0 )  { if ( numberOfTokens == 3 ) { commandConnect   ( tokens[1] , tokens[2] ) ;  return ; } }
  else if ( strcmp( command , "disconnect" ) == 0 )  { if ( numberOfTokens == 3 ) { commandDisconnect( tokens[1] , tokens[2] ) ;  return ; } }
  else if ( strcmp( command , "path"       ) == 0 )  { if ( numberOfTokens == 3 ) { commandPath      ( tokens[1] , tokens[2] ) ;  return ; } }
  else if ( strcmp( command , "sort"       ) == 0 )  { if ( numberOfTokens == 3 ) { commandSort      ( tokens[1] , tokens[2] ) ;  return ; } }
  else                                               { NL ;  I2 ;  printf( "Invalid command!\n" ) ;                               return ;   }

  /* If we reach here, the user must have provided incorrect number of arguments to a valid command */

  command[0] += 'A' - 'a' ;

  NL ;  I2 ;  printf( "Incorrect number of arguments provided for the command '%s'!\n" , command ) ;
}

/***************************************************************************************************************************************************/




/* Main Function ***********************************************************************************************************************************/

int main ( int argc , char * argv[] )
{
  char input [ MAX_INPUT_LENGTH ] ;

  if ( argc < 4 )  { printUsage( argv[0] ) ;  return 0 ; }

  configureCengBook( /* maxNumberOfUsers          */ atoi( argv[1] ) ,
                     /* maxUserNameLength         */ atoi( argv[2] ) ,
                     /* maxNumberOfFriendsPerUser */ atoi( argv[3] ) ) ;
  bookPtr = allocateBook() ;

  if ( bookPtr == NULL )  { NL ;  printf( "Error: Cannot allocate memory to store CengBook! Exiting!\n\n" ) ;  exit( 0 ) ; }

  printBanner() ;
  printMenu  () ;

  while ( TRUE )
  {
    NL                        ;  /* New line     */
    printf( "[CENGBOOK] > " ) ;  /* Print prompt */

    if ( fgets( input , MAX_INPUT_LENGTH , stdin ) == NULL )  /* Read input line, 'fgets' is safer than 'gets'. */
    {
      /* In the following two lines, the "if" statements surrounding the "freopen" function calls are used to eliminate warnings. */

      if   ( strcmp( operatingSystem , "Windows" ) == 0 )  { if ( freopen( "CON"      , "r" , stdin ) == NULL ) ; }
      else /* Assumption:               Linux          */  { if ( freopen( "/dev/tty" , "r" , stdin ) == NULL ) ; }

      continue ;
    }

    processInput( input ) ;  /* Tokenize and process the input command */
  }

  return 0 ;
}

/***************************************************************************************************************************************************/
