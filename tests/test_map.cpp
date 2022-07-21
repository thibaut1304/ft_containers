#define _NC "\033[0;0m"
#define _RED "\033[0;31m"
#define _GREEN "\033[0;32m"

// template <typename T, typename TT>
// void	print_ascii(std::map<T, TT>std_map) {
// 	typename std::map<T, TT>::iterator std_it = std_map.begin();
// 	std::cout << "Print valeur en ascii" << std::endl;
// 	unsigned long ret = 0;
// 	for (; std_it != std_map.end(); std_it++) {
// 		ret = 0;
// 		for (unsigned long i = 0; i < std_it->first.size(); i++) {
// 			ret += std_it->first[i]; 
// 		}
// 		std::cout << ret << std::endl;
// 	}
// }

template <typename T, typename TT>
void	print_the_map(std::map<T, TT>std_map) {
	typename std::map<T, TT>::iterator it = std_map.begin();
	for (; it != std_map.end(); it++) {
		std::cout << _BLUE << it->first << " => " << it->second << _NC << std::endl;
	}
	std::cout << "SIZE : " << std_map.size() << std::endl;
}

void	test_string_map() {
	std::map<std::string, int> std_map;
	std::vector<std::string> std_vector = { "zzz",
											"je", 
											"suis", 
											"un",
											"test",
											"aaa",
											"aza",
											"az"};

	typename std::vector<std::string>::iterator std_vector_it = std_vector.begin();
	print_the_vector(std_vector);
	int i = 100;
	for (; std_vector_it != std_vector.end(); i++, std_vector_it++) {
		std_map.insert(std::pair<std::string, int>(*std_vector_it, i));
	}
	
	print_the_map(std_map);
	// print_ascii(std_map);
}

void	test_int_map() {
	std::map<int, int> std_map;
	std::vector<int> std_vector;

	for (int i = 1; i < 200; i++) {
		std_vector.push_back(i);
	}
	
	typename std::vector<int>::iterator std_vector_it = std_vector.begin();
	
	for (int i = 1; i < 27; i++, std_vector_it++)
		std_map.insert(std::pair<int, int>(i, *std_vector_it));
	
	std_map.insert(std::pair<int, int>(50, 505));
	std_map.insert(std::pair<int, int>(0, 505));
	print_the_map(std_map);
}

void	test_pair() {
	std::pair <std::string, int> p1;
	std::pair <std::string, int> p2("shoes", 100);
	std::pair <std::string, int> p3(p2);

	p1 = std::make_pair(std::string("t-shirt"), 10);

	p2.first = "pant";
	p2.second = 30;

	std::cout << "Product 1 : " << p1.first << "\t" << "Cost : " << p1.second << std::endl;
	std::cout << "Product 2 : " << p2.first << "\t" << "Cost : " << p2.second << std::endl;
	std::cout << "Product 3 : " << p3.first << "\t" << "Cost : " << p3.second << std::endl;
}

void	test_my_pair() {
	std::cout << std::endl << "My pair :" << std::endl;
	ft::pair <std::string, int> p1("Laptop", 42);
	ft::pair <std::string, int> p2(p1);

	std::cout << "Product 1 : " << p1.first << "\t" << "Cost : " << p1.second << std::endl;
	std::cout << "Product 2 : " << p2.first << "\t" << "Cost : " << p2.second << std::endl;
}

void	test_map() {
	std::map<char, int> std_map;
	std::vector<int> std_vector;
	char letter = 'a';

	for (int i = 1; i < 200; i++) {
		std_vector.push_back(i);
	}
	
	typename std::vector<int>::iterator std_vector_it = std_vector.begin();
	
	for (; letter <= 'z'; letter++, std_vector_it++)
		std_map.insert(std::pair<char, int>(letter, *std_vector_it));

	std_map.insert(std::pair<char, int>('-', 30));
	std_map.insert(std::pair<char, int>('|', 42));
	print_the_map(std_map);
	// test_int_map();
	// test_string_map();
	test_pair();
	test_my_pair();
}