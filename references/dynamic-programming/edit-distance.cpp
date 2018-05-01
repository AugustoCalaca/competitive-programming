#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int editDistance(string str1, string str2) {
  int sz1 = str1.size();
  int sz2 = str2.size();
  int pd[sz1 + 1][sz2 + 1];

  for(int i = 0; i <= sz1; i++) pd[i][0] = i;
  for(int j = 0; j <= sz2; j++) pd[0][j] = j;

  for(int i = 1; i <= sz1; i++) {
    for(int j = 1; j <= sz2; j++) {
      if(str1[i] == str2[j]) pd[i][j] = pd[i - 1][j - 1];
      else pd[i][j] = min(min(pd[i - 1][j], pd[i][j - 1]), pd[i - 1][j - 1]) + 1;
    }
  }

  return pd[sz1][sz2];
}
