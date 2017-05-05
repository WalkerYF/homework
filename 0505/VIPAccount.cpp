// VIPAccount.cpp
#include "VIPAccount.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
using std::sprintf;
int VIPAccount::_total_vip_account = 0;
int VIPAccount::_acc_id_ptr = 0;

VIPAccount::VIPAccount()
{
	_id = (12050000 + _acc_id_ptr);
	_balance = 10;
	_valid = true;
	_loan = 0;
	_loan_limit = 1000;
	_total_vip_account++;
	_acc_id_ptr++;
}
VIPAccount::~VIPAccount()
{
	_total_vip_account--;
}
bool VIPAccount::loan(const double &num)
{
	if (num < 0 || _loan_limit <= (num + _loan))
		return false;
	else
	{
		_loan += num;
		_balance += num;
		return true;
	}
}
bool VIPAccount::repay(const double &num)
{
	if (num < 0 || num > _balance)
		return false;
	else
	{
		if (num < _loan)
		{
			_balance -= num;
			_loan -= num;
		}
		else //( num >= _loan)
		{
			_balance -= _loan;
			_loan = 0;
		}
		return true;
	}
}
// override
std::string VIPAccount::profile() const
{
	char out[120];
	sprintf(out, "ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:VIP\nLOAN:%.6lf,LIMIT:%.6lf\n", _id, _balance, _loan, _loan_limit);
	return out;
}
void VIPAccount::reset()
{
	_balance = 10;
	_valid = true;
	_loan = 0;
	_loan_limit = 1000;	
}
// static
int VIPAccount::get_total_vip_account()
{
	return _total_vip_account;
}
