#include <iostream>
#define INF 1100000000

using namespace std;

// accepted
int main() {
  int prime[35], interval[35], n;

  prime[0] = 2; interval[0] = 0;
  prime[1] = 3; interval[1] = 1;
  prime[2] = 5; interval[2] = 2;
  prime[3] = 11; interval[3] = 4;
  prime[4] = 29; interval[4] = 6;
  prime[5] = 97; interval[5] = 8;
  prime[6] = 127; interval[6] = 14;
  prime[7] = 541; interval[7] = 18;
  prime[8] = 907; interval[8] = 20;
  prime[9] = 1151; interval[9] = 22;
  prime[10] = 1361; interval[10] = 34;
  prime[11] = 9587; interval[11] = 36;
  prime[12] = 15727; interval[12] = 44;
  prime[13] = 19661; interval[13] = 52;
  prime[14] = 31469; interval[14] = 72;
  prime[15] = 156007; interval[15] = 86;
  prime[16] = 360749; interval[16] = 96;
  prime[17] = 370373; interval[17] = 112;
  prime[18] = 492227; interval[18] = 114;
  prime[19] = 1349651; interval[19] = 118;
  prime[20] = 1357333; interval[20] = 132;
  prime[21] = 2010881; interval[21] = 148;
  prime[22] = 4652507; interval[22] = 154;
  prime[23] = 17051887; interval[23] = 180;
  prime[24] = 20831533; interval[24] = 210;
  prime[25] = 47326913; interval[25] = 220;
  prime[26] = 122164969; interval[26] = 222;
  prime[27] = 189695893; interval[27] = 234;
  prime[28] = 191913031; interval[28] = 248;
  prime[29] = 387096383; interval[29] = 250;
  prime[30] = 436273291; interval[30] = 282;
  prime[31] = INF;

  cin.tie(NULL);
  cout.sync_with_stdio(false);

  while(cin >> n) {
    int i = 0;
    for(; prime[i] <= n; i++) {};
    cout << interval[i - 1] << "\n";
  }


  return 0;
}