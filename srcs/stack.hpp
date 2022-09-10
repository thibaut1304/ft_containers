/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:17:17 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/11 00:43:19 by thhusser         ###   ########.fr       */
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

		protected:
			container_type	c;

		public:
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}

			stack (const stack &rhs) : c(rhs.c) {}

			stack &operator=(const stack &rhs) {
				if (this != &rhs) {
					c = rhs.c;
				}
				return (*this);
			}

			~stack() {}

			bool empty() const { return(c.empty());}

			size_type size() const { return(c.size());}

			value_type &top() { return (c.back());}

			const value_type &top() const { return (c.back());}

			void push(const value_type &val) {c.push_back(val);}

			void pop() {c.pop_back();}

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
		return (lhs.c == rhs.c);
	}

	template< class T, class Container >
	bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (!(lhs.c == rhs.c));
	}

	template< class T, class Container >
	bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (lhs.c < rhs.c);
	}

	template< class T, class Container >
	bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (!(rhs.c < lhs.c));
	}

	template< class T, class Container >
	bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (rhs.c < lhs.c);
	}

	template< class T, class Container >
	bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (!(lhs.c < rhs.c));
	}
}
#endif
