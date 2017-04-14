
#include "fraction.h"
#include <iostream>
#include <algorithm>
using std::abs;

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
	if (_denominator < 0){
		_denominator = 0 - _denominator;
		_numerator = 0 - _numerator;
	}
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
	return fraction(_numerator * t._denominator 
								+
				 	_denominator * t._numerator,
				  		_denominator * t._denominator);
}
fraction fraction::operator-(const fraction & t ) const
{
	return fraction(_numerator * t._denominator 
								-
				 	_denominator * t._numerator,
				  		_denominator * t._denominator);
}
fraction fraction::operator*(const fraction & t ) const
{
	return fraction(_numerator * t._numerator, _denominator * t._denominator);

}
fraction fraction::operator/(const fraction & t ) const
{
	return fraction(_numerator * t._denominator, _denominator * t._numerator);
}
void fraction::operator+=(const fraction & t)
{
	*this = *this + t;
	return ;
}
void fraction::operator-=(const fraction & t)
{
	*this = *this - t;
	return ;
}
void fraction::operator*=(const fraction & t)
{
	*this = *this * t;
	return ;
}
void fraction::operator/=(const fraction & t)
{
	*this = *this / t;
	return ;
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
	return (_numerator * t._denominator < _denominator * t._numerator);
}
bool fraction::operator>(const fraction & t) const
{
	return !(*this <= t);
}
bool fraction::operator<=(const fraction & t) const
{
	return (_numerator * t._denominator <= _denominator * t._numerator);
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
			out << ((t._numerator *  t._denominator < 0)? "-":"" )
			    << abs(t._numerator) << "/" << abs(t._denominator);
		}
	return out;
}
    // Normally you should output "a/b" without any space and L
    // Sometims you may output a single integer (Why? Guess XD)
    // If it is not a number (den = 0), output "NaN"