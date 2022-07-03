/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:04:24 by thhusser          #+#    #+#             */
/*   Updated: 2022/07/03 21:40:26 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	print_my_vector(ft::vector<T> ft_my_vector) {
	std::cout << "--------- Print ft_vector ---------" << std::endl;
	std::cout << "Size : " << ft_my_vector.size() << std::endl;
	
	typedef typename ft::vector<T>::iterator iterator;
	iterator it = ft_my_vector.begin() ;
	iterator itend = ft_my_vector.end();

	for (it = ft_my_vector.begin(); it != itend; it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n" << std::endl;
}

template <typename T>
void	print_the_vector(std::vector<T> ft_my_vector) {
	std::cout << "--------- Print std_vector ---------" << std::endl;
	std::cout << "Size : " << ft_my_vector.size() << std::endl;
	typedef typename std::vector<T>::iterator iterator;
	iterator it = ft_my_vector.begin() ;
	iterator itend = ft_my_vector.end();

	for (it = ft_my_vector.begin(); it != itend; it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n" << std::endl;
}

template <typename T>
void	print_vector(std::vector<T> std_vector, ft::vector<T> ft_vector) {
	std::cout << "--------- Print std_vector -- >> ";
	std::cout << "Size : " << std_vector.size() << std::endl;
	typedef typename std::vector<T>::iterator std_iterator;
	std_iterator std_it = std_vector.begin();
	std_iterator std_itend = std_vector.end();

	for (std_it = std_vector.begin(); std_it != std_itend; std_it++) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl;
	std::cout << "--------- Print ft_vector  -- >> ";
	std::cout << "Size : " << ft_vector.size() << std::endl;
	typedef typename ft::vector<T>::iterator ft_iterator;
	ft_iterator ft_it = ft_vector.begin();
	ft_iterator ft_itend = ft_vector.end();

	for (ft_it = ft_vector.begin(); ft_it != ft_itend; ft_it++) {
		std::cout << *ft_it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
