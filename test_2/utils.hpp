/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:14:42 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/10 19:05:56 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_HPP_
# define _UTILS_HPP_

# include <iostream>
# include <string>
# include <ctime>
# include <unistd.h>
# include <iomanip>

#ifdef USE
	# include <vector>
	# include <map>
	# include <stack>
	# define USING "STD"
#else
	#include "vector.hpp"
	#include "map.hpp"
	#include "stack.hpp"
	# define USING "FT"
#endif

# define _NC "\033[0;0m"
# define _RED "\033[0;31m"
# define _GREEN "\033[0;32m"
# define _YELLOW "\033[0;33m"
# define _BLUE "\033[0;34m"
# define _PURPLE "\033[0;95m"
# define _CYAN "\033[0;36m"
# define _WHITE "\033[0;37m"

# define T1 int
# define T2 std::string
# define T3 char

typedef NM::pair<const T1, T2> _pair;

/*************    VECTOR    ****************/
template <typename VEC>
void	print(VEC &vc, std::string pp = "NULL");
void	header(std::string name = "NULL", std::ostream &o = std::cout);
void	vector_constructor_and_equal();
void	iterator();
void	iterator_end();
void	capacity();
void	insert();
NM::vector<T1>		insert2();
void	erase(NM::vector<T1> v);
void	swap_and_clear();
void	launch_vector();
/*******************************************/
/*************    STACK    ****************/
void	basic_stack();
void test_stack();
void	launch_stack();
/*******************************************/

#endif
