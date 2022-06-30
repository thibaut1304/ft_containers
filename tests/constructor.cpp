/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:17:09 by thhusser          #+#    #+#             */
/*   Updated: 2022/06/28 09:46:59 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	two_copy (ft::vector<int>ft_vector, std::vector<int>std_vector) {
	ft::vector<int>ft_copy(ft_vector);
	std::vector<int>std_copy(std_vector);

	typedef ft::vector<int>::iterator ft_it;

	ft_it ft_it_begin = ft_copy.begin();
	ft_it ft_it_end = ft_copy.end();

	typedef std::vector<int>::iterator std_it;

	std_it std_it_begin = std_copy.begin();
	std_it std_it_end = std_copy.end();

	int i = 0;
	for (std_it_begin = std_copy.begin(); std_it_begin != std_it_end; std_it_begin++, i++) {
		*std_it_begin = i * 3;
	}
	i = 0;
	for(;ft_it_begin != ft_it_end; ft_it_begin++, i++) {
		*ft_it_begin = i * 3;
	}
	i = 0;
	std::cout << "Size officiel std_copy : " << std_copy.size() << std::endl;
	std::cout << "Size officiel ft_copy : " << ft_copy.size() << std::endl;

	print_vector(std_copy, ft_copy);
	print_vector(std_vector, ft_vector);

	ft::vector<int>ft_copy_copy(ft_copy);
	std::vector<int>std_copy_copy(std_copy);
	print_vector(std_copy_copy, ft_copy_copy);
}

void	part_two() {
	ft::vector<int>ft_vector(5);
	std::vector<int>std_vector(5);

	typedef ft::vector<int>::iterator ft_it;

	ft_it ft_it_begin = ft_vector.begin();
	ft_it ft_it_end = ft_vector.end();

	typedef std::vector<int>::iterator std_it;

	std_it std_it_begin = std_vector.begin();
	std_it std_it_end = std_vector.end();

	std::cout << "taille ft : " << ft_it_end - ft_it_begin << std::endl;
	std::cout << "taille std : " << std_it_end - std_it_begin << std::endl;
	two_copy(ft_vector, std_vector);
}

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
	part_two();
}
