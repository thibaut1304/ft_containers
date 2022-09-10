/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:45:19 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/10 23:33:37 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITERATOR_TRAITS_HPP_
# define _ITERATOR_TRAITS_HPP_

# include <cstddef>


namespace ft {
	struct random_access_iterator_tag {};

	template<typename _Iterator>
	struct iterator_traits {
		typedef typename _Iterator::value_type			value_type;
		typedef typename _Iterator::difference_type		difference_type;
		typedef typename _Iterator::pointer				pointer;
		typedef typename _Iterator::reference			reference;
		typedef typename _Iterator::iterator_category	iterator_category;
	};

	template<typename _Tp>
	struct iterator_traits<_Tp*> {
		typedef ft::random_access_iterator_tag		iterator_category;
		typedef _Tp									value_type;
		typedef ptrdiff_t							difference_type;
		typedef _Tp*								pointer;
		typedef _Tp&								reference;
	};

	template<typename _Tp>
	struct iterator_traits<const _Tp*> {
		typedef ft::random_access_iterator_tag		iterator_category;
		typedef _Tp									value_type;
		typedef ptrdiff_t							difference_type;
		typedef const _Tp*							pointer;
		typedef const _Tp&							reference;
	};
}

#endif
