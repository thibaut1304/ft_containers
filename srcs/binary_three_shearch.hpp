/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_three_shearch.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:12:37 by thhusser          #+#    #+#             */
/*   Updated: 2022/09/11 04:16:13 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BINARY_THREE_SHEARCH_
# define _BINARY_THREE_SHEARCH_

# include <memory>

# include "pair.hpp"

namespace ft {

	template<class T>
	struct 	s_node {
		T			_data;
		s_node<T>	*parent;
		s_node<T>	*left;
		s_node<T>	*right;

		s_node(T data, s_node* parent, s_node* left, s_node* right) : _data(data), parent(parent), left(left), right(right) {}
	};

	template<class Key, class T, class Compare, class Alloc>
	class tree {
		public:
			typedef Key																					key_type;
			typedef T 																					value_type;
			typedef s_node<T>*																			nodePtr;
			typedef s_node<T>																			nodeType;
			typedef typename Alloc::template rebind<s_node<T> >::other 									allocator_type;
			typedef	typename allocator_type::size_type 													size_type;
			typedef Compare																				key_compare;

		private:
			allocator_type		_alloc;
			nodePtr				_root;
			nodePtr				_end;
			size_type			_compteur;
			key_compare 		_comp;

			nodePtr		createNode(const value_type& data, nodePtr &old) {
				nodePtr	tmp = _alloc.allocate(1);
				_alloc.construct(tmp, nodeType(data, old, _end, _end));
				return (tmp);
			}

			void		destroy(nodePtr &ptr) {
				if (ptr == _end) {return;}
				destroy(ptr->left);
				destroy(ptr->right);
				_alloc.destroy(ptr);
				_alloc.deallocate(ptr, 1);
				_compteur--;
			}

			void		insert(const value_type& data, nodePtr &ptr, nodePtr old) {
				if (ptr == _end || !ptr) {
					ptr = createNode(data, old);
					return ;
				}
				else if (data.first == ptr->_data.first) {
					_compteur--;
					return ;
				}
				if (_comp(data.first, ptr->_data.first)) {
					insert(data, ptr->left, ptr);
				}
				else {
					insert(data, ptr->right, ptr);
				}
			}

			void		infixe(nodePtr ptr) const {
				if (ptr == _end || !ptr) {return ;}
				infixe(ptr->left);
				// std::cout << _YELLOW << "ptr  : " << ptr << " - " << ptr->left << " - " << ptr->right << _NC;
				// std::cout << " - KEY : " << ptr->_data.first << " - T : " << ptr->_data.second << "\n";
				// std::cout << _YELLOW << "papa : " << ptr->parent << _NC << std::endl << std::endl;
				infixe(ptr->right);
			}

			nodePtr	successeur(nodePtr ptr) const {
				if (ptr == _end) {return (_end);}

				nodePtr curent = ptr;
				while (curent->left != _end) {
					curent = curent->left;
				}
				return (curent);
			}

			void		toDelete(nodePtr	ptr) {
				nodePtr padre = ptr->parent;

				if (ptr->left == _end && ptr->right == _end) {
					if (ptr != _root) {
						if (padre->left == ptr) {
							padre->left = _end;
						}
						else {
							padre->right = _end;
						}
					}
					else {
						_root = _end;
					}
				}
				else if (ptr->left != _end && ptr->right != _end) {
					nodePtr		succ = successeur(ptr->right);
					if (ptr == _root) {
						if (succ->right != _end && ptr->right != succ) {
							succ->parent->left = succ->right;
							succ->right->parent = succ->parent;
						}
						else if (ptr->right != succ)
							succ->parent->left = _end;

						if (ptr->right != _end && ptr->right != succ)
							ptr->right->parent = succ;
						if (ptr->left != _end)
							ptr->left->parent = succ;

						succ->parent = ptr->parent;
						succ->left = ptr->left;
						if (ptr->right != succ)
							succ->right = ptr->right;
						_root = succ;
					}
					else {
						if (succ->right != _end && ptr->right != succ) {
							succ->parent->left = succ->right;
							succ->right->parent = succ->parent;
						}
						else if (ptr->right != succ)
							succ->parent->left = _end;

						if (ptr->left != _end) {
							ptr->left->parent = succ;
							succ->left = ptr->left;
						}

						succ->parent = ptr->parent;
						if (ptr->parent->right == ptr) {
							ptr->parent->right = succ;
						}
						else if (ptr->parent->left == ptr) {
							ptr->parent->left = succ;
						}
						if (ptr->right != succ) {
							ptr->right->parent = succ;
							succ->right = ptr->right;
						}
					}
				}
				else {
					nodePtr	child = (ptr->left != _end) ? ptr->left : ptr->right;
					if (ptr != _root) {
						if (ptr == padre->left)
							padre->left = child;
						else
							padre->right = child;
						child->parent = padre;
					}
					else {
						_root = child;
						_root->parent = _end;
					}
				}
				_alloc.destroy(ptr);
				_alloc.deallocate(ptr, 1);
				ptr = NULL;
			}

			nodePtr	find(const value_type& data, nodePtr node) {
				if (node == _end || !node)
					return (_end);
				if (data.first == node->_data.first)
					return (node);
				if (_comp(data.first, node->_data.first)) {
					return (find(data, node->left));
				}
				else {
					return (find(data, node->right));
				}
			}

			nodePtr	find_key(const key_type& k, const nodePtr node) const {
				if (node == _end || !node)
					return (_end);
				if (k == node->_data.first)
					return (node);
				if (_comp(k, node->_data.first)) {
					return (find_key(k, node->left));
				}
				else {
					return (find_key(k, node->right));
				}
			}

			void		infixe() {
				infixe(_root);
			}

		public:
			tree(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type()) :  _alloc(alloc), _compteur(0), _comp(comp) {
				_end = _alloc.allocate(1);
				_alloc.construct(_end, nodeType(value_type(), NULL, NULL, NULL));
				_root = _end;
			}

			virtual ~tree() {
				destroy(_root);
				_alloc.destroy(_end);
				_alloc.deallocate(_end, 1);
				_end = NULL;
			}

			nodePtr		getEnd() const {return (_end);}
			nodePtr		getRoot() const {return (_root);}

			nodePtr		getMin(nodePtr node = NULL) const {
				if (!node) {
					if (_root == _end)
						return (_root);
					node = _root;
				}
				while (node->left != _end)
					node = node->left;
				return (node);
			}

			nodePtr		getMax(nodePtr node = NULL) const {
				if (!node) {
					if (_root == _end)
						return (_root);
					node = _root;
				}
				while (node->right != _end)
					node = node->right;
				return (node);
			}

			void	swap(tree& Tree) {
				nodePtr			root = _root;
				nodePtr			end = _end;
				allocator_type	alloc = _alloc;
				key_compare		comp = _comp;
				size_type		compteur = _compteur;

				_root = Tree._root;
				_end = Tree._end;
				_alloc = Tree._alloc;
				_comp = Tree._comp;
				_compteur = Tree._compteur;

				Tree._root = root;
				Tree._end = end;
				Tree._alloc = alloc;
				Tree._comp = comp;
				Tree._compteur = compteur;
			}

			void	clear() {
				infixe(_root);
				destroy(_root);
				_root = _end;
				_compteur = 0;
			}

			nodePtr	find(const value_type& data) {
				return (find(data, _root));
			}

			nodePtr	find_key(const key_type &k) const {
				return (find_key(k, _root));
			}


			void	insert(const value_type& data) {
				_compteur++;
				insert(data, _root, _root);
			}

			void		erase(const value_type& data) {
				nodePtr	del = find(data, _root);

				if (del == _end)
					return ;
				else {
					toDelete(del);
					_compteur--;
				}
				return ;
			}

			size_type		size() const {return (_compteur);}
			bool			empty() const {return (_compteur == 0);}
			size_type		max_size() const { return (allocator_type().max_size());}
			allocator_type	get_allocator() const {return (_alloc);}
	};
}
#endif
