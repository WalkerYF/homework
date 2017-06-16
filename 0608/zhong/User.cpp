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
    pair<int, string> want_pair = Mediator::getInstance()->TradeHandler(id, pay, name);
    Dress wanted_dress(want_pair.second, want_pair.first);
    
    if (pay > wanted_dress.getPrice())
        cout << this->name << " : " << "Forget to Check Wallet!" << endl;
    if (pay == wanted_dress.getPrice()){
      dresses.push_back(wanted_dress);
      cout << this->name << " : " << "So happy to get new Dress!" << endl;
    }
    if (wanted_dress.getName().size() == 0)
        cout << this->name << " : " << "I'm so sorry maybe just because I love it so much." << endl;
    if (pay < wanted_dress.getPrice())
      cout << this->name << " : " <<  "OMG! Why it is so Expensive!" << endl;

}
void User::GetDressInfo(const int & id){
    Mediator::getInstance()->DressInfoHandler(id);
}
pair<int, string> User::SellBeautifulDress(const int & pay, const string & dname){
    int flag = 0;
    auto find_dress = dresses.begin();
    for (;find_dress != dresses.end(); find_dress++){
        if (find_dress->getName() == dname){
            flag = 1;
        }
    }
    if (flag == 0){
        cout << this->name << " : " << "I never have this Dress stupid!" << endl;
        return {-1,""};
    }
    if (pay < find_dress->getPrice()){
        cout << this->name << " : " <<  "No money then no talking" << endl;
        return {-1,""};
    }
    if (pay >= find_dress->getPrice()){
        cout << this->name << " : " << "What a good taste you have !" << endl;
        pair<int, string> sell_pair(find_dress->getPrice(), find_dress->getName());
        dresses.erase(find_dress);
        return sell_pair;
    }

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