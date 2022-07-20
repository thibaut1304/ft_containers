/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:04:24 by thhusser          #+#    #+#             */
/*   Updated: 2022/07/20 19:52:25 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	global = 0;

template <typename T>
int		verif(std::vector<T> std_vector, ft::vector<T> ft_vector, int erase = 0) {
	int ret = 0;
	typename std::vector<T>::iterator std_it = std_vector.begin();
	typename ft::vector<T>::iterator ft_it = ft_vector.begin();

	for (; std_it != std_vector.end(); std_it++, ft_it++) {
		if (*std_it != *ft_it) {
			std::cout << _RED << "Diff vector" << _NC << std::endl;
			ret = 1;
			global++;
			break ;
		}
	}
	int i = 0;
	while (ft_it != ft_vector.end())
		i++;
	if (i != 0) {
		std::cout << _RED << "Diff vector" << _NC << std::endl;
		global++;
		ret = 1;
	}
	if (ft_vector.size() != std_vector.size()) {
		std::cout << _RED << "Diff size vector" << _NC << std::endl;
		global++;
		ret = 1;
	}
	if (ft_vector.capacity() != std_vector.capacity() && erase == 0) {
		std::cout << _RED << "Diff capacity vector" << _NC << std::endl;
		ret = 1;
	}
	return (ret);
}

template <typename T>
void	print_my_vector(ft::vector<T> ft_my_vector) {
	std::cout << "--------- Print ft_vector ---------" << std::endl;
	std::cout << "Size : " << ft_my_vector.size() << "\t";
	std::cout << "Capa : " << ft_my_vector.capacity() << std::endl;
	
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
	std::cout << "Size : " << ft_my_vector.size() << "\t";
	std::cout << "Capa : " << ft_my_vector.capacity() << std::endl;
	typedef typename std::vector<T>::iterator iterator;
	iterator it = ft_my_vector.begin() ;
	iterator itend = ft_my_vector.end();

	for (it = ft_my_vector.begin(); it != itend; it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n" << std::endl;
}

template <typename T>
void	print_vector(std::vector<T> std_vector, ft::vector<T> ft_vector, int i = 0) {
	std::cout << "--------- Print std_vector -- >> ";
	std::cout << "Size : " << std_vector.size() << "\t";
	if (i == 0)
		std::cout << "Capa : " << std_vector.capacity();
	std::cout << std::endl;
	typedef typename std::vector<T>::iterator std_iterator;
	std_iterator std_it = std_vector.begin();
	std_iterator std_itend = std_vector.end();

	for (std_it = std_vector.begin(); std_it != std_itend; std_it++) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl;
	std::cout << "--------- Print ft_vector  -- >> ";
	std::cout << "Size : " << ft_vector.size() << "\t";
	if (i == 0)
		std::cout << "Capa : " << ft_vector.capacity();
	std::cout << std::endl;
	typedef typename ft::vector<T>::iterator ft_iterator;
	ft_iterator ft_it = ft_vector.begin();
	ft_iterator ft_itend = ft_vector.end();

	for (ft_it = ft_vector.begin(); ft_it != ft_itend; ft_it++) {
		std::cout << *ft_it << " ";
	}
	std::cout << std::endl;
	if (!verif(std_vector, ft_vector, i))
		std::cout << _GREEN << "No diff vector" << _NC << std::endl;
	std::cout << std::endl;
}
