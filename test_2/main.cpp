#include "utils.hpp"

void	header(std::string name, std::ostream &o) {
	std::string enter = "Press enter to continue tests !";
	o << _GREEN << "|" << std::setfill('-') << std::setw(100) << "|" << _NC << std::setfill(' ') << std::endl;
	o << _GREEN << std::setw(50) << name << " - TESTS !" << _NC << std::endl;
	o << _GREEN << "|" << std::setfill('-') << std::setw(100) << "|" << _NC << std::setfill(' ') << std::endl;
	o << _WHITE << "|" << std::setw(100 - enter.length()) << enter << _NC << std::endl;
	while (std::cin.get() != '\n') {}
}

int main(void) {
	clock_t t;
	t = clock();



	header("VECTOR");
	launch_vector();

	header("STACK");
	launch_stack();
	header("MAP");
	launch_map();

	t = clock() - t;
	printf ("\n(%f seconds).\n", ((float)t)/CLOCKS_PER_SEC);


	return (0);
}
