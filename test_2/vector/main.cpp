/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:14:24 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/10 17:40:11 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

template <typename VEC>
void	print_char(VEC &vc, std::string pp = "NULL") {
	NM::vector<char>::iterator it = vc.begin(), ite = vc.end();
	if (vc.empty() == 0) {
		std::cout << _CYAN << USING << " VECTOR" << _NC << std::endl;
		std::cout << _CYAN << "SIZE : " << vc.size() << _NC << std::endl;
		std::cout << _CYAN << "CAPA : " << vc.capacity() << _NC << std::endl;
		if (pp != "NULL")
			std::cout << _YELLOW << pp << _NC << std::endl;
		std::cout << _CYAN << "Value : " << _NC;
		for (;it != ite; it++) {
			std::cout << *it;
			if (it != --vc.end())
				std::cout << ", ";
			else
				std::cout << "." << std::endl;
		}
	}
	else {
		std::cout << _YELLOW << pp << _NC << std::endl;
		std::cout << _CYAN << "Vectos is empty !" << std::endl;
	}
	std::cout << std::endl;
}

template <typename VEC>
void	print(VEC &vc, std::string pp = "NULL") {
	NM::vector<T1>::iterator it = vc.begin(), ite = vc.end();
	if (vc.empty() == 0) {
		std::cout << _CYAN << USING << " VECTOR" << _NC << std::endl;
		std::cout << _CYAN << "SIZE : " << vc.size() << _NC << std::endl;
		std::cout << _CYAN << "CAPA : " << vc.capacity() << _NC << std::endl;
		if (pp != "NULL")
			std::cout << _YELLOW << pp << _NC << std::endl;
		std::cout << _CYAN << "Value : " << _NC;
		for (;it != ite; it++) {
			std::cout << *it;
			if (it != --vc.end())
				std::cout << ", ";
			else
				std::cout << "." << std::endl;
		}
	}
	else {
		std::cout << _YELLOW << pp << _NC << std::endl;
		std::cout << _CYAN << "Vectos is empty !" << std::endl;
	}
	std::cout << std::endl;
}

void	header(std::string name = "NULL", std::ostream &o = std::cout) {
	std::string enter = "Press enter to continue tests !";
	o << _GREEN << "|" << std::setfill('-') << std::setw(100) << "|" << _NC << std::setfill(' ') << std::endl;
	o << _GREEN << std::setw(50) << name << " - TESTS !" << _NC << std::endl;
	o << _GREEN << "|" << std::setfill('-') << std::setw(100) << "|" << _NC << std::setfill(' ') << std::endl;
	o << _WHITE << "|" << std::setw(100 - enter.length()) << enter << _NC << std::endl;
	while (std::cin.get() != '\n') {}
}

void	vector_constructor_and_equal() {

	std::string name = "CONSTRUCTOR VECTOR and OPERATOR =";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	NM::vector<T1> first;
	print(first, "Default. Name : first");
	NM::vector<T1> second(2, 100);
	print(second, "Fill. Name : second");
	NM::vector<T1> third(second.begin(), second.end());
	print(third, "Range. Name : third");
	NM::vector<T1> fourth(third);
	print(third, "Copy with third. Name : fourth");
	first = fourth;
	print(first, "Copy with fourth. Name : first");
}

void	iterator() {
	std::string name = "ITERATOR VECTOR";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	NM::vector<T1> vec;
	static int i = 10;
	for (int y = 0; y < i; y++) {
		vec.push_back(i - y);
	}
	print(vec);
	NM::vector<T1>::iterator it = vec.begin(), ite = vec.end();
	--ite;
	std::cout << "Vector begin     : " << _YELLOW << *it << _NC << "\t\tVector end    : " << _YELLOW << *ite << _NC << std::endl;
	it += 2;
	ite -=2;
	std::cout << "Vector begin + 2 : " << _YELLOW << *it << _NC << "\t\tVector end -2 : " << _YELLOW << *ite << _NC << std::endl;
	std::cout << std::endl;

	NM::vector<T1>::const_iterator c_it = vec.begin(), c_ite = vec.end();
	--c_ite;
	std::cout << "Vector const begin     : " << _YELLOW << *c_it << _NC << "\nVector const end       : " << _YELLOW << *c_ite << _NC << std::endl;
	c_it += 2;
	c_ite -=2;
	std::cout << "Vector const begin + 2 : " << _YELLOW << *c_it << _NC << "\nVector const end -2    : " << _YELLOW << *c_ite << _NC << std::endl;
	std::cout << std::endl;

	NM::vector<T1>::reverse_iterator r_it = vec.rbegin(), r_ite = vec.rend();
	--r_ite;
	std::cout << "Vector rbegin     : " << _YELLOW << *r_it << _NC << "\t\tVector rend    : " << _YELLOW << *r_ite << _NC << std::endl;
	r_it += 2;
	r_ite -=2;
	std::cout << "Vector rbegin + 2 : " << _YELLOW << *r_it << _NC << "\t\tVector rend -2 : " << _YELLOW << *r_ite << _NC << std::endl;
	std::cout << std::endl;
}

