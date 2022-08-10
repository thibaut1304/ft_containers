#ifndef _BINARY_THREE_SHEARCH_
# define _BINARY_THREE_SHEARCH_

# define FEUILLE NULL
# include <iostream>
# include <memory>

# include "pair.hpp"

// creer ici pair clé / valeur ?
// ou juste les recup independament ?

namespace ft {
	template<class KEY, class T>
	class node {
		public:
			typedef T 											value_type;
		private:
			pair<KEY, T>	_pair;
			class node		_left;
			class node		_right;
	};
}
#endif
