#include <iostream>
using std::cout;
using std::endl;




class B : public A
{
public:
    B(int a, int b):
    	A(a), _b(b) {}
    void show(){ 
    	A::show();
    	cout<<"b="<<_b<<endl; 
    }
private:
    int _b;
};
