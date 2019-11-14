#include <iostream>
#include <string>
using namespace std;

int randGenerator(int seed){
  return ((rand()%3)+1);
}

string translator(int choice){
  switch( choice ){
  case 1: return "Rock";
  case 2: return "Paper";
  case 3: return "Scissors";
  default: return "Not understood";
  }
}

void referee(int& usrScore, int& compScore, int usrChoice, int compChoice){
  if( usrChoice == 0 ){
    return;
  }
  if( usrChoice == compChoice ){
    cout << "Draw!" << endl;
    return;
  }
  if( usrChoice - compChoice == 1 || usrChoice - compChoice == -2 ){
    usrScore++;
    cout << "You win!" << endl;
    return;
  }else{
    compScore++;
    cout << "Computer wins!" << endl;
    return;
  }
}
  
void referee(int usrScore, int compScore){
  cout << "You: " << usrScore << ", Computer: " << compScore << endl;
  if( usrScore == compScore ){
    cout << "Draw!" << endl;
    return;
  }
  if( usrScore > compScore ){
    cout << "Winner: You" << endl;
    return;
  }else{
    cout << "Winner: Computer" << endl;
  }
}

void commentator(int usrChoice, int compChoice){
  if( usrChoice == 0 ){
    return;
  }
  cout << translator(usrChoice) << " (you) vs " << translator(compChoice) << " (computer). ";
}

int main(){

  int usrChoice;
  int compChoice;
  int usrScore = 0;
  int compScore = 0;
  
  int seed;
  cout << "Random seed: ";
  cin >> seed;
  
  cout << "Please type 1 for rock, 2 for paper, 3 for scissors or 0 to exit" << endl;

  do{
    
    compChoice = randGenerator(seed);
    cout << "Your choice: ";
    cin >> usrChoice;

    commentator(usrChoice, compChoice); // Tells you what happened
    referee(usrScore, compScore, usrChoice, compChoice); // Announces winner and keeps score

  } while( usrChoice != 0 );

  referee(usrScore, compScore); // Announces winner

}
