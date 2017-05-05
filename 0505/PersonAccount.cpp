// PersonAccount.cpp
#include "PersonalAccount.h"
#include <cstdlib>
#include <cstdio>
#include <cstdlib>
using std::sprintf;
int PersonalAccount::_total_per_account = 0;
int PersonalAccount::_acc_id_ptr = 0;

PersonalAccount::PersonalAccount()
{
	_id = (12010000 + _acc_id_ptr);
	_balance = (10);
	_valid = (true);
	_total_per_account++; 
	_acc_id_ptr++;
}
PersonalAccount::~PersonalAccount()
{
	_total_per_account--;
}
// override
std::string PersonalAccount::profile() const
{
	char out[100];
	sprintf(out, "ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:PERSONAL\n", _id, _balance);
	return out;
}
void PersonalAccount::reset()
{
	_balance = 0;
}
// static
int PersonalAccount::get_total_per_account()
{
	return _total_per_account;
}