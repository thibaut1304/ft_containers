#include "utils.hpp"

template <typename ft_map, typename std_map>
void	print_map_test(ft_map ft_mp, std_map std_mp) {
		std::map<T1, T2> print;

		std::map<T1, T2>::iterator std_it = std_mp.begin(), std_ite = std_mp.end();
		ft::map<T1, T2>::iterator ft_it = ft_mp.begin(), ft_ite = ft_mp.end();

		std::cout << _YELLOW << "PRINT STD MAP :" << _NC << "\t\t\t";
		std::cout << _CYAN << "PRINT FT MAP :" << _NC << std::endl;
		std::cout << _YELLOW << "Size : " << std_mp.size() <<  _NC << "\t\t\t";
		std::cout << _CYAN << "Size : " << ft_mp.size() <<  _NC << std::endl;

		while (std_it != std_ite) {
			std::cout << "key : " << std_it->first << " - T : " << std_it->second << "\t\t";
			int i = 1;
			while (ft_it != ft_ite) {
				std::cout << "key : " << ft_it->first << " - T : " << ft_it->second << std::endl;
				ft_it++;
				if (i)
					break ;
			}
			std_it++;
		}
		std::cout << std::endl;
}

template <typename Map>
void	print_map(Map mp, bool test) {
	(void)test;
		std::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
		std::cout << _YELLOW << "PRINT STD MAP :" << _NC << std::endl;
		std::cout << _YELLOW << "Size : " << mp.size() <<  _NC << std::endl;
		for (; it != ite; it++) {
			std::cout << "key : " << it->first << " - T : " << it->second << std::endl;
		}
		std::cout << std::endl;
}


template <typename Map>
void	print_map(Map mp) {
		ft::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
		std::cout << _CYAN << "PRINT FT MAP :" << _NC << std::endl;
		std::cout << _CYAN << "Size : " << mp.size() <<  _NC << std::endl;
		for (; it != ite; it++) {
			std::cout << "key : " << it->first << " - T : " << it->second << std::endl;
		}
		std::cout << std::endl;
}

template <typename ft_map, typename std_map>
void	print(ft_map ft_mp, std_map std_mp) {
	print_map_test(ft_mp, std_mp);
	// print_map(ft_mp);
	// print_map(std_mp, 1);
}

template <typename List>
void	print_list(List &lst) {
		std::list<L1>::iterator it = lst.begin(), ite = lst.end();
		std::cout << _RED << "PRINT LIST :" << _NC << std::endl;
		std::cout << _RED << "Size : " << lst.size() <<  _NC << std::endl;
		for (; it != ite; it++) {
			std::cout << *it;
			if (it != --lst.end())
				std::cout << ", ";
		}
		std::cout << std::endl;
}
