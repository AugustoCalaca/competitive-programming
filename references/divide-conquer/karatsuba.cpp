#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int makeEqualSize(string& a, string& b) {
  int sz1 = a.size();
  int sz2 = b.size();

  if(sz1 < sz2) {
    for(int i = 0; i < sz2 - sz1; i++)
      a = '0' + a;
    return sz2;
  } else if(sz2 < sz1) {
    for(int i = 0; i < sz1 - sz2; i++)
      b = '0' + b;
  }

  return sz1;
}

int karatsubaSingleBit(string& a, string& b) {
  return (a[0] - '0') * (b[0] - '0');
}

string addBit(string& a, string& b) {
  string ans;
  int sz = makeEqualSize(a, b);
  int carry = 0;

  for(int i = sz - 1; i >= 0; i--) {
    int firstBit = a[i] - '0';
    int secondBit = b[i] - '0';

    char sum = (firstBit ^ secondBit ^ carry) + '0';
    carry = ((firstBit & secondBit) ||
             (firstBit & carry) ||
             (secondBit & carry));
    ans = sum + ans;
  }

  // overflow
  if(carry) ans = '1' + ans;

  return ans;
}

ll karatsuba(string a, string b) {
  int n = makeEqualSize(a, b);

  if(n == 0) return 0;
  if(n == 1) return karatsubaSingleBit(a, b);

  // first half and second half
  int fh = n / 2;
  int sh = n - fh;

  // a -> left, a -> right, b -> left and b -> right
  string al = a.substr(0, fh);
  string ar = a.substr(fh, sh);
  string bl = b.substr(0, fh);
  string br = b.substr(fh, sh);

  ll z2 = karatsuba(al, bl);
  ll z1 = karatsuba(addBit(al, ar), addBit(bl, br));
  ll z0 = karatsuba(ar, br);

  return z2 * (1 << (2 * sh)) + (z1 - z2 - z0) * (1 << sh) + z0;
}

int main() {
  cout << karatsuba("1101", "10") << '\n';
  // 13 * 2 = 26
}