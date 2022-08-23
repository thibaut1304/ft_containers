/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_three_shearch.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:12:37 by thhusser          #+#    #+#             */
/*   Updated: 2022/08/23 16:50:45 by thhusser         ###   ########.fr       */
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
	
	template<class M>
	struct 	s_node {
		M			*_data;
		s_node<M>	*left;
		s_node<M>	*right;
	};
	
	template<class KEY, class T, class Alloc = std::allocator<ft::pair<const KEY, T> > >
	class node {
		public:
			typedef Alloc																				allocator_type;
			typedef ft::pair<const KEY, T>																M;
			typedef typename allocator_type::template rebind<s_node<ft::pair<const KEY, T> > >::other 	alloc_node;
			typedef T 																					value_type;
		private:
			allocator_type		_alloc;
			alloc_node			_alloc_node;
			s_node<M>			*_root;
			int					_compteur;
			
			s_node<M>	*createNode(const T& value, const KEY& key) {
				ft::pair<const KEY, T>	*_pair = _alloc.allocate(1);
				_alloc.construct(_pair, ft::make_pair(key, value));
				s_node<M>			*tmp = _alloc_node.allocate(1);
				// ft::pair<KEY, T>temp(key,value);
				// tmp->_data = temp;
				// std::cout << sizeof(tmp->_data.second) << std::endl << "\n";
				tmp->_data = _pair;
				// tmp->_data->first = key;
				// tmp->_data->second = value;
				tmp->left = NULL;
				tmp->right = NULL;
				return (tmp);
			}
			
			void		destroy(s_node<M> *ptr) {
				if (!ptr) {return;}
				destroy(ptr->left);
				destroy(ptr->right);
				_alloc.destroy(ptr->_data);
				_alloc.deallocate(ptr->_data, 1);
				_alloc_node.destroy(ptr);
				_alloc_node.deallocate(ptr, 1);
			}
			
			void		insert(const KEY& key, const T& value, s_node<M>*& ptr) {
				if (!ptr) {
					ptr = createNode(value, key);
					return ;
				}
				else if (key == ptr->_data->first) {
					_compteur--;
					return;
				}
				else if (key < ptr->_data->first) {
					insert(key, value, ptr->left);
				}
				else {
					insert(key, value, ptr->right);
				}
			}
			
			void		infixe(s_node<M> *ptr) const {
				if (!ptr) {return;}
				
				infixe(ptr->left);
				std::cout << "KEY : " << ptr->_data->first << " - T : " << ptr->_data->second << "\n";	
				infixe(ptr->right);	
			}
			
			s_node<M> 	*successeur(s_node<M> *ptr, s_node<M> *&parent) const {
				if (!ptr) {return (NULL);}
				
				s_node<M> *curent = ptr;
				while (curent->left != 0) {
					parent = curent;
					curent = curent->left;
				}
				return (curent);
			}
			
			s_node<M>	*predecesseur (s_node<M> *ptr, s_node<M>*& parent) const {
				if (!ptr) {return (NULL);}

				s_node<M> *curent = ptr;
				while (curent->right != 0) {
					parent = curent;
					curent = curent->droit;
				}
				return (curent);
			}
			
			void		toDelete(s_node<M> *ptr, s_node<M> *parent) {
				if (ptr->left == 0 &&  ptr->right == 0) { // Dans le cas ou le noeuds n'a pas d'enfants, est une feuille !
					std::cout << "Value key : " << ptr->_data->first << " - Value key parent : " << parent->_data->first << std::endl;
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
					_alloc.destroy(ptr->_data);
					_alloc.deallocate(ptr->_data, 1);
					_alloc_node.destroy(ptr);
					_alloc_node.deallocate(ptr, 1);
				}
				else if (ptr->left && ptr->right) { // Dans le cas ou left et right est pas null
					s_node<M>	*pere = ptr;
					s_node<M>	*succ = successeur(ptr->right, pere);
					// pair<const KEY, T> val  = *succ->_data;
					toDelete(succ, pere);
					ptr = succ;
				}
				else {
					s_node<M>	*child = (ptr->left) ? ptr->left : ptr->right;
					
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
					_alloc.destroy(ptr->_data);
					_alloc.deallocate(ptr->_data, 1);
					_alloc_node.destroy(ptr);
					_alloc_node.deallocate(ptr, 1);
				}
			}
			
			s_node<M>	*find(const KEY& key, s_node<M> *ptr, s_node<M> *&parent) const {
				if (!ptr) {
					return (NULL);
				}
				else if ((ptr->_data->first)  == key) {
					return (ptr);
				}
				else if (key < (ptr->_data->first)) {
					parent = ptr;
					return (find(key, ptr->left, parent));
				}
				else {
					parent = ptr;
					return (find(key, ptr->right, parent));
				}
			}
			
		public:
			node() : _root(0), _compteur(0) {}
			~node() { destroy(_root); }
			
			void		toDelete(const KEY& key) {
				s_node<M>	*parent = 0;
				s_node<M>	*del = find(key, _root, parent);
				if (!del) {
					std::cout << "Le noeud n'appartient pas a l'arbre" << std::endl;
				}
				else {
					toDelete(del, parent);
					_compteur--;
				}
			}
			
			s_node<M>	*find(const KEY& key, const T& value) const {
				s_node<M>	*parent = find(key, value);
				return (parent);
			}

			void		insert(const KEY& key, const T& value) {
				_compteur++;
				insert(key, value, _root);
			}
			
			void		infixe() const {
				infixe(_root);
			}

			int			size() const {return (_compteur);}
			bool		empty() const {return (_compteur == 0);}			
	};
}
#endif
