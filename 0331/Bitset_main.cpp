#include<iostream>
#include"Bitset.h"
using namespace std;
int main() {
    // bitset a;
    // for (int i = 0; i < 10; i++)
    //     a.set(i);
    // cout << a << endl;
    // a.reset(4);
    // cout << a << endl;
    // a.reset(5);
    // cout << a << endl;
    // a = ~a;
    // cout << a << endl;
    // a.reset(7);
    // cout << a << endl;
    // a = a << 1;
    // cout << a << endl;
    // a <<= 80;
    // cout << a << endl;
    // a = a >> 1;
    // cout << a << endl;
    
    bitset a, b;
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.set(x);
    }
    cout << "a.count() is " << a.count() << "\n";
    cout << "a.test(5) is " << (a.test(5) ? "true" : "false") << "\n";
    cout << "a.any() is " << (a.any() ? "true" : "false") << "\n";
    cout << "a.none() is " << (a.none() ? "true" : "false") << "\n";
    cout << "a.all() is " << (a.all() ? "true" : "false") << "\n";
    b = ~b;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.reset(x);
    }
    cout << a << "\n";
    cout << b << "\n";
    if (a == b) {
        cout << "hello\n";
    }
    if (a != b) {
        cout << "world\n";
    }
    bitset c;
    // test &
    c = a;
    c &= b;
    cout << c << "\n";
    c = a & b;
    cout << c << "\n";
    // test |
    c = a;
    c |= b;
    cout << c << "\n";
    c = a | b;
    cout << c << "\n";
    // test ^
    c = a;
    c ^= b;
    cout << c << "\n";
    c = a ^ b;
    cout << c << "\n";
    // test <<
    c = a;
    c <<= 2;
    cout << c << "\n";
    c = a << 2;
    cout << c << "\n";
    // test >>
    c = b;
    c >>= 2;
    cout << c << "\n";
    c = b >> 2;
    cout << c << "\n";
    // test []
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (a[i])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

