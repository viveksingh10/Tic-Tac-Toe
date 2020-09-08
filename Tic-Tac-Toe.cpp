#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

char square[9];
void print_board();
int check_win();
int computer_mark();

int main()
{
 system("cls");
 int choice, mark, p, q, r, k, j=1, win=0, mark_2;
   for(p=0;p<=100; p++)                                                                   //just to print loading of game 1-100 :))
     {
        system("cls");
        cout<<"Game is loading -> "<<p;
          for(q= 0;q<=10000; q++)
             {
              for(r=0; r<=3; r++)
                {
                 cout<<"";
                }
             }
      } 
 cout<<"\n\n*************** Tic Tac Toe****************\n\n";
     
 cout<<" Press 1 for player vs player \n Press 2 for player vs computer.  \n Your choice -> ";             //Enter number of player.
 cin>>choice;
     
	 for(k=1;k<=9; k++)                                                                   
       { 
        square[k] = '-';
       }
    print_board();
    

        if(choice == 2)                                                                    //For 2 player
            {
              cout<<" \n For player 1 - (X)               For player 2 - (O)";
  
                while(win == 0)
                   {
                     cout<<"\n Player 1 enter your move, in which box you want to mark -> ";        //Player1 move
                     cin>>mark;
                     square[mark] = 'X';
                     print_board();
                     
                     win = check_win();
    	                if (win==1)
                          {
                           cout<<"\n Player 1 win!!";
                           exit(0);
                          }
                        else if (win==2)
                            {
                              cout<<"\n Its a tie!!";
                              exit(0);
                            }
           
                         cout<<"\n Player 2 enter your move, in which box you want to mark -> ";        //Player 2 move
                         cin>>mark;
          
                            square[mark] = 'O' ;
                            print_board();
                            
                            win = check_win();   
	     			           if (win==1)
                                 {
                                   cout<<"\n Player 2 win!!";
                                   exit(0);
                                 }
          
                    }
           }
     
	 else if(choice==1)                                                                      // For 1 player game
      {
         cout<<"\n For player 1 - (X)          For computer - (O)";
         
		     while(win ==0)
               {
                 cout<<"\n Player 1 enter your move, in which box you want to mark ->";           //Player move
                 cin>>mark;
                   
                  square[mark] = 'X' ;
                  j++;
                  print_board();
                  
                  win = check_win();
			         if(win==1)
                       {
                        cout<<"\n Player win";
                        exit(0);
                       }
                 
				      else if(win==2)
                       {
                         cout<<"\n Its a Tie";
                         exit(0);
                       }
              
              mark_2 = computer_mark();                                               
               for(int i=1;i<=j;i++)                                                   //To check repetition of move to avoid overwrite.
                   {
				     if(square[mark_2]== '-')
				      {
				   	  mark=mark_2;  
				   	  break;
				      }        
				     else
			           {
				      	mark_2 = computer_mark();
		   		       }
			       }
				      
              square[mark] = 'O' ;
              j++;
              cout<<"\n Computer's move -> "<<mark<<"\n";                                                 //Computer move 
              print_board();
              
              win = check_win();
			    if(win==1)
                   {
                     cout<<"\n computer wins";
                     exit(0);
                   }
     
	       }
	   }
    
	   else
          {
             cout<<"\n Invalid Input";
          }
      
	getch();
    return 0;

}


void print_board()

 {
       cout << "\n   |   | " << endl; 
       cout << " " << square[1] << " | " << square[2] << " | " << square[3] << endl; 
       cout << "___|___|___" << endl;
       cout << "   |   | " << endl; 
       cout << " " << square[4] << " | " << square[5] << " | " << square[6] << endl; 
       cout << "___|___|___" << endl; 
       cout << "   |   | " << endl; 
       cout << " " << square[7] << " | " << square[8] << " | " << square[9] << endl; 
       cout << "   |   | " << endl << endl;
 }


int check_win()
{

/*
*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    0 FOR GAME IS IN PROGRESS
    2 GAME IS OVER AND NO RESULT
**********************************************/
    if (square[1] == square[2] && square[2] == square[3] && square[3] != '-')

        return 1;
    else if (square[4] == square[5] && square[5] == square[6] && square[6] != '-')

        return 1;
    else if (square[7] == square[8] && square[8] == square[9] && square [9] != '-')

        return 1;
    else if (square[1] == square[4] && square[4] == square[7] && square [7] != '-')

        return 1;
    else if (square[2] == square[5] && square[5] == square[8] && square [8] != '-')

        return 1;
    else if (square[3] == square[6] && square[6] == square[9] && square [9] != '-')

        return 1;
    else if (square[1] == square[5] && square[5] == square[9] && square [9] != '-')

        return 1;
    else if (square[3] == square[5] && square[5] == square[7] && square [7] != '-')

        return 1;
    else if (square[1] != '-' && square[2] != '-' && square[3] != '-' 
                    && square[4] != '-' && square[5] != '-' && square[6] != '-' 
                  && square[7] != '-' && square[8] != '-' && square[9] != '-')

        return 2;
    else
        return 0;
}


int computer_mark()
{
    return (rand()%10);
}


