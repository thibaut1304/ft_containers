/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:04:00 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/02 18:18:13 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_HPP_
# define _MAP_HPP_

#define _NC "\033[0;0m"
#define _RED "\033[0;31m"
#define _GREEN "\033[0;32m"
#define _YELLOW "\033[0;33m"
#define _BLUE "\033[0;34m"
#define _PURPLE "\033[0;95m"
#define _CYAN "\033[0;36m"
#define _WHITE "\033[0;37m"

/*********************************/
// # include <utility> // --> pair
// # include <iterator>
/*********************************/
# include <functional> // --> LESS
# include <iterator>

# include "reverse_iterator.hpp"
# include "bidirectional_iterator.hpp"
# include "binary_three_shearch.hpp"
# include "equal.hpp"
# include "pair.hpp"

// # include <cstddef> // ptrdiff -->  dans iterator_traits

// value_comp --> true si la clé du premier argument est considérée comme devant celle du second sinon false

namespace ft {
	// template <class KEY, class T>
	// struct get_key : public std::unary_function<KEY, T>
	// {
	// 	const KEY &operator()(const KEY &x) const
	// 	{
	// 		// return (x.first);
	// 		return (x);
	// 	}
	// };

	template < class Key,                                  // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                // map::key_compare      --> check si a recoder LESS --> NOP
			class Alloc = std::allocator<ft::pair<const Key,T> > >  // map::allocator_type   --> recoder PAIR --> ok
			class map {
				// private:
					// typedef typename allocator_type::template rebind<nodeType>::other 	alloc_node;
				public:

					typedef	Key 														key_type;
					typedef	T															mapped_type;
					typedef	ft::pair<const key_type,mapped_type>						value_type;     //coder PAIR !
					typedef	Compare														key_compare;
					// typedef ft::tree<Key, T>											tree -->nop, template tree modifie pour compare !
					// typedef --> regarder value_compare nouv class ?

					typedef Alloc														allocator_type;

					typedef ft::tree<value_type, key_compare, allocator_type>			tree_type;

					typedef s_node<value_type>											nodeType;

					typedef typename tree_type::nodePtr									nodePtr;

					typedef typename allocator_type::reference							reference;
					typedef typename allocator_type::const_reference					const_reference;
					typedef typename allocator_type::pointer							pointer;
					typedef typename allocator_type::const_pointer						const_pointer;
					typedef ft::bidirectional_iterator<value_type, nodeType>				iterator;		// coder bidirectional_iterator
					typedef ft::bidirectional_iterator<const value_type, const nodeType>		const_iterator; // coder bidirectional_iterator
					typedef ft::reverse_iterator<value_type>							reverse_iterator;
					typedef ft::reverse_iterator<const value_type>						const_reverse_iterator;
					// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
					typedef typename allocator_type::difference_type					difference_type;	// utiliser ft::iterator
					typedef typename allocator_type::size_type							size_type;
					// typedef ft::tree<key_type, mapped_type, get_key<key_type, mapped_type>, key_compare>	tree_type;
					class value_compare : public std::binary_function<value_type, value_type, bool>
					{
						friend class map;
						protected:
							key_compare comp;
							value_compare(key_compare c) : comp(c) {}
						public:
							bool operator()(const value_type& lhs, const value_type& rhs) const {
								return comp(lhs.first, rhs.first);
							}
					};

				private:
						key_compare 	_comp;
						allocator_type 	_alloc;
						tree_type 		_tree;

				public:

