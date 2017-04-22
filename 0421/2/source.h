#include <string>
using std::string;

class MyDate{
  int _year;
  int _month;
  int _day;
public:
  MyDate(int year, int month, int day):
    _year(year), _month(month), _day(day) {}
  MyDate():
    _year(0), _month(0), _day(0) {}
};




class Person{
  string _name;
  string _address;
  string _phoneNumber;
  string _email;
public:
  Person(string name, string address, string phoneNumber, string email):
    _name(name), _address(address), _phoneNumber(_phoneNumber), _email(_email){}
  Person():
    _name("none"), _address("none"), _phoneNumber("none"), _email("none") {}
	virtual string toString(){
    return "Person";
  }

};


class Student : public Person{
  enum class_status{frssman,sophomore,junior,senior};  
  class_status _status;
public:
  Student(string name, string address, string phoneNumber, string email, class_status t):
    Person(name, address, phoneNumber, email), _status(t) {}
  Student() {}
  string toString(){
    return "Student" ;
  }
};

class Employee : public Person{
  string _office;
  int _salary;
  MyDate _dateHired;
public:
  Employee(string name, string address, string phoneNumber, string email, 
          string office, int salary, MyDate dateHired):
    Person(name, address, phoneNumber, email), 
      _office(office), _salary(salary), _dateHired(dateHired) {}
  Employee() {}
  string toString(){
    return "Employee";
  }
	
};

class Faculty : public Employee{
  string _officeHours;
  int _rank;
public:
  Faculty(string name, string address, string phoneNumber, string email,
      string office, int salary, MyDate dateHired,
      string officeHours, int rank):
  Employee(name, address, phoneNumber, email, office, salary, dateHired),
    _officeHours(officeHours), _rank(rank)   {}

  Faculty() {}

  string toString(){
    return "Faculty";
  }
};


class Staff: public Employee{
  string _title;
public:
  Staff(string name, string address, string phoneNumber, string email,
      string office, int salary, MyDate dateHired,
      string title):
  Employee(name, address, phoneNumber, email, office, salary, dateHired),
    _title(title)  {}  
  Staff() {}  
  string toString(){
    return "Staff";
  }

};

