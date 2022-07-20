/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:33:12 by thhusser          #+#    #+#             */
/*   Updated: 2022/07/15 21:46:28 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PAIR_HPP_
# define _PAIR_HPP_

namespace ft {
	template <class T1, class T2>
	struct pair {

		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		// par défaut (1)
		pair();
		// copie (2)
		template<class U, class V> pair (const pair<U,V>& pr);
		// initialisation (3)
		pair (const first_type& a, const second_type& b);

		// déclaré implicitement :
		// copie (1)
		pair& operator= (const pair& pr);
	};

	// (1)
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	// (2)
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	// (3)
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	// (4)
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	// (5)
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	// (6)
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y);
}

#endif