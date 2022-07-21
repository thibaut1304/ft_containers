/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:59:53 by thhusser          #+#    #+#             */
/*   Updated: 2022/07/21 16:06:46 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BIDIRECTIONAL_ITERATOR_HPP_
# define _BIDIRECTIONAL_ITERATOR_HPP_

# include "iterator_traits.hpp"

namespace ft {
	template <typename T>
	class bidirectional_iterator {
		
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef	T*								pointer;
		typedef T&								reference;
		typedef const T*						const_pointer;
		typedef const T&						const_reference;
	
		bidirectional_iterator();
		bidirectional_iterator(bidirectional_iterator const &rhs);
		bidirectional_iterator& operator=(bidirectional_iterator const &rhs);
		~bidirectional_iterator();
	};
}

#endif