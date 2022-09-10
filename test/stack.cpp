/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:53:04 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/10 19:06:06 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	basic_stack() {
	NM::stack<T1>s;
	std::string name = "Push, Top and Size";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;

	static int size = 10;
	std::cout << _CYAN << USING << " STACK" << _NC << std::endl;
	for (int i = 0; i < size; i++) {
		s.push(size * i + size);
		std::cout << s.top();
			if ( i != size - 1)
				std::cout << ", ";
			else
				std::cout << ".\n";
	}
	std::cout << _CYAN << "SIZE : " << s.size() << _NC << std::endl << std::endl;
	std::string name2 = "Pop all and empty";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name2 << _NC << std::endl;
	for (int i = 0; i < size; i ++)
		s.pop();
	if (s.empty())
		std::cout << _CYAN << "Stack is empty !" << std::endl;

}
void test_stack() {
	std::string name = "DEFAULT CONSTRUCTOR";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name << _NC << std::endl;
	NM::stack<int> ft_stack;

	std::cout << "Stack size : " << _YELLOW << ft_stack.size() << _NC << std::endl << std::endl;

	std::cout << "Is empty ?" << _YELLOW << ((ft_stack.empty() == 1) ? " yes" : " no" ) << _NC << std::endl << std::endl;;

	std::cout << _CYAN << USING << " STACK" << _NC << std::endl;
	std::cout << _CYAN << "Value : " << _NC;
	for (int i = 0; i < 10; i++) {
	ft_stack.push(42 * i);
		std::cout << ft_stack.top();
		if ( i != 10 - 1)
			std::cout << ", ";
		else
			std::cout << ".\n";
	}
	std::cout << std::endl;
	std::cout << "Stack size : " << _YELLOW << ft_stack.size() << _NC << std::endl << std::endl;

	std::cout << "Is empty ?" << _YELLOW << ((ft_stack.empty() == 1) ? " yes" : " no" ) << _NC << std::endl << std::endl;;

	std::string name2 = "COPY CONSTRUCTOR";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name2 << _NC << std::endl;

	NM::stack<int> ft_stack_copy(ft_stack);

	std::cout << std::endl;
	std::cout << _CYAN << USING << " STACK" << _NC << std::endl;
	std::cout << _CYAN << "POP : " << _NC;
	for (int i = 0; i < 10; i++) {
		std::cout << ft_stack.top();
		if ( i != 10 - 1)
			std::cout << ", ";
		else
			std::cout << ".\n";
		ft_stack.pop();
	}
	std::cout << std::endl;

	std::string name3 = "ASSIGNATION OPERATOR = ";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name3 << _NC << std::endl;
	ft_stack_copy = ft_stack;
	std::cout << std::endl;
	std::cout << "stack = stack_copy !" << std::endl;
	std::cout << std::endl;

	std::string name4 = "OPERATIONAL OPERATOR";
	std::cout << std::setw(40 - (name.length() / 2)) << _PURPLE << name4 << _NC << std::endl;
	std::cout << "(stack == stack_copy) : " << _YELLOW << (((ft_stack == ft_stack_copy) == 1) ? "TRUE" : "FALSE") << _NC << std::endl;
	std::cout << "(stack != stack_copy) : " << _YELLOW << (((ft_stack != ft_stack_copy) == 1) ? "TRUE" : "FALSE") << _NC << std::endl;
	std::cout << "(stack < stack_copy)  : " << _YELLOW << (((ft_stack < ft_stack_copy) == 1) ? "TRUE" : "FALSE") << _NC << std::endl;
	std::cout << "(stack <= stack_copy) : " << _YELLOW << (((ft_stack <= ft_stack_copy) == 1) ? "TRUE" : "FALSE") << _NC << std::endl;
	std::cout << "(stack > stack_copy)  : " << _YELLOW << (((ft_stack > ft_stack_copy) == 1) ? "TRUE" : "FALSE") << _NC << std::endl;
	std::cout << "(stack >= stack_copy) : " << _YELLOW << (((ft_stack >= ft_stack_copy) == 1) ? "TRUE" : "FALSE") << _NC << std::endl;
	std::cout << std::endl;
}

void	launch_stack() {
	test_stack();
	basic_stack();
}
