#include "../srcs/binary_three_shearch.hpp"

#include <string>


using namespace ft;

int main () {
	node<int, std::string> arbre;
	//insert key et T
	arbre.insert(30, "hello");
	arbre.insert(25, "hi");
	arbre.insert(10, "bonjour");
	arbre.insert(26, "saut");
	arbre.insert(32, "salut");
	arbre.insert(31, "aie");
	arbre.insert(42, "yes");

	arbre.infixe();
	std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;
	
	std::cout  << "Supression 25 !" << std::endl;
	arbre.toDelete(25);
	std::cout  << "Affichage apres suprission 25 avec 2 enfants !" << std::endl;
	arbre.infixe();
	std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;
	arbre.toDelete(55);
	std::cout  << "Affichage apres test suprission 55 !" << std::endl;
	arbre.infixe();
	std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;
	arbre.insert(8, "hi");
	arbre.infixe();
	std::cout << "Taille de  l'arbre : " << arbre.size() << std::endl;
}