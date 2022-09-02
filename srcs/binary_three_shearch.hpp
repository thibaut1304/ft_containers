/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_three_shearch.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:12:37 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/03 01:25:53 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BINARY_THREE_SHEARCH_
# define _BINARY_THREE_SHEARCH_

#define _NC "\033[0;0m"
#define _RED "\033[0;31m"
#define _GREEN "\033[0;32m"
#define _YELLOW "\033[0;33m"
#define _BLUE "\033[0;34m"
#define _PURPLE "\033[0;95m"
#define _CYAN "\033[0;36m"
#define _WHITE "\033[0;37m"

# define FEUILLE NULL
# include <iostream>
# include <memory>

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

		s_node(T data, s_node* parent, s_node* left, s_node* right) : _data(data), parent(parent), left(left), right(right) {}
	};

	template<class T, class Compare, class Alloc>
	class tree {
		public:
			typedef T 																					value_type;
			typedef s_node<T>*																			nodePtr;
			typedef s_node<T>																			nodeType;
			typedef typename Alloc::template rebind<s_node<T> >::other 									allocator_type;
			typedef	typename allocator_type::size_type 													size_type;
			typedef Compare																				key_compare;
			// typedef std::size_t																			size_type;


		private:
			allocator_type		_alloc;
			nodePtr				_root;
			nodePtr				_end;
			size_type			_compteur;
			key_compare 		_comp;

			nodePtr		createNode(const value_type& data, nodePtr &old) {
				nodePtr	tmp = _alloc.allocate(1);
				_alloc.construct(tmp, nodeType(data, old, _end, _end));
				return (tmp);
			}

			void		destroy(nodePtr ptr) {
				if (ptr == _end || !ptr) {return;}
				destroy(ptr->left);
				destroy(ptr->right);
				_alloc.destroy(ptr);
				_alloc.deallocate(ptr, 1);
			}

			void		insert(const value_type& data, nodePtr &ptr, nodePtr &old) {
				if (ptr == _end || !ptr) {
					ptr = createNode(data, old);
					return ;
				}
				else if (data.first == ptr->_data.first) {
					_compteur--;
					return ;
				}
				if (_comp(data.first, ptr->_data.first)) {
					insert(data, ptr->left, ptr);
				}
				else {
					insert(data, ptr->right, ptr);
				}
			}

			void		infixe(nodePtr ptr) const {
				if (ptr == _end || !ptr) {return ;}
				infixe(ptr->left);
				std::cout << _YELLOW << "ptr  : " << ptr << " - " << ptr->left << " - " << ptr->right << _NC;
				std::cout << " - KEY : " << ptr->_data.first << " - T : " << ptr->_data.second << "\n";
				std::cout << _YELLOW << "papa : " << ptr->parent << _NC << std::endl << std::endl;
				infixe(ptr->right);
			}

			nodePtr	successeur(nodePtr ptr) const {
				if (ptr == _end || !ptr) {return (_end);}

				nodePtr curent = ptr;
				while (curent->left != _end) {
					// parent = curent;
					curent = curent->left;
				}
				// std::cout << curent->_data.first << std::endl;
				// std::cout << curent->right->_data.first << std::endl;
				return (curent);
			}

			// nodePtr	predecesseur (nodePtr ptr, nodePtr& parent) const {
			// 	if (!ptr) {return (NULL);}

			// 	nodePtr	curent = ptr;
			// 	while (curent->right != _end) {
			// 		parent = curent;
			// 		curent = curent->droit;
			// 	}
			// 	return (curent);
			// }

			void		toDelete(nodePtr	ptr) {
				if (ptr->left == _end && ptr->right == _end) { // Dans le cas ou le noeuds n'a pas d'enfants, est une feuille !
					// std::cout << "Value key : " << ptr->_data->first << " - Value key parent : " << parent->_data->first << std::endl;
					if (ptr != _root) {
						nodePtr padre = ptr->parent;
						if (padre->left == ptr) {
							padre->left = _end;
						}
						else {
							padre->right = _end;
						}
					}
					else {
						_root = _end;
					}
					_alloc.destroy(ptr);
					_alloc.deallocate(ptr, 1);
					// _alloc_node.destroy(ptr);
					// _alloc_node.deallocate(ptr, 1);
				}
				else if (ptr->left != _end && ptr->right != _end) { // Dans le cas ou left et right est pas null
					// nodePtr		pere = ptr;
					nodePtr		succ = successeur(ptr->right);

					if (succ->parent == ptr) {
						succ->left = ptr->left;
						succ->parent = ptr->parent;
						succ->right = _end;

						nodePtr big_papa_succ = succ->parent;
						if (_comp(succ->_data.first, big_papa_succ->_data.first))
							big_papa_succ->left = succ;
						else
							big_papa_succ->right = succ;

					}
					else {
						nodePtr papa_succ = succ->parent;

						if (succ->right != _end)
								papa_succ->left = succ->right;
						else
							papa_succ->left = _end;

						succ->parent = ptr->parent;
						succ->left = ptr->left;
						succ->right = ptr->right;
					}

					if (ptr == _root)
						_root = succ;
					// std::cout << succ->parent->_data.first << std::endl;
					_alloc.destroy(ptr);
					_alloc.deallocate(ptr, 1);

					// value_type val  = succ->_data;
					// _alloc.destroy(ptr);
					// _alloc.deallocate(ptr, 1);
					// ptr = _alloc.allocate(1);
					// _alloc.construct(ptr, nodeType(succ->_data, succ->parent, succ->left, succ->right));

					// ptr->parent = succ->parent;
					// ptr->left = succ->left;
					// ptr->right = succ->right;
					// toDelete(ptr, pere);

					// std::cout << _CYAN << succ->right->_data.first << _NC << std::endl;

					// _alloc.destroy(ptr);
					// _alloc.deallocate(ptr, 1);
					// delete ptr;
					// ptr->_data = val;
				}
				else {
					// std::cout << _YELLOW << ptr->_data.first << _NC << std::endl;
					nodePtr	child = (ptr->left != _end) ? ptr->left : ptr->right;
					nodePtr padre = ptr->parent;
					// std::cout << _YELLOW << padre->_data.first << _NC << std::endl;

					if (ptr != _root) {
						if (ptr == padre->left) {
							padre->left = child;
						}
						else {
							padre->right = child;
						}
						child->parent = padre;
					}
					else {
						_root = child;
					}
					_alloc.destroy(ptr);
					_alloc.deallocate(ptr, 1);
				}
			}

			nodePtr	find(const value_type& data, nodePtr& node) {
				if (node == _end || !node)
					return (NULL);
				if (data.first == node->_data.first)
					return (node);
				if (_comp(data.first, node->_data.first)) {
					return (find(data, node->left));
				}
				else {
					return (find(data, node->right));
				}
			}

		public:
			tree(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type()) :  _alloc(alloc), _compteur(0), _comp(comp) {
				_end = _alloc.allocate(1);
				_alloc.construct(_end, nodeType(value_type(), NULL, NULL, NULL));
				_root = _end;
			}

			~tree() {
				destroy(_root);
				_alloc.destroy(_end);
				_alloc.deallocate(_end, 1);
				_end = NULL;
			}

			nodePtr		getEnd() const {return (_end);}
			nodePtr		getRoot() const {return (_root);}

			nodePtr		getMin(nodePtr node = NULL, bool test = 0) const {
				if (!node) {
					if (_root == _end)
						return (_root);
					node = _root;
				}
				while (node->left != _end)
					node = node->left;
				if (test) {
					std::cout << "ARBRE : " << std::endl;
					std::cout << node << std::endl;
					std::cout << node->left << std::endl;
					std::cout << node->right << std::endl << std::endl;
				}
				return (node);
			}

			nodePtr		getMax(nodePtr node = NULL) const {
				if (!node) {
					if (_root == _end)
						return (_root);
					node = _root;
				}
				while (node->right != _end)
					node = node->right;
				return (node);
			}

			// nodePtr	lowerBound(const value_type& data) {
			// 	nodePtr node = getMin();
            //     while (node != _end)
            //     {
            //         if (!_comp(node->_data.first, data.first))
            //             return (node);
            //         node = successeur(node);
            //     }
            //     return (NULL);
			// }

			// nodePtr	upperBound(const value_type& data) {
			// 	nodePtr node = getMin();
            //     while (node != _end)
            //     {
            //         if (_comp(data.first, node->_data.first))
            //             return (node);
            //         node = successeur(node);
            //     }
            //     return (NULL);
			// }

			void	swap(tree& Tree) {
				nodePtr			root = _root;
				nodePtr			end = _end;
				allocator_type	alloc = _alloc;
				key_compare		comp = _comp;
				size_type		compteur = _compteur;

				_root = Tree._root;
				_end = Tree._end;
				_alloc = Tree._alloc;
				_comp = Tree._comp;
				_compteur = Tree._compteur;

				Tree._root = root;
				Tree._end = end;
				Tree._alloc = alloc;
				Tree._comp = comp;
				Tree._compteur = compteur;
			}

			void	clear() {
				destroy(_root);
				_root = _end;
				_compteur = 0;
			}

			nodePtr	find(const value_type& data) {
				return (find(data, _root));
			}

			void	insert(const value_type data) {
				_compteur++;
				insert(data, _root, _root);
			}

			bool		erase(const value_type& data) {
				nodePtr	del = find(data, _root);
				// nodePtr	parent = del->parent;
				// std::cout << _RED << data.first << _NC << std::endl;
				if (del == _end) {
					std::cout << "Le noeud n'appartient pas a l'arbre" << std::endl;
					return (0);
				}
				else {
					if (_root != _end)
						_root->parent = _end;
					toDelete(del);
					_compteur--;
					// std::cout << _compteur << std::endl;
				}
				return (1);
			}

			void		infixe() {
				infixe(_root);
				// clear();
			}

			// void	print_node_find(const KEY& key) {
				// s_node<M>	*node = find(key, _root, _root);
				// std::cout << "Clé : " << node->_data->first << " Valeur : " << node->_data->second << std::endl;
			// }

			size_type		size() const {return (_compteur);}
			bool			empty() const {return (_compteur == 0);}
			size_type		max_size() const { return (allocator_type().max_size());}
			allocator_type	get_allocator() const {return (_alloc);}
	};
}
#endif
