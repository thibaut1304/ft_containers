
#include "vector.hpp"
// #include "iterator_traits.hpp"
// #include "reverse_iterator.hpp"

#include <vector>
#include <memory>
#include <iterator>
#include <iostream>

void	print_vector(ft::vector<int> test) {
	ft::vector<int>::iterator it = test.begin() ;
	ft::vector<int>::iterator itend = test.end();
	
	for (it = test.begin(); it != itend; it++) {
		std::cout << *it << " ";
	}
}

void	officiel_vector() {
	std::vector<int> test(5, 25);

	// for (int i = 0; i < 10; i++) {
	// 	test.push_back(i);
	// }
	std::vector<int>::iterator it = test.begin();
	std::vector<int>::iterator itend = test.end();

	for (it = test.begin(); it != itend; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	my_vector(void) {
	ft::vector<int> test2(5, 25);
	print_vector(test2);
	// for (int i = 0)
}
int main () {
	// officiel_vector();
	my_vector();
	// ft::vector<int>::iterator it = test2.begin();
	
	return (0);
}
