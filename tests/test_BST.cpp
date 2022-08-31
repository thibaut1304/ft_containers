// #include "../srcs/binary_three_shearch.hpp"

#include <string>

// #include <map>
 #include "map.hpp"


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

int main () {
	// tree<ft::pair<int, int> > test;
	ft::map<int, int> test;
	typedef ft::map<int, int>::iterator iterator;
	ft::pair<iterator, bool> tmp;
	ft::pair<iterator, bool> tmp2;
	ft::pair<iterator, bool> tmp3;

	tmp = test.insert(ft::map<int, int>::value_type(3, 5));
	tmp2 = test.insert(ft::map<int, int>::value_type(1, 5));
	tmp3 = test.insert(ft::map<int, int>::value_type(3, 5));
	// std::cout << tmp.first << std::endl;
	print_result(tmp);
	print_result(tmp2);
	print_result(tmp3);
	test.print_infixe();


	// ft::pair<std::map<int, int>::iterator, bool> hello= test.insert(ft::make_pair<int, int>(5, 3));
	// std::cout << hello.second << std::endl;
	// std::cout << test.size() << std::endl;
	// std::cout << test.empty() << std::endl;
	// std::cout << test.max_size() << std::endl;
	// std::map<T1, T2>	mp;

	// mp['a'] = 2.3;
	// mp['b'] = 1.4;
	// mp['c'] = 0.3;
	// mp['d'] = 4.2;

	// for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
	// 	for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
	// 		ft_comp(mp, it1, it2);

	// return (0);
	// std::map<char, int> tree;
	// tree.insert(std::pair<char, int>('x', 1001));
	// tree.insert(std::pair<char, int>('y', 2002));
	// tree.insert(std::pair<char, int>('z', 3003));
	// std::map<char, int>::iterator it = tree.begin();
	// std::pair<char, int> hi = *tree.rbegin();
	// std::cout << "Pair rbegin : " << hi.first << " - " << hi.second << std::endl << std::endl;
	// do {
	// 	std::cout << it->first << " => " << it->second << std::endl;
	// 	std::cout << tree.value_comp()(*it, hi) << std::endl;
	// } while (tree.value_comp()(*it++, hi));

	// std::map<char, int> tree2(tree.value_comp()('c', 'a'));
	// std::cout << sizeof(int) << " "

	// ft::tree<int, std::string, get_key<int, std::string> > arbre;
	//insert key et T
	// arbre.insert(40, "hi");
	// arbre.insert(50, "hi");
	// arbre.insert(14, "hi");
	// arbre.insert(16, "hi");
	// arbre.insert(5, "hello");
	// arbre.insert(3, "3");
	// arbre.insert(7, "b");
	// arbre.insert(55, "hi");
	// arbre.insert(45, "hi");

	// // arbre.insert(9, "hello");
	// // arbre.insert(5, "el padre");
	// // arbre.insert(11, "hi");
	// // arbre.insert(3, "b");
	// // arbre.insert(7, "saut");
	// // arbre.insert(4, "saut");
	// // arbre.insert(6, "succeseur");
	// // arbre.insert(8, "saut");

	// arbre.infixe();
	// // arbre.print_node_find(42);
	// std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;

	// // std::cout  << "Supression 25 !" << std::endl;
	// arbre.toDelete(14);
	// // arbre.toDelete(26);
	// // std::cout  << "Affichage apres suprission 25 avec 2 enfants !" << std::endl;
	// arbre.infixe();
	// std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;
	// std::cout << "\n\n------------------------------------\n\n";

	// tree<std::string, std::string> three;

	// three.insert("a", "a");
	// three.insert("e", "e");
	// three.insert("h", "h");
	// three.insert("b", "b");
	// three.insert("a", "a");
	// three.infixe();
	// // three.print_node_find("a");
	// std::cout << "Taille de three : " << three.size() << std::endl;
	// std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;
	// arbre.toDelete(55);
	// std::cout  << "Affichage apres test suprission 55 !" << std::endl;
	// arbre.infixe();
	// std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;
	// arbre.insert(8, "hi");
	// arbre.infixe();
	// std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;
}
