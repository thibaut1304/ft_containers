
#include "vector.hpp"
// #include "iterator_traits.hpp"
// #include "reverse_iterator.hpp"

#include <vector>
#include <memory>
#include <iterator>
#include <iostream>

int main () {
	std::vector<int> test;

	for (int i = 0; i < 10; i++) {
		test.push_back(i);
	}
	std::vector<int>::iterator it = test.begin();
	std::vector<int>::iterator itend = test.end();

	for (it = test.begin(); it != itend; it++) {
		std::cout << *it << " ";
	}
	ft::vector<int> test2;
	// ft::vector<int>::iterator it = test2.begin();
	
	return (0);
}
