//my_string.h
//Tate Walker
//221
//1-22-17
#include <iostream>


using namespace std;
class my_string{


public:

	//---------------Constructors---------------\\
	
	my_string();
	my_string(int n);
	my_string(const char* c_string);
	my_string(const my_string& cop); 	
 	~my_string();
 	
 	//---------------Functions---------------\\
 	 		
	void increaseCap();
 	int size() const;
 	int capacity() const;
 	bool empty();
 	char at(int index) const;

	//---------------Operators---------------\\

 	char operator[](int i) const;
 	my_string& operator+=(my_string& q);
	my_string& operator+=(char c);
	istream& operator>> (const my_string&);
 	ostream& operator<< (const my_string&);
 	my_string& operator= (const my_string q);

	
private:
	char* ptr;
	int sz; //number of characters in the string
	int cap; // length in bytes of allocated memory pointed to by prt

};