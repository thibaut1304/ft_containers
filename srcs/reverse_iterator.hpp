/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:08:16 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/02 18:57:43 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REVERSE_ITERATOR_HPP_
# define _REVERSE_ITERATOR_HPP_

# include "iterator_traits.hpp"
// # include "iterator_traits.hpp"

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

			/****************/
			/* CONSTRUCTEUR */
			/****************/
			// 3 constructeur : default,  initalization, copy
			reverse_iterator() : _current() {}
			explicit reverse_iterator(iterator_type it) : _current(it) {}
			// it : An iterator, whose sense of iteration is inverted in the constructed object.
			// it : Member type iterator_type is the underlying bidirectional iterator type (the class template parameter: Iterator).
			template<typename _It>
			reverse_iterator(const reverse_iterator<_It> &rev_it) : _current(rev_it.base()) {}
			template<typename _It>
			reverse_iterator &operator=(reverse_iterator const &rhs)
			{
				if (this != &rhs) {
					_current = rhs._current;
				}
				return (*this);
			}
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
				return *(newref);
			};

			reverse_iterator operator+ (difference_type n) const {
				return(reverse_iterator<_Iterator>(_current - n));		// il doit etre un random access
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
				return (reverse_iterator<_Iterator>(_current + n));
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
				return (_current[-n-1]);
			}

			template <class _It>
			friend bool operator==(const reverse_iterator<_It> &lhs, const reverse_iterator<_It> &rhs);
			template <class _It>
			friend bool operator!= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It>
			friend bool operator<  (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It>
			friend bool operator<= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It>
			friend bool operator>  (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It>
			friend bool operator>= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It>
			friend reverse_iterator<_It> operator+ (typename reverse_iterator<_It>::difference_type n, const reverse_iterator<_It>& rev_it);
			template <class _It, class _Iter>
			friend reverse_iterator<_It> operator+(typename reverse_iterator<_It>::difference_type n, const reverse_iterator<_Iter> &rev_it);
			template <class _It>
			friend typename reverse_iterator<_It>::difference_type operator- (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It, typename _Iter>
			friend typename reverse_iterator<_It>::difference_type operator- (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs);

			difference_type substract(const reverse_iterator<_Iterator> rhs) const {
				return (rhs.base() - this->_current);
			}

			protected:
				_Iterator				_current;
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

	/*                      NON FIRENDS               */
	template <class _It, class _Iter>
	bool operator==(const reverse_iterator<_It> &lhs, const reverse_iterator<_Iter> &rhs) {
		return (lhs.base() == rhs.base());			// --> coder BASE ! renvoie l'iterateur courant !
	}

	template <class _It, class _Iter>
	bool operator!= (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class _It, class _Iter>
	bool operator<  (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		return (rhs.base() < lhs.base());
	}

	template <class _It, class _Iter>
	bool operator<= (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		return (rhs.base() <= lhs.base());
	}

	template <class _It, class _Iter>
	bool operator>  (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		return (rhs.base() > lhs.base());
	}

	template <class _It, class _Iter>
	bool operator>= (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		return (rhs.base() >= lhs.base());
	}

	template <class _It>
	reverse_iterator<_It> operator+ (typename reverse_iterator<_It>::difference_type n, const reverse_iterator<_It>& rev_it) {
		return (rev_it + n);
	}

	template <class _It, class _Iter>
	reverse_iterator<_It> operator+(typename reverse_iterator<_It>::difference_type n, const reverse_iterator<_Iter>& rev_it) {
		return (rev_it + n);
	}

	template <class _It>
	typename reverse_iterator<_It>::difference_type operator- (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
		// return (lhs - rhs);
		return (lhs.substract(rhs));
	}

	template <class _It, typename _Iter>
	typename reverse_iterator<_It>::difference_type operator- (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		// return (lhs - rhs);
		return (lhs.substract(rhs));
	}

}
#endif
