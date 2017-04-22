#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Complex

{

double real, imag; 

public:

Complex(double x = 0.0, double y = 0.0);  
// constructor, set real = x, imag = y

void print();           
//output the complex number with proper form. e.g. 1+i

friend Complex add(const Complex&, const Complex&);   
// return sum of two complex numbers 

friend Complex multiply(const Complex&, const Complex&);  
// return product of two complex numbers

};

Complex::Complex(double x, double y )
{
	real = x;
	imag = y;
}
void Complex::print()
{
	if (real == 0 && imag == 0)
		 cout << "0" << endl;
	if (real == 0 && imag != 0)
		cout << imag << "i" << endl;
	if (real != 0 && imag == 0)
		cout << real << endl;
	if (real != 0 && imag != 0)
		cout << real << ((imag > 0)?"+":"") << imag << "i" << endl;
}

Complex add(const Complex& c1, const Complex& c2)
{
	return Complex(c1.real+c2.real, c1.imag+c2.imag);
}

Complex multiply(const Complex& c1, const Complex& c2)
{
	return Complex(c1.real*c2.real - c1.imag*c2.imag, c1.real*c2.imag+c1.imag*c2.real);
}
