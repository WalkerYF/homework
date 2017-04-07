#include <iostream>
#include "myStack.h"

using namespace std;

int main() {
 int a[100];
 int n, m, num;
 cin >> n >> m;
 myStack s1;
 cout << "s1 is empty? " << s1.empty() << endl;
 for (int i = 0; i < n/2; ++i) {
  cin >> num;
  s1.push(num);
 }
 cout << "s1's size is " << s1.size() << endl;
 myStack s2(s1), s3;
 for (int i = 0;  i < m; ++i) {
  s1.pop();
 }
 cout << "now s1's size is " << s1.size() << endl;
 for (int i = n/2; i < n; ++i) {
  cin >> num;
  s1.push(num); s3.push(num);
 }
 cout << "s1's size is " << s1.size() << endl;
 cout << "s1 is " << s1 << endl;
 cout << "s3 is " << s3 << endl;
 cout << "s2's top is " << s2.top() << endl;
 s2.pop();
 cout << "s2 is "  << s2 << endl;
 cout << "s2 is empty?" << s2.empty() << endl;
 s2 = s1;
 cout << "now s2 is " << s2 << endl;
 cin >> n;
 for (int i = 0; i < n; ++i) {
  cin >> a[i];
 }
 myStack s4(a, n);
 cout << "s4's size is " << s4.size() << endl;
 cout << "s4 is " << s4 << endl;
 s3 = s4; s3.pop();
 cout << "s3 is " << s3 << endl;
 return 0;
}
