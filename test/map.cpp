/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:52:18 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/11 04:17:31 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

template <typename MAP>
void	mprint(MAP &m, std::string text = "NULL") {
	NM::map<T1, T2>::iterator it = m.begin(), ite = m.end();
	if (m.empty() == 0) {
		std::cout << _CYAN << USING << " MAP" << _NC << std::endl;
		std::cout << _CYAN << "SIZE : " << m.size() << _NC << std::endl;
		if (text != "NULL")
			std::cout << _YELLOW << text << _NC << std::endl;
		std::cout << _CYAN << "Value : " << _NC << std::endl;
		for (;it != ite; it++) {
			std::cout << it->first << " - " << it->second << std::endl;;
		}
	}
	else {
		if (text != "NULL")
			std::cout << _YELLOW << text << _NC << std::endl;
		std::cout << _CYAN << "Map is empty !" << std::endl;
	}
	std::cout << std::endl;
}

void	constructor() {
	std::string name = "CONSTRUCTOR";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	NM::map<T1, T2> m;
	mprint(m, "Default constructor");

	static int size = 10;
	int tab[10] = {42, 25, 50, 21, 30, 46, 55, 12, 38, 43};
	std::string text[10] = {"Hello", "MAP", "VECTOR", "STACK", "Mouse", "Laptop", "screen", "Windows", "Board", "Headphones"};
	for (int i = 0; i < size; i++) {
		m[tab[i]] = text[i];
	}
	mprint(m);

	NM::map<T1, T2> rm(m.begin(), m.end());
	mprint(rm, "Range constructor");

	NM::map<T1, T2> cm(rm);
	mprint(cm, "Copy constructor");

	NM::map<T1, T2> am;
	am = cm;
	mprint(am, "Assignation operator");
}

void	map_iterator() {
	std::string name = "ITERATOR";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	NM::map<T1, T2> m;

	static int size = 10;
	int tab[10] = {42, 25, 50, 21, 30, 46, 55, 12, 38, 43};
	std::string text[10] = {"Hello", "MAP", "VECTOR", "STACK", "Mouse", "Laptop", "screen", "Windows", "Board", "Headphones"};
	for (int i = 0; i < size; i++) {
		m[tab[i]] = text[i];
	}
	typedef NM::map<T1, T2>::iterator iterator;
	typedef NM::map<T1, T2>::const_iterator const_iterator;
	typedef NM::map<T1, T2>::const_reverse_iterator const_reverse_iterator;

	iterator it = m.begin(), ite = m.end();
	std::cout << _YELLOW << "Iterator : " << _NC << std::endl;
	for (; it != ite; it++) {
		std::cout << it->first << " - " << it->second;
		if (it != --m.end())
			std::cout << ", ";
		else
			std::cout << "." << std::endl;
	}

	const_iterator cit = m.begin(), cite = m.end();
	std::cout << _YELLOW << "Const_iterator : " << _NC << std::endl;
	for (; cit != cite; cit++) {
		std::cout << cit->first << " - " << cit->second;
		if (cit != --m.end())
			std::cout << ", ";
		else
			std::cout << "." << std::endl;
	}

	const_reverse_iterator rit = m.rbegin(), rite = m.rend();
	std::cout << _YELLOW << "Const_reverse_iterator : " << _NC << std::endl;
	for (; rit != rite; rit++) {
		std::cout << rit->first << " - " << rit->second;
		if (rit != --m.rend())
			std::cout << ", ";
		else
			std::cout << "." << std::endl;
	}
	std::cout << std::endl;
}

void	map_insert() {
	std::string name = "INSERT";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	NM::map<T1, T2>m;
	int tab[10] = {42, 25, 50, 21, 30, 46, 55, 12, 38, 43};
	std::string text[10] = {"Hello", "MAP", "VECTOR", "STACK", "Mouse", "Laptop", "screen", "Windows", "Board", "Headphones"};
	static int size = 10;

	for (int i = 0 ; i < size; i++) {
		m.insert(_pair(tab[i], text[i]));
	}
	mprint(m, "Insert value");

	typedef NM::map<T1, T2>::iterator iterator;
	NM::pair<iterator, bool> tmp = m.insert(_pair(90, "Hey !"));
	mprint(m, "Insert return pair");
	std::cout << _YELLOW << tmp.first->first << _NC << " is insered in map ? " << _YELLOW << ((tmp.second == 1) ? "yes" : "no") << _NC << std::endl;

	int tab2[8] = {18, 23, 28, 35, 44, 48, 53, 80};
	std::string text2[8] = {"kissingly", "lest", "rudely", "phew", "woot", "hydrocarbon", "hm", "gee"};
	NM::map<T1, T2> m2;
	for (int i = 0 ; i < 8; i++)
		m2.insert(_pair(tab2[i], text2[i]));

	m.insert(m2.begin(), m2.end());
	mprint(m, "Insert with ite other map");

	std::string name2 = "ERASE";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name2 << _NC << std::endl;

	m.erase(42);
	mprint(m, "Removal 42 in map");
	m.erase(m.begin(), ++(++(++(++(++m.begin())))));
	mprint(m, "Removal of the first five");
	m.erase(--m.end());
	mprint(m, "Removal the last of this map");
	std::string name3 = "CLEAR";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name3 << _NC << std::endl;
	m.clear();
	mprint(m, "Clear this map");
}

