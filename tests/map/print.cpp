
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
