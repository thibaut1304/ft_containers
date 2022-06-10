/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:08:16 by thhusser          #+#    #+#             */
/*   Updated: 2022/06/10 11:35:10 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REVERSE_ITERATOR_HPP_
# define _REVERSE_ITERATOR_HPP_

# include "iterator_traits.hpp"

namespace ft {
	template<typename _Iterator>
	class reverse_iterator {
		public:
			typedef					_Iterator										iterator_type;
			typedef	typename		iterator_traits<_Iterator>::iterator_category	category;
			typedef	typename		iterator_traits<_Iterator>::value_type			value_type;
			typedef	typename		iterator_traits<_Iterator>::difference_type		difference_type;
			typedef	typename		iterator_traits<_Iterator>::pointer				pointer;
			typedef	typename 		iterator_traits<_Iterator>::reference			reference;

			// iterator_type		Iterator										Iterator's type
			// iterator_category	iterator_traits<Iterator>::iterator_category	Preserves Iterator's category
			// value_type			iterator_traits<Iterator>::value_type			Preserves Iterator's value type
			// difference_type		iterator_traits<Iterator>::difference_type		Preserves Iterator's difference type
			// pointer				iterator_traits<Iterator>::pointer				Preserves Iterator's pointer type
			// reference			iterator_traits<Iterator>::reference			Preserves Iterator's reference type

			/****************/
			/* CONSTRUCTEUR */
			/****************/
			// 3 constructeur : default,  initalization, copy
			reverse_iterator();
			reverse_iterator(iterator_type it);
			// it : An iterator, whose sense of iteration is inverted in the constructed object.
			// it : Member type iterator_type is the underlying bidirectional iterator type (the class template parameter: Iterator).
			template<typename _It>
			// rev_it : An iterator of a reverse_iterator type, whose sense of iteration is preserved.
			reverse_iterator(const reverse_iterator<_It> &rev_it);

			/****************/
			/***** BASE *****/
			/****************/
			iterator_type base() const;

			/****************/
			/**** OPERATOR **/
			/****************/
			reference operator*() const;

			reverse_iterator operator+ (difference_type n) const;

			reverse_iterator& operator++();
			reverse_iterator  operator++(int);

			reverse_iterator& operator+= (difference_type n);

			reverse_iterator operator- (difference_type n) const;

			reverse_iterator& operator--();
			reverse_iterator  operator--(int);

			reverse_iterator& operator-= (difference_type n);

			pointer operator->() const;

			reference operator[] (difference_type n) const;

			/****************/
			/** OVERLOADS ***/
			/****************/
			template <class _It>
 			bool operator== (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);

			template <class _It>
			bool operator!= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);

			template <class _It>
			bool operator<  (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);

			template <class _It>
			bool operator<= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);

			template <class _It>
			bool operator>  (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);

			template <class _It>
			bool operator>= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);


			template <class _It>
			reverse_iterator<_It> operator+ (typename reverse_iterator<_It>::difference_type n, const reverse_iterator<_It>& rev_it);


			template <class _It>
			typename reverse_iterator<_It>::difference_type operator- (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);

	};
}
#endif
