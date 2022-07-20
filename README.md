# ft_containers

Code source itérator_traits : https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator_base_types.h.html

edit: leaks regle sur insert ! double allocate de tmp !

Insert n'a pas le comportement atendu avec ite + val + val ! Mon test ne passe pas mais MLi oui

Mauvais calcul de capacité sur vector !