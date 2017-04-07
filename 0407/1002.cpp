#include <iostream>
using std::ostream;
using std::istream;

class Int
{
  int i;
public:
  int getI() { return i; }
  //add any member function needed here

  //initialization
  Int();
  Int(int n){ i = n ;}
  Int(double n) { i = n;}

  // operator double() const { return double(i) ;}
  operator int() {return int(i);}

  // plus
  void operator+=(int t){
  	i += t;
  }

  Int  operator+(const Int& t){
	return Int(this->i + t.i);
  }
  Int operator+(int t){
  	return Int(this->i + t); 
  }
  friend Int operator+(int t, const Int & t2){
  	return Int(t + t2.i);
  }
  double operator+(double t){
  	return this->i + t;
  }
  friend double operator+(double t, const Int & t2){
  		// std::cout << t2.i << "  ";
 		return t + t2.i;
  }

  // jianfa -
    void operator-=(int t){
  	i -= t;
  }
  Int  operator-(const Int& t){
	return Int(this->i - t.i);
  }
  Int operator-(int t){
  	return Int(this->i - t); 
  }
  friend Int operator-(int t, const Int & t2){
  	return Int(t - t2.i);
  }
  double operator-(double t){
  	return this->i - t;
  }
  friend double operator-(double t, const Int & t2){
 		return t - t2.i;
  }


  // times
  void operator*=(int t){
  	i *= t;
  }
  Int  operator*(const Int& t){
	return Int(this->i * t.i);
  }
  Int operator*(int t){
  	return Int(this->i * t); 
  }
  friend Int operator*(int t, const Int & t2){
  	return Int(t * t2.i);
  }
  double operator*(double t){
  	return this->i * t;
  }
  friend double operator*(double t, const Int & t2){
 		return t * t2.i;
  }

  // divide
  void operator/=(int t){
  	i /= t;
  }
  Int  operator/(const Int& t){
	return Int(this->i / t.i);
  }
  Int operator/(int t){
  	return Int(this->i / t); 
  }
  friend Int operator/(int t, const Int & t2){
  	return Int(t / t2.i);
  }
  double operator/(double t){
  	return this->i / t;
  }
  friend double operator/(double t, const Int & t2){
 		return t / t2.i;
  }

  // modules
   Int  operator%(const Int& t){
	return Int(this->i % t.i);
  }
  Int operator%(int t){
  	return Int(this->i % t); 
  }
  friend Int operator%(int t, const Int & t2){
  	return Int(t % t2.i);
  }

  //++c
  Int & operator++(){
  	++i;
 	return *this;
  }
  //c++
  Int & operator++(int){
  	i++;
 	return *this;
  }

  //--c
  Int & operator--(){
  	--i;
	return *this;

  }
  //c--
  Int & operator--(int){
  	i--;
  	return *this;
  }

  // -
  Int operator-(){
  	return Int(-i);
  }


  //io
  friend ostream & operator<<(ostream & out, const Int & t){
	out << t.i;
	return out;
}
  friend istream & operator>>(istream & in, Int & t){
	in >> t.i;
	return in;
}
};


// Int operator+(const Int& t1, const Int & t2)
// {
// 	return Int(t1.i + t2.i);
// }

// Int operator-(const Int& t1, const Int& t2)


// Int operator*(const Int& t1, const Int& t2)


// Int operator/(const Int& t1, const Int& t2)


// Int operator%(const Int& t1, const Int& t2)


// ostream & operator<<(ostream & out, const Int & t)

// istream & operator>>(istream & in, Int & t)
