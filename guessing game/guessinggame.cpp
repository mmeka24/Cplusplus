#include<iostream>
#include<cstring>
#include<cmath> 

// Rule 1: No global variables
// Rule 2: no strings 
// Rule 3: use iostream and use break/continue ocassionally. no high mouse usage:(  



using namespace std; 

int main()
{
 
   
  
  //initalizing the variables 
  int input = 0;
  int secretnum = 0;
  int turn = 0; 
  char playagain; 
  srand (time(NULL));
  bool Game = true;
  char ans[1]; //going to use char array to determine if user wants to cont playing
  secretnum = rand() % 100+1; 

  //creating a random number from 1 to 100 
  while (Game){

    cout << "guess a number 1-100"; 
    //cout << secretnum << endl;
  cin >> input;
  cout << "You entered: " << input << endl;
  turn++; 
  if (input == secretnum){
    cout << "You guessed the number in " << turn << " guesses. Type y if you'd like to play again or n" << endl;
    cin >> ans;
    //identifying the y from user input and generating a new number 
    if(strcmp(ans, "y") == 0){
      cout << "new number created";
      secretnum = rand() % 100+1;
      turn = 0; 
    }
    //identifying the n form user input and terminating the process
    if (strcmp(ans, "n") == 0) {
      cout << "you are done playing";
      //game is over so boolean is now false
      Game = false; 
    }

  }

  else if (input > secretnum) {
    cout << "your number is too large. try again";
  }

  else if (input < secretnum){
    cout << "your number is too small. try again"; 
  }

  

}
} 
