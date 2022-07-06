/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:31:04 by thhusser          #+#    #+#             */
/*   Updated: 2022/07/06 19:41:07 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EQUAL_HPP_
# define _EQUAL_HPP_

namespace ft {
	template <class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	template <class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		while (first1 != last1)
		{
			if (!p(*first1, *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}
}

#endif
