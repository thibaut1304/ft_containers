#include <stdio.h>
#include <stdlib.h>

# define FEUILLE NULL

typedef struct 	s_node {
	struct s_node	*left;
	struct s_node	*right;
	int 			element;
}				t_node;

void	print_element(t_node *node) {
	if (node)
		printf("Valeur de l'element : %d\n", node->element);
}

void	print_bst(t_node *node, t_node *current) {
	if (node)
		print_element(node);
	if (node->left) {
		print_bst(node->left, current);
	}
}

t_node	*create_node(t_node *node, t_node *current, int nb) {
	printf("%p\n", node);
	if (node) {
		if (nb < node->element)
			create_node(node->left, current, nb);
		else
			create_node(node->right, current, nb);
	}
	else {
		node = (t_node*)malloc(sizeof(t_node) * 1);
		printf("%p\n", node);
		node->element = nb;
		node->left = FEUILLE;
		node->right = FEUILLE;
		current = node;
	}
	// printf("%p\n", node);
	return (node);
}

int 	main() {
	t_node *node;

	node = FEUILLE;
	// node->left = FEUILLE;
	// node->right = FEUILLE;
	node = create_node(node, node, 30);
	node = create_node(node, node, 25);
	print_bst(node, node);
	// node = create_node(node, node, 32);
	// node = create_node(node, node, 10);
	// node = create_node(node, node, 26);
	// node = create_node(node, node, 31);
	// node = create_node(node, node, 42);
	// if (node)
		// printf("TEST : %d\n", node->element);
	// if (node->left)
		// printf("TEST : %d\n", node->left->element);
	// if (node->right)
		// printf("TEST : %d\n", node->right->element);
}