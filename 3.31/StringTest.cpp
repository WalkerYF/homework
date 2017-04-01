#include <iostream>
#include <cstring>
#include "String.h"
#include <string>
using namespace std;
 
String a("HYOUKAQWERTYMORE"), b("MFGZ!");
String c = a;
 
void display() {
  cout << a.empty() << " " << a.length() << " " << a << endl;
  cout << b.empty() << " " << b.length() << " " << b << endl;
  cout << c.empty() << " " << c.length() << " " << c << endl;
}
 
int main() {
  cout << a.find(String("1993")) << endl;
  cout << b.find(String("HYOUKA")) << endl;
  cout << c.find(String("RIKKA")) << endl;
  cout << a.substr(0, 3) << endl;
  cout << c.substr(3, 8) << endl;
  cout << b.substr(6, 1) << endl;
  cout << (a > b) << (a >= b) << (a < b) << (a <= b) << (a == b) << endl;
  cout << a.compare(b) << b.compare(a) << endl;
  cout << (a > c) << (a >= c) << (a < c) << (a <= c) << (a == c) << endl;
  cout << a.compare(c) << c.compare(a) << endl;
  b = a;
  cout << (a > b) << (a >= b) << (a < b) << (a <= b) << (a == b) << endl;
  cout << a.compare(b) << b.compare(a) << endl;
  cout << a.compare(a) << endl;
  return 0;
}
 