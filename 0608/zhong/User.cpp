#include"User.hpp"
#include "Mediator.hpp"
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::pair;
using std::cout;
using std::endl;
int User::Count = 0;
User::User(const string & name, const int & money, const vector<pair<string, int> > & dresses){
    this->id = Count;
    this->name = name;
    this->money = money;
    for (auto i : dresses){
        this->dresses.push_back(Dress(i.first, i.second));
    }
    Count++;
}

void User::BuyBeautifulDress(const int & id, const int & pay, const string & name){
        Mediator::getInstance()->TradeHandler(id, pay, name);
// if pay > money
//   cout << this->name << " : " << "Forget to Check Wallet!" << endl;
// if buy success
//   cout << this->name << " : " << "So happy to get new Dress!" << endl;
// if No such a dress
//   cout << this->name << " : " << "I'm so sorry maybe just because I love it so much." << endl;
// if Can't afford it
//   cout << this->name << " : " <<  "OMG! Why it is so Expensive!" << endl;

}
void User::GetDressInfo(const int & id){

}
pair<int, string> User::SellBeautifulDress(const int & pay, const string & dname){

    // if Don't have that dress
    // cout << this->name <<" : " << "I never have this Dress stupid!" << endl;
    // if pay is lower than your price
    // cout << this->name << " : " <<  "No money then no talking" << endl;
    // if success
    // cout << this->name << " : " << "What a good taste you have !" << endl;

}
void User::SendMessage(const int & to, const string & msg){
    Mediator::getInstance()->ChatHandler(to, msg);
}
void User::GetMessage(const string & msg){
    cout << this->name << " : I got a Msg - " << msg << endl;
}
void User::ShowMyCuteDresses(){
    cout << this->name << " : ok,these are all I have : "<<endl;
    for (int i = 0; i < dresses.size(); i++){
        cout << dresses[i].getName() << "-" << dresses[i].getPrice() << endl;
    }
}