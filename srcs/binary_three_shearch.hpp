/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_three_shearch.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:12:37 by thhusser          #+#    #+#             */
/*   Updated: 2022/08/17 16:56:33 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BINARY_THREE_SHEARCH_
# define _BINARY_THREE_SHEARCH_

# define FEUILLE NULL
# include <iostream>
# include <memory>

# include "pair.hpp"

// creer ici pair clé / valeur ?
// ou juste les recup independament ?

namespace ft {
	
	template<typename T>
	typedef struct 	s_node {
		T 			_data;
		s_node<T>	*_left;
		s_node<T>	*_right;
	}				t_node;
	
	// template<class KEY, class T>
	template<class T>
	class node {
		public:
			typedef T 											value_type;
		private:
		t_node<T>	*_root;
		int			compteur;
		void		destroy(t_node<T> *ptr);
		void		insert(const T& value, t_node<T>*& ptr);
		void		infixe(t_node<T> *ptr) const;
		t_node<T> 	*successeur(t_node<T> *ptr, t_node<T> *&parent) const;
		t_node<T>	*predecesseur (t_node<T> *ptr, t_node<T>*& parent) const;
			// pair<KEY, T>	_pair;
			
	};
}
#endif
