#include <iostream>
#include <string>

using namespace std;

void arrayPrefSuff(int lps[], string pat) {
  int m = pat.size();

  lps[0] = 0;
  for(int j = 0, i = 1; i < m; ) {
    if(pat[i] == pat[j]) j++, lps[i] = j, i++;
    else {
      if(j != 0) j = lps[j - 1];
      else lps[i] = 0, i++;
    }
  }
}

void kmpSearch(string txt, string pat) {
  int m = pat.size();
  int n = txt.size();

  int lps[m];
  arrayPrefSuff(lps, pat);

  for(int i = 0, j = 0; i < n; ) {
    if(txt[i] == pat[j]) i++, j++;
    if(j == m) {
      cout << "Found at index " << i - j << "\n";
      j = lps[j - 1];
    } else if(i < n && txt[i] != pat[j]) {
      if(j != 0) j = lps[j - 1];
      else i++;
    }
  }
}

int main() {
  string text = "abxabcabcaby";
  string pattern = "abcaby";

  kmpSearch(text, pattern);
  return 0;
}