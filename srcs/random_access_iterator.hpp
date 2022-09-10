/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:11:00 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/10 23:36:01 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RANDOM_ACCESS_ITERATOR_HPP_
# define _RANDOM_ACCESS_ITERATOR_HPP_

#include <cstddef>

#include "iterator_traits.hpp"

namespace ft {
	template<typename T>
	class random_access_iterator {
		public:
			typedef std::random_access_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef	T*								pointer;
			typedef T&								reference;
			typedef const T*						const_pointer;
			typedef const T&						const_reference;

			random_access_iterator() : _ptr(NULL) {}

			random_access_iterator(pointer ptr) : _ptr(ptr) {}

			random_access_iterator(random_access_iterator  const &rhs) : _ptr(rhs._ptr) {}

			random_access_iterator &operator=(random_access_iterator const &rhs) {
				if (this != &rhs) {
					this->_ptr = rhs._ptr;
				}
				return (*this);
			}

			operator random_access_iterator<value_type const>() const {
				return random_access_iterator<value_type const>(_ptr);
			}

			virtual ~random_access_iterator() {}

			template<typename _Iterator>
			friend bool operator==(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs);

			template<typename _Iterator, typename _Iter>
			friend bool operator==(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs);

			template<typename _Iterator>
			friend bool operator!=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs);

			template<typename _Iterator, typename _Iter>
			friend bool operator!=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs);

			reference	operator*() { return (*_ptr); }
			const_reference	operator*() const { return (*_ptr); }

			pointer operator->() { return (_ptr); }
			const_pointer operator->() const { return (_ptr); }

			random_access_iterator &operator++() {
				++_ptr;
				return (*this);
			}

			random_access_iterator operator++(int) {
				random_access_iterator<T> tmp = *this;

				++_ptr;
				return (tmp);
			}

			random_access_iterator &operator--() {
				--_ptr;
				return (*this);
			}

			random_access_iterator operator--(int) {
				random_access_iterator<T> tmp = *this;

				_ptr--;
				return (tmp);
			}

			random_access_iterator operator+(difference_type const n) const {
				return (random_access_iterator<T>( _ptr + n));
			}

			random_access_iterator operator-(difference_type const n) const {
				return (random_access_iterator<T>(_ptr - n));
			}

			difference_type operator-(random_access_iterator const rhs) const {
				return (_ptr - rhs._ptr);
			}

			template<typename _Iterator>
			friend bool operator<(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs);

			template<typename _Iterator>
			friend bool operator>(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs);

			template<typename _Iterator>
			friend bool operator<=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs);

			template<typename _Iterator>
			friend bool operator>=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs);

			random_access_iterator &operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			}

			random_access_iterator &operator-=(difference_type n) {
				_ptr -= n;
				return (*this);
			}

			reference operator[](difference_type n) const {
				return *(_ptr + n);
			}

			template<typename _Iterator, typename _Iter>
			friend bool operator<(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs);

			template<typename _Iterator, typename _Iter>
			friend bool operator<=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs);

			template<typename _Iterator, typename _Iter>
			friend bool operator>(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs);

			template<typename _Iterator, typename _Iter>
			friend bool operator>=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs);


		protected:
			pointer	_ptr;
	};

	template<typename _Iterator>
	bool operator==(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs) {
		return (lhs._ptr == rhs._ptr);
	}

	template<typename _Iterator, typename _Iter>
	bool operator==(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs) {
		return (lhs._ptr == rhs._ptr);
	}

	template<typename _Iterator>
	bool operator!=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs) {
		return (lhs._ptr != rhs._ptr);
	}

	template<typename _Iterator, typename _Iter>
	bool operator!=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs) {
		return (lhs._ptr != rhs._ptr);
	}

	template<typename _Iterator>
	bool operator<(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs) {
		return (lhs._ptr < rhs._ptr);
	}

	template<typename _Iterator, typename _Iter>
	bool operator<(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs) {
		return (lhs._ptr < rhs._ptr);
	}

	template<typename _Iterator>
	bool operator>(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs) {
		return (lhs._ptr > rhs._ptr);
	}

	template<typename _Iterator, typename _Iter>
	bool operator>(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs) {
		return (lhs._ptr > rhs._ptr);
	}

	template<typename _Iterator>
	bool operator<=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs) {
		return (lhs._ptr <= rhs._ptr);
	}

	template<typename _Iterator, typename _Iter>
	bool operator<=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs) {
		return (lhs._ptr <= rhs._ptr);
	}

	template<typename _Iterator>
	bool operator>=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iterator> const &rhs) {
		return (lhs._ptr >= rhs._ptr);
	}

	template<typename _Iterator, typename _Iter>
	bool operator>=(random_access_iterator<_Iterator> const &lhs, random_access_iterator<_Iter> const &rhs) {
		return (lhs._ptr >= rhs._ptr);
	}

	template<class _Iterator>
	ft::random_access_iterator<_Iterator> operator+(typename ft::random_access_iterator<_Iterator>::difference_type n, ft::random_access_iterator<_Iterator> const &lhs) {
		return (lhs + n);
	}
}

#endif
