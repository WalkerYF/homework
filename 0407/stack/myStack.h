#ifndef MYSTACK__H__
#define MYSTACK__H__
#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
 int number;
 Node *next;
};

class myStack {
private:
 Node *mtop;
 int _size;
public:
 myStack();
 myStack(const myStack &stack);
 myStack(const int *arr, const int _size); // 用数组构造,按顺序压栈
 ~myStack();
 bool empty() const;  // 栈空则返回true
 int top() const; // 返回栈顶元素，如果栈为空则返回0
 bool pop();  
 bool push(int _number); // 请注意push失败的情况，即new失败
 int size() const;

 myStack& operator=(const myStack& stack);
 friend ostream& operator<<(ostream& out, const myStack& stack) {
  Node *t = stack.mtop;
 if (t == NULL) {
  out << "The stack is empty!";
  return out;
 }
 while (t != NULL) {
  out << t->number << ' ';
  t = t->next;
 }
 return out;
 };
};

#endif