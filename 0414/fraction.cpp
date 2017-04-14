
#include "fraction.h"
#include <iostream>
#include <algorithm>
using std::abs;

long long gcd2(long long numerator, long long denominator) 
{
	if (denominator == 0)
		return numerator;
	return gcd2(denominator, numerator % denominator);
}

void simple(long long num, long long den, long long & num2, long long & den2)
{
	long long gcd_num = gcd2(num, den);
	num2 = num / gcd_num;
	den2 = den / gcd_num;
}

int fraction::gcd(const int & numerator, const int & denominator) const
{
	if (denominator == 0)
		return numerator;
	return gcd(denominator, numerator % denominator);
}
void fraction::simp()
{
	int gcd_num = gcd(_numerator, _denominator);
	_numerator /= gcd_num;
	_denominator /= gcd_num;
	return ;
}
fraction::fraction(const int & numerator, const int & denominator):
	_numerator(numerator), _denominator(denominator)
{
	// if (_denominator < 0){
	// 	_denominator = 0 - _denominator;
	// 	_numerator = 0 - _numerator;
	// }
	simp();
}
    // The numerator and the denominato
    // fraction(5) = 5/1 = 5 :
fraction::fraction(const fraction & t):
fraction(t._numerator, t._denominator){};
void fraction::operator=(const fraction & t)
{
	_numerator = t._numerator;
	_denominator = t._denominator;
	simp();
}
// You must know the meaning of +-*/, don't you 
fraction fraction::operator+(const fraction & t) const
{
	fraction ans = *this;
	ans += t;
	return ans;
}
fraction fraction::operator-(const fraction & t ) const
{
	fraction ans = *this;
	ans -= t;
	return ans;
}
fraction fraction::operator*(const fraction & t ) const
{
	fraction ans = *this;
	ans *= t;
	return ans;
}
fraction fraction::operator/(const fraction & t ) const
{
	fraction ans = *this;
	ans /= t;
	return ans;
}

void fraction::operator+=(const fraction & t)
{
	this->simp();
	// t.simp();
	long long a1; 
	long long  a2;
	long long mid1 = (long long)(_numerator) * t._denominator + (long long)_denominator * t._numerator;
	long long mid2 =(long long)_denominator * t._denominator;
	 simple(mid1,mid2, a1, a2);
	*this = fraction(a1, a2);
}
void fraction::operator-=(const fraction & t)
{
	this->simp();
	// t.simp();
	long long a1; 
	long long  a2;
	long long mid1 = (long long)_numerator * t._denominator - (long long)_denominator * t._numerator;
	long long mid2 =(long long)_denominator * t._denominator;
	 simple(mid1,mid2, a1, a2);
	*this = fraction(a1, a2);
}
void fraction::operator*=(const fraction & t)
{
	this->simp();
	// t.simp();
	long long a1; 
	long long a2;
	 simple((long long)_numerator * t._numerator,
	 			 (long long)_denominator * t._denominator,
	 			 	 a1, a2);
	*this = fraction(a1, a2);
}
void fraction::operator/=(const fraction & t)
{
	this->simp();
	// t.simp();
	fraction div = fraction(t._denominator, t._numerator);
	*this *= div;
}
// Comparison operator
bool fraction::operator==(const fraction & t) const
{
	return (_numerator == t._numerator && _denominator == t._denominator);
}
bool fraction::operator!=(const fraction & t) const
{
	return !(*this == t);
}
bool fraction::operator<(const fraction & t) const
{
	bool ans = (abs((long long)_numerator * t._denominator) < abs((long long)_denominator * t._numerator));

	if ((_denominator < 0 && _numerator > 0 ) || (_denominator >0 && _numerator < 0)){
		return !ans;
	}
	else 
		return ans;
}
bool fraction::operator>(const fraction & t) const
{
	return !(*this <= t);
}
bool fraction::operator<=(const fraction & t) const
{
	return (*this < t || *this == t);
}
bool fraction::operator>=(const fraction & t) const
{
	return !(*this < t);
}
std::istream & operator>>(std::istream & in, fraction & t)
{
	int numerator, denominator;
	in >> numerator >> denominator;
	t = fraction(numerator, denominator);
	return in;
}
    // Input Format: two integers with a space in it
    // "a b" is correct. Not "a/b"
std::ostream & operator<<(std::ostream & out, const fraction & t)
{
	if (t._denominator == 0)
		out << "NaN" ;
	else
		{ 
		if (t._denominator == 1)
			out << t._numerator;
		else 
			out << ((t._numerator < 0 ||  t._denominator < 0)? "-":"" )
			    << abs(t._numerator) << "/" << abs(t._denominator);
		}
	return out;
}
    // Normally you should output "a/b" without any space and L
    // Sometims you may output a single integer (Why? Guess XD)
    // If it is not a number (den = 0), output "NaN"
// void simple(long long num, long long den)
// {

// }

