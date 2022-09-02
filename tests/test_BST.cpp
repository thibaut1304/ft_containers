#include "../srcs/binary_three_shearch.hpp"

#include <string>


using namespace ft;

int main () {
	// std::cout << sizeof(int) << " "
	tree<int, std::string> arbre;
	//insert key et T
	arbre.insert(42, "hi");
	arbre.insert(50, "hi");
	arbre.insert(35, "hi");
	arbre.insert(21, "hi");
	arbre.insert(38, "hello");
	arbre.insert(45, "3");
	arbre.insert(55, "b");
	// arbre.insert(55, "hi");
	// arbre.insert(45, "hi");

	// arbre.insert(9, "hello");
	// arbre.insert(5, "el padre");
	// arbre.insert(11, "hi");
	// arbre.insert(3, "b");
	// arbre.insert(7, "saut");
	// arbre.insert(4, "saut");
	// arbre.insert(6, "succeseur");
	// arbre.insert(8, "saut");

	arbre.infixe();
	// arbre.print_node_find(42);
	std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;

	// std::cout  << "Supression 25 !" << std::endl;
	// arbre.toDelete(14);
	// arbre.toDelete(26);
	// std::cout  << "Affichage apres suprission 25 avec 2 enfants !" << std::endl;
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
