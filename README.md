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


### Note Map

- get_key pour recupere le comp pour node dans map.
- faire value_compare
- check template tree pour Alloc

- Passer template arbre binaire en value_type, compare et alloc !

- Probleme const iterator n'est pas trouvé en tant que *const mais en pointeur
- A regler le succeseur et le predecesseur pour ++ et -- sur bidirectionel_iterartor
