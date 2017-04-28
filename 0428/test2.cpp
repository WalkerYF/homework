 class base
{
	char *name;
	int age;
public:
	base(){}
	void setname(char arr[]);
	void setage(int age);
	char* getname();
	int getage();
};



class leader:virtual public base{
	char * _job;
	char * _dep;
public:
	setjob(char job[]);
	setdep(char dep[]);
};

class engineer:virtual public base{
	char * _major;
	char * _prof;
public:
	setjob(char major[]);
	setdep(char prof[]);
};

class leader:public leader, public engineer{

};


#include<iostream>
#include<string.h>
#include<cstring>
#include <fstream>
using namespace std;
#include "source.h"
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