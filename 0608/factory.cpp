// class Product{

// };
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
// class Product{
// public:
//     ~Product();
//     // virtual ~Product();
// };

// class Laptop:public Product{
class Laptop{
public:
    Laptop(const string& brand):_brand(brand){}
    void compileCppProgram(){
        cout << _brand + " Laptop compiles a cpp program." << endl;
    }
private:
    string _brand;
};

// class MobilePhone:public Product{
class MobilePhone{
public:
    MobilePhone(const string& brand):_brand(brand){}
    void sendShortMessage(){
        cout << _brand + " MobilePhone sends a short message." << endl;
    }
private:
    string _brand;
};

class Factory{
public:
    virtual Laptop* produceLaptop() = 0;
    virtual MobilePhone* produceMobilePhone() = 0;
    virtual ~Factory() {}
    // ~Factory();
};

class AppleFactory:public Factory{
public:
    Laptop* produceLaptop(){
        Laptop* product = new Laptop(_brand);
        return product; 
    }
    MobilePhone* produceMobilePhone(){
        MobilePhone* product = new MobilePhone(_brand);
        return product;
    }
    AppleFactory():_brand("Apple"){}
private:
    string _brand;
};


class XiaomiFactory:public Factory{
public:
    Laptop* produceLaptop(){
        Laptop* product = new Laptop(_brand);
        return product; 
    }
    MobilePhone* produceMobilePhone(){
        MobilePhone* product = new MobilePhone(_brand);
        return product;
    }
    XiaomiFactory():_brand("Xiaomi"){}
private:
    string _brand;
};




#include <iostream>
// #include "Product.hpp"
// #include "Factory.hpp"
using std::cin;

void test() {
  Factory* factory = NULL;
  int choose;
  cin >> choose;

  factory = new AppleFactory();
//   switch (choose) {
//     case 0:
//       factory = new AppleFactory();
//       break;
//     case 1:
//     default:
//       factory = new XiaomiFactory();
//       break;
//   }

//   Laptop* laptop = factory->produceLaptop();
//   MobilePhone* phone = factory->produceMobilePhone();

//   laptop->compileCppProgram();
//   phone->sendShortMessage();

//   delete laptop;
//   delete phone;

//   delete factory;
}

int main() {
  test();
  return 0;
}
