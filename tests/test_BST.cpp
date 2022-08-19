#include "../srcs/binary_three_shearch.hpp"

using namespace ft;

int main () {
	node<int> arbre;
	arbre.insert(40);
	arbre.insert(14);
	arbre.insert(50);
	arbre.insert(5);
	arbre.insert(16);
	arbre.insert(3);
	arbre.insert(7);
	arbre.insert(45);
	arbre.insert(55);

	arbre.infixe();
}