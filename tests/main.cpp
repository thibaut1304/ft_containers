#include "vector.hpp"

#include <vector>
#include <memory>
#include <iterator>
#include <iostream>

#include "print.cpp"
#include "constructor.cpp"
#include "R_begin_and_end.cpp"

int main () {
	std::cout << " - - - - - CONSTRUCTOR - - - - -" << std::endl << std::endl;
	std::cout << " - Operator= and begin and end -" << std::endl << std::endl;
	constructor();
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	std::cout << " - - - - Rbegin and Rend - - - -" << std::endl << std::endl;
	R_begin_and_end();
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;

	ft::vector<int> test;

	for (int i = 0;i < 10; i++) {
		test.push_back(i);
	}
	ft::vector<int> test2 = test;
	print_my_vector(test2);
	std::cout << "SIZE     : " << test.size() << std::endl;
	std::cout << "SIZE    2: " << test2.size() << std::endl;
	std::cout << "CAPACITY : " << test.capacity() << std::endl;
	std::cout << "CAPACITY2: " << test2.capacity() << std::endl;
	return (0);
}
