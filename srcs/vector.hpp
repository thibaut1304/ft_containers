/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:11:20 by thhusser          #+#    #+#             */
/*   Updated: 2022/06/12 18:11:36 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

// #include <memory>
# include "reverse_iterator.hpp"


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

			typedef typename allocator_type::differente_type	differente_type;
			typedef typename allocator_type::size_type			size_type;


			/****************/
			/**CONSTRUCTOR***/
			/****************/
			// Default Constructs an empty container, with no elements.
			explicit vector (const allocator_type& alloc = allocator_type());
			// fill Constructs a container with n elements. Each element is a copy of val.
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			// range Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
			template <class _InputIterator>
			vector (_InputIterator first, _InputIterator last, const allocator_type& alloc = allocator_type());
			// copy Constructs a container with a copy of each of the elements in x, in the same order.
			vector (const vector& x);
			// Destructor
			~vector();
			vector& operator= (const vector& x);

			/****************/
			/****ITERATOR****/
			/****************/
			iterator begin();
			const_iterator begin() const;

			iterator end();
			const_iterator end() const;

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;

			reverse_iterator rend();
			const_reverse_iterator rend() const;

			/****************/
			/****CAPACITY****/
			/****************/
			size_type size() const;

			size_type max_size() const;

			void resize (size_type n, value_type val = value_type());

			size_type capacity() const;

			bool empty() const;

			void reserve (size_type n);

			/****************/
			/*****ACCESS*****/
			/****************/
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;

			reference at (size_type n);
			const_reference at (size_type n) const;

			reference front();
			const_reference front() const;

			reference back();
			const_reference back() const;

			/****************/
			/****MODIFIERS***/
			/****************/
			// range
			template <class _InputIterator>
			void assign (_InputIterator first, _InputIterator last);
			// fill
			void assign (size_type n, const value_type& val);

			void push_back (const value_type& val);

			void pop_back();

			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class _InputIterator>
			void insert (iterator position, _InputIterator first, _InputIterator last);

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			void swap (vector& x);

			void clear();

			/****************/
			/****ALLOCATOR***/
			/****************/
			allocator_type get_allocator() const;

			allocator_type get_allocator() const;
	};
}

#endif _VECTOR_HPP_