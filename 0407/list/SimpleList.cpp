#include <cstdio>
#include "SimpleList.hpp"


list::list()
{
	this->head = nullptr;
	this->_size = 0;
}
list::list(const list& t)
{
	if (t.empty()){
		this->head = nullptr;
		this->_size = 0;
	}
	else {
		// the first node
		// X -> NULL
		node * new_node = new node(t.head->data, nullptr);
		this->head = new_node;

		// t:    x->x->c->.....
		// this: x->c->null
		node * cur_t_node = t.head->next;
		node * cur_this_node = this->head;
		while (cur_t_node != nullptr){
			cur_this_node->next = new node (cur_t_node->data, nullptr);
			cur_t_node = cur_t_node->next;
			cur_this_node = cur_this_node->next;
		}

		this->_size = t._size;
	}
}
list& list::operator=(const list& t)
{
	//if the oroginal list is not empty, clear it
	if (!(this->empty())){
		node * cur = this->head;
		while (cur != nullptr){
			node * temp = cur;
			cur = cur->next;
			delete temp;
		}
		this->head = nullptr;
		this->_size = 0;
	}

	if (!(t.empty() )){
		// the first node
		// X -> NULL
		node * new_node = new node(t.head->data, nullptr);
		this->head = new_node;

		// t:    x->c->.....
		// this: x->c->null
		node * cur_t_node = t.head->next;
		node * cur_this_node = this->head;
		while (cur_t_node != nullptr){
			cur_this_node->next = new node (cur_t_node->data, nullptr);
			cur_t_node = cur_t_node->next;
			cur_this_node = cur_this_node->next;
		}
		this->_size = t._size;
	}
	return *this;
}
list::~list()
{
	//if the oroginal list is not empty, clear it
	if (!(this->empty())){
		node * cur = this->head;
		while (cur != nullptr){
			node * temp = cur;
			cur = cur->next;
			delete temp;
		}
		this->head = nullptr;
		this->_size = 0;
	}

}
 
  // Capacity
bool list::empty(void) const
{
	return !this->_size;
}
int list::size(void) const
{
	return _size;
}
std::string list::toString(void) const
{
	std::string ans;
	node * cur_node = this->head;

	// the first node
	while (cur_node != nullptr){
		char  num_to_str[50];
		sprintf(num_to_str, "%d",cur_node->data);
		ans += std::string(num_to_str) + std::string("->");
		cur_node = cur_node->next;
	}
	ans += std::string("NULL");
	return ans;

}
void list::insert(int position, const int& data)
{



	if (position < 0 || position > _size){
		// std::cout << "throw a exception here!!!\n";
		return ;
	}
	node * new_node = new node(data, nullptr);
	if (this->empty()){
		this->head = new_node;
		this->_size++;
		return ;
	}


	// the first
	if (position == 0){
		new_node->next = this->head;
		this->head = new_node;
	}
	else {
		// include the mid and the last
		int cnt = 0;
		node * cur_node = this->head;
		// x->x -> x->x->NULL
		//    c  i 
		while (cnt < position-1){
			cur_node = cur_node->next;
			cnt++;
		}
	
		new_node->next = cur_node->next;
		cur_node->next = new_node;
	}
	this->_size++;
	return ;
}


void list::erase(int position)
{
	if (position < 0 || position > _size-1){
		// std::cout << "throw a exception here!!!\n";
		return ;

	}

	if (this->empty()){
		// std::cout << "It is empty!!!\n";
		return ;
	}

	// the first	
	if (position == 0){
		node * temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
	else {
	// the mid and last element
		int cnt = 0;
		node * delete_node = this->head;
		node * front_delete_node = nullptr;	

		while (cnt < position){
			front_delete_node = delete_node;
			delete_node = delete_node->next;
			cnt++;
		}

		front_delete_node->next = delete_node->next;
		delete delete_node;
	}
	this->_size--;
	return ;
}


list& list::sort(void)
{
	if (this->empty())
		return *this;
	if (this->_size == 1){
		return *this;
	}
	for (node * p1 = this->head; p1 != nullptr; p1 = p1->next){
		for (node * p2 = p1->next; p2 != nullptr; p2 = p2->next){
			if (p1->data > p2->data){
				int temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}
		}
	}
	return *this;
}