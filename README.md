# ft_containers

Code source itérator_traits : https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator_base_types.h.html

Par default un constructeur est dit de conversion, avec le mot clé "explicit" prend le parametre comme il est ! -> Evite les erreurs si on passe de mauvais parametre a notre constructeur !

enable_if -> assign et constructor vector
is_integral -> constructor vector !

strat_size = 7
it[i] = (start_size - i) * 3;
for (int i = 2; i < 7; ++i)
	-> it[2] = 