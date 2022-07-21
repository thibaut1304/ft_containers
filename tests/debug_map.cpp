#define HEY std

void	constructor_map() {
	HEY::map<int, int>ft_map;

	ft_map[1] = 10;
	ft_map[2] = 20;
	ft_map[3] = 30;

	print_the_map(ft_map);
}