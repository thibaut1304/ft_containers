#include "../srcs/binary_three_shearch.hpp"

#include <string>


using namespace ft;

int main () {
	// std::cout << sizeof(int) << " " 
	tree<int, std::string> arbre;
	//insert key et T
	arbre.insert(30, "hello");
	arbre.insert(1, "3");
	arbre.insert(25, "hi");
	arbre.insert(10, "b");
	arbre.insert(26, "saut");
	// arbre.insert(27, "saut");
	arbre.infixe();
	// arbre.print_node_find(42);
	std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;
	
	// std::cout  << "Supression 25 !" << std::endl;
	arbre.toDelete(25);
	// arbre.toDelete(26);
	std::cout  << "Affichage apres suprission 25 avec 2 enfants !" << std::endl;
	arbre.infixe();
	std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;
	std::cout << "\n\n------------------------------------\n\n";

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