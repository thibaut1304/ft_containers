/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_three_shearch.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:12:37 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/02 16:14:23 by thhusser         ###   ########.fr       */
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
			nodePtr				_root;
			nodePtr 			_end;
			int					_compteur;

			nodePtr	createNode(const value_type& data, nodePtr &old) {
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

			void		insert(const T& data, nodePtr &ptr, nodePtr old) {
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



		public:
			tree() : _compteur(0) {
				_end = _alloc_node.allocate(1);
				_alloc_node.construct(_end, nodeType(value_type(), NULL, NULL, NULL));
				_root = _end;
			}

			~tree() {
				destroy(_root);
				_alloc_node.destroy(_end);
				_alloc_node.deallocate(_end, 1);
			}

			void		insert(const T& data) {
				_compteur++;
				insert(data, _root, _root);
			}

			void		infixe() const {
				infixe(_root);
			}

			int			size() const {return (_compteur);}
			bool		empty() const {return (_compteur == 0);}
	};
}
#endif
