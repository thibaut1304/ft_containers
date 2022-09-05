#include "utils.hpp"

std::string	date_now() {
	time_t now = time(NULL);
	struct tm * tm = localtime(&now);
	char date[18];
	strftime(date, sizeof date, "%d-%m-%y_%H-%M-%S", tm);
	return (date);
}

// std::ofstream	create_file() {
// 	std::string date = "tests/map/ressource_testing/" + date_now() + ".tkt";
// 	const char *c = date.c_str();
// 	std::ofstream file(c);
// 	return (file);
// }

// std::string recup_type2() {
// 	std::string type2;
// 	if (typeid(T2) == typeid(int))
// 		type2 = "int";
// 	else if (typeid(T2) == typeid(std::string))
// 		type2 = "std::string";
// 	else if (typeid(T2) == typeid(unsigned char))
// 		type2 = "unsigned char";
// 	else if (typeid(T2) == typeid(unsigned int))
// 		type2 = "unsigned int";
// 	else if (typeid(T2) == typeid(short int))
// 		type2 = "short int";
// 	else if (typeid(T2) == typeid(unsigned long))
// 		type2 = "unsigned long";
// 	else if (typeid(T2) == typeid(long))
// 		type2 = "long";
// 	else if (typeid(T2) == typeid(float))
// 		type2 = "float";
// 	else if (typeid(T2) == typeid(double))
// 		type2 = "double";
// 	else if (typeid(T2) == typeid(long double))
// 		type2 = "long double";
// 	else if (typeid(T2) == typeid(char))
// 		type2 = "char";
// 	return (type2);
// }

// std::string recup_type1() {
// 	std::string type1;
// 	if (typeid(T1) == typeid(int))
// 		type1 = "int";
// 	else if (typeid(T1) == typeid(std::string))
// 		type1 = "std::string";
// 	else if (typeid(T1) == typeid(unsigned char))
// 		type1 = "unsigned char";
// 	else if (typeid(T1) == typeid(unsigned int))
// 		type1 = "unsigned int";
// 	else if (typeid(T1) == typeid(short int))
// 		type1 = "short int";
// 	else if (typeid(T1) == typeid(unsigned long))
// 		type1 = "unsigned long";
// 	else if (typeid(T1) == typeid(long))
// 		type1 = "long";
// 	else if (typeid(T1) == typeid(float))
// 		type1 = "float";
// 	else if (typeid(T1) == typeid(double))
// 		type1 = "double";
// 	else if (typeid(T1) == typeid(long double))
// 		type1 = "long double";
// 	else if (typeid(T1) == typeid(char))
// 		type1 = "char";
// 	return (type1);
// }

template <typename ft_map, typename std_map>
void	print_file(ft_map ft_mp, std_map std_mp, std::ostream &o) {
		std::map<T1, T2> print;

		std::map<T1, T2>::iterator std_it = std_mp.begin(), std_ite = std_mp.end();
		ft::map<T1, T2>::iterator ft_it = ft_mp.begin(), ft_ite = ft_mp.end();

		if (o == std::cout) {
			o << _YELLOW << "PRINT STD MAP :" << _NC << "\t\t\t";
			o << _CYAN << "PRINT FT MAP :" << _NC << std::endl;
			o << _YELLOW << "Size : " << std_mp.size() <<  _NC << "\t\t\t";
			o << _CYAN << "Size : " << ft_mp.size() <<  _NC << std::endl;
		}
		else {
			o << "PRINT STD MAP :" << "\t\t\t";
			o << "PRINT FT MAP :" << std::endl;
			o << "Size : " << std_mp.size() << "\t\t\t\t";
			o << "Size : " << ft_mp.size() << std::endl;
		}

		while (std_it != std_ite) {
			o << "key : " << std_it->first << " - T : " << std_it->second << "\t\t";
			int i = 1;
			while (ft_it != ft_ite) {
				o << "key : " << ft_it->first << " - T : " << ft_it->second << std::endl;
				ft_it++;
				if (i)
					break ;
			}
			std_it++;
		}
		o << std::endl;
}

template<typename ft_map, typename std_map>
void	ft_compare_file(ft_map ft_mp, std_map std_mp, std::ostream &o = std::cout) {
	std::map<T1, T2>::iterator	std_it = std_mp.begin(), std_ite = std_mp.end();
	ft::map<T1, T2>::iterator	ft_it = ft_mp.begin();
	for (;std_it != std_ite; std_it++, ft_it++) {
		if ((std_it->first != ft_it->first) || (std_it->second != ft_it->second)) {
			if (o == std::cout) {o << _RED << "\t\t\tFAILLURE !" << _NC << std::endl;return ;}
			else {o << "\t\t\tFAILLURE !" << std::endl;return ;}
		}
	}
	if (o == std::cout) {o << _GREEN << "\t\t\tSUCCESS !" << _NC << std::endl;}
	else {o << "\t\t\t\t\tSUCCESS !" << std::endl;}
}

template <typename List, typename ft_map, typename std_map>
void	write_in_file(List &lst, ft_map &ft_mp, std_map &std_mp) {
	std::string type1 = recup_type1();
	std::string type2 = recup_type2();
	std::string date = "tests/map/ressource_testing/" + date_now() + ".tkt";
	const char *c = date.c_str();
	std::ofstream o(c);
	o << "// Remplace '.' with ft or std !\n#define   .   NAMESPACE\n\n";
	o << "// Remplace '.' with your string with \" \"\n#define WORD   .\n\n";
	o << "NAMESPACE::map<int, std::string> mp;\n\n" << "\n";

	std::list<L1>::iterator l_it = lst.begin(), l_ite = lst.end();
	for (; l_it != l_ite; l_it++) {
		o << "mp.insert(NAMESPACE::pair<const " << abi::__cxa_demangle(typeid(T1).name(), NULL, NULL, NULL) << ", " << abi::__cxa_demangle(typeid(T2).name(), NULL, NULL, NULL) << ">(" << *l_it << ", WORD));" << "\n";
	}
	o << "\n\n\n";
	o << "Your results : \n\n";
	print_file(ft_mp, std_mp, o);
	ft_compare_file(ft_mp, std_mp, o);
	o.close();
}
