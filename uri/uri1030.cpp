
#include <iostream>

using namespace std;

// accepted
int main(){
  int numPersons, jump, cases;

  cin >> cases;
  for(int inc = 1 ; inc <= cases; inc++){
    cin >> numPersons >> jump;
      int dead = 1;
      for( int i = 2; i <= numPersons; i++ )
        dead = (dead + jump) % i ? (dead + jump) % i : i;
      cout << "Case " << inc << ": " << dead << "\n";
  }

  return 0;
}
