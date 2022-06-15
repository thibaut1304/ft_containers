/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:08:16 by thhusser          #+#    #+#             */
/*   Updated: 2022/06/14 13:10:38 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REVERSE_ITERATOR_HPP_
# define _REVERSE_ITERATOR_HPP_

# include "iterator_traits.hpp"

namespace ft {
	template<typename _Iterator>
	class reverse_iterator {
		protected:
			_Iterator				_current;
		public:
			typedef					_Iterator										iterator_type;
			typedef	typename		iterator_traits<_Iterator>::iterator_category	category;
			typedef	typename		iterator_traits<_Iterator>::value_type			value_type;
			typedef	typename		iterator_traits<_Iterator>::difference_type		difference_type;
			typedef	typename		iterator_traits<_Iterator>::pointer				pointer;
			typedef	typename 		iterator_traits<_Iterator>::reference			reference;

			/****************/
			/* CONSTRUCTEUR */
			/****************/
			// 3 constructeur : default,  initalization, copy
			reverse_iterator() {};
			reverse_iterator(_Iterator it) : _current(it) {};
			// it : An iterator, whose sense of iteration is inverted in the constructed object.
			// it : Member type iterator_type is the underlying bidirectional iterator type (the class template parameter: Iterator).
			template<typename _It>
			reverse_iterator(const reverse_iterator<_It> &rev_it) : _current(rev_it.base()) {} ;
			// rev_it : An iterator of a reverse_iterator type, whose sense of iteration is preserved.
			virtual ~reverse_iterator() {};
			/****************/
			/***** BASE *****/
			/****************/
			iterator_type base() const {
				return (this->_current);
			}

			/****************/
			/**** OPERATOR **/
			/****************/
			reference operator*() const {
				_Iterator newref(this->_current);
				newref--;
				return (*newref);
			};

			reverse_iterator operator+ (difference_type n) const {
				return(_current - n);		// il doit etre un random access
			}

			reverse_iterator& operator++() {  // --> pré-incrementation
				--_current;
				return (*this);
			}
			reverse_iterator  operator++(int) {	// post incrementation
				reverse_iterator<_Iterator>	temp = *this;
				_current--;
				return (temp);
			}

			reverse_iterator& operator+= (difference_type n) {
				// faut que l'iterateur soir un random access
				_current -= n;
				return (*this);
			}

			reverse_iterator operator- (difference_type n) const {
				// faut que l'iterateur soir un random access
				return (_current + n);
			}

			reverse_iterator& operator--() { // --> pré-incrementation
				++_current;
				return (*this);
			}
			reverse_iterator  operator--(int) {	// post incrementation
				reverse_iterator<_Iterator> temp = *this;
				_current++;
				return (temp);
			}

			reverse_iterator& operator-= (difference_type n) { // itérateur de base soit un itérateur à accès aléatoire .
				_current += n;
				return (*this);
			}

			pointer operator->() const {
				return &(operator*());
			}

			reference operator[] (difference_type n) const {
				return (_current.base()[-n-1]);
			}
	};
		/****************/
		/** OVERLOADS ***/
		/****************/
		template <class _It>
		bool operator==(const reverse_iterator<_It> &lhs, const reverse_iterator<_It> &rhs) {
			return (lhs.base() == rhs.base());			// --> coder BASE ! renvoie l'iterateur courant !
		}

		template <class _It>
		bool operator!= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
			return (lhs.base() != rhs.base());
		}

		template <class _It>
		bool operator<  (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
			return (rhs.base() < lhs.base());
		}

		template <class _It>
		bool operator<= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
			return (rhs.base() <= lhs.base());
		}

		template <class _It>
		bool operator>  (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
			return (rhs.base() > lhs.base());
		}

		template <class _It>
		bool operator>= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
			return (rhs.base() >= lhs.base());
		}


		template <class _It>
		reverse_iterator<_It> operator+ (typename reverse_iterator<_It>::difference_type n, const reverse_iterator<_It>& rev_it) {
			return (rev_it._current -= n);
		}


		template <class _It>
		typename reverse_iterator<_It>::difference_type operator- (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
			return (lhs._current -= rhs._current);
		}

}
#endif