void	map_swap() {
	std::string name = "SWAP";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	int tab[10] = {42, 25, 50, 21, 30, 46, 55, 12, 38, 43};
	std::string text[10] = {"Hello", "MAP", "VECTOR", "STACK", "Mouse", "Laptop", "screen", "Windows", "Board", "Headphones"};
	static int size = 10;
	NM::map<T1, T2>m;
	for (int i = 0 ; i < size; i++) {
		m.insert(_pair(tab[i], text[i]));
	}

	mprint(m, "First MAP");

	int tab2[8] = {18, 23, 28, 35, 44, 48, 53, 80};
	std::string text2[8] = {"kissingly", "lest", "rudely", "phew", "woot", "hydrocarbon", "hm", "gee"};
	NM::map<T1, T2> m2;
	for (int i = 0 ; i < 8; i++)
		m2.insert(_pair(tab2[i], text2[i]));

	mprint(m2, "Second MAP");

	m.swap(m2);
	mprint(m, "First MAP");
	mprint(m2, "Second MAP");
}

void	map_find() {
	std::string name = "FIND";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	int tab[10] = {42, 25, 50, 21, 30, 46, 55, 12, 38, 43};
	std::string text[10] = {"Hello", "MAP", "VECTOR", "STACK", "Mouse", "Laptop", "screen", "Windows", "Board", "Headphones"};
	static int size = 10;
	NM::map<T1, T2>m;
	for (int i = 0 ; i < size; i++) {
		m.insert(_pair(tab[i], text[i]));
	}
	mprint(m);
	typedef NM::map<T1, T2>::iterator iterator;
	iterator find = m.find(30);
	iterator find2 = m.find(50);

	std::cout << "Find key '30' -> " << _YELLOW << find->first << _NC << " - " << _YELLOW << find->second << _NC << std::endl;
	std::cout << "Find key '50' -> " << _YELLOW << find2->first << _NC << " - " << _YELLOW << find2->second << _NC << std::endl;

	std::string name2 = "COUNT";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name2 << _NC << std::endl;

	mprint(m);
	std::cout << 38;
	if (m.count(38) > 0)
		std::cout << " is an element of map.\n";
	else
		std::cout << " is not an element of map.\n";
	std::cout << 37;
	if (m.count(37) > 0)
		std::cout << " is an element of map.\n";
	else
		std::cout << " is not an element of map.\n";

}

void	range() {
	std::string name = "LOWER AND UPPER BOUND";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	int tab[10] = {42, 25, 50, 21, 30, 46, 55, 12, 38, 43};
	std::string text[10] = {"Hello", "MAP", "VECTOR", "STACK", "Mouse", "Laptop", "screen", "Windows", "Board", "Headphones"};
	static int size = 10;
	NM::map<T1, T2>m;
	for (int i = 0 ; i < size; i++) {
		m.insert(_pair(tab[i], text[i]));
	}
	mprint(m);
	NM::map<T1, T2>::iterator low = m.lower_bound(15);
	NM::map<T1, T2>::iterator up = m.upper_bound(50);

	std::cout << "Lower Bound of 15 is " << _YELLOW << low->first << _NC << std::endl;
	std::cout << "Upper Bound of 50 is " << _YELLOW << up->first << _NC << std::endl;
	m.erase(low, up);
	mprint(m, "Erase with lower and upper bound");

	std::string name2 = "EQUAL RANGE";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name2 << _NC << std::endl;
	int tab2[8] = {18, 23, 28, 35, 44, 48, 53, 80};
	std::string text2[8] = {"kissingly", "lest", "rudely", "phew", "woot", "hydrocarbon", "hm", "gee"};
	NM::map<T1, T2> m2;
	for (int i = 0 ; i < 8; i++)
		m2.insert(_pair(tab2[i], text2[i]));

	mprint(m2);
	NM::pair<NM::map<T1, T2>::iterator, NM::map<T1, T2>::iterator> ret;

	ret = m2.equal_range(30);
	std::cout << "Lower bound points to : ";
	std::cout << _YELLOW << ret.first->first << _NC << " => " << _YELLOW << ret.first->second << _NC << std::endl;
	std::cout << "Upper bound points to : ";
	std::cout << _YELLOW << ret.second->first << _NC << " => " << _YELLOW << ret.second->second << _NC << std::endl;;

}

void	launch_map() {
	constructor();
	map_iterator();
	map_insert();
	map_swap();
	map_find();
	range();
}
