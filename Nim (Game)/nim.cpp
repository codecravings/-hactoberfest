#include <iostream>
using namespace std;
int main()
{
   const int Human_player = 1;
   const int Computer_player = 0;
   const int Max_nim_sticks = 22;

   char firstplayer;
   bool validPlayer = false;

   int currentPlayer;
   int nimsticks;
   int currentPlayerMove;

   bool validHumanMove;
   int idealmove;

   cout << "Welcome hooman to the Game of Single-Pile Nim" << endl;
   cout << "-------------------------------------" << endl << endl;

   do{
       cout << "Who plays first: [P]layer or [C]omputer?";
       cin >> firstplayer;

       switch (firstplayer)
       {
	       case 'p':
	       case 'P':
		   validPlayer = true;
		   currentPlayer = Human_player;
		   break;

	       case 'c':
	       case 'C':
		   validPlayer = true;
		   currentPlayer = Computer_player;
		   break;
	       default:
		   cout << "uh oh! retry, seems you are dumb!" << endl;
		   break;
       }
   } while (!validPlayer);//repeat as long as necessary
   //Process
   //Start the game by initializing the pile of sticks
   nimsticks = Max_nim_sticks;

   while (nimsticks != 0)
   {

       cout << "There are now " << nimsticks << " in the pile." << endl;
       //currentPlayer1 = 0;
       if (currentPlayer == Human_player)
       {

           validHumanMove = false;
           do
           {
               cout << "How many sticks do you want to remove (1-4)";
               cin >> currentPlayerMove;
               validHumanMove = (currentPlayerMove >= 1) && (currentPlayerMove <= 4)
                  && (currentPlayerMove <= nimsticks);
               if (!validHumanMove)
               {
                   cout << "Between 1 and 4, and no more than there are in the pile, please." << endl;
               }
           } while (!validHumanMove);
       }
       else
       {

           idealmove = (nimsticks % 5);

           if (idealmove == 0)
           {
               currentPlayerMove = 1;
           }
           else { //ideal move
               currentPlayerMove = idealmove;
           }

           cout << "Computer is taking " << currentPlayerMove
               << " sticks from the pile." << endl;
       }

       nimsticks -= currentPlayerMove;

       if (nimsticks == 0) {

           if (currentPlayer == Human_player) {
               cout << "somehow you win, congratulations!" << endl;
           }
           else {
               cout << "Computer Wins! Best Luck next time hooman...." << endl;
           }
       }
       else {
           currentPlayer = !currentPlayer;
       }
   }

   cout << "go ask someone else to challenge!" << endl;

   return 0;
}
