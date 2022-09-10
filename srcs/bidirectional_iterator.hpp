/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:59:53 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/10 23:29:47 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BIDIRECTIONAL_ITERATOR_HPP_
# define _BIDIRECTIONAL_ITERATOR_HPP_

# include "iterator_traits.hpp"
# include "binary_three_shearch.hpp"

namespace ft {
	template <class T, class nodeType>
	class bidirectional_iterator {
		public:
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef	nodeType*										nodePtr;
			typedef T												value_type;
			typedef std::ptrdiff_t									difference_type;
			typedef T&												reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;

		protected:
			nodePtr	_node;
			nodePtr	_root;
			nodePtr	_end;
		public:

			bidirectional_iterator() : _node(NULL), _root(NULL), _end(NULL) {}

			bidirectional_iterator(nodePtr ptr, nodePtr root, nodePtr end) : _node(ptr), _root(root), _end(end) {}

			bidirectional_iterator(bidirectional_iterator const &rhs) : _node(rhs._node), _root(rhs._root), _end(rhs._end) {}

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

			bool operator==(ft::bidirectional_iterator<value_type, nodeType> const &lhs) const {
				return (this->_node == lhs._node);
			}

			bool operator!=(ft::bidirectional_iterator<value_type, nodeType> const &lhs) const {
				return (this->_node != lhs._node);
			}

			template<class Iterator, class Iter>
			friend bool operator==(ft::bidirectional_iterator<Iterator, ft::s_node<Iterator> > const &lhs, ft::bidirectional_iterator<Iter, ft::s_node<Iter> > const &rhs);

			template<class Iterator, class Iter>
			friend bool operator!=(ft::bidirectional_iterator<Iterator, ft::s_node<Iterator> > const &lhs, ft::bidirectional_iterator<Iter, ft::s_node<Iter> > const &rhs);

			nodePtr		base() const {return (_node);}

			pointer			operator->() {return (&(_node->_data));}
			const_pointer	operator->() const {return (&(_node->_data));}
			reference		operator*() {return (_node->_data);}
			const_reference	operator*() const {return (_node->_data);}

			bidirectional_iterator &operator++() {
				if (_node != _end)
					_node = successor(_node);
				return (*this);
			}

			bidirectional_iterator operator++(int) {
				bidirectional_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			bidirectional_iterator &operator--() {
				if (_node == _end) {
					_node = maximum(_root);
				}
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
				if (x->right != _end)
					return minimum(x->right);
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
	};

	template<class Iterator, class Iter>
	bool operator==(ft::bidirectional_iterator<Iterator, ft::s_node<Iterator> > const &lhs, ft::bidirectional_iterator<Iter, ft::s_node<Iter> > const &rhs) {
		return (lhs._node == rhs._node);
	}

	template<class Iterator, class Iter>
	bool operator!=(ft::bidirectional_iterator<Iterator, ft::s_node<Iterator> > const &lhs, ft::bidirectional_iterator<Iter, ft::s_node<Iter> > const &rhs)
	{
		return (lhs._ptr != rhs._ptr);
	}

	template <class Iter, class nodePtr>
	bool operator== (const bidirectional_iterator<Iter, nodePtr>& lhs, const bidirectional_iterator<Iter, nodePtr>& rhs) {
		return (lhs.base() == rhs.base());
	}

	template <class Iter, class nodePtr>
	bool operator!= (const bidirectional_iterator<Iter, nodePtr>& lhs, const bidirectional_iterator<Iter, nodePtr>& rhs) {
		return (lhs.base() != rhs.base());
	}
}

#endif
