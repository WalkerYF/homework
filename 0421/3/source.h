#include <cmath>
#include <string>
using std::string;

class GeometricObject
{
public:
  GeometricObject(string color, bool filled)
  {
    this->color = color;
    this->filled = filled;
  }
  
  string getColor()
  { 
    return color; 
  }
  void setColor(string color)
  { 
    this->color = color; 
  }
  bool isFilled()
  { 
    return filled; 
  }
  void setFilled(bool filled)
  { 
    this->filled = filled;
  }
  string toString()
  {
    return "Geometric object color " + color +
    " filled " + ((filled) ? "true" : "false");
  }
private:
  string color;
  bool filled;
};
 

class Triangle : public GeometricObject{
private:
  double _side1, _side2, _side3;
public:
  Triangle():
    Triangle(1,1,1) {};
  Triangle(double side1, double side2 = 1, double side3 = 1):
    GeometricObject("blue", true),
      _side1(side1), _side2(side2), _side3(side3) {}

  double getSide1(){
    return _side1;
  }
  double getSide2(){
    return _side2;
  }
  double getSide3(){
    return _side3;
  }

  double getArea(){
    double p = (_side1 + _side2 + _side3)/2;
    double area = std::sqrt(p * (p - _side1) * (p - _side2) * (p - _side3));
    return area;
  }

  double getPerimeter(){
    return (_side1 + _side2 + _side3);
  }
};