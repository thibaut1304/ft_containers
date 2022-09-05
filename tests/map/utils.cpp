#include "utils.hpp"

std::list<L1>	random_list() {
	std::list<L1> lst;
	srand(time(NULL));
	int roll = rand() % 10 + 5;
	for (int i = 0; i < roll; i++) {
		srand(i + time(0));
		int y = rand() % 100 + 10;
		lst.push_back(y);
	}
	return (lst);
}

int	test_continue() {
	std::cout << "Do you want to run the test again? y/n" << std::endl;
	std::string c;
	std::getline(std::cin, c);
	for (std::size_t i = 0; i < c.length(); i++) {
		c[i] = std::toupper(c[i]);
	}
	if (c == "YES" || c == "Y" || c == ".")
		if (c == ".")
			return (2);
		return (1);
	return (0);
}

std::string recup_type2() {
	std::string type2;
	if (typeid(T2) == typeid(int))
		type2 = "int";
	else if (typeid(T2) == typeid(std::string))
		type2 = "std::string";
	else if (typeid(T2) == typeid(unsigned char))
		type2 = "unsigned char";
	else if (typeid(T2) == typeid(unsigned int))
		type2 = "unsigned int";
	else if (typeid(T2) == typeid(short int))
		type2 = "short int";
	else if (typeid(T2) == typeid(unsigned long))
		type2 = "unsigned long";
	else if (typeid(T2) == typeid(long))
		type2 = "long";
	else if (typeid(T2) == typeid(float))
		type2 = "float";
	else if (typeid(T2) == typeid(double))
		type2 = "double";
	else if (typeid(T2) == typeid(long double))
		type2 = "long double";
	else if (typeid(T2) == typeid(char))
		type2 = "char";
	return (type2);
}

std::string recup_type1() {
	std::string type1;
	if (typeid(T1) == typeid(int))
		type1 = "int";
	else if (typeid(T1) == typeid(std::string))
		type1 = "std::string";
	else if (typeid(T1) == typeid(unsigned char))
		type1 = "unsigned char";
	else if (typeid(T1) == typeid(unsigned int))
		type1 = "unsigned int";
	else if (typeid(T1) == typeid(short int))
		type1 = "short int";
	else if (typeid(T1) == typeid(unsigned long))
		type1 = "unsigned long";
	else if (typeid(T1) == typeid(long))
		type1 = "long";
	else if (typeid(T1) == typeid(float))
		type1 = "float";
	else if (typeid(T1) == typeid(double))
		type1 = "double";
	else if (typeid(T1) == typeid(long double))
		type1 = "long double";
	else if (typeid(T1) == typeid(char))
		type1 = "char";
	return (type1);
}
