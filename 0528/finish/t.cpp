#include <queue>
#include <iostream>
using std::cout;
using std::endl;
using std::queue;

template <typename T>
class Stack {
  public:
    Stack(); // constructor.
    void push(const T& data); // push operation.
    T pop(); // return the value in the top and pop it out of the stack.
    T top(); // return the value in top.
    int size() const;  // return size of the stack.
    bool empty(); // check whether is empty.
    void print();
  private:
    queue<T> q1; // two queues.
    queue<T> q2;
    int count; // the number of elements.
};

template <typename T>
Stack<T>::Stack(){
    count = 0;
}

template <typename T>
void Stack<T>::push (const T & data){
    q1.push(data);
    count++;
}

template <typename T>
T Stack<T>::pop() {
    if (empty())
        return 0;
    count--;
    for ( int i = 0 ; i <  count; i++){
        q2.push(q1.front());
        q1.pop();
    }
    T temp = q1.front();
    q1.pop();
    for (int i = 0; i < count; i++){
        q1.push(q2.front());
        q2.pop();
    }
    return temp;
}

template <typename T>
T Stack<T>::top() {
    return q1.back();
}

template <typename T>
int Stack<T>::size() const {
    return this->count;
}

template <typename T>
bool Stack<T>::empty() {
    return (count == 0);
}

template<typename T>
void Stack<T>::print(){
    T data[count];
    for (int i = 0; i < count; i++){
        data[i] = q1.front();
        q1.pop();
        q2.push(data[i]);
    }
    for (int i = count-1; i >= 0; i--){
        cout << data[i] << " " ;
    }
    for (int i = 0; i < count ; i++){
        q1.push(q2.front());
        q2.pop();
    }
    cout << endl;

} 

template<typename T>
void print(Stack<T> &t){
    t.print();
}



#include<iostream>
#include<exception>

using namespace std;

class StackForbidden : public exception {
    virtual const char *what() const throw() {
        return "Please do not use Stack in stl..";
    }
};

int main() {

    #if defined(_GLIBCXX_STACK)
        throw StackForbidden();
    #endif

    Stack<int> stack;
    stack.push(88);
    stack.push(44);
    stack.push(99);

    cout << "The size is: " << stack.size() << endl;
    if (!stack.empty()) cout << stack.top() << endl;
    print(stack);

    stack.pop();
    print(stack);

    stack.push(777);
    cout << "The size is: " << stack.size() << endl;
    if (!stack.empty()) cout << stack.top() << endl;
    print(stack);

    stack.pop();
    stack.pop();
    cout << "The size is: " << stack.size() << endl;
    print(stack);
    stack.pop();
    if (!stack.empty()) cout << stack.top() << endl;
    else cout << "it is empty now." << endl;

    Stack<double> stack1;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        stack1.push(i + 0.01);
    }
    print(stack1);
    while (m--) {
        stack1.pop();
    }
    cout << "The size is: " << stack1.size() << endl;
    if (!stack1.empty()) cout << stack1.top() << endl;
    print(stack1);

}
