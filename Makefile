all: my_string.o
	c++ -std=c++11 -g my_string.o -o my_string
my_string.o: my_string.cpp my_string.h
	c++ -std=c++11 -c -g my_string.cpp
clean:
	rm *.o my_string
