#ifndef _MEDIATOR_
#define _MEDIATOR_
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)
#include <list>
#include <iostream>
#include "User.hpp"
using std::list;
class Mediator {
    private:
        DISALLOW_COPY_AND_ASSIGN(Mediator);
        std::list<User*> users;
        Mediator() {}
        ~Mediator() {}
        static Mediator* Ins;
    public:
        static Mediator* getInstance() {
            return Mediator::Ins == NULL ? (Mediator::Ins = new Mediator()) : Mediator::Ins;
        }
        static void DestroyIns() {
            if (Ins)
                delete Ins;
            Ins = NULL;
        }
        void RegisterHandler(User * u);
        void ChatHandler(const int & to, const string & msg);
        pair<int,string> TradeHandler(const int & to, const int & pay, const string & dressName);
        void DressInfoHandler(const int & to);
};


#endif