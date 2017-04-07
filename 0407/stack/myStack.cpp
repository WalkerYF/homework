 #include "myStack.h"

myStack::myStack()
{
	mtop = nullptr;
	_size = 0;
}
myStack::myStack(const myStack &stack)
{
	mtop = nullptr;
	_size = 0;
	if (stack.empty()){
		// mtop = nullptr;
		// _size = 0;
	}
	else{
		Node * t = stack.mtop;

		// the first node
		mtop = new Node;
		mtop->number = t->number;
		mtop->next = nullptr;
		_size++;

		Node * cur = mtop;
		t = t->next;

		while (t != nullptr){
			Node * new_node = new Node;
			new_node->number = t->number;
			new_node->next = nullptr;

			cur->next = new_node;
			cur = cur->next;
			_size++;
			t = t->next;
		}
	}
}
myStack::myStack(const int *arr, const int _size) 
// 用数组构造,按顺序压栈
{
	this->mtop = nullptr;
	this->_size = 0;
	
	if (_size == 0){
		// this->mtop = nullptr;
		// this->_size = 0;
	}
	else {
		// push the first element
		mtop = new Node;
		mtop->number = arr[0];
		mtop->next = nullptr;
		this->_size++;
		Node * cur = mtop;

		for (int i = 1; i < _size; i++){
			push(arr[i]);
		}
	}
}
myStack::~myStack()
{
	Node * cur = mtop;
	Node * temp = nullptr;
	while (cur != nullptr){
		temp = cur;
		cur = cur->next;
		delete temp;
	}
}
bool myStack::empty() const  // 栈空则返回true
{
	if (_size == 0 
		|| mtop == nullptr)
		return 1;
	return 0;
}
int myStack::top() const // 返回栈顶元素，如果栈为空则返回0
{
	if (empty()){
		return 0;
	}
	else {
		return mtop->number;
	}
}

bool myStack::pop(){
	if (empty()){
		return false;
	}
	else{
		Node * temp = mtop;
		mtop = mtop->next;
		delete temp;
		_size--;
		return true;
	}
}
bool myStack::push(int _number) // 请注意push失败的情况，即new失败
{
	Node * new_node = new Node;
	if (new_node == nullptr){
		return false;
	}
	else{
		new_node->number = _number;
		new_node->next = mtop;
		mtop = new_node;
		_size++;
		return true;
	}
}
int myStack::size() const
{
	return _size;
}

myStack& myStack::operator=(const myStack& stack)
{
	Node * cur = mtop;
	Node * temp = nullptr;
	while (cur != nullptr){
		temp = cur;
		cur = cur->next;
		delete temp;
	}
	mtop = nullptr;
	_size = 0;


	if (stack.empty()){
		// mtop = nullptr;
		// _size = 0;
	}
	else{

		Node * t = stack.mtop;

		// the first node
		mtop = new Node;
		mtop->number = t->number;
		mtop->next = nullptr;
		_size++;
		cur = mtop;
		t = t->next;

		while (t != nullptr){
			Node * new_node = new Node;
			new_node->number = t->number;
			new_node->next = nullptr;

			cur->next = new_node;
			_size++;
			cur = cur->next;
			t = t->next;
		}
	}
	return *this;
}