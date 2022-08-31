/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:59:53 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/01 00:35:52 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BIDIRECTIONAL_ITERATOR_HPP_
# define _BIDIRECTIONAL_ITERATOR_HPP_

# include "iterator_traits.hpp"

namespace ft {
	template <class T, class nodePtr>
	class bidirectional_iterator {
		protected:
			nodePtr	_node;
		public:
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef	typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			// typedef typename iterator_traits<T>::const_pointer						const_pointer;
			// typedef const T&						const_reference;

			bidirectional_iterator() : _node(NULL) {}

			bidirectional_iterator(nodePtr ptr) : _node(ptr) {}

			bidirectional_iterator(bidirectional_iterator const &rhs) : _node(rhs._node) {}

			bidirectional_iterator& operator=(bidirectional_iterator const &lhs) {
				if (this == &lhs)
					return (*this);
				this->_node = lhs._node;
				return (*this);
			}

			virtual ~bidirectional_iterator() {}

			nodePtr		base() const {return (_node);}

			pointer			operator->() const {return (&(_node->_data));}
			// const_pointer	operator->() const {return (&(_node->_data));}
			reference		operator*() const {return (_node->_data);}
			// const_reference	operator*() const {return (_node->_data);}

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
				bidirectional_iterator tmp(*this);
				--_node;
				// this = (--_node);
				// std::cout << _node->_data.first << std::endl;
				// std::cout << "BI : " << _node << std::endl;
				// std::cout << _node << std::endl;
				// if (_node)
					// _node = successeur(_node->parent, _node);
				// std::cout << _node << std::endl;
				// _node = _node->right;
				// if (_node)
					// _node = successor(_node);
				return (--tmp);
			}

			bidirectional_iterator operator++(int) {
				bidirectional_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			bidirectional_iterator &operator--() {
				// ++_node;
				if (_node)
					_node = predecesseur(_node->left, _node);
				else
					_node = maximum(_node);
				return (*this);
			}

			bidirectional_iterator operator--(int) {
				bidirectional_iterator tmp(*this);
				operator--();
				return (tmp);
			}

		private:

			nodePtr maximum(nodePtr ptr) {
				while (ptr->right)
					ptr = ptr->right;
				return (ptr);
			}

			nodePtr minimum(nodePtr ptr) {
				while (ptr->left)
					ptr = ptr->left;
				return (ptr);
			}

			nodePtr successor(nodePtr x) {
				// if the right subtree is not null the successor is the leftmost node in the sright subtree
				if (x->right != NULL)
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
					return NULL;
				return y;
			}

			nodePtr	successeur(nodePtr ptr, nodePtr &parent) const {
				if (!ptr) {return (NULL);}

				nodePtr curent = ptr;
				while (curent->left != 0) {
					parent = curent;
					curent = curent->left;
				}
				return (curent);
			}

			nodePtr	predecesseur (nodePtr ptr, nodePtr& parent) const {
				if (!ptr) {return (NULL);}

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
