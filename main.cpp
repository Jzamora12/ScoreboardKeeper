#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;

void printScoreboard(vector < vector <int> >);
int randomBetween( int, int );

int main()
{
  srand((int) time(0));
  int periods;
  int teams;

  cout<<"How many competitors? ";
  cin>>teams;
  cout<<"How many scoring periods? ";
  cin>>periods;

  if( teams < MIN_TEAMS || periods < MIN_PERIODS || 
      teams > MAX_TEAMS || periods > MAX_PERIODS )
  {
    cout<<"Must have between "<<MIN_TEAMS<<" and "<<MAX_TEAMS<<" competitors.\n";
    cout<<"and between "<<MIN_PERIODS<<" and "<<MAX_PERIODS<<" periods.\n";
    return 0;
  }
  else
  {
   //make scoreboard and fill it with zeros
   vector < vector<int> > board; 
   board.resize(teams); 
   for ( int r=0; r < board.size(); r++ )
   {
     board[r].resize(periods);
   }
   printScoreboard(board);
  
    for ( int r=0; r < board.size(); r++ )
    {
      for ( int c=0; c < board[r].size(); c++ )
      {
        board[r][c] = randomBetween(5,5);
      }
    }
   printScoreboard(board);

  }
  return 0;
}

void printScoreboard(vector< vector<int> > board)
{
  cout<<"SCOREBOARD\n";
  for ( int r=0; r < board.size(); r++ )
  {
    cout<<"Player "<< r+1 <<": ";
    for ( int c=0; c < board[r].size(); c++)
    {
      cout<<board[r][c]<<"|";
    }
    cout<<endl;
  }
}

int randomBetween( int first,int second )
{
  if ( first > second )
  {
    return second + rand()%(first-second+1);
  }
  else if ( second > first ) 
  { 
    return first + rand()%(second-first+1);
  }
}
