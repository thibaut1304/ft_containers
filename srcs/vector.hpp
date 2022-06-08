/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:11:20 by thhusser          #+#    #+#             */
/*   Updated: 2022/06/08 16:48:43 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
	template<typename T, typename Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::pointer			pointeur;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			
			typedef typename allocator_type::differente_type	differente_type;
			typedef typename allocator_type::size_type			size_type;

	}
}

