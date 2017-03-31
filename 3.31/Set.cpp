#include "Set.hpp"
#include <cstring>
#include <cstdlib>
#include <algorithm>

// Create an empty set.
Set::Set()
{
	size = 0;
	std::memset(members, 1, sizeof(members));
}
// Create an set with some element.
Set::Set(int* m, int s)
{
	size = s;
	std::memset(members, 1, sizeof(members));
	for (int i = 0; i < s; i++){
		members[i] = m[i];
	}
}
// Copy Constructor
Set::Set(Set const &s)
{
	size = s.size;
	std::memset(members, 1, sizeof(members));
	for (int i = 0; i < size; i++){
		this->members[i] = s.members[i];
	}
}
// append a element to set.
// If element in the set, return false.
// Or insert in set and return true.
bool Set::append(int e)
{
	if (isInSet(e)) 
		return false;
	else{
		members[size] = e;
		size++;
		return true;
	}
}
// remove a element by its value from set.
// If element in the set, then remove it and return true.
// Or return false.
bool Set::remove(int e)
{
	int * find_mem = std::find(members,members+size,e);
	if ( find_mem != members+size){
		std::swap(*find_mem, members[size-1]);
		size -= 1;
		members[size] = 0;
		return true;

	} 
	else{
		return false;
	}
}
// return true if the set is empty, or return false.
bool Set::isEmptySet()
{
	return !size;
}
// return true if the element e is in the set, or return false.
bool Set::isInSet(int e)
{
	int * find_mem = std::find(members,members+size,e);
	if (find_mem == members+size)
		return false;
	else
		return true;
}
// & is intersection of two set
Set Set::operator&(const Set &s)
{
	Set ans;
	for (int i = 0; i < s.size; i++){
		if (isInSet(s.members[i])){
			ans.append(s.members[i]);
		}
	}
	return ans;
}
// | is union of two set
Set Set::operator|(const Set &s)
{
	Set ans = *this;
	for (int i = 0; i < s.size; i++){
		ans.append(s.members[i]);
	}
	return ans;
}
// A - B is the complement of B with respect to A
Set Set::operator-(const Set &s)
{
	Set ans;
	Set t_s = s;
	for (int i = 0; i < size; i++){
		if (!t_s.isInSet(members[i])){
			ans.append(members[i]);
		}
	}
	return ans;
}
// A + B is their symmetric difference. A + B = (A - B) | (B - A)
Set Set::operator+(const Set &s)
{
	Set t1 = *this;
	Set t2 = s;
	return ((t1-t2)|(t2 - t1));
}
// return set.
int* Set::getMembers()
{
	return members;
}
// return size of set.
int Set::getSize()
{
	return size;
}