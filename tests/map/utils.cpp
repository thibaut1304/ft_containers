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
	if (c == "YES" || c == "Y" || c == ".") {
		if (c == ".")
			return (2);
		return (1);
	}
	return (0);
}
