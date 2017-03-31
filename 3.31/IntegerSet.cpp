//  If k is invalid, print "Invalid insert attempted!\n".
//  "Invalid delete attempted\n".
//  A printSet member function (already provided) prints a set as a list of numbers separated by spaces. Print only those elements which are present in the set (i.e., their position in the array has a value of 1). Print "---"

// without quotation marks for an empty set.

#include "IntegerSet.h"


IntegerSet::IntegerSet(int s[], int l)
{
	emptySet();
	for (int i = 0; i < l; i++){
		if (validEntry(s[i]))
			set[s[i]] = 1;
		else
			cout << "Invalid insert attempted!\n";
	}
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet& t)
{
	IntegerSet ans;
	for (int i = 0; i < 101; i++){
		if (this->set[i] == 1 || t.set[i] == 1)
			ans.set[i] = 1;
	}
	return ans;
}


IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& t)
{
	IntegerSet ans;
	for (int i = 0; i < 101; i++){
		if (this->set[i] == 1 && t.set[i] == 1)
			ans.set[i] = 1;
	}
	return ans;
}


void IntegerSet::emptySet()
{
	for (int i = 0; i < 101; i++){
		set[i] = 0;
	}
}

void IntegerSet::insertElement(int element)
{
	if (validEntry(element))
		set[element] = 1;
	else
		cout << "Invalid insert attempted!\n";
	return ;
}
void IntegerSet::deleteElement(int element)
{
	if (validEntry(element))
		set[element] = 0 ;
	else 
		cout <<"Invalid delete attempted\n";
	return ;
}

bool IntegerSet::isEqualTo(const IntegerSet& t) const
{
	int flag = 1;
	for (int i = 0; i < 101; i++){
		if (set[i] != t.set[i])
			flag = 0;
	}
	return flag;
}
