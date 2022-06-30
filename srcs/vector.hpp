/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:11:20 by thhusser          #+#    #+#             */
/*   Updated: 2022/06/30 18:00:13 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

#include <iostream>
// #include <type_traits>
#include <memory> // --> alloc --> construct & allocator
// #include <cstdlib> --> realloc finlement pas utilisé
#include <limits> // --> std::numeric_limits
#include <stdexcept> // --> execption Element access: at !

# include "reverse_iterator.hpp"
# include "random_access_iterator.hpp"


namespace ft {
	template<typename T, typename Alloc = std::allocator<T> >
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
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;


			/****************/
			/**CONSTRUCTOR***/
			/****************/
			// Default Constructs an empty container, with no elements.
			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _tab(NULL), _size(0), _capacity(0) {}
			// fill Constructs a container with n elements. Each element is a copy of val.
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc),  _tab(NULL), _size(n), _capacity(n) {
				// _tab - allouer à n
				// _tab le remplir avec val

				std::cout << "TEST" << std::endl;

				_tab = _alloc.allocate(n);
				for (size_type i = 0; i < n ; i++) {
					_alloc.construct(_tab + i, val);
				}
			}
			// range Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
			template <class _InputIterator>
			vector (_InputIterator first, _InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<!std::is_integral<_InputIterator>::value, _InputIterator>::type* = NULL) : _alloc(alloc), _tab(NULL) {

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
			// copy Constructs a container with a copy of each of the elements in x, in the same order.
			vector (const vector& x) :_alloc(x._alloc), _tab(NULL),  _size(x._size), _capacity(x._capacity) {
				if (x._capacity == 0)
					_capacity = x._size;
				_tab = _alloc.allocate(_size);
				for (size_type i = 0; i < x._size; i++) {
					_alloc.construct(_tab + i, x._tab[i]);
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
			// Destructor
			~vector() { // check capacity and destroys !
			// allocator::destroy -> destructor(value_type)pas dans vector !
			// allocator::deallocate
			// vector::clear -> supprime les donnes sauf la capacite
				clear();
				if (_capacity != 0) {
					// for(size_type i = 0;i < _capacity; i++) {
						_alloc.deallocate(_tab, _capacity);
					// }
				}
				_capacity = 0;
			}
			/****************/
			/****ITERATOR****/
			/****************/
			iterator begin() {
				return(iterator(_tab));
			}

			const_iterator begin() const {
				return(const_iterator(_tab));
			}

			iterator end() {
				return(iterator(_tab + _size));
			}
			const_iterator end() const {
				return(const_iterator(_tab + _size));
			}

			reverse_iterator rbegin() {
				return(reverse_iterator(end()));
			}
			const_reverse_iterator rbegin() const {
				return(const_reverse_iterator(end()));
			}

			reverse_iterator rend() {
				return(reverse_iterator(_tab));
			}

			const_reverse_iterator rend() const {
				return(const_reverse_iterator(_tab));
			}

			/****************/
			/****CAPACITY****/
			/****************/
			size_type size() const {
				return (_size);
			}

			size_type max_size() const {
				return (_alloc.max_size());
			}

			void resize (size_type n, value_type val = value_type()) {
				while (_size > n)
					pop_back();
				if (_size < n) {
					if (_capacity * 2 < n)
						reserve(n);
					else if (_capacity < n)
						reserve(_capacity * 2);
					for (size_type old_size = _size; old_size != n; old_size++) {
						_alloc.construct(_tab + old_size, val);
					}
					_size = n;
				}
			}

			size_type capacity() const {
				return (_capacity);
			}

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
					// T *tmp = _alloc.allocate(n);
					// size_type current_size = _size;
					// for (size_type i = 0; i < _size; i++)
					// 	_alloc.construct(tmp + i, _tab[i]);
					// this->~vector();
					// this->_tab = tmp;
					// this->_size = current_size;
					// this->_capacity = n;
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
			reference operator[] (size_type n) {
				return *(_tab + n);
			}
			const_reference operator[] (size_type n) const {
				return *(_tab + n);
			}

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

			reference front() {
				return *(_tab);
			}
			const_reference front() const {
				return *(_tab);
			}

			reference back() {
				return *(_tab + _size - 1);
			}
			const_reference back() const {
				return *(_tab + _size - 1);
			}

			/****************/
			/****MODIFIERS***/
			/****************/
			// range
			template <class _InputIterator>
			void assign(typename std::enable_if<!std::numeric_limits<_InputIterator>::is_integer, _InputIterator>::type first, _InputIterator last) {
			// void assign (_InputIterator first, _InputIterator last) {
				size_type	diff = 0;
					// std::cout << "TEST : ";
				for (_InputIterator tmp = first; tmp != last; tmp++) {
					// std::cout << " " << *first++;
					diff++;
				}
				// std::cout << std::endl;
				// for (_InputIterator tmp = first; tmp != last; tmp++) {
				// 	std::cout << " " << *first++;
				// 	diff++;
				// }
				std::cout << std::endl;
				// std::cout << std::endl;
				// std::cout << "je suis diff     :" << diff << std::endl;
				// std::cout << "je suis capacity :" << _capacity << std::endl;
				// clear();
				// std::cout << "Je suis _SIZE !!: " << _size << std::endl;
				resize(diff);
				// std::cout << "Je suis first !!: " << *first + 5 << std::endl;
				for (size_type tmp = 0; tmp != diff; tmp++) {
					_alloc.construct(_tab + tmp, *first++);
				// std::cout << "Je suis first !!: " << *first + 1 << std::endl;
				// first += 1;
				}
			}
			// fill
			void assign (size_type n, const value_type& val) {
				clear();
				resize(n);
				for (size_type it = 0; it != n; it++) {
					_alloc.construct(_tab + it, val);
				}
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

			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class _InputIterator>
			void insert (iterator position, _InputIterator first, _InputIterator last);

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			void swap (vector& x);

			void clear() {
				while (!empty())
					pop_back();
			}

			/****************/
			/****ALLOCATOR***/
			/****************/
			allocator_type get_allocator() const {
				return (_alloc);
			}

		protected:
			Alloc												_alloc;
			T*													_tab;
			size_type											_size;
			size_type											_capacity;
	};
}

#endif
