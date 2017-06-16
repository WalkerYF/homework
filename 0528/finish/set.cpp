#define MAX 1000
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using std::find;
using std::sort;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
template< typename T >
class Set
{
public:
 Set():count(0), maxSize(0){}
 Set( int maxSize ):count(0), maxSize(maxSize){}
 ~Set(){}
 Set( const Set& t) {
    this->data = t.data;
    this->count = t.count;
    this->maxSize = t.maxSize;
 }
 Set operator+( const Set& s ){
     Set ans;
     for(auto i : this->data){
        auto result = find(ans.data.begin(), ans.data.end(), i);
        if (result == ans.data.end()){
            ans.insert(i);
        }
     }
     for (auto i : s.data){
        auto result = find(ans.data.begin(), ans.data.end(), i);
        if (result == ans.data.end()){
            ans.insert(i);
        }          
     }
     return ans;
 }
 Set operator-( const Set& s )
 {
     Set ans;
     for(auto i : this->data){
        auto result_ans = find(ans.data.begin(), ans.data.end(), i);
		auto result = find(s.data.begin(), s.data.end(), i);
        if (result == s.data.end() && result_ans == ans.data.end()){
            ans.insert(i);
        }
     }
     return ans;
 }
 void operator=( const Set& s )
 {
     this->data = s.data;
    this->count = s.count;
    this->maxSize = s.maxSize;   
 }
 bool insert( T newItem ){
    auto result = find(this->data.begin(), this->data.end(), newItem);
    if (result == this->data.end()){
        data.push_back(newItem);
		count++;
        return true;
    }
    else{
        return false;
    }
 }
 bool erase( T targetItem ){
    auto result = find(this->data.begin(), this->data.end(), targetItem);
    if (result == this->data.end()){
        return false;
    }
    else{
        data.erase(result);
		count--;
        return true;
    }    

 }
 void print() const{
     for (auto i : data){
         cout << i << " ";
     }
     cout << endl;
 }
 T* getData() const{
     return nullptr;
 }
 int getCount() const{
     return count;
 }
 int getMaxSize() const {
     return maxSize;
 }
private:
 int count ;
 int maxSize ;
 vector<T> data;
} ;


#include <iostream>
#include <string.h>


using namespace std ;

//test operator + and operator - and intersection
void test1()
{
	Set<int> s1( 10 ), s2( 10 ), s_plus, s_minus, s_intersection ;
	
	s1.insert( 1 ) ;
	s1.insert( 2 ) ;
	s1.insert( 2 ) ;
	s1.insert( 4 ) ;
	cout << "Items in s1 are : " ;
	s1.print() ;
	
	s2.insert( 3 ) ;
	s2.insert( 3 ) ;
	s2.insert( 1 ) ;
	s2.insert( 2 ) ;
	cout << "Items in s2 are: " ;
	s2.print() ;
	s_plus = s1 + s2 ;
	cout << "Items in s_plus are: " ;
	s_plus.print() ;
	
	s_minus = s1 - s2 ;
	cout << "Items in s_minus are: " ;
	s_minus.print() ;
	
	s_intersection = s1 - ( s1 - s2 ) ;
	cout << "Items in s_intersection are: " ;
	s_intersection.print() ;
}

void test2()
{
	Set<double> s1( 100 ), s2( 100 ), s_plus, s_minus, s_intersection ;
	
	
	for ( int i = 0; i < s1.getMaxSize(); i++ )
	{
		s1.insert( i % 17 ) ;
	}
	cout << "Items in s1 are : " ;
	s1.print() ;
	for ( int i = 0; i < s2.getMaxSize(); i++ )
	{
		s2.insert( i % 15 ) ;
	}
	cout << "Items in s2 are: " ;
	s2.print() ;
	
	s_plus = s1 + s2 ;
	cout << "Items in s_plus are: " ;
	s_plus.print() ;
	
	s_minus = s1 - s2 ;
	cout << "Items in s_minus are: " ;
	s_minus.print() ;
	
	s_intersection = s1 - ( s1 - s2 ) ;
	cout << "Items in s_intersection are: " ;
	s_intersection.print() ;
}

void test3()
{
	Set<char> s1( 1000 ), s2( 1000 ), s_plus, s_minus, s_intersection ;
	const char str1[] = "adsfasdfasdfasdfdshfhasdfashjglcnvyerwqjtoiruetwertbnsdfosiftgwertiu324u54owert" ;
	const char str2[] = "adsfhahdfuqwernfqwjerfqwhtfihvagiutewrfbnsduasdfqwerqwgb ahb.,p[phvbfgiopsudfgsdafjfas" ;
	
	for ( int i = 0; i < strlen( str1 ); i++ )
	{
		s1.insert( str1[i] ) ;
	}
	cout << "Items in s1 are : " ;
	s1.print() ;
	for ( int i = 0; i < strlen( str2 ); i++ )
	{
		s2.insert( str2[i] ) ;
	}
	cout << "Items in s2 are: " ;
	s2.print() ;
	
		s_plus = s1 + s2 ;
	cout << "Items in s_plus are: " ;
	s_plus.print() ;
	
	s_minus = s1 - s2 ;
	cout << "Items in s_minus are: " ;
	s_minus.print() ;
	
	s_intersection = s1 - ( s1 - s2 ) ;
	cout << "Items in s_intersection are: " ;
	s_intersection.print() ;
}

int main()
{
	test1() ;
	test2() ;
	test3() ;
	return 0 ;
}