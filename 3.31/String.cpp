#include "String.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

char String::_error_sign;  
// initial as any char is okay
// constructors
String::String()
{

    _size = 5;
    _buff = new char [_size];
    std::strcpy(_buff, "\0");
    _length = 0;

}
String::String(const char *src)
{
    _length = std::strlen(src);
    _size = 2 * _length;
    _buff = new char [_size];
    std::strcpy(_buff, src);
}
String::String(const String &src)
{
    _length = src._length;
    _size = src._size;
    _buff = new char [_size];
    std::strcpy(_buff, src._buff);
}
// destructor
String::~String()
{
    delete [] _buff;
    _buff = nullptr;
    _length = 0;
    _size = 0;
}
// member methods
void String::assign(const char *src)
{
    delete [] _buff;
    _length = std::strlen(src);
    _size = 2*_length;
    _buff = new char [_size];
    std::strcpy(_buff, src);
}
void String::append(const char &other)
{
    if (_length < _size){
    }
    else{
        _size = 2 * _size + 1;
        char * newBuff = new char [_size];
        strcpy(newBuff, _buff);
        delete [] _buff;
        _buff = newBuff;
    }
    _buff[_length] = other;
    _length++;
}
void String::clear()
{
    std::memset(_buff, 0, sizeof(_size));
}
int String::compare(const String &other) const
{
    int ans = std::strcmp(_buff, other._buff);
    if (ans < 0)
        return -1;
    if (ans > 0)
        return 1;
    return 0;
}


const char* String::c_str() const
{
    return _buff;
}
bool String::empty() const
{
    return !_length;
}
int String::find(const String &other, int pos) const
{
    char * p = std::strstr(_buff + pos, other._buff);
    if (p == nullptr)
        return -1;
    else
        return (p-_buff);
}
int String::length() const
{
    return _length;

}
String String::substr(const int &pos, const int &count) const
{
    String ans;
    for (int i = 0; i < count ; i++)
    {
        ans.append(_buff[pos+i]);
    }
    return ans;
}
// overload operators
char& String::operator[](const int &index)
{
    return _buff[index];
}
void String::operator=(const String &other)
{
    delete _buff;
    _length = other._length;
    _size = other._size;
    _buff = new char [_size];
    std::strcpy(_buff, other._buff);
}
void String::operator=(const char *src)
{
    delete _buff;
    _length = std::strlen(src);
    _size = 2 * _length;
    _buff = new char [_size];
    std::strcpy(_buff, src);
}
String String::operator+(const String &other) const
{
    char * ans;
    ans = new char [_size + other._size];
    std::strcat(ans, _buff);
    std::strcat(ans, other._buff);
    return String(ans);
}
bool String::operator<(const String &other) const
{
    if (std::strcmp(_buff, other._buff) < 0)
        return true;
    return false;
}
bool String::operator<=(const String &other) const
{
    if (std::strcmp(_buff, other._buff) <= 0)
        return true;
    return false;
}
bool String::operator>(const String &other) const
{
    if (std::strcmp(_buff, other._buff) > 0)
        return true;
    return false;
}
bool String::operator>=(const String &other) const
{
    if (std::strcmp(_buff, other._buff) >= 0)
        return true;
    return false;
}
bool String::operator==(const String &other) const
{
    if (std::strcmp(_buff, other._buff) == 0)
        return true;
    return false;    
}
bool String::operator!=(const String &other) const
{
    return !(*this==other);
}

// friend methods
std::ostream& operator<<(std::ostream& out, const String &str)
{
    out << str._buff;
    return out;
}
// non-meaning static property
