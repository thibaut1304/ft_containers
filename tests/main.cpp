#include "vector.hpp"

#include <vector>
#include <memory>
#include <iterator>
#include <iostream>
#include <string>

#include "print.cpp"
#include "constructor.cpp"
#include "R_begin_and_end.cpp"
#include "insert.cpp"

void ft_push_back() {
	std::vector<std::string>std_vector(5);
	ft::vector<std::string>	ft_vector(5);
	std::cout << "Max size ft : " << ft_vector.max_size() << std::endl;
	std::cout << "Max size st : " << std_vector.max_size() << std::endl;

	std::vector<std::string>::iterator it = std_vector.begin();

	for (unsigned long int i = 0; i < std_vector.size(); ++i)
		it[i] = std::string(std_vector.size() - i, i + 65);
	ft::vector<std::string>::iterator ft_it = ft_vector.begin();
	for (unsigned long int i = 0; i < ft_vector.size(); ++i) {
		ft_it[i] = std::string(ft_vector.size() - i, i + 65);
	}

	for (int i = 0; i < 10; i++) {
		std_vector.push_back("A");
	}
	for (int i = 0; i < 10; i++) {
		ft_vector.push_back("A");
	}
	// print_the_vector(std_vector);
	// print_my_vector(ft_vector);
	print_vector(std_vector, ft_vector);
}

void	ft_erase() {
	std::vector<int> std_vector(2, 9);
	ft::vector<int> ft_vector(2, 9);

	// std_vector.push_back(5);
	// ft_vector.push_back(5);

	print_vector(std_vector, ft_vector);
	std_vector.erase(std_vector.end() - 2);
	ft_vector.erase(ft_vector.end() - 2);
	print_vector(std_vector, ft_vector);
	std_vector.erase(std_vector.begin(), std_vector.end());
	ft_vector.erase(ft_vector.begin(), ft_vector.end());
	print_vector(std_vector, ft_vector);
}

int main () {
	// test_capa_insert();
	// ft_insert();
	// ft_insert_mli();
	ft_erase();
	exit(0);
	std::cout << " - - - - - CONSTRUCTOR - - - - -" << std::endl << std::endl;
	std::cout << " - Operator= and begin and end -" << std::endl << std::endl;
	constructor();
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	std::cout << " - - - - Rbegin and Rend - - - -" << std::endl << std::endl;
	R_begin_and_end();
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;

	ft::vector<int> test(2, 5);

	for (int i = 0;i < 10; i++) {
		test.push_back(i);
	}
	ft::vector<int> test2 = test;
	print_my_vector(test2);
	std::cout << "SIZE     : " << test.size() << std::endl;
	std::cout << "SIZE    2: " << test2.size() << std::endl;
	std::cout << "CAPACITY : " << test.capacity() << std::endl;
	std::cout << "CAPACITY2: " << test2.capacity() << std::endl;
	std::cout << " - - - - - PUSH_BACK - - - - - -" << std::endl << std::endl;
	ft_push_back();
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	std::cout << " - - - - - INSERT - - - - -" << std::endl << std::endl;
	// ft_insert();
	// ft_insert_mli();
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;

	return (0);
}


