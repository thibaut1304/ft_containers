/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:17:09 by thhusser          #+#    #+#             */
/*   Updated: 2022/06/17 15:26:06 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	constructor() {
	ft::vector<int> 	ft_vector1;
	std::vector<int> 	std_vector1;

	ft::vector<int> 	ft_vector2(5);
	std::vector<int> 	std_vector2(5);
	print_vector(std_vector2, ft_vector2);

	ft::vector<int> 	ft_vector3(5, 5);
	std::vector<int> 	std_vector3(5, 5);
	print_vector(std_vector3, ft_vector3);

	ft::vector<int> ft_vector4 = ft_vector3;
	std::vector<int> std_vector4 = std_vector3;
	print_vector(std_vector4, ft_vector4);

	ft::vector<int> 	ft_vector5(ft_vector4);
	std::vector<int> 	std_vector5(std_vector4);
	print_vector(std_vector5, ft_vector5);

	typedef ft::vector<int>::iterator ft_iterator;
	typedef std::vector<int>::iterator std_iterator;
	ft_iterator ft_it = ft_vector5.begin();
	ft_iterator ft_itend = ft_vector5.end();
	std_iterator std_it = std_vector5.begin();
	std_iterator std_itend = std_vector5.end();

	ft::vector<int> 	ft_vector6(ft_it, ft_itend);
	std::vector<int> 	std_vector6(std_it, std_itend);
	print_vector(std_vector6, ft_vector6);
}
