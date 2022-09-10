/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:11:20 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/10 03:10:56 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

/***************COLOR*************/

# define _NC "\033[0;0m"
# define _RED "\033[0;31m"
# define _GREEN "\033[0;32m"
# define _YELLOW "\033[0;33m"
# define _BLUE "\033[0;34m"
# define _PURPLE "\033[0;95m"
# define _CYAN "\033[0;36m"
# define _WHITE "\033[0;37m"

/*********************************/

#include <iostream>
// #include <type_traits>
#include <memory> // --> alloc --> construct & allocator
// #include <cstdlib> --> realloc finlement pas utilisé
#include <limits> // --> std::numeric_limits
#include <stdexcept> // --> execption Element access: at !

# include "reverse_iterator.hpp"
# include "random_access_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"

# include <stdlib.h>

namespace ft {
	template<class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T 											value_type;
			typedef Alloc 										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::pointer			pointeur;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<value_type const>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;


			/****************/
			/**CONSTRUCTOR***/
			/****************/
			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _tab(NULL), _size(0), _capacity(0) {}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc),  _tab(NULL), _size(n), _capacity(n) {
				_tab = _alloc.allocate(n);
				for (size_type i = 0; i < n ; i++) {
					_alloc.construct(_tab + i, val);
				}
			}

			template <class _InputIterator>
			vector (_InputIterator first, _InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<_InputIterator>::value, _InputIterator>::type* = NULL) : _alloc(alloc), _tab(NULL) {

				size_type	diff = 0;
				for (_InputIterator tmp = first; tmp != last; tmp++) {
					diff++;
				}
				_size = diff;
				_capacity = diff;
				_tab = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(_tab + i, *first++);
				}
			}

			vector (const vector& x) :_alloc(x._alloc), _tab(NULL),  _size(x._size), _capacity(x._capacity) {
				if (x._capacity == 0)
					_capacity = x._size;
				if (_capacity != 0) {
					_tab = _alloc.allocate(_capacity);
					for (size_type i = 0; i < x._size; i++) {
						_alloc.construct(_tab + i, x._tab[i]);
					}
				}
			}

			vector& operator= (const vector& x) {
				if (this != &x) {
					size_type current_capacity = this->_capacity;
					this->~vector();
					this->_size = x._size;
					this->_capacity = current_capacity;
					if (x._size > this->_capacity)
						this->_capacity = x._size;
					_tab = _alloc.allocate(_size);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(_tab + i, x._tab[i]);
				}
				return (*this);
			}

			~vector() {
				clear();
				if (_capacity != 0) {
					_alloc.deallocate(_tab, _capacity);
					_capacity = 0;
				}
			}

			/****************/
			/****ITERATOR****/
			/****************/
			iterator begin() {return(iterator(_tab));}

			const_iterator begin() const {return(const_iterator(_tab));}

			iterator end() {return(iterator(_tab + _size));}

			const_iterator end() const {return(const_iterator(_tab + _size));}

			reverse_iterator rbegin() {return(reverse_iterator(end()));}

			const_reverse_iterator rbegin() const {return(const_reverse_iterator(end()));}

			reverse_iterator rend() {return(reverse_iterator(_tab));}

			const_reverse_iterator rend() const {return(const_reverse_iterator(_tab));}

			/****************/
			/****CAPACITY****/
			/****************/
			size_type size() const {return (_size);}

			size_type max_size() const {return (_alloc.max_size());}

			void resize (size_type n, value_type val = value_type()) {
				if ( _size > n) {
					while (_size != n)
						pop_back();
				}
				else if (_size < n) {
					if ((_capacity * 2) < n || _capacity == 0)
						reserve(n);
					else if (_capacity < n)
						reserve(_capacity * 2);
					while (_size != n)
						push_back(val);
				}
			}

			size_type capacity() const {return (_capacity);}

			bool empty() const {
				if (!_size)
					return (true);
				return (false);
			}

			void reserve (size_type n) {
				if (n > this->max_size())
					throw (std::length_error("vector::reserve"));
				else if (n > _capacity)
				{
					value_type	*prev_ptr = _tab;
					std::size_t	prev_size = _size;
					std::size_t	prev_capacity = _capacity;
					_tab = _alloc.allocate(n);
					_capacity = n;
					for(std::size_t i = 0; i < prev_size; i++)
						_alloc.construct(_tab + i, *(prev_ptr + i));
					_alloc.deallocate(prev_ptr, prev_capacity);
				}
			}

			/****************/
			/*****ACCESS*****/
			/****************/
			reference operator[] (size_type n) {return *(_tab + n);}

			const_reference operator[] (size_type n) const {return *(_tab + n);}

			reference at (size_type n) {
				if (n >= _size)
					throw std::out_of_range("at:: out of range index");
				return *(_tab + n);
			}
			const_reference at (size_type n) const {
				if (n >= _size)
					throw std::out_of_range("at:: out of range index");
				return *(_tab + n);
			}

			reference front() {return *(_tab);}

			const_reference front() const {return *(_tab);}

			reference back() {return *(_tab + _size - 1);}

			const_reference back() const {return *(_tab + _size - 1);}

			/****************/
			/****MODIFIERS***/
			/****************/

			template <class _InputIterator>
			void assign(typename ft::enable_if<!std::numeric_limits<_InputIterator>::is_integer, _InputIterator>::type first, _InputIterator last) {
				size_type	diff = 0;
				for (_InputIterator tmp = first; tmp != last; tmp++) {
					diff++;
				}
				size_type i = 0;
				if (_capacity < diff)
					i = 1;
				clear();
				if (i)
					resize(diff);
				for (size_type tmp = 0; tmp != diff; tmp++) {
					_alloc.construct(_tab + tmp, *first++);
				}
				_size = diff;
			}

			void assign (size_type n, const value_type& val) {
				size_type i = 0;
				if (_capacity < n)
					i = 1;
				clear();
				if (i)
					resize(n);
				for (size_type it = 0; it != n; it++) {
					_alloc.construct(_tab + it, val);
				}
				_size = n;
			}

			void push_back (const value_type& val) {
				if (_capacity == 0)
					reserve(1);
				else if (_size == _capacity)
					reserve(_capacity * 2);
				_alloc.construct(_tab + _size, val);
				_size++;
			}

			void pop_back() {
				_alloc.destroy(&_tab[_size - 1]);
				_size -= 1;
			}

			iterator insert (iterator position, const value_type& val) {
					difference_type index = position - begin();

					insert(position, 1, val);
					return (iterator(begin() + index));

			}

			void insert(iterator position, size_type n, const value_type &val) {
				difference_type const pos_diff = position - begin();
				difference_type const old_end_diff = end() - begin();
				iterator old_end;
				iterator new_end;

				resize(this->_size + n);
				new_end = end();
				position = begin() + pos_diff;
				old_end = begin() + old_end_diff;
				while (old_end != position)
					*--new_end = *--old_end;
				while (n-- > 0)
					*position++ = val;
			}

			template <class InputIterator>
			void insert (iterator position, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last) {
				size_type n = 0;
				for (InputIterator tmp = first; tmp != last; tmp++) {
					n++;
				}
				difference_type const pos_diff = position - begin();
				difference_type const old_end_diff = end() - begin();
				iterator old_end;
				iterator new_end;

				resize(_size + n);
				new_end = end();
				position = begin() + pos_diff;
				old_end = begin() + old_end_diff;
				while (old_end != position)
					*--new_end = *--old_end;
				while (first != last)
					*position++ = *first++;
			}

			iterator erase (iterator position) {
				_alloc.destroy(&*position);
				for (iterator tmp = position; tmp + 1 != end(); tmp++)
				{
					_alloc.construct(&*tmp, *(tmp + 1));
					_alloc.destroy(&*(tmp + 1));
				}
				_size--;
				return (position);
			}

			iterator erase (iterator first, iterator last) {
				size_type diff = 0;

				for (iterator tmp = first; tmp != last; tmp++)
					diff++;
				for (iterator tmp = first; tmp != last; tmp++)
					_alloc.destroy(&*tmp);
				for (iterator tmp = first; tmp + diff != end(); tmp++) {
					_alloc.construct(&*tmp, *(tmp + diff));
					_alloc.destroy(&*(tmp + diff));
				}
				_size -= diff;
				return (first);
			}

			void swap (vector& x) {
				T*	tmp_tab = _tab;
				_tab = x._tab;
				x._tab = tmp_tab;

				size_type tmp_size = _size;
				_size = x._size;
				x._size = tmp_size;

				size_type tmp_capacity = _capacity;
				_capacity = x._capacity;
				x._capacity = tmp_capacity;

				Alloc tmp_alloc = _alloc;
				_alloc = x._alloc;
				x._alloc = tmp_alloc;
			}

			void clear() {
				while (!empty())
					pop_back();
			}

			/****************/
			/****ALLOCATOR***/
			/****************/

			allocator_type get_allocator() const {return (_alloc);}

		protected:
			Alloc												_alloc;
			T*													_tab;
			size_type											_size;
			size_type											_capacity;
	};

	template <class T, class Alloc>
  	bool operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
  	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}
		template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}
}

#endif
