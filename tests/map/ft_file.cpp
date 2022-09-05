#include "utils.hpp"

std::string	date_now() {
	time_t now = time(NULL);
	struct tm * tm = localtime(&now);
	char date[18];
	strftime(date, sizeof date, "%d-%m-%y_%H-%M-%S", tm);
	return (date);
}


std::ofstream	create_file() {
	std::string date = "tests/map/ressource_testing/" + date_now() + ".tkt";
	const char *c = date.c_str();
	std::ofstream file(c);
	if (!file)
		std::cout << "erreur" << std::endl;
	return (file);
}

template <typename List, typename ft_map, typename std_map>
void	write_in_file(List &lst, ft_map &ft_mp, std_map &std_mp) {
	std::string type1 = recup_type1();
	std::string type2 = recup_type2();
	std::ofstream o = create_file();
	o << "// Remplace '.' with ft or std !\n#define   .   NAMESPACE\n\n";
	o << "// Remplace '.' with your string with \" \"\n#define WORD   .\n\n";
	o << "NAMESPACE::map<int, std::string> mp;\n\n" << "\n";

	std::list<L1>::iterator l_it = lst.begin(), l_ite = lst.end();
	for (; l_it != l_ite; l_it++) {
		o << "mp.insert(NAMESPACE::pair<const " << type1 << ", " << type2 << ">(" << *l_it << ", WORD));" << "\n";
	}
	o << "\n\n\n";
	o << "Your results : \n\n";
	print(ft_mp, std_mp, o);
	ft_compare(ft_mp, std_mp, o);
	o.close();
}

