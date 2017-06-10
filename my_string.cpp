//mystring.cpp
//Tate Walker
//221
//1-22-17

#include "my_string.h"
#include <iostream>
using namespace std;

//---------------Constructors---------------\\

my_string::my_string() //default constructor
{
	sz = 0;
	cap = 0;
	ptr = new char[0];
}

my_string::my_string(int n) //size constructor
{
	ptr = new char(n);
	cap = n;
	sz = 0;
}

my_string::my_string(const char* c_string) //c_string constructor
{
	int index = 0;
	while (c_string[index] != '\0')
	{
		index++;
		
	}
	ptr = new char[index];
	sz = index;
	cap = index;
	
	for (int i = 0; i < index; ++i)
	{
		ptr[i] = c_string[i];
	}
}

my_string::my_string(const my_string& cop) //copy constructor
{
	cap = cop.capacity();
	sz = cop.size();
	ptr = new char[sz];
	for(int i = 0; i < (sz); i++)
	{
		ptr[i] = cop[i];
	}
}

my_string::~my_string() //destructor
{
	delete[] ptr;
}

//---------------Functions---------------\\

int my_string::capacity() const //returns capacity of my_string
{
	return cap;	
}

int my_string::size() const //returns size of my_string
{
	return sz;
}

bool my_string::empty() //checks if my_string is empty
{
 	if(size() == 0)
 	{
 		return true;
 	}
 	else
 	{
 		return false;
 	}
}	

char my_string::at(int index) const //returns character at index provided no range error
{

		if(index<=(sz-1) && index>=0)
		{
			return (*this)[index];
		}
		else
		{
			throw std::range_error("Out of range");
		}
	
}

void my_string::increaseCap() //doubles capacity if size exceeds existing capacity
{
	if(cap==0)
	{
		cap = cap+1;
	}
	else
	{
		cap = cap*2;
	}
}

 //---------------Operators---------------\\
 
istream& operator >> (istream& is, my_string& str)  //reads input into my_string
{
 	char c;
 	while(is.get(c)) 
 	{
 		if(isspace(c))
 		{
 			break;
 		}
 		str += c;
 	}
 	return is;
 		
}
 
ostream& operator<<(ostream& os, const my_string& obj) //outputs my_string
{
	for(int i = 0; i <obj.size(); i++)
	{
		os << obj.at(i);
	}
    return os;
}

char my_string::operator[](int i) const //returns char at index
{
		return ptr[i];
}
 
my_string& my_string::operator+=(my_string& q) //appends one my_string to another
{
	int original_size = sz;
	sz = q.size() + sz;
	while(sz > cap)
	{
		increaseCap();
	}
	for(int i=0; i<q.size(); i++)
	{
		ptr[original_size+i] = q[i];
	}
	return *this;
}

my_string& my_string::operator+=(char c) //appends char to my_string
{
	while(sz + 1 > cap)
	{
		increaseCap();
	}
	sz++;
	ptr[sz-1] = c;
}

my_string& my_string::operator=(const my_string q) //sets one my_string to another
{
	for (int i = 0; i < q.size(); ++i)
	{
		ptr[i] = q[i];
	}
	return *this;
}

int main()
{
return 0;
}