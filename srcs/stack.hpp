/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:17:17 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/10 23:38:40 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_HPP_
# define _STACK_HPP_

# include "vector.hpp"
# include <cstdio>

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef T				value_type;
			typedef Container		container_type;
			typedef std::size_t		size_type;

		private:
			container_type	_c;

		public:
			explicit stack (const container_type& ctnr = container_type()) : _c(ctnr) {}

			stack (const stack &rhs) : _c(rhs._c) {}

			stack &operator=(const stack &rhs) {
				if (this != &rhs) {
					_c = rhs._c;
				}
				return (*this);
			}

			~stack() {}

			bool empty() const { return(_c.empty());}

			size_type size() const { return(_c.size());}

			value_type &top() { return (_c.back());}

			const value_type &top() const { return (_c.back());}

			void push(const value_type &val) {_c.push_back(val);}

			void pop() {_c.pop_back();}

			template <class type, class C>
			friend bool operator==(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
			template <class type, class C>
			friend bool operator!=(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
			template <class type, class C>
			friend bool operator<(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
			template <class type, class C>
			friend bool operator<=(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
			template <class type, class C>
			friend bool operator>(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
			template <class type, class C>
			friend bool operator>=(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
	};

	template< class T, class Container >
	bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (lhs._c == rhs._c);
	}

	template< class T, class Container >
	bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (!(lhs._c == rhs._c));
	}

	template< class T, class Container >
	bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (lhs._c < rhs._c);
	}

	template< class T, class Container >
	bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (!(rhs._c < lhs._c));
	}

	template< class T, class Container >
	bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (rhs._c < lhs._c);
	}

	template< class T, class Container >
	bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (!(lhs._c < rhs._c));
	}
}
#endif
