
// #include "vector.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

#include <vector>
#include <iterator>
#include <iostream>

int main () {
	std::vector<int> test;

	for (int i = 0; i < 10; i++) {
		test.push_back(i);
	}

	typedef std::vector<int>::iterator iter_type;

	iter_type debut(test.begin());
	iter_type fin(test.end());

	std::reverse_iterator<iter_type> rev_until (debut);
	std::reverse_iterator<iter_type> rev_from (fin);

	for (test.begin(); debut != fin; *debut++) {
		std::cout << " " << *debut;
	}
	std::cout << "\n\n";
	while (rev_until != rev_from) {
		std::cout << " " << *rev_from++;
	}
	std::cout << " | " << *rev_from;
	*--rev_from;
	--rev_from;
	std::cout << " | " << *rev_from;
	std::cout << "\n";
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;


	return (0);
}
