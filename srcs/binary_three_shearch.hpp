/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_three_shearch.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:12:37 by thhusser          #+#    #+#             */
/*   Updated: 2022/08/19 22:55:06 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BINARY_THREE_SHEARCH_
# define _BINARY_THREE_SHEARCH_

# define FEUILLE NULL
# include <iostream>
# include <memory>

# include "pair.hpp"

// creer ici pair clé / valeur ?
// ou juste les recup independament ?

namespace ft {
	
	// template<typename T>
	template<class KEY, class T>
	struct 	s_node {
		// T 			_data;

		pair<KEY, T>	_data;
		s_node<KEY, T>	*left;
		s_node<KEY, T>	*right;
	};
	
	// template<class T>
	template<class KEY, class T>
	class node {
		public:
			typedef T 											value_type;
		private:
			s_node<KEY, T>	*_root;
			int			_compteur;
			
			s_node<KEY, T>	*createNode(const T& value, const KEY& key) {
				s_node<KEY, T>	*tmp = new s_node<KEY, T>;
				tmp->_data.first = key;
				tmp->_data.second = value;
				tmp->left = NULL;
				tmp->right = NULL;
				return (tmp);
			}
			
			void		destroy(s_node<KEY, T> *ptr) {
				if (!ptr) {return;}
				destroy(ptr->left);
				destroy(ptr->right);
				delete ptr;
			}
			
			void		insert(const KEY& key, const T& value, s_node<KEY, T>*& ptr) {
				if (!ptr) {
					ptr = createNode(value, key);
					return ;
				}
				else if (key < ptr->_data.first) {
					insert(key, value, ptr->left);
				}
				else {
					insert(key, value, ptr->right);
				}
			}
			
			void		infixe(s_node<KEY, T> *ptr) const {
				if (!ptr) {return;}
				
				infixe(ptr->left);
				std::cout << "KEY : " << ptr->_data.first << " - T : " << ptr->_data.second << "\n";	
				infixe(ptr->right);	
			}
			
			s_node<KEY, T> 	*successeur(s_node<KEY, T> *ptr, s_node<KEY, T> *&parent) const {
				if (!ptr) {return (NULL);}
				
				s_node<KEY, T> *curent = ptr;
				while (curent->left != 0) {
					parent = curent;
					curent = curent->left;
				}
				return (curent);
			}
			
			s_node<KEY, T>	*predecesseur (s_node<KEY, T> *ptr, s_node<KEY, T>*& parent) const {
				if (!ptr) {return (NULL);}

				s_node<KEY, T> *curent = ptr;
				while (curent->right != 0) {
					parent = curent;
					curent = curent->droit;
				}
				return (curent);
			}
			
			void		toDelete(s_node<KEY, T> *ptr, s_node<KEY, T> *parent) {
				if (ptr->left == 0 &&  ptr->right == 0) { // Dans le cas ou le noeuds n'a pas d'enfants, est une feuille !
					std::cout << "Value key : " << ptr->_data.first << " - Value key parent : " << parent->_data.first << std::endl;
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
					delete ptr;
				}
				else if (ptr->left && ptr->right) { // Dans le cas ou lest eet right est pas null
					s_node<KEY, T>	*pere = ptr;
					s_node<KEY, T>	*succ = successeur(ptr->right, pere);
					pair<KEY, T> val  = succ->_data;									// A check avec le type !
					toDelete(succ, pere);
					ptr->_data = val;
				}
				else {
					s_node<KEY, T>	*child = (ptr->left) ? ptr->left : ptr->right;
					
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
					delete ptr;
				}
			}
			
			s_node<KEY, T>	*find(const KEY& key, s_node<KEY, T> *ptr, s_node<KEY, T> *&parent) const {
				if (!ptr) {
					return (NULL);
				}
				else if ((ptr->_data.first)  == key) {
					return (ptr);
				}
				else if (key < (ptr->_data.first)) {
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
			void		insert(const KEY& key, const T& value) {
				insert(key, value, _root);
				_compteur++;
			}
			
			void		toDelete(const KEY& key) {
				s_node<KEY, T>	*parent = 0;
				s_node<KEY, T>	*del = find(key, _root, parent);
				if (!del) {
					std::cout << "Le noeud n'appartient pas a l'arbre" << std::endl;
				}
				else {
					toDelete(del, parent);
					_compteur--;
				}
			}
			
			s_node<KEY, T>	*find(const KEY& key, const T& value) const {
				s_node<KEY, T>	*parent = 0;
				return (find(key, value, _root));
			}
			
			void		infixe() const {
				infixe(_root);
			}

			int			size() const {return (_compteur);}
			bool		empty() const {return (_compteur == 0);}			
	};
}
#endif
