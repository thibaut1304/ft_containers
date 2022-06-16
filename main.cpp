
#include "vector.hpp"
// #include "iterator_traits.hpp"
// #include "reverse_iterator.hpp"

#include <vector>
#include <memory>
#include <iterator>
#include <iostream>

void	print_vector(ft::vector<int> test) {
	std::cout << "--------- Print vector ---------" << std::endl;
	ft::vector<int>::iterator it = test.begin() ;
	ft::vector<int>::iterator itend = test.end();
	
	for (it = test.begin(); it != itend; it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n" << std::endl;
}

void	print_officiel_vector(std::vector<int> test) {
	std::cout << "--------- Print officiel vector ---------" << std::endl;
	std::vector<int>::iterator it = test.begin();
	std::vector<int>::iterator itend = test.end();

	for (it = test.begin(); it != itend; it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n" << std::endl;
}

void	officiel_vector() {
	std::vector<int> test(5, 25);

	print_officiel_vector(test);
	test.resize(6, -1);
	print_officiel_vector(test);
	std::cout << "Size     : " << test.size() << std::endl; 
	std::cout << "Capacity : " << test.capacity() << std::endl; 
}

void	my_vector(void) {
	ft::vector<int> test2(5, 10);

	print_vector(test2);
	
	for (int i = 0; i < 5;i++) {
		test2.push_back(i);
	}
	test2.resize(11);
	print_vector(test2);
}
int main () {
	// officiel_vector();
	my_vector();
	// ft::vector<int>::iterator it = test2.begin();
	
	return (0);
}
