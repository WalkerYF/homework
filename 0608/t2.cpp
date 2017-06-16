#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cctype>

class NumberParseException{

};

bool isNumber(const char* str){
    if (str == nullptr || strlen(str) == 0){
        return false;
    }
    int length = strlen(str);
    if (strlen(str) == 1 && !isdigit(str[0])){
        return false;
    }
    if (!isdigit(str[0]) && str[0] != '-' && str[0] != '+'){
        return false;
    }
    for (int i = 1; i < length; i++){
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

int parseNumber(const char *str){
    if (!isNumber(str))
        throw NumberParseException();
    else{
        int ans = 0; 
        int e = 1;
        for (int i = strlen(str)-1; i >= 0; i--){
            if (str[i] == '+'){
                ans *= 1;
            }
            else
                if (str[i] == '-'){
                    ans *= -1;
                }
                else {
                    ans += e * (str[i] - '0');
                    e *= 10;
                }
        }
        return ans;
    }
}


#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


void BasicTest() {
    string str1 = "", str2 = "1";
    try {
        int num1 = parseNumber(str1.c_str());
        int num2 = parseNumber(str2.c_str());
        printf("sum is %d\n", num1+num2);
    } catch (NumberParseException) {
        printf("Not a number.\n");
    }
    str1 = "1";
    try {
        int num1 = parseNumber(str1.c_str());
        int num2 = parseNumber(NULL);
        printf("sum is %d\n", num1+num2);
    } catch (NumberParseException) {
        printf("Not a number.\n");
    }
    cin >> str1 >> str2;
    try {
        int num1 = parseNumber(str1.c_str());
        int num2 = parseNumber(str2.c_str());
        printf("sum is %d\n", num1+num2);
    } catch (NumberParseException) {
        printf("Not a number.\n");
    }
}

void HardTest() {
    int Ttime;
    cin >> Ttime;
    while (Ttime--) {
        string str1, str2;
        cin >> str1 >> str2;
        // cout << str1 << str2;
        try {
            int num1 = parseNumber(str1.c_str());
            int num2 = parseNumber(str2.c_str());
            printf("sum is %d\n", num1+num2);
        } catch (NumberParseException) {
            printf("Not a number.\n");
        }
    }
}

int main() {
    int hard;
    cin >> hard;
    if (hard)
        HardTest();
    else
        BasicTest();
}