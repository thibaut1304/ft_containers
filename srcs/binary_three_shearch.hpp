/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_three_shearch.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:12:37 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/01 16:09:39 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BINARY_THREE_SHEARCH_
# define _BINARY_THREE_SHEARCH_

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

		s_node() : parent(0), left(0), right(0) {}
		s_node(T data, s_node* parent, s_node* left, s_node* right) : _data(data), parent(parent), left(left), right(right) {}
	};

	template<class T, class Compare, class Alloc>
	class tree {
		public:
			// typedef ft::pair<const KEY, T>																M;
			typedef T 																					value_type;
			typedef s_node<T>*																			nodePtr;
			typedef s_node<T>																			nodeType;
			typedef typename Alloc::template rebind<s_node<T> >::other 									allocator_type;
            // typedef std::size_t																			size_type;
			typedef	typename allocator_type::size_type 													size_type;
            typedef Compare																				key_compare;


		private:
			// alloc_node			_alloc_node;
			allocator_type		_alloc;
			nodePtr				_root;
			nodePtr				_end;
			size_type			_compteur;
			key_compare 		_comp;

			nodePtr		createNode(const value_type& data, nodePtr &old) {
				nodePtr	tmp = _alloc.allocate(1);
				_alloc.construct(tmp, nodeType(data, old, _end, _end));
				// std::cout << "Adresse create end : " << tmp->right << std::endl;
				// tmp->right = NULL;
				// tmp->left = NULL;

				// tmp->parent = old;
				return (tmp);
			}

			void		destroy(nodePtr &ptr) {
				if (ptr == _end || !ptr) {return;}
				destroy(ptr->left);
				destroy(ptr->right);
				// _alloc.destroy(ptr->_data);
				// _alloc.deallocate(ptr->_data, 1);
				// _alloc.destroy(ptr);
				_alloc.deallocate(ptr, 1);
				ptr = NULL;
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
				if (!ptr) {return;}
				if (ptr != _end) {
					std::cout << "node: " << ptr << "    KEY : " << ptr->_data.first << " - T : " << ptr->_data.second << "\n"; //" - Parent : " << ptr->parent->_data.first << "\n";

					std::cout << "left: " << ptr->left << std::endl;
					std::cout << "right: " << ptr->right << std::endl;
					std::cout << "parent: " << ptr->parent << std::endl;
				}
				infixe(ptr->left);
				// std::cout << "KEY : " << ptr->_data.first << " - T : " << ptr->_data.second << "\n"; //" - Parent : " << ptr->parent->_data.first << "\n";
				infixe(ptr->right);
			}

			nodePtr	successeur(nodePtr ptr, nodePtr &parent) const {
				if (!ptr) {return (NULL);}

				nodePtr curent = ptr;
				while (curent->left != _end) {
					parent = curent;
					curent = curent->left;
				}
				return (curent);
			}

			nodePtr	predecesseur (nodePtr ptr, nodePtr& parent) const {
				if (!ptr) {return (NULL);}

				nodePtr	curent = ptr;
				while (curent->right != _end) {
					parent = curent;
					curent = curent->droit;
				}
				return (curent);
			}

			void		toDelete(nodePtr	ptr, nodePtr	parent) {
					// std::cout << "hello : " << ptr << std::endl;
				if (ptr->left == 0 &&  ptr->right == 0) { // Dans le cas ou le noeuds n'a pas d'enfants, est une feuille !
					// std::cout << "Value key : " << ptr->_data->first << " - Value key parent : " << parent->_data->first << std::endl;
					if (ptr != _root) {
						if (parent->left == ptr) {
							parent->left = NULL;
						}
						else {
							parent->right = NULL;
						}
					}
					else {
						_root = NULL;
					}
					_alloc.destroy(ptr);
					_alloc.deallocate(ptr, 1);
					// _alloc_node.destroy(ptr);
					// _alloc_node.deallocate(ptr, 1);
				}
				else if (ptr->left && ptr->right) { // Dans le cas ou left et right est pas null
					// s_node<M>	*pere 2;
					nodePtr		pere = ptr;
					nodePtr		succ = successeur(ptr->right, pere);
					value_type val  = succ->_data;
					_alloc.destroy(ptr);
					_alloc.deallocate(ptr, 1);
					ptr->_data = val;
					// _alloc.construct(ptr->_data, ft::make_pair(val->first, val->second));
					toDelete(succ, pere);
				}
				else {
					nodePtr	child = (ptr->left) ? ptr->left : ptr->right;

					if (ptr != _root) {
						if (ptr == parent->left) {
							parent->left = child;
						}
						else {
							parent->right = child;
						}
					}
					else {
						_root = child;
					}
					_alloc.destroy(ptr);
					_alloc.deallocate(ptr, 1);
					// _alloc_node.destroy(ptr);
					// _alloc_node.deallocate(ptr, 1);
				}
			}

			// s_node<M>	*find(const KEY& key, s_node<M> *ptr, s_node<M> *&parent) const {
			// 	if (!ptr) {
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

			nodePtr	find(const value_type& data, nodePtr& node, nodePtr& parent) {
				if (node == _end || !node)
					return (NULL);
				if (data.first == node->_data.first)
					return (node);
				if (_comp(data.first, node->_data.first)) {
					parent = node;
					return (find(data, node->left, parent));
				}
				else {
					parent = node;
					return (find(data, node->right, parent));
				}
			}

		public:
			tree(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type()) :  _alloc(alloc), _root(0), _end(0), _compteur(0), _comp(comp) {
				_end = _alloc.allocate(1);
				_alloc.construct(_end, nodeType(value_type(), NULL, NULL, NULL));
				_root = _end;
				// std::cout << "address _end : " << _end << std::endl;
				// std::cout << "adree max : " << getMax() << std::endl;
			}

			~tree() {
				// std::cout << "destructeur max : " << getMax() << std::endl;
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
					// infixe(_root);
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
				Tree._size = compteur;
			}

			void	clear() {
				destroy(_root);
				_root = _end;
				_compteur = 0;
			}

			nodePtr	find(const value_type& data) {
				return (find(data, _root, _root));
			}

			void	insert(const value_type data) {
				_compteur++;
				insert(data, _root, _root);
				// _end->left = _root;
				// _end->right = _root;
				// _root->parent = _end;
			}

			void		erase(const value_type& data) {
				nodePtr	parent = 0;
				nodePtr	del = find(data, _root, parent);
				if (!del) {
					std::cout << "Le noeud n'appartient pas a l'arbre" << std::endl;
				}
				else {
					if (_root)
						_root->parent = _end;
					toDelete(del, parent);
					_compteur--;
				}
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
