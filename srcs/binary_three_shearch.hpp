/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_three_shearch.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:12:37 by thhusser          #+#    #+#             */
/*   Updated: 2022/08/19 22:07:31 by thhusser         ###   ########.fr       */
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
	
	template<typename T>
	struct 	s_node {
		T 			_data;
		s_node<T>	*left;
		s_node<T>	*right;
	};
	
	// template<class KEY, class T>
	template<class T>
	class node {
		public:
			typedef T 											value_type;
		private:
			s_node<T>	*_root;
			int			_compteur;
			
			s_node<T>	*createNode(const T& value) {
				s_node<T>	*tmp = new s_node <T>;
				tmp->_data = value;
				tmp->left = NULL;
				tmp->right = NULL;
				return (tmp);
			}
			
			void		destroy(s_node<T> *ptr) {
				if (!ptr) {return;}
				destroy(ptr->left);
				destroy(ptr->right);
				delete ptr;
			}
			
			void		insert(const T& value, s_node<T>*& ptr) {
				if (!ptr) {
					ptr = createNode(value);
					return ;
				}
				else if (value < ptr->_data) {
					insert(value, ptr->left);
				}
				else {
					insert(value, ptr->right);
				}
			}
			
			void		infixe(s_node<T> *ptr) const {
				if (!ptr) {return;}
				
				infixe(ptr->left);
				std::cout << ptr->_data << "\t";	
				infixe(ptr->right);	
			}
			
			s_node<T> 	*successeur(s_node<T> *ptr, s_node<T> *&parent) const {
				if (!ptr) {return (NULL);}
				
				s_node<T> *curent = ptr;
				while (curent->left != 0) {
					parent = curent;
					curent = curent->left;
				}
				return (curent);
			}
			
			s_node<T>	*predecesseur (s_node<T> *ptr, s_node<T>*& parent) const {
				if (!ptr) {return (NULL);}

				s_node<T> *curent = ptr;
				while (curent->right != 0) {
					parent = curent;
					curent = curent->droit;
				}
				return (curent);
			}
			
			void		toDelete(s_node<T> *ptr, s_node<T> *parent) {
				if (ptr->left == 0 &&  ptr->right == 0) { // Dans le cas ou le noeuds n'a pas d'enfants, est une feuille !
					std::cout << ptr->_data << parent->_data << std::endl;
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
					s_node<T>	*pere = ptr;
					s_node<T>	*succ = successeur(ptr->right, pere);
					int val  = succ->_data;									// A check avec le type !
					toDelete(succ, pere);
					ptr->_data = val;
				}
				else {
					s_node<T>	*child = (ptr->left) ? ptr->left : ptr->right;
					
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
			
			s_node<T>	*find(const T& value, s_node<T> *ptr, s_node<T> *&parent) const {
				if (!ptr) {
					return (NULL);
				}
				else if ((ptr->_data)  == value) {
					return (ptr);
				}
				else if (value < (ptr->_data)) {
					parent = ptr;
					return (find(value, ptr->left, parent));
				}
				else {
					parent = ptr;
					return (find(value, ptr->right, parent));
				}
			}
		public:
			node() : _root(0), _compteur(0) {}
			~node() { destroy(_root); }
			void		insert(const T& value) {
				insert(value, _root);
				_compteur++;
			}
			// void		detroy();
			
			void		toDelete(const T& value) {
				s_node<T>	*parent = 0;
				s_node<T>	*del = find(value, _root, parent);
				if (!del) {
					std::cout << "Le noeud n'appartient pas a l'arbre" << std::endl;
				}
				else {
					toDelete(del, parent);
				}
			}
			
			s_node<T>	*find(const T& value) const {
				s_node<T>	*parent = 0;
				return (find(value, _root));
			}
			
			void		infixe() const {
				infixe(_root);
			}

			int			size() const {return (_compteur);}
			bool		empty() const {return (_compteur == 0);}			
	};
}
#endif
