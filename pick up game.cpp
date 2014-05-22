//You can add or delete includes
#include <iostream>
#include <stdlib.h> //For system()
#include <conio.h> //For getche()
#include <time.h>
using namespace std;

//You can modify these numbers but don't delete these constants or this starting code will not work
const int MAX_HEIGHT = 20; //The height of the grid
const int MAX_WIDTH = 40; //The width of the grid

// DO NOT ALTER OR DELETE THIS CODE (START)!!!!!!!!!!!!!!!!!!!!!!!!!!!
/********************************************************************
 * Class: PickUpGame
 * Purpose: To store the grid and the current x and y position of the
 * user. Also has memeber functions to intialize the grid and print it.
 * Allows the user to move around the grid but provides no out of
 * bounds checking.
 ********************************************************************/
class PickUpGame
{
protected:
      char Screen[MAX_HEIGHT][MAX_WIDTH]; //The grid to print to the screen
      int xPos, yPos; //The current x and y position of the users cursor on the grid

public:
      //Constructor that will intialize the screen and x and y positions
      PickUpGame() : xPos(0), yPos(MAX_WIDTH - 1)
      {
           SetupScreen(); //Initalize the grid
      }

      //Initialize the screen with all '.' characters and set the intial user cursor position on the grid
      void SetupScreen()
      {
           for(int height = 0; height < MAX_HEIGHT; height++) {
                for(int width = 0; width < MAX_WIDTH; width++) {
                     Screen[height][width] = '.'; //Initialize each grid position
                }
           }
           Screen[xPos][yPos] = '<'; //Set the users initial cursor position
      }

      //Print the grid to the screen
      void Print()
      {
           for(int height = 0; height < MAX_HEIGHT; height++) {
                for(int width = 0; width < MAX_WIDTH; width++) {
                     cout << Screen[height][width]; //Print the character at this location in the grid
                }
                cout << endl; //After each row is printed, print a newline character
           }
      }

      //Take in user input to move around the grid
      void Move(char Direction)
      {
           switch(static_cast<int>(Direction)) //Don't know the ASCII characters for the arrow keys so use the ASCII numbers
           {
                case 72: //Up arrow
                     Screen[xPos][yPos] = ' '; //Wipe out the users current cursor
                     xPos--; //Move the users x position on the grid
                     Screen[xPos][yPos] = '^'; //Move the users cursor
                     break;
                case 80: //Down arrow
                     Screen[xPos][yPos] = ' ';
                     xPos++;
                     Screen[xPos][yPos] = 'V';
                     break;
                case 75: //Left arrow
                     Screen[xPos][yPos] = ' ';
                     yPos--;
                     Screen[xPos][yPos] = '<';
                     break;
                case 77: //Right arrow
                     Screen[xPos][yPos] = ' ';
                     yPos++;
                     Screen[xPos][yPos] = '>';
                     break;
           }
      }
};
// DO NOT ALTER OR DELETE THIS CODE (END)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//You can modify and change main()


/********************************************************************
 * Class: param
 * Purpose: to overwhright some code in order to drop cookies and  
 * put in boarders.
 * 
 * 
 ********************************************************************/


class param : public PickUpGame // new class for pickup game
	{
	public: 
		int number;
		int cookie;
		param() : PickUpGame() // constuctor for param
      {
           SetupScreen(); //Initalize the grid
      }


		void Move(char Direction){
			 switch(static_cast<int>(Direction)) //Don't know the ASCII characters for the arrow keys so use the ASCII numbers
           { 
			  

                case 72: //Up arrow 
					if (Screen[xPos-1][yPos] == '0'){ //picks up cookie
						++number; //number of cookies picked up
					}
					 if(xPos > 0){ //keeps curser on bounds
						 PickUpGame::Move(Direction); //moves curser
					 }
                     break;
                case 80: //Down arrow	 
					  if (Screen[xPos+1][yPos] == '0'){//picks up cookie
						  ++number;//number of cookies picked up
					  }
					if(xPos < 19){//keeps curser on bounds
						PickUpGame::Move(Direction); //moves curser
					}
                     break;
                case 75: //Left arrow
					  if (Screen[xPos][yPos-1] == '0'){//picks up cookie
						  ++number;	//number of cookies picked up
					  }
						if(yPos > 0){//keeps curser on bounds
							PickUpGame::Move(Direction); //moves curser
						}
                     break;
                case 77: //Right arrow               
					if (Screen[xPos][yPos+1] == '0'){//picks up cookie
						++number; //number of cookies picked up
					}
					if(yPos < 39){//keeps curser on bounds
						PickUpGame::Move(Direction); //moves curser
					}
                     break;
                     
           }
		}
			 void SetupScreen()// sets up cookies and baord
			 {
           for(int height = 0; height < MAX_HEIGHT; height++) {
                for(int width = 0; width < MAX_WIDTH; width++) {
                     Screen[height][width] = '.'; //Initialize each grid position 
					}
				}
					 int counter = 0;
					 srand(time(0));
					 cookie = rand() % 9 + 1; //randomize number of cookies
				do
				{
					
					
				 int height = rand() % 19;
				int  width = rand() % 39;
				  if (Screen[height][width] == '0'){ // if cookie is set on cookie then rerandomize it
					  Screen[height = rand() % 19][width = rand() % 39];
				  } 
				  if (Screen[height][width] == '.'){ //sets the cookie
					  Screen[height][width] = '0';
					  ++counter;
				  }
				  if (height == 0 && width ==39 ){ // if cookie is set on curser spawn
					   Screen[height = rand() % 19][width = rand() % 39];
				  }
				}while(cookie > counter);
                
				
           
           Screen[xPos][yPos] = '<'; //Set the users initial cursor position
      }
};
int main()
{
      param* Game = new param; //Create a new game object and store it in a object pointer
	  Game->number = 0; // number of cookies it picked up
	  Game->cookie; 
	  int sum;
      char UserMove = ' '; //This is used to store the users input
      do {
           system("cls"); //Clear the screen before printing anything
           cout << "Welcome to cookie pickup. You will move to the cookies by using the arrow keys." << endl; //Program intro
           Game->Print(); //Print the grid out
           cout << "What direction would you like to move in? \n(Move using the arrow keys or type q to quit.) "; //Instructions to the user
           cout << endl;
		   cout << "number of cookies you have " << Game->number <<"out of " << Game->cookie << endl;
		   //UserMove = getche(); //Get one character from the user (some compilers have "getche()")
           UserMove = _getche(); //Get one character from the user (Visual Studio 2008 "_getche()" is the new version of "getche()")
           Game->Move(UserMove); //Process the users input
		   if(Game->number ==  Game->cookie) // if users picks up all cookies it ends the program
		   break;

      } while(UserMove != 'Q' && UserMove != 'q'); //Keep running the program until the user types in a Q or q

      system("cls"); //Clear the screen
      cout << endl;
      Game->Print(); //Print the final grid out to the user
      cout << endl;
	  if(Game->number ==  Game->cookie) // if person gets all cookies
		  cout << "good job you have all the cookies!" <<endl;
	  if(Game->number <  Game->cookie)// if person dose not get all the cookies.
		 sum = Game->cookie - Game->number;
		  cout << "darn you only needed "<< sum << " more cookies!"<< endl;

      system("PAUSE");
      return 0;
}
