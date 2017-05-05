// Account.cpp
#include "Account.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
using std::sprintf;
int Account::_total_account = 0;
Account::Account():_id(0),_balance(0),_valid(false) 
{
	_total_account++;
}

Account::~Account() 
{
	_total_account--;
}

int Account::id() const
{
	return _id;
}

double Account::balance() const
{
	return _balance;
}
bool Account::valid() const
{
	return _valid;
}
std::string Account::profile() const
{
	char out[100];
	memset(out, 0, sizeof(out));
	sprintf(out, "ID:%d\nBALANCE:%.6lf\nVALID:N\n", _id, _balance); // 打成_valid 造成位数不对
	return out;
}
void Account::reset()
{
	_balance = 0;
}
bool Account::deposit(const double &num)
{
	if (num < 0)
		return false;
	else
		_balance += num;
	return true;
}
bool Account::draw(const double &num)
{
	if (num < 0 || (_balance <= num))
		return false;
	else
		_balance -= num;
	return true;
}
int Account::get_total_account()
{
	return _total_account;
}
