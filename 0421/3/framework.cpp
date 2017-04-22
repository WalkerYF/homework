#include <iostream>
#include <string>
#include "source.h"
using namespace std;
int main()
{
  Triangle shape1;
  cout << shape1.getSide1() << endl;
  cout << shape1.getSide2() << endl;
  cout << shape1.getSide3() << endl;  
  cout << shape1.getArea() << endl;
  cout << shape1.getPerimeter() << endl;
  cout << shape1.getColor() << endl;
  cout << shape1.isFilled() << endl;

  Triangle shape(1, 1.5, 1);
  cout << shape.getColor() << endl;
  cout << shape.isFilled() << endl;

  shape.setColor("yellow");
  shape.setFilled(true);

  cout << shape.getSide1() << endl;
  cout << shape.getSide2() << endl;
  cout << shape.getSide3() << endl;  
  cout << shape.getArea() << endl;
  cout << shape.getPerimeter() << endl;
  cout << shape.getColor() << endl;
  cout << shape.isFilled() << endl;

  return 0;
}

// Design a class named Triangle that extends GeometricObject class.
// The class contains:

// Three double data fields named side1, side2, and side3 
// with default values 1.0 to denote three sides of the triangle.

// A no-arg constructor that creates a default triangle 
// with color = "blue", filled = true.

// A constructor that creates a triangle 
// with the specified side1, side2, side3 and color = "blue",
// filled = true.

// The accessor functions for all three data fields, 
// named getSide1(), getSide2(), getSide3().

// A function named getArea() that 
// returns the area of this triangle.

// A function named getPerimeter() 
// that returns the perimeter of the triangle.
