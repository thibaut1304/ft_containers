void	ft_insert() {
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	for (int i = 0; i < 10 ; i++) {
		if (i == 5) {
			std_vector.push_back(99);
			ft_vector.push_back(99);
		}
		else {
			std_vector.push_back(i);
			ft_vector.push_back(i);
		}
	}

	std::vector<int>::iterator it = std_vector.begin();
	ft::vector<int>::iterator ft_it = ft_vector.begin();

	for (; ft_it < ft_vector.end(); ft_it++) {
		if (*ft_it == 99)
			break;
	}

	for (; it < std_vector.end(); it++) {
		if (*it == 99)
			break;
	}
	print_vector(std_vector, ft_vector);
	ft_vector.insert(ft_it, 5, 0);
	std_vector.insert(it, 5, 0);
	print_vector(std_vector, ft_vector);

}

void	ft_insert_mli() {
	ft::vector<int> ft_(10);
	std::vector<int> std_(10);

	for (unsigned long int i = 0; i < ft_.size(); i++)
		ft_[i] = (ft_.size() - i) * 3;
	for (unsigned long int i = 0; i < std_.size(); i++)
		std_[i] = (std_.size() - i) * 3;

	// print_vector(std_, ft_);

	ft::vector<int> ft_vector;
	std::vector<int> std_vector;

	// for (int i = 0; i < 5; i++) {
		// ft_vector.pop_back();
		// std_vector.pop_back();

	// }
	std_vector.insert(std_vector.end(), 42);
	ft_vector.insert(ft_vector.end(), 42);
	std_vector.insert(std_vector.begin(), 2, 21);
	ft_vector.insert(ft_vector.begin(), 2, 21);
	ft_vector.insert(ft_vector.begin(), ft_vector.begin(), ft_vector.end());
	std_vector.insert(std_vector.begin(), std_vector.begin(), std_vector.end());
	ft_vector.insert(ft_vector.begin(), 2, 21);
	std_vector.insert(std_vector.begin(), 2, 21);
	print_vector(std_vector, ft_vector);

	ft_vector.insert(ft_vector.end() - 2, 42);
	std_vector.insert(std_vector.end() - 2, 42);
	print_vector(std_vector, ft_vector);

	ft_vector.insert(ft_vector.end(), 2, 84);
	std_vector.insert(std_vector.end(), 2, 84);
	print_vector(std_vector, ft_vector);

	// ft_vector.resize(4);
	// std_vector.resize(4);
	// print_vector(std_vector, ft_vector);

	ft_vector.insert(ft_vector.begin() + 2, ft_vector.begin(), ft_vector.end());
	std_vector.insert(std_vector.begin() + 2, std_vector.begin(), std_vector.end());
	print_vector(std_vector, ft_vector);
	// ft_vector.clear();
	// std_vector.clear();
	// print_vector(std_vector, ft_vector);
}

#define DIFF 4

void	test_capa_insert(void) {
	std::vector<int> std_vector(1);
	ft::vector<int> ft_vector(1);

	for (int i = 0; i < DIFF; i++) {
		std_vector.push_back(i);
		ft_vector.push_back(i);
	}

	// std_vector.insert(std_vector.begin(), 1, 0);
	// ft_vector.insert(ft_vector.begin(), 1, 0);
	print_vector(std_vector, ft_vector);
}