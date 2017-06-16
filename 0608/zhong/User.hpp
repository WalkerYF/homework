#ifndef _USER_
#define _USER_

#include "Dress.hpp"
#include <vector>
#include <iostream>
using std::vector;
using std::pair;
using std::cout;

using std::endl;

using std::string;

class Mediator;
class User {
    private:
        string name;
        int money;
        int id;
        vector<Dress>dresses;
    public:
        int getId() const {return id;}
        static int Count; 
        User(const string & name, const int & money, const vector<pair<string, int> > & dresses);
        void BuyBeautifulDress(const int & id, const int & pay, const string & name);
        void GetDressInfo(const int & id);
        pair<int, string> SellBeautifulDress(const int & pay, const string & dname); 
        void SendMessage(const int & to, const string & msg);
        void GetMessage(const string & msg);
        void ShowMyCuteDresses();

};

#endif