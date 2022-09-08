/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:14:24 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/08 17:14:51 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	vector_constructor_and_equal() {

	std::cout << _PURPLE << "CONSTRUCTOR VECTOR and OPERATOR =" << _NC << std::endl;
	NM::vector<T1> first;
	NM::vector<T1> second(2, 100);
	NM::vector<T1> third(second.begin(), second.end());
	NM::vector<T1> fourth(third);
	first = fourth;
	std::cout << _CYAN << USING << " VECTOR" << _NC << std::endl;
	std::cout << _CYAN << "SIZE : " << first.size() << _NC << std::endl;
	std::cout << _CYAN << "Value : " << _NC;

	NM::vector<T1>::iterator it = first.begin(), ite = first.end();
	for (;it != ite; it++) {
		std::cout << *it;
		if (it != --first.end())
			std::cout << ", ";
		else
			std::cout << "." << std::endl;
	}
	std::cout << std::endl;
}

void	iterator() {
	std::cout << _PURPLE << "ITERATOR VECTOR" << _NC << std::endl;
	NM::vector<T1> vec;
	static int i = 10;
	for (int y = 0; y < i; y++) {
		vec.push_back(i - y);
	}

	std::cout << _CYAN << USING << " VECTOR" << _NC << std::endl;
	std::cout << _CYAN << "SIZE : " << vec.size() << _NC << std::endl;
	std::cout << _CYAN << "Value : " << _NC;
	NM::vector<T1>::iterator it = vec.begin(), ite = vec.end();
	for (;it != ite; it++) {
		std::cout << *it;
		if (it != --vec.end())
			std::cout << ", ";
		else
			std::cout << "." << std::endl;
	}
	std::cout << std::endl;
	it = vec.begin(), ite = vec.end();
	std::cout << "Vector begin     : " << *it << "\t\tVector end   : " << *ite << std::endl;
	it += 2;
	ite -=2;
	std::cout << "Vector begin + 2 : " << *it << "\t\tVector end -2 : " << *ite << std::endl;
	std::cout << std::endl;

	NM::vector<T1>::const_iterator c_it = vec.begin(), c_ite = vec.end();

	std::cout << "Vector const begin     : " << *c_it << "\t\tVector const end    : " << *c_ite << std::endl;
	c_it += 2;
	c_ite -=2;
	std::cout << "Vector const begin + 2 : " << *c_it << "\t\tVector const end -2 : " << *c_ite << std::endl;
	std::cout << std::endl;

	NM::vector<T1>::reverse_iterator r_it = vec.rbegin(), r_ite = vec.rend();

	std::cout << "Vector rbegin     : " << *r_it << "\t\tVector rend    : " << *r_ite << std::endl;
	r_it += 2;
	r_ite -=2;
	std::cout << "Vector rbegin + 2 : " << *r_it << "\t\tVector rend -2 : " << *r_ite << std::endl;
	std::cout << std::endl;
}

// void	capacity() {

// }

int main(void) {
	int time = 0;

	vector_constructor_and_equal();
	iterator();
	// capacity();

	NM::map<T1, T2> mp;


	time = clock();
	std::cout << _RED << time << _NC << std::endl;


	return (0);
}