void	iterator_end() {
	const int size = 5;
	NM::vector<T1> vc(size);
	NM::vector<T1>::iterator it = vc.begin();
	NM::vector<T1>::iterator it_tmp;
	NM::vector<T1>::const_iterator const_it = vc.begin();

	for (int i = 0; i < size; i++)
		it[i] = (size - i);
	print(vc);
	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << "it +=: " << _YELLOW << *(it += 2) << _NC << std::endl;
	std::cout << "it +=: " << _YELLOW << *(it -= 1) << _NC << std::endl;

	std::cout << "const_it +=: " << _YELLOW << *(const_it += 2) << _NC << std::endl;
	std::cout << "const_it -=: " << _YELLOW << *(const_it -= 2) << _NC << std::endl;

	std::cout << "(it == const_it): " << _YELLOW <<  (const_it == it) << _NC << std::endl;
	std::cout << "(const_it - it): " << _YELLOW << (const_it - it) << _NC << std::endl;
	std::cout << "(const_it + 3 == it): " << _YELLOW << (const_it + 3 == it) << _NC << std::endl;

	std::cout << "Pre incrementation  : ";
	it_tmp = ++it;
	std::cout << _YELLOW << *it_tmp << " | " << *it << _NC << std::endl;

	std::cout << "Pre decremtation    : ";
	it_tmp = --it;
	std::cout << _YELLOW << *it_tmp << " | " << *it << _NC << std::endl;

	std::cout << "Post incrementation : ";
	it_tmp = it++;
	std::cout << _YELLOW << *it_tmp << " | " << *it << _NC << std::endl;

	std::cout << "Post decremtation   : ";
	it_tmp = it--;
	std::cout << _YELLOW << *it_tmp << " | " << *it << _NC << std::endl;
	std::cout << std::endl;
}

void	capacity() {
	std::string name = "CAPACITY";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;

	NM::vector<T1>v1(10);
	NM::vector<T1>v2(25);
	NM::vector<T1>v3(1);
	NM::vector<T1>v4(5);
	NM::vector<T1>v5;

	std::cout << "SIZE : " << _YELLOW << v1.size() << _NC << " Is empty ? " << _YELLOW << ((v1.empty() == 0) ? "no" : "yes") << _NC << std::endl;
	std::cout << "SIZE : " << _YELLOW << v2.size() << _NC << " Is empty ? " << _YELLOW << ((v2.empty() == 0) ? "no" : "yes") << _NC << std::endl;
	std::cout << "SIZE : " << _YELLOW << v3.size() << _NC << "  Is empty ? " << _YELLOW << ((v3.empty() == 0) ? "no" : "yes") << _NC << std::endl;
	std::cout << "SIZE : " << _YELLOW << v4.size() << _NC << "  Is empty ? " << _YELLOW << ((v4.empty() == 0) ? "no" : "yes") << _NC << std::endl;
	std::cout << "SIZE : " << _YELLOW << v5.size() << _NC << "  Is empty ? " << _YELLOW << ((v5.empty() == 0) ? "no" : "yes") << _NC << std::endl;
	std::cout << std::endl;
}

void	insert() {
	std::string name = "INSERT" ;
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	NM::vector<T1> vec;
	print(vec);
	vec.insert(vec.begin(), 10, 10);
	print(vec);
	vec.insert(vec.begin()+5, 5);
	print(vec, "Insert 5 in begin()+5 : ");

	static int size = 5;
	NM::vector<T1> vec2(size);
	NM::vector<T1>::iterator cp = vec2.begin();
	for (int i = 0; i < size; i++)
			cp[i] = (size * i) - 1;
	vec.insert(vec.end(), vec2.begin(), vec2.end());
	print(vec, "Insert -1 4 9 14 19 in vector :");
}

NM::vector<T1>		insert2() {
	static int size = 10;
	NM::vector<T1> v;
	for (int i = 0; i < size; i++)
		v.push_back(10 * i + size);
	NM::vector<T1> v2;
	for (int i = 0; i < size; i++)
		v2.push_back(10 * i);
	print(v);
	v.insert(v.end(), v2.begin(), v2.end());
	print(v);
	return (v);
}

void	erase(NM::vector<T1> v) {
	std::string name = "ERASE" ;
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	print(v);
	v.erase(v.begin());
	v.erase(--v.end());
	print(v, "Erase first and last");
	v.erase((v.begin() + 3), (v.begin() + 15));
	print(v, "Erase 50 to 50");
}

void	swap_and_clear() {
	std::string name = "SWAP and CLEAR" ;
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	static int size = 10;
	NM::vector<T1> v;
	for (int i = 0 ; i < size; i++)
		v.push_back(i);
	NM::vector<int> v2;
	for (int i = 0 ; i < size; i++)
		v2.push_back(i + 65);
	print(v, "First");
	print(v2, "Second");

	v.swap(v2);

	print(v, "Swap First and Second");
	print(v2, "Swap Second and First");
	v.clear();
	v2.clear();
	print(v, "Clear First");
	print(v2, "Clear Second");
}

int main(void) {
	int time = 0;


	iterator();
	iterator_end();
	capacity();
	insert();
	NM::vector<T1> V;
	V = insert2();
	erase(V);
	swap_and_clear();

	time = clock();
	std::cout << _RED << time << _NC << std::endl;


	return (0);
}

