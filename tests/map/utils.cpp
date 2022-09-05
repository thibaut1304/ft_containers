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

bool	test_continue() {
	std::cout << "Do you want to run the test again? y/n" << std::endl;
	std::string c;
	std::getline(std::cin, c);
	for (std::size_t i = 0; i < c.length(); i++) {
		c[i] = std::toupper(c[i]);
	}
	if (c == "YES" || c == "Y")
		return (true);
	return (false);
}

template<typename ft_map, typename std_map>
void	ft_compare(ft_map ft_mp, std_map std_mp) {
	std::map<T1, T2>::iterator	std_it = std_mp.begin(), std_ite = std_mp.end();
	ft::map<T1, T2>::iterator	ft_it = ft_mp.begin();
	for (;std_it != std_ite; std_it++, ft_it++) {
		if ((std_it->first != ft_it->first) || (std_it->second != ft_it->second)) {
			std::cout << _RED << "\t\t\tFAILLURE !" << _NC << std::endl;
			return ;
		}
	}
	std::cout << _GREEN << "\t\t\tSUCCESS !" << _NC << std::endl;
}
