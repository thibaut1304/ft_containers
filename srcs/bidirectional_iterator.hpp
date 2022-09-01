/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:59:53 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/01 21:20:13 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BIDIRECTIONAL_ITERATOR_HPP_
# define _BIDIRECTIONAL_ITERATOR_HPP_

# include "iterator_traits.hpp"
#include <iostream>

namespace ft {
	template <class T, class nodeType>
	class bidirectional_iterator {
		public:
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef	nodeType*										nodePtr;
			// typedef typename iterator_traits<T>::value_type			value_type;
			// typedef typename iterator_traits<T>::difference_type	difference_type;
			// typedef	typename iterator_traits<T>::pointer			pointer;
			// typedef typename iterator_traits<T>::reference			reference;
			// typedef typename iterator_traits<const T>::pointer 						const_pointer;
			typedef T				                        value_type;
			typedef std::ptrdiff_t	                        difference_type;
			typedef T&						reference;
			typedef const T&						const_reference;
			// typedef typename iterator_traits<const T>::reference			const_reference;
			typedef T*						pointer;
			typedef const T*						const_pointer;

		protected:
			nodePtr	_node;
			nodePtr	_root;
			nodePtr	_end;
		public:

			bidirectional_iterator() : _node(0), _root(0), _end(0) {}

			bidirectional_iterator(nodePtr ptr, nodePtr root, nodePtr end) : _node(ptr), _root(root), _end(end) {}

			bidirectional_iterator(bidirectional_iterator const &rhs) : _node(rhs._node), _root(rhs._root), _end(rhs._end) {}

			// template <class Iter, class nodeptr>
			// bidirectional_iterator (const bidirectional_iterator<Iter, nodeptr>& it) : _node(it._node) {}

			bidirectional_iterator& operator=(bidirectional_iterator const &lhs) {
				if (this == &lhs)
					return (*this);
				this->_node = lhs._node;
				this->_root = lhs._root;
				this->_end = lhs._end;
				return (*this);
			}

			operator bidirectional_iterator<value_type const, nodeType const>() const {
				return bidirectional_iterator<value_type const, nodeType const>(_node, _root, _end);
			}

			virtual ~bidirectional_iterator() {}

			nodePtr		base() const {return (_node);}

			pointer			operator->() {return (&(_node->_data));}
			const_pointer	operator->() const {return (&(_node->_data));}
			reference		operator*() {return (_node->_data);}
			const_reference	operator*() const {return (_node->_data);}

			bidirectional_iterator &operator++() {
				// std::cout << "BI : ";
				// std::cout << _node << std::endl;
					// std::cout << _node->right << std::endl;
					// std::cout << _node->left << std::endl;
				// std::cout << "Node right : ";
				// std::cout << _node->right << std::endl;
				// std::cout << "Node left  : ";
				// std::cout << _node->left << std::endl;
				// --(*this);
				// nodePtr tmp = _node;
				// _node = _node->parent;
				// bidirectional_iterator tmp(*this);
				// --_node;
				// this = (--_node);
				// std::cout << _node->_data.first << std::endl;
				// std::cout << "BI : " << _node << std::endl;
				// std::cout << _node << std::endl;
				// if (_node)
					// _node = successeur(_node->parent, _node);
				// std::cout << _node << std::endl;
				// _node = _node->right;
				// std::cout << "Racine : " << root() << std::endl;
				if (_node)
					_node = successor(_node);
				// std::cout << "inc max : " << _node << std::endl;
				return (*this);
			}

			bidirectional_iterator operator++(int) {
				bidirectional_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			nodePtr root() {
				nodePtr node = _node;

				while (node->parent != _end && node->parent) {
					node = node->parent;
				}
				std::cout << node << std::endl;
				return (node);
			}

			bidirectional_iterator &operator--() {
				// ++_node;
				// std::cout << _node << std::endl;

				if (_node == _end)
					_node = maximum(_root);
				else
					_node = predecessor(_node);
				return (*this);
			}

			bidirectional_iterator operator--(int) {
				bidirectional_iterator tmp(*this);
				operator--();
				return (tmp);
			}

		private:

			nodePtr maximum(nodePtr ptr) {
				while (ptr->right != _end)
					ptr = ptr->right;
				return (ptr);
			}

			nodePtr minimum(nodePtr ptr) {
				while (ptr->left != _end)
					ptr = ptr->left;
				return (ptr);
			}

			nodePtr predecessor(nodePtr x) {
				// if the left subtree is not null the predecessor is the rightmost node in the left subtree
				if (x->left != _end)
				{
					return maximum(x->left);
				}
				nodePtr y = x->parent;
				while (y != NULL && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			nodePtr successor(nodePtr x) {
				// if the right subtree is not null the successor is the leftmost node in the sright subtree
				if (x->right != _end)
				{
					return minimum(x->right);
				}
				// else it is the lowest ancestor of x whose left child is also an ancestor of x
				nodePtr y = x->parent;
				while (y != NULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				if (y == NULL)
					return _end;
				return y;
			}

			nodePtr	successeur(nodePtr ptr, nodePtr &parent) const {
				if (ptr == _end) {return (NULL);}

				nodePtr curent = ptr;
				while (curent->left != 0) {
					parent = curent;
					curent = curent->left;
				}
				return (curent);
			}

			nodePtr	predecesseur (nodePtr ptr, nodePtr& parent) const {
				if (ptr == _end) {return (NULL);}

				nodePtr	curent = ptr;
				while (curent->right != 0) {
					parent = curent;
					curent = curent->right;
				}
				return (curent);
			}

	};
	template <class Iter, class nodeptr>
	bool operator== (const bidirectional_iterator<Iter, nodeptr>& lhs,
					const bidirectional_iterator<Iter, nodeptr>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iter, class nodeptr>
	bool operator!= (const bidirectional_iterator<Iter, nodeptr>& lhs,
					const bidirectional_iterator<Iter, nodeptr>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
}

#endif
