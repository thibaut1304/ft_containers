#include "vector.hpp"

#include <vector>
#include <memory>
#include <iterator>
#include <iostream>
#include <string>

#include "print.cpp"
#include "constructor.cpp"
#include "R_begin_and_end.cpp"

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

// void	ft_insert() {
	// std::vector<int> std_vector;
	// ft::vector<int> ft_vector;

	// for (int i = 0; i < 10 ; i++) {
	// 	if (i == 5) {
	// 		std_vector.push_back(99);
	// 		ft_vector.push_back(99);
	// 	}
	// 	else {
	// 		std_vector.push_back(i);
	// 		ft_vector.push_back(i);
	// 	}
	// }

	// std::vector<int>::iterator it = std_vector.begin();
	// ft::vector<int>::iterator ft_it = ft_vector.begin();

	// for (; ft_it < ft_vector.end(); ft_it++) {
	// 	if (*ft_it == 99)
	// 		break;
// 	}

// 	for (; it < std_vector.end(); it++) {
// 		if (*it == 99)
// 			break;
// 	}
// 	print_vector(std_vector, ft_vector);
// 	ft_vector.insert(ft_it, 5, 0);
// 	std_vector.insert(it, 5, 0);
// 	print_vector(std_vector, ft_vector);

// }

void	ft_insert_mli() {
	ft::vector<int> ft_(10);
	std::vector<int> std_(10);

	for (unsigned long int i = 0; i < ft_.size(); i++)
		ft_[i] = (ft_.size() - i) * 3;
	for (unsigned long int i = 0; i < std_.size(); i++)
		std_[i] = (std_.size() - i) * 3;

	// print_vector(std_, ft_);

	ft::vector<int> ft_vector(8, 9);
	std::vector<int> std_vector(8, 9);

	for (int i = 0; i < 5; i++) {
		ft_vector.pop_back();
		std_vector.pop_back();

	}
	// std_vector.insert(std_vector.end()-2, 42);
	// ft_vector.insert(ft_vector.end() -2, 42);
	// std_vector.insert(std_vector.begin(), 2, 21);
	ft_vector.insert(ft_vector.begin(), ft_vector.begin(), ft_vector.end());
	std_vector.insert(std_vector.begin(), std_vector.begin(), std_vector.end());
	// ft_vector.insert(ft_vector.begin(), 2, 21);
	print_vector(std_vector, ft_vector);

	// ft_vector.insert(ft_vector.end() - 2, 42);
	// std_vector.insert(std_vector.end() - 2, 42);
	// print_vector(std_vector, ft_vector);

	// ft_vector.insert(ft_vector.end(), 2, 84);
	// std_vector.insert(std_vector.end(), 2, 84);
	// print_vector(std_vector, ft_vector);

	// ft_vector.resize(4);
	// std_vector.resize(4);
	// print_vector(std_vector, ft_vector);

	// ft_vector.insert(ft_vector.begin() + 2, ft_vector.begin(), ft_vector.end());
	// std_vector.insert(std_vector.begin() + 2, std_vector.begin(), std_vector.end());
	// print_vector(std_vector, ft_vector);
	// ft_vector.clear();
	// std_vector.clear();
	// print_vector(std_vector, ft_vector);






}

int main () {
	ft_insert_mli();
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
	std::cout << " - - - - - - - - - - - - - - - -" << std::endl << std::endl;

	return (0);
}


