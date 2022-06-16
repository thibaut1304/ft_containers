#include "vector.hpp"

#include <vector>
#include <memory>
#include <iterator>
#include <iostream>

#include "print.cpp"
#include "constructor.cpp"
#include "R_begin_and_end.cpp"

int main () {
	std::cout << " - - - - - CONSTRUCTOR - - - - -" << std::endl;
	std::cout << " - Operator= and begin and end -" << std::endl << std::endl;
	constructor();
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	std::cout << " - - - - Rbegin and Rend - - - -" << std::endl;
	R_begin_and_end();

	return (0);
}
