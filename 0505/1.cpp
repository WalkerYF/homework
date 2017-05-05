#include <iostream>
using std::cout;
using std::endl;

class A
{
  public:
    A() {}
    A(int a){}
    virtual void Prin()
    {
        cout << "Prin come form class A" << endl;
    }
    virtual ~A()
    {
        cout << "A::~A()called" << endl;
    }

};
class B : public A
{
    char *buf;

  public:
    B() {}
    B(int b)
    {
        buf = nullptr;
    }
    void Prin()
    {
        cout << "Prin come from class B" << endl;
    }
    ~B()
    {
        cout << "B::~B()called" << endl;
    }
};

void fun(A *a)
{
    delete a;
}
int main()
{
    A *a = new B(10);
    a->Prin();
    fun(a);
    B *b = new B(20);
    fun(b);
    return 0;
}

// Prin come from class B
// B::~B()called
// A::~A()called
// B::~B()called
// A::~A()called