/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:14:24 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/07 22:52:49 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int main(void) {
	NM::vector<T1> ft(10, 5);
	// NM::list<T1> lst;
	NM::vector<T1>::iterator it = ft.begin(), ite = ft.end();

	for (;it != ite; it++) {
		std::cout << "T : " << *it << std::endl;
	}

	return (0);
}
