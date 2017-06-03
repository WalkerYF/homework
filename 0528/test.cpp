#include <iostream>
#include <vector>
using namespace std;

class test{
    static int a;
    int id;
public:
    test():id(a){a++;}
    int getId(){return id;}
    void setID(int number){id = number;}
};

int test::a = 0;


int main(){
    test t1;
    vector<test> t;
    t.push_back(t1);
    cout << t1.getId() << endl;
    cout << t[0].getId() << endl;
    // t1.setID(3);
    // cout << t1.getId() << endl;
    // cout << t[0].getId() << endl;
    t.begin()->setID(3);
    cout << t1.getId() << endl;
    cout << t.begin()->getId() << endl;

    return 0;
}