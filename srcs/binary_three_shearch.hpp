/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_three_shearch.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:12:37 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/02 16:07:59 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BINARY_THREE_SHEARCH_
# define _BINARY_THREE_SHEARCH_

# define FEUILLE NULL
# include <iostream>
# include <memory>

#define _NC "\033[0;0m"
#define _RED "\033[0;31m"
#define _GREEN "\033[0;32m"
#define _YELLOW "\033[0;33m"
#define _BLUE "\033[0;34m"
#define _PURPLE "\033[0;95m"
#define _CYAN "\033[0;36m"
#define _WHITE "\033[0;37m"

#include <stdio.h>

# include "pair.hpp"

// creer ici pair clé / valeur ?
// ou juste les recup independament ?


// alouer avec _alloc en premier pair et apres s_node

namespace ft {

	template<class T>
	struct 	s_node {
		T			_data;
		s_node<T>	*parent;
		s_node<T>	*left;
		s_node<T>	*right;

		// s_node(s_node* parent, s_node* left, s_node* right) : parent(parent), left(left), right(right) {}
		s_node(T data, s_node* parent, s_node* left, s_node* right) : _data(data), parent(parent), left(left), right(right) {}
	};

	template<class T, class Alloc = std::allocator<s_node<T> > >
	class tree {
		public:
			typedef Alloc																				allocator_type;
			// typedef ft::pair<const KEY, T>																M;
			typedef s_node<T>*																			nodePtr;
			typedef s_node<T>																			nodeType;
			// typedef typename allocator_type::template rebind<s_node<ft::pair<const KEY, T> > >::other 	alloc_node;
			typedef T 																					value_type;
		private:
			allocator_type		_alloc_node;
			// alloc_node			_alloc_node;
			nodePtr				_root;
			nodePtr 			_end;
			int					_compteur;

			nodePtr	createNode(const T& data, nodePtr &old) {
				// ft::pair<const KEY, T>	*_pair = _alloc.allocate(1);

				// _alloc.construct(_pair, ft::make_pair(key, value));

				nodePtr		tmp = _alloc_node.allocate(1);

				_alloc_node.construct(tmp, nodeType(data, old, _end, _end));
				return (tmp);
			}

			void		destroy(nodePtr ptr) {
				if (!ptr || ptr == _end) {return;}
				destroy(ptr->left);
				destroy(ptr->right);
				// _alloc.destroy(ptr->_data);
				// _alloc.deallocate(ptr->_data, 1);
				_alloc_node.destroy(ptr);
				_alloc_node.deallocate(ptr, 1);
			}

			void		insert(const T& data, nodePtr& ptr, nodePtr old) {
				if (!ptr || ptr == _end) {
					ptr = createNode(data, old);
					return ;
				}
				else if (data.first == ptr->_data.first) {
					_compteur--;
					return;
				}
				else if (data.first < ptr->_data.first) {
					insert(data, ptr->left, ptr);
				}
				else {
					insert(data, ptr->right, ptr);
				}
			}

			void		infixe(nodePtr ptr) const {
				if (!ptr || ptr == _end) {return;}

				infixe(ptr->left);
				std::cout << _YELLOW << "ptr  : " << ptr << " - " << ptr->left << " - " << ptr->right << _NC;
				std::cout << " - KEY : " << ptr->_data.first << " - T : " << ptr->_data.second << "\n";
				std::cout << _YELLOW << "papa : " << ptr->parent << _NC << std::endl << std::endl;
				infixe(ptr->right);
			}

			// s_node<M> 	*successeur(s_node<M> *ptr, s_node<M> *&parent) const {
			// 	if (!ptr) {return (NULL);}

			// 	s_node<M> *curent = ptr;
			// 	while (curent->left != 0) {
			// 		parent = curent;
			// 		curent = curent->left;
			// 	}
			// 	return (curent);
			// }

			// s_node<M>	*predecesseur (s_node<M> *ptr, s_node<M>*& parent) const {
			// 	if (!ptr) {return (NULL);}

			// 	s_node<M> *curent = ptr;
			// 	while (curent->right != 0) {
			// 		parent = curent;
			// 		curent = curent->droit;
			// 	}
			// 	return (curent);
			// }

			// s_node<M>	*find_el_padre(s_node<M> *ptr) {

			// }

