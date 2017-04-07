// This is an easy big integer. Your task is to finish the class big integer:

// Tips:

// size_ means the size of the big integer

// friend function should have been declared outside;

// when you declare the friend function, you should forward declare the class.

// when you cannot compile, try to read the informations or google it.

// overload "<<" : please output like this format: "123456", no wrap.

// overload "-": we promise that a > b when a - b .

// Hint

// operator overloading
// ( we promise that left will bigger than right when doing subtract operation )

// friend function

// deep copy

// From: 欧文杰

//from low to high
 
#include "Biginteger.h"
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 10000
using std::string;
using std::max;
using std::min;

BigInteger::BigInteger()
{
	data_ = nullptr;
	size_ = 0;
}
BigInteger::BigInteger(const string& number)
{
	size_ = number.size();
	data_ = new int [MAX];
	std::memset(data_, 0, sizeof(int) * MAX);
	for (int i = 0; i < size_; i++){
		data_[i] = number[size_-1-i]-'0';
	}
}
BigInteger::BigInteger(const BigInteger& other)
{
	size_ = other.size_;
	data_ = new int [MAX];
	std::memset(data_, 0, sizeof(int) * MAX);
	for (int i = 0; i < size_; ++i){
		data_[i] = other.data_[i];
	}
}

 BigInteger::~BigInteger()
 {
 	delete [] data_;
 	size_ = 0;
 }


BigInteger operator+(const BigInteger& left, const BigInteger& right)
{
	BigInteger ans;
	int max_len = max(left.size_, right.size_);
	int min_len = min(left.size_, right.size_);
	ans.data_ = new int[MAX];
	std::memset(ans.data_, 0, sizeof(int)*MAX);
	int carry = 0;
	int cur = 0;
	int len = 0;
	for (int i = 0; i < max_len; i++){
		cur = (left.data_[i] + right.data_[i] + carry)%10;
		ans.data_[i] = cur;
		carry = (left.data_[i] + right.data_[i] +carry)/10;
		ans.size_++;
	}
	// i == max_len
	if (carry != 0){
		ans.data_[max_len] = carry;
		ans.size_++;
	}
	return ans;
}
BigInteger operator-(const BigInteger& left, const BigInteger& right)
{
	BigInteger ans;
	ans.data_ = new int [MAX];
	int borrow = 0;
	int cur = 0;
	for (int i = 0; i < left.size_; i++){
		if (left.data_[i] < right.data_[i]){
			borrow = 1;
			left.data_[i+1]--;
		}
		else{
			borrow = 0;
		}
		cur = (borrow * 10 + left.data_[i] - right.data_[i]);
		ans.data_[i] = cur;
		ans.size_++;
	}
	for (int i = ans.size_-1; i >= 0; i--){
		if (ans.data_[i] != 0)
			break;
		if (ans.data_[i] == 0)
			ans.size_--;
	}
	return ans;
}
ostream& operator<<(ostream& out, const BigInteger& Bint)
{
	for (int i = Bint.size_-1; i >= 0 ; --i){
		out << Bint.data_[i];
	}
	return out;
}