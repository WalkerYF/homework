
class Cat
{
    int _data;
public:
    Cat():_data(0)
    {
    	cout << "Default Constructor of Cat is Running" << endl;
    }
    Cat(int data):_data(data)
    {
    	cout << "Constructor of Cat is Running " << _data << endl;
    }
    ~Cat()
    {
    	cout << "Destructor of Cat is Running " << _data << endl;
    }
};

class Tiger : public Cat
{
    int _data;
public:
    Tiger(int data):Cat(data), _data(data)
    {
    	cout << "Constructor of Tiger is Running " << _data << endl;
    }
    ~Tiger()
    {
    	cout << "Destructor of Tiger is Running " << _data << endl;    }
};




// 运行结果：
// Default Constructor of Cat is Running
// Constructor of Cat is Running 6
// Constructor of Tiger is Running 6
// Constructor of Cat is Running 18
// Constructor of Tiger is Running 18
// Destructor of Tiger is Running 18
// Destructor of Cat is Running 18
// Destructor of Tiger is Running 6
// Destructor of Cat is Running 6
// Destructor of Cat is Running 0

// 注意：你只需要提交类定义。