			// void		toDelete(s_node<M> *ptr, s_node<M> *parent) {
			// 		// std::cout << "hello : " << ptr << std::endl;
			// 	if (ptr->left == 0 &&  ptr->right == 0) { // Dans le cas ou le noeuds n'a pas d'enfants, est une feuille !
			// 		// std::cout << "Value key : " << ptr->_data->first << " - Value key parent : " << parent->_data->first << std::endl;
			// 		if (ptr != _root) {
			// 			if (parent->left == ptr) {
			// 				parent->left = NULL;
			// 			}
			// 			else {
			// 				parent->right = NULL;
			// 			}
			// 		}
			// 		else {
				// 		_root = NULL;
				// 	}
				// 	// _alloc.destroy(ptr->_data);
				// 	// _alloc.deallocate(ptr->_data, 1);
				// 	_alloc_node.destroy(ptr);
				// 	_alloc_node.deallocate(ptr, 1);
				// }
				// else if (ptr->left && ptr->right) { // Dans le cas ou left et right est pas null
				// 	// s_node<M>	*pere 2;
				// 	s_node<M>	*pere = ptr;
					// s_node<M>	*succ = successeur(ptr->right, pere);
					// pair<const KEY, T> *val  = succ->_data;
					// // _alloc.destroy(ptr->_data);
					// // _alloc.deallocate(ptr->_data, 1);
					// // ptr->_data = _alloc.allocate(1);
					// // _alloc.construct(ptr->_data, ft::make_pair(val->first, val->second));
			// 		toDelete(succ, pere);
			// 	}
			// 	else {
			// 		s_node<M>	*child = (ptr->left) ? ptr->left : ptr->right;

			// 		if (ptr != _root) {
			// 			if (ptr == parent->left) {
			// 				parent->left = child;
			// 			}
			// 			else {
			// 				parent->right = child;
			// 			}
			// 		}
			// 		else {
			// 			_root = child;
			// 		}
			// 		// _alloc.destroy(ptr->_data);
			// 		// _alloc.deallocate(ptr->_data, 1);
			// 		_alloc_node.destroy(ptr);
			// 		_alloc_node.deallocate(ptr, 1);
			// 	}
			// }

			// s_node<M>	*find(const KEY& key, s_node<M> *ptr, s_node<M> *&parent) const {
			// 	if (!ptr || ptr == _end) {
			// 		return (NULL);
			// 	}
			// 	else if ((ptr->_data->first)  == key) {
			// 		return (ptr);
			// 	}
			// 	else if (key < (ptr->_data->first)) {
			// 		parent = ptr;
			// 		return (find(key, ptr->left, parent));
			// 	}
			// 	else {
			// 		parent = ptr;
			// 		return (find(key, ptr->right, parent));
			// 	}
			// }

		public:
			tree() : _compteur(0) {
				// ft::pair<const KEY, T>	*_pair = _alloc.allocate(1);
				// _alloc.construct(_pair, ft::make_pair(KEY(), T()));
				_end = _alloc_node.allocate(1);
				_alloc_node.construct(_end, nodeType(value_type(), NULL, NULL, NULL));
				// _end->_data = _pair;
				// _end->parent = NULL;
				// _end->left = NULL;
				// _end->right = NULL;
				_root = _end;
				// std::cout << _CYAN << _end << _NC << std::endl;
			}

			~tree() {
				// std::cout << _CYAN << _end << _NC << std::endl;
				destroy(_root);
				// _alloc.destroy(_end->_data);
				// _alloc.deallocate(_end->_data, 1);
				_alloc_node.destroy(_end);
				_alloc_node.deallocate(_end, 1);
			}

			// void		toDelete(const KEY& key) {
			// 	s_node<M>	*parent = 0;
			// 	s_node<M>	*del = find(key, _root, parent);
			// 	if (!del) {
			// 		std::cout << "Le noeud n'appartient pas a l'arbre" << std::endl;
			// 	}
			// 	else {
			// 		// std::cout << "HERE : " << del->_data->first << std::endl;
			// 		// std::cout << "HERE : " << del->left << std::endl;
			// 		// std::cout << "HERE : " << del->right << std::endl;
			// 		toDelete(del, parent);
			// 		_compteur--;
			// 	}
			// }

			// s_node<M>	*find(const KEY& key, const T& value) const {
			// 	s_node<M>	*parent = find(key, value);
			// 	return (parent);
			// }

			void		insert(const T& data) {
				// std::cout << _CYAN << _root << _NC << std::endl;
				_compteur++;
				insert(data, _root, _root);
			}

			void		infixe() const {
				infixe(_root);
			}

			// void	print_node_find(const KEY& key) {
			// 	s_node<M>	*node = find(key, _root, _root);
			// 	std::cout << "Clé : " << node->_data->first << " Valeur : " << node->_data->second << std::endl;
			// }

			int			size() const {return (_compteur);}
			bool		empty() const {return (_compteur == 0);}
	};
}
#endif
