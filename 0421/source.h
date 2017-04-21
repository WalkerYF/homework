class Person{
  string name;
  string address;
  string phoneNumber;
  string email;
public:
	string toString()
};


class Student : public Person{

public:
  enum class_status{frssman,sophomore,junior,senior};  
  class_status status;
  string toString()
};

class Employee : public Person{
  string office;
  int salary;
  MyDate dateHired;
string toString()
	
}

class Faculty : public Employee{

  string officeHours;
  int rank;
string toString()
}


class Staff: public Employee{
  string title;

string toString()

};

MyDate class contains the following member: 

class MyDate{
  int year;
  int month;
  int day;

};


