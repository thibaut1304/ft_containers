/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:14:42 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/08 00:54:02 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_HPP_
# define _UTILS_HPP_

# include <iostream>
# include <string>
# include <ctime>
# include <vector>
# include <unistd.h>

#ifndef NM
# define NM ft
# define USING "FT"
#endif

#include "vector.hpp"
#include "pair.hpp"

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

typedef ft::pair<const T1, T2> ft_pair;


#endif
