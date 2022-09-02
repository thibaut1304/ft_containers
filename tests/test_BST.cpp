// #include "../srcs/binary_three_shearch.hpp"

#include <string>

// #include <map>
#include <list>
 #include "map.hpp"

#include <iostream>

using namespace ft;

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T>
void	print_result(const T &iter) {
	std::cout << printPair(iter.first);
	std::cout << "Est entrée dans l'arbre ? ";
	std::cout << ((iter.second) ? "Oui" : "Non") << std::endl;
}

#define T1 int
#define T2 std::string
typedef ft::pair<const T1, T2> T3;

template <typename Map, typename Iter>
void	ft_erase(Map mp, Iter iterator) {
	mp.erase(iterator);
	ft::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
	std::cout << _CYAN "Size : " << mp.size() << _NC << std::endl;
	for (; it != ite; it++) {
		std::cout << "key : " << it->first << " - T : " << it->second << std::endl;
	}
	std::cout << std::endl;

}

int main () {
	// tree<ft::pair<T1, T2> > arbre;
	ft::map<T1, T2> test;
	// typedef ft::map<T1, T2>::iterator iterator;
	// ft::pair<iterator, bool> tmp;
	// ft::pair<iterator, bool> tmp2;
	// ft::pair<iterator, bool> tmp3;
	// ft::pair<iterator, bool> tmp4;

	// test.insert(ft::map<T1, T2>::value_type(42, "root"));
	//  test.insert(ft::map<T1, T2>::value_type(50, "root -1 right"));
	//  test.insert(ft::map<T1, T2>::value_type(35, "root -1 left"));
	// test.print_infixe();
	//  test.insert(ft::map<T1, T2>::value_type(45, "root -2 right"));
	//  test.insert(ft::map<T1, T2>::value_type(55, "root -2 right"));
	//  test.insert(ft::map<T1, T2>::value_type(21, "root -2 left"));
	//  test.insert(ft::map<T1, T2>::value_type(38, "root -2 left"));

	typedef ft::map<T1, T2>::iterator iterator;
	ft::pair<iterator, bool> tmp;
	ft::pair<iterator, bool> tmp2;
	ft::pair<iterator, bool> tmp3;
	ft::pair<iterator, bool> tmp4;

	tmp = test.insert(ft::map<T1, T2>::value_type(42, "lol"));
	// print_result(tmp);
	tmp2 = test.insert(ft::map<T1, T2>::value_type(50, "mdr"));
	// print_result(tmp2);
	tmp3 = test.insert(ft::map<T1, T2>::value_type(35, "funny"));
	// print_result(tmp3);
	tmp4 = test.insert(ft::map<T1, T2>::value_type(21, "bunny"));
	// print_result(tmp4);
	tmp4 = test.insert(ft::map<T1, T2>::value_type(38, "bunny"));
	// print_result(tmp4);
	tmp4 = test.insert(ft::map<T1, T2>::value_type(45, "bunny"));
	// print_result(tmp4);
	tmp4 = test.insert(ft::map<T1, T2>::value_type(55, "bunny"));
	tmp4 = test.insert(ft::map<T1, T2>::value_type(47, "bunny"));
	// print_result(tmp4);
	// test.erase((--test.end()));
	// test.erase(++(++(++(++(++(++(++test.begin())))))));
	// test.print_infixe();

	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	ft::map<T1, T2> mp(lst.begin(), lst.end());

	// std::cout << _RED << ite->first << _NC << std::endl;
	// mp.erase(--(--mp.end()));

	ft_erase(mp, mp.begin());
	ft::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
	std::cout << _CYAN "Size : " << mp.size() << _NC << std::endl;
	for (; it != ite; it++) {
		std::cout << "key : " << it->first << " - T : " << it->second << std::endl;
	}
	std::cout << std::endl;
	// ft_erase(mp, mp.begin());
	// ft_erase(mp, mp.begin()++);
	// ft_erase(mp,--(--mp.end()));
	// --ite;
	// --ite;
	// std::cout << _RED << ite->first << _NC << std::endl;
	// std::cout <<
	// mp.insert(ft::map<T1, T2>::value_type(47, "bunny"));
	// mp.erase(47);
	// mp.print_infixe();

	return (0);
}
