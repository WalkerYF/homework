const int MAX_LEN = 5;
template<class T>
class Stack

{

public:

    explicit Stack(){
        stack_size = 0;
    }

    bool empty() const
    {
        return !stack_size;
    }

    int size() const{
        return stack_size;
    }

    T& top(){
        if (empty()){
            throw int(3);
        }
        return data[stack_size-1];
    }

    const T& top() const{
        if (empty()){
            throw int(3);
        }
        return data[stack_size-1];
    }

    void push(const T& x){
        if (stack_size == 5 ){
            if ( x > data[stack_size-1])
                data[stack_size-1] = x;
        }
        else{
            data[stack_size] = x;
            stack_size++;
        }
        return ;
    }

    void pop(){
        if (empty()){
            throw double(0.1);
        }
        stack_size--;
        return ;
    }

private:

    T data[MAX_LEN];

    int stack_size;

};





#include <iostream>

using namespace std;

int main() {
    Stack<int> s;
    cout << s.size() << endl;
    for (int i = 10; i < 15; i++) {
        s.push(i);
        cout << s.size() << endl;
    }
    cout << s.size() << endl;
    s.push(12);
    cout << s.top() << endl;
    cout << s.size() << endl;
    s.push(16);
    cout << s.top() << endl;
    cout << s.size() << endl;

    for (int i = 5; i >= 0; i--) {
        try {
            cout << s.top() << endl;
        }
        catch(int int_e) {
            cout << "get top failed" << endl;
        }

        try {
            s.pop();
        }
        catch(double dou_e) {
            cout << "pop failed" << endl;
        }

        cout << s.size() << endl;
    }

    for (int i = 10; i < 15; i++) {
        s.push(i);
        cout << s.size() << endl;
        cout << s.top() << endl;
    }
    return 0;
}

