// Account.cpp
#include "Account.h"
#include <cstdlib>
#include <cstdio>
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
	sprintf(out, "ID:%d\nBALANCE:%.6lf\nVALID:N\n", _id, _valid);
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
}
bool Account::draw(const double &num)
{
	if (num < 0 || (_balance < num))
		return false;
	else
		_balance -= num;
}
int Account::get_total_account()
{
	return _total_account;
}
