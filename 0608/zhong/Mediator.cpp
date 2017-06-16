#include <iostream>
#include "User.hpp"
#include "Mediator.hpp"
using std::list;

Mediator* Mediator::Ins = nullptr;
list<User*>::iterator findUser(list<User*> users, int id ){
    auto find_user = users.begin();
    int flag = 0;
    for (;find_user != users.end(); find_user++){
        if ((*find_user)->getId() == id){
            flag = 1;
            break;
        }
    }
    return find_user;
}


void Mediator::RegisterHandler(User * u){
    users.push_back(u);
}
void Mediator::ChatHandler(const int & to, const string & msg){
    auto find_user = findUser(this->users, to);
    if (find_user == users.end())
        cout << "Are you kidding ? There is no such a guy!" << endl;
    else{
        (*find_user)->GetMessage(msg);
    }
}

pair<int,string> Mediator::TradeHandler(const int & to, const int & pay, const string & dressName){
    auto find_user = findUser(this->users, to);
    if (find_user == users.end())
        cout << "There is no Such a guy!" << endl;
    else{
        pair<int, string> want_dress = (*find_user)->SellBeautifulDress(pay, dressName);
        return want_dress;
    }

}

void Mediator::DressInfoHandler(const int & to){
    auto find_user = findUser(this->users, to);
    (*find_user)->ShowMyCuteDresses();
}
