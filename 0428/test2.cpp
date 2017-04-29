 class base
{
// protected:
	char * _name;
	int _age;
public:
	base(){}
	void setname(char arr[]) { _name = arr;} 
	void setage(int age) { _age = age;} 
	char* getname() {return _name;} 
	int getage() {return _age;};
};



class leader:virtual public base{
// protected:
	char * _job;
	char * _dep;
public:
	void setjob(char job[]){_job = job;} ;
	void setdep(char dep[]) {_dep = dep;} ;
	char * getjob(){return _job;} ;
	char * getdep(){return _dep;} ;
};

class engineer:virtual public base{
// protected:
	char * _major;
	char * _prof;
public:
	void setmajor(char major[]){_major = major;} 
	void setprof(char prof[]){_prof = prof;} 
	char * getmajor(){return _major;} 
	char * getprof(){return _prof;} 
};

class chairman: public leader, public engineer{

};

#include<iostream>   
#include<string.h>
#include<cstring> 
#include <fstream>
using namespace std;
// #include "source.h"
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		char name[20],job[20],dep[20],major[20],prof[20];
    	int age;
		cin>>name>>age>>job>>dep>>major>>prof;
		chairman man;
		man.setname(name);
		man.setage(age);
		man.setjob(job);
		man.setdep(dep);
		man.setmajor(major);
		man.setprof(prof);
		cout<<"name: "<<man.getname()<<" age: "<<man.getage()<<" dep: "<<man.getdep()
			<<" job: "<<man.getjob()<<endl;
		cout<<"prof: "<<man.getprof()<<" major: "<<man.getmajor()<<endl;
	}
	return 0;
}