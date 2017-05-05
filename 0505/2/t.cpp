#include <iostream>
#include <cstdio>
using namespace std;
class INT
{
    int _data[200];
    int _length;
  public:
    INT(){
        for (int i = 0; i < 200; i++)
            _data[i] = 0;
        _length = 0;
    }
    INT(int n):INT(){
        int temp = n;
        int i = 0;
        _length = 0;
        while (temp != 0){
            int lsb = temp % 10;
            _data[i] = lsb;
            i++;
            temp = temp / 10;
            _length ++;
        }
    }
    void print() const{
        for (int i = _length-1; i >= 0; i--){
            cout << _data[i];
        }
    }
    int getLength() const{
        return _length;
    }
    friend INT  operator+(const INT & lhs, const INT & rhs){
        INT ans;
        if (lhs._length < rhs._length)
            return rhs + lhs;
        else {
            int carry = 0;
            for (int i = 0; i < 200; i++){
                if (carry == 0 && lhs._data[i] == 0 && rhs._data[i] == 0 && (i > rhs._length-1 && i > lhs._length-1 ) ){
                    ans._length = i;
                    break;
                }
                ans._data[i] = (lhs._data[i] + rhs._data[i] + carry) % 10;
                carry = (lhs._data[i] + rhs._data[i] + carry) / 10;
            }
        }
        return ans;
    }
} ;
int main()
{
    int m, d;
    cin >> m >> d;
    while (m != 0 || d != 0)
    {
        INT num[d + m + 1];
        int i = 1;
        for (; i <= m; i++)
        {
            num[i] = 1;
        }
        for (; i <= d + m; i++)
        {
            num[i] = num[i - 1] + num[i - m];
        }
        num[d + m].print();
        cout << endl;
        cin >> m >> d;
    }
    // INT num[4];
    // for (int i = 1; i <=4; i++){
    //     num[i-1] = i;
    // }
    // for (int i = 0; i <4; i++){
    //     num[i].print();
    // }
    // cout  << c.getLength() << endl;

}