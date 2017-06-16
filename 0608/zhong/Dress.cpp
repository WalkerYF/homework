#include "Dress.hpp"
#include <string>
using std::string;

Dress::Dress(const string & name, const int price){
    this->name = name;
    this->price = price;
}

Dress::Dress(const Dress & oth){
    this->name = oth.name;
    this->price = oth.price;
}

int Dress::getPrice() const{
    return price;
}

string Dress::getName() const{
    return name;
}