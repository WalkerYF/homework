




#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_
#include <sstream>
#include <string>

class Utils {
 public:
  static std::string int2String(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
  }
};

class Exception {
 public:
  virtual const std::string what() const throw() { return "Exception occors"; };
};

class ExpressionException : public Exception {
 public:
  virtual const std::string what() const throw() {
    return "ExpressionException";
  }
};

class IllegalSymbolException : public ExpressionException {
 private:
  int position;

 public:
  IllegalSymbolException(int position) : position(position) {}
  virtual const std::string what() const throw() {
    return "IllegalSymbolException at position:" + Utils::int2String(position);
  }
};

class MissingOperatorException : public ExpressionException {
 private:
  int position;

 public:
  MissingOperatorException(int position) : position(position) {}
  virtual const std::string what() const throw() {
    return "Expected operator at position:" + Utils::int2String(position);
  }
};

class MissingOperandException : public ExpressionException {
 private:
  int position;

 public:
  MissingOperandException(int position) : position(position) {}
  virtual const std::string what() const throw() {
    return "Expected operand at position:" + Utils::int2String(position);
  }
};

class EmptyExpressionException : public ExpressionException {
 public:
  EmptyExpressionException() {}
  virtual const std::string what() const throw() {
    return "The expression is empty";
  }
};

#endif


class calculator{
public:
    bool check(char t){
      if ('0' <= t && t <= '9'){
        return true;
      }
      if ((t == '-' || t == '+')){
        return true;
      }
      return false;
    }
    int calculate(const std::string& s){
        if (s.size() == 0){
          throw EmptyExpressionException();
        }
        int ans = 0;
        for (int i = 0; i < s.size(); i++){
          if (!check(s[i]))
            throw IllegalSymbolException(i);
          if (i % 2 == 0){
            if (!('0' <= s[i] && s[i] <= '9')){
              throw MissingOperandException(i);
            }
            if (i == 0)
              ans = s[0] - '0';
            else if (s[i-1] == '+')
                ans = ans + s[i] - '0';
              else if (s[i-1] == '-')
                ans = ans - (s[i] - '0');
          } 
          else {
            if (s[i] != '-' && s[i] != '+'){
              throw MissingOperatorException(i);
            }
            if (i == s.size()-1)
              throw MissingOperandException(i+1);
          }
        }
        return ans;
    }
private:
};










#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  calculator c;
  std::string str;
  bool flag;

  while (cin >> str) {
    flag = false;
    try {
      cout << c.calculate(str) << endl;
    } catch(EmptyExpressionException e) {
      cout << e.what() << endl;
      flag = true;
    } catch(MissingOperatorException e) {
      cout << e.what() << endl;
      flag = true;
    } catch(MissingOperandException e) {
      cout << e.what() << endl;
      flag = true;
    } catch(IllegalSymbolException e) {
      cout << e.what() << endl;
      flag = true;
    } catch(ExpressionException e) {
      cout << e.what() << endl;
      flag = true;
    } catch(Exception e) {
      // unhandled exception
      throw e;
    }
    if (!flag) {
      std::cout << "No exception happened!" << std::endl;
    }
  }

  return 0;
}

