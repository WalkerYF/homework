// 1001.cpp

// 使得函数f()输出为
// num 1 is odd? 1
// num 2 is odd? 0
// 1 objects of Int has been constructed.
// 2 objects of Int has been constructed.
// 2 objects of Int has been constructed.

#include <iostream>
using std::cout;

class Int{

public:
	Int(){
		num++;
		cout << num 
			<< " objects of Int has been constructed.\n";
	}
	Int(int number){
		num++;
		cout << num 
			<< " objects of Int has been constructed.\n";
	}

	~Int(){
		num--;
	}

	static int num;
	static int isodd(int number){
		return (number % 2);
	}
};