					// empty (1)
					explicit map	(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree() {}

					// range (2)
					template <class InputIterator>
					map	(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree() {
						while (first != last) {
							_tree.insert(*first);
							first++;
						}
						insert(first, last);
					}

					// copy (3)
					map (const map& x) : _comp(x._comp), _alloc(x._alloc) {
						// *this = x;
						insert(x.begin(), x.end());
					}

					~map() {}

					// copy (1)
					 map&	operator= (const map& x) {
						if (this == &x)
							return *this;
						_tree.clear();
						if (x.size())
							insert(x.begin(), x.end());
						_alloc = x._alloc;
						_comp = x._comp;
						return *this;
					 }

					void	print_infixe() {
						std::cout << "\nAffichage arbre bianaire :\n";
						_tree.infixe();
					}

					iterator begin() {
						// std::cout << "MAP : ";
						// std::cout << _tree.getMin() << std::endl;
						// nodePtr test = _tree.getMin();
						// _tree.infixe();
						// std::cout << "Node right : ";
						// std::cout << test->right << std::endl;
						// std::cout << "Node left  : ";
						// std::cout << test->left << std::endl;
						// std::cout << "Value : " << test->_data.first << " - " <<  test->_data.second << std::endl;
						// std::cout << "Ite : " << _tree.getMin() << std::endl;
						// std::cout << "Ite : " << _tree.getRoot() << std::endl;
						// std::cout << "Ite : " << _tree.getEnd() << std::endl;
						return (iterator(_tree.getMin(), _tree.getRoot(), _tree.getEnd()));
					}
					const_iterator begin() const {
						// std::cout << "MIN MAP : " << _tree.getMin() << std::endl;
						return (const_iterator(_tree.getMin(), _tree.getRoot(), _tree.getEnd()));
					}

					iterator end() {
						// std::cout << "MAX MAP : " << _tree.getMax() << std::endl;
						return (iterator(_tree.getEnd(), _tree.getRoot(),  _tree.getEnd()));
					}

					const_iterator end() const {
						return (const_iterator(_tree.getEnd(), _tree.getRoot(), _tree.getEnd()));
					}

					reverse_iterator rbegin() {
						return (reverse_iterator(end()));
					}

					const_reverse_iterator rbegin() const {
						return (const_reverse_iterator(end()));
					}

					reverse_iterator rend() {
						return (reverse_iterator(begin()));
					}

					const_reverse_iterator rend() const {
						return (const_reverse_iterator(begin()));
					}

					bool empty() const {
						return (_tree.empty());
					}

					size_type size() const {
						return (_tree.size());
					}

					size_type max_size() const {
						// std::cout << _alloc.max_size() <<std::endl;
						return (_tree.max_size());
					}

					mapped_type& operator[] (const key_type& k);

					// single element (1)
					// ft::pair<iterator,bool> insert (const value_type& val) {
					// 	bool x = _tree.insert(val.first, val.second);
					// 	value_type node = _tree.get_pair(_tree.find(val.first, val.second));
					// 	// return (ft::make_pair<iterator, bool>(iterator(node.first), x));
					// 	(void)node;
					// 	return(ft::make_pair<iterator, bool>(iterator(), x));
					// }

					pair<iterator,bool> insert (const value_type& val) {
						nodePtr	node = _tree.find(val);
						bool	notInserted = false;
						if (!node || node == _tree.getEnd())
						{
							_tree.insert(val);
							node = _tree.find(val);
						// std::cout << "adresse end de node dans map : " << node << std::endl;
							notInserted = true;
						}
						// std::cout << "BOOL : " << notInserted << std::endl;
						// print_infixe();
						// std::cout << "ROOT insert : " << _tree.getRoot() << std::endl;
						// std::cout << "END  insert : " << _tree.getEnd() << std::endl;
						return (ft::make_pair(iterator(node, _tree.getRoot(), _tree.getEnd()), notInserted));
					}

					// void insert (const value_type& val) {
					// 	nodePtr	node;

					// 	// if (node != _tree.xgetEnd())
					// 		// return ;
					// 	// bool nil = false;

					// 	// if (node == _tree.getEnd())
					// 		// nil = true;
					// 	// bool	notInserted = false;
					// 	// if (nil)
					// // 	// {
					// 		_tree.insert(val);
					// 		node = _tree.find(val);
					// 	// std::cout << "adresse end de node dans map : " << node << std::endl;
					// 		// notInserted = true;
					// 	// }
					// 	(void)node;
					// 	// std::cout << "BOOL : " << notInserted << std::endl;
					// 	// print_infixe();
					// 	// std::cout << _RED << _tree.getMin() << _NC <<std::endl;
					// 	// std::cout << "ROOT insert : " << _tree.getRoot() << std::endl;
					// 	// std::cout << "END  insert : " << _tree.getEnd() << std::endl;
					// 	// return (ft::make_pair(iterator(node, _tree.getRoot(), _tree.getEnd()), notInserted));
					// }

					// with hint (2)
					// iterator insert (iterator position, const value_type& val);
					iterator insert (iterator position, const value_type& val) {
						static_cast<void>(position);
						nodePtr	node = _tree.find(val);
						if (!node || node == _tree.getEnd())
						{
							_tree.insert(val);
							node = _tree.find(val);
						// std::cout << _CYAN << node << _NC << std::endl;
						}
						// print_infixe();
						return (iterator(node, _tree.getRoot(), _tree.getEnd()));
					}

					// range (3)
					template <class InputIterator>
					void insert (InputIterator first, InputIterator last) {
						while (first != last)
						{
							_tree.insert(*first);
							first++;
						}
					}

					// (1)
					void erase (iterator position);

					// (2)
					size_type erase (const key_type& k);

					// (3)
					void erase (iterator first, iterator last);

					void swap (map& x);

					void clear() {_tree.clear();}

					key_compare key_comp() const;

					value_compare value_comp() const;


					iterator find (const key_type& k);
					const_iterator find (const key_type& k) const;

					size_type count (const key_type& k) const;

					iterator lower_bound (const key_type& k);
					const_iterator lower_bound (const key_type& k) const;

					iterator upper_bound (const key_type& k);
					const_iterator upper_bound (const key_type& k) const;

					ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
					ft::pair<iterator,iterator>             equal_range (const key_type& k);

					allocator_type get_allocator() const;
			};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	// template <class Key, class T, class Compare, class Alloc>
	// class map<Key,T,Compare,Alloc>::value_compare {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
	// 	friend class map;
	// 	protected:
	// 		Compare comp;
	// 		value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object
	// 	public:
	// 		typedef bool result_type;
	// 		typedef value_type first_argument_type;
	// 		typedef value_type second_argument_type;
	// 		bool operator() (const value_type& x, const value_type& y) const {
	// 			return comp(x.first, y.first);
	// 		}
	// };
}

#endif
