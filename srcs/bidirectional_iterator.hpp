/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:59:53 by thhusser          #+#    #+#             */
/*   Updated: 2022/08/31 17:04:34 by thhusser         ###   ########.fr       */
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

			bidirectional_iterator operator++(int) {
				bidirectional_iterator tmp(*this);
				++(*this);
				return (tmp);
			}

			bidirectional_iterator &operator++() {
				_node = successeur(_node->right, _node);
				return (*this);
			}

			bidirectional_iterator operator--(int) {
				bidirectional_iterator tmp(*this);
				--(*this);
				return (*tmp);
			}

			bidirectional_iterator &operator--() {
				_node = predecesseur(_node->left, _node);
				return (*this);
			}
		private:
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
