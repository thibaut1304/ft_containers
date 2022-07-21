#include "vector.hpp"

#define _NC "\033[0;0m"
#define _RED "\033[0;31m"
#define _GREEN "\033[0;32m"
#define _YELLOW "\033[0;33m"
#define _BLUE "\033[0;34m"
#define _PURPLE "\033[0;95m"
#define _CYAN "\033[0;36m"
#define _WHITE "\033[0;37m"

#include <vector>
#include <memory>
#include <iterator>
#include <iostream>
#include <string>

#include "print.cpp"
#include "constructor.cpp"
#include "R_begin_and_end.cpp"
#include "insert.cpp"
#include "resize.cpp"


#include <map>
#include "map.hpp"
#include "test_map.cpp"



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
	print_vector(std_vector, ft_vector);
}

void	ft_erase() {
	std::vector<int> std_vector(100, 9);
	ft::vector<int> ft_vector(100, 9);



	print_vector(std_vector, ft_vector, 1);
	std_vector.erase(std_vector.end() - 2);
	ft_vector.erase(ft_vector.end() - 2);
	print_vector(std_vector, ft_vector, 1);
	std_vector.erase(std_vector.begin(), std_vector.end());
	ft_vector.erase(ft_vector.begin(), ft_vector.end());
	print_vector(std_vector, ft_vector, 1);
}

void	ft_swap() {
	std::vector<int> std_vector(10, 99);
	ft::vector<int> ft_vector(10, 99);
	std::vector<int> std_vector_swap;
	ft::vector<int> ft_vector_swap;

	for (int i = 0; i < 10; i++) {
		std_vector.push_back(i);
		ft_vector.push_back(i);
	}
	std_vector.insert(std_vector.end() - 5, 5, 42);
	ft_vector.insert(ft_vector.end() - 5, 5, 42);
	std::cout << _PURPLE << " - - - - - BEFORE SWAP - - - - -" << _NC <<std::endl << std::endl;
	print_vector(std_vector_swap, ft_vector_swap);
	std::cout << _PURPLE << " - - - - - AFTER SWAP  - - - - -" << _NC << std::endl << std::endl;
	std_vector_swap.swap(std_vector);
	ft_vector_swap.swap(ft_vector);
	print_vector(std_vector_swap, ft_vector_swap);
}

int main () {
	test_map();
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
	ft_insert();
	ft_insert_mli();
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	std::cout << " - - - - - - ERASE - - - - - - -" << std::endl << std::endl;
	ft_erase();
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	std::cout << " - - - - - - RESIZE  - - - - - -" << std::endl << std::endl;
	ft_resize();
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	std::cout << " - - - - - - SWAP  - - - - - - -" << std::endl << std::endl;
	ft_swap();
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	if (global != 0)
		std::cout << _RED << "NB error : " << global << _NC << std::endl;
	return (0);
}


