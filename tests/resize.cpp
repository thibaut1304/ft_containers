void 	ft_resize() {
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	std_vector.resize(5);
	ft_vector.resize(5);
	print_vector(std_vector, ft_vector);

	std_vector.resize(3);
	ft_vector.resize(3);
	print_vector(std_vector, ft_vector, 1);

	std_vector.resize(11, 2);
	ft_vector.resize(11, 2);
	print_vector(std_vector, ft_vector);

	std_vector.resize(34, 9);
	ft_vector.resize(34, 9);
	print_vector(std_vector, ft_vector);
}