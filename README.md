# ft_containers

Code source itérator_traits : https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator_base_types.h.html

edit: leaks regle sur insert ! double allocate de tmp !

pb de capacite sur erase std::vector decrement et resize idem

correction assign ne pas realloc si pas besoin ok

## Testeur Vector
- [x] Constructeur
- [x] Rbegin and rend
- [x] Push_back
- [x] Insert
- [x] erase
- [x] resize
- [x] reserve -- je l'utilise partout donc oui forcement
- [ ] assign
- [x] pop_back
- [x] swap
- [x] clear
