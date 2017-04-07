#include "Biginteger.h"
#include <iostream>
#include <string>
using namespace std;
 
int main() {
  string s1, s2, s3, s4;
  cin >> s1 >> s2;
  cin >> s4;
  cout << s1 << endl;
  cout << s2 << endl;
  BigInteger a(s1);
  BigInteger b(s2);
  BigInteger c(a);
  BigInteger d(s4);
  cout << a << endl;
  cout << b << endl;
  BigInteger sum(a+b);
  BigInteger diff(a-b);
  cout << sum << endl;
  cout << diff << endl;
  return 0;
}
 