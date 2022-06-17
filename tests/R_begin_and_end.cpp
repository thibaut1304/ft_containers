/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   R_begin_and_end.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:08:21 by thhusser          #+#    #+#             */
/*   Updated: 2022/06/17 15:21:04 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void R_begin_and_end() {
	ft::vector<int> ft_vector;
	std::vector<int> std_vector;

	for (int i = 0; i < 10; i++) {
		ft_vector.push_back(i);
		std_vector.push_back(i);
	}
	print_vector(std_vector, ft_vector);

	typedef ft::vector<int>::reverse_iterator ft_iterator;
	typedef std::vector<int>::reverse_iterator std_iterator;

	ft_iterator ft_it = ft_vector.rbegin();
	std_iterator std_it = std_vector.rbegin();

	ft_iterator ft_itend = ft_vector.rend();
	std_iterator std_itend = std_vector.rend();

	std::cout << "ft_vector : rbegin : " << *ft_it << std::endl;
	std::cout << "std_vector : rbegin : " << *std_it << std::endl;
	std::cout << "ft_vector : rend : " << *ft_itend << std::endl;
	std::cout << "std_vector : rend : " << *std_itend << std::endl << std::endl;

	ft_it++;
	std_it++;

	std::cout << "ft_vector : rbegin ++ : " << *ft_it << std::endl;
	std::cout << "std_vector : rbegin ++ : " << *std_it << std::endl;
}
