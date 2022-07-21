/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:04:00 by thhusser          #+#    #+#             */
/*   Updated: 2022/07/21 14:36:06 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_HPP_
# define _MAP_HPP_

/*********************************/
# include <utility> // --> pair
# include <iterator>
/*********************************/
# include <functional> // --> LESS

# include "reverse_iterator.hpp"
// # include "pair.hpp"

// # include <cstddef> // ptrdiff -->  dans iterator_traits


namespace ft {
	template < class Key,                                  // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare      --> check si a recoder LESS --> NOP
			class Alloc = std::allocator<std::pair<const Key,T> > >  // map::allocator_type   --> recoder PAIR
			class map {
				public:

					typedef	Key 														key_type;
					typedef	T															mapped_type;
					typedef	std::pair<const key_type,mapped_type>						value_type;     //coder PAIR !
					typedef	Compare														key_compare;
					// typedef --> regarder value_compare nouv class ?
					typedef Alloc														allocator_type;
					typedef typename allocator_type::reference							reference;
					typedef typename allocator_type::const_reference					const_reference;
					typedef typename allocator_type::pointer							pointer;
					typedef typename allocator_type::const_pointer						const_pointer;
					typedef typename std::bidirectional_iterator_tag<value_type>		iterator;		// coder bidirectional_iterator
					typedef typename std::bidirectional_iterator_tag<value_type const>	const_iterator; // coder bidirectional_iterator
					typedef typename ft::reverse_iterator<value_type>					reverse_iterator;
					typedef typename ft::reverse_iterator<value_type const>				const_reverse_iterator;
					typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;	// utiliser ft::iterator
					typedef typename std::size_t										size_type;



					// empty (1)
					explicit map	(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

					// range (2)
					template <class InputIterator>
					map	(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

					// copy (3)
					map	(const map& x);

					~map();

					// copy (1)
					 map&	operator= (const map& x);

					iterator begin();
					const_iterator begin() const;

					iterator end();
					const_iterator end() const;

					reverse_iterator rbegin();
					const_reverse_iterator rbegin() const;

					reverse_iterator rend();
					const_reverse_iterator rend() const;

					bool empty() const;

					size_type size() const;

					size_type max_size() const;

					mapped_type& operator[] (const key_type& k);

					// single element (1)
					std::pair<iterator,bool> insert (const value_type& val);   // --> redocer pair

					// with hint (2)
					iterator insert (iterator position, const value_type& val);

					// range (3)
					template <class InputIterator>
					void insert (InputIterator first, InputIterator last);

					// (1)
					void erase (iterator position);

					// (2)
					size_type erase (const key_type& k);

					// (3)
					void erase (iterator first, iterator last);

					void swap (map& x);

					void clear();

					key_compare key_comp() const;

					value_compare value_comp() const;


					iterator find (const key_type& k);
					const_iterator find (const key_type& k) const;

					size_type count (const key_type& k) const;

					iterator lower_bound (const key_type& k);
					const_iterator lower_bound (const key_type& k) const;

					iterator upper_bound (const key_type& k);
					const_iterator upper_bound (const key_type& k) const;

					pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
					pair<iterator,iterator>             equal_range (const key_type& k);

					allocator_type get_allocator() const;
			};
}

#endif
