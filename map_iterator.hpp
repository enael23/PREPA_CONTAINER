/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:11:06 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/26 18:11:37 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include <iostream>

# include "iterator_traits.hpp"
# include "map_utils.hpp"

namespace ft
{

	template < class T >
	class const_map_iterator;

	template < class T >
	class map_iterator {

		public:

			typedef typename std::bidirectional_iterator_tag		iterator_category;
			typedef T						value_type;
			typedef T*						pointer;
			typedef T&						reference;
			typedef s_map_node<T>*					node;
			typedef typename iterator_traits<node>::difference_type	difference_type;

		private:

			node _node;

		public:

			map_iterator(void) : _node(NULL) {}
			map_iterator(const map_iterator & src) : _node(src.base()) {}
			map_iterator(node n) : _node(n) {}
			~map_iterator(void) {}

			node base(void) const 
            {
				return this->_node;
			}

			map_iterator &operator= (const map_iterator & rhs)
			{
				if (*this != rhs)
					this->_node = rhs.base();
				return *this;
			}

			map_iterator &operator++ (void)
			{
// std::cout << "TOTO++ void\n";
				this->_node = this->_node->tree_successor();
				return *this;
			}

			map_iterator &operator-- (void)
			{
// std::cout << "TOTO-- void\n";
				this->_node = this->_node->tree_predecessor();
				return *this;
			}

			// map_iterator &operator-- (void)
			// {
			// 	if (this->_node->is_end)
			// 		this->_node = this->_node->right;
			// 	else
			// 		this->_node = this->_node->tree_predecessor();
			// 	return *this;
			// }

			map_iterator operator++ (int)
			{
// std::cout << "TOTO++ int\n";
				map_iterator tmp = *this;
				this->_node = this->_node->tree_successor();
				return tmp;
			}

			map_iterator operator-- (int)
			{
// std::cout << "TOTO-- int\n";
				map_iterator tmp = *this;
				this->_node = this->_node->tree_predecessor();
				return tmp;
			}

			// map_iterator operator-- (int)
			// {
			// 	map_iterator tmp = *this;
			// 	if (this->_node->is_end)
			// 		this->_node = this->_node->right;
			// 	else
			// 		this->_node = this->_node->tree_predecessor();
			// 	return tmp;
			// }

			bool operator== (const map_iterator & rhs) const
			{
				return (this->_node == rhs._node);
			}

			bool operator!= (const map_iterator &rhs) const
			{
				return this->_node != rhs._node;
			}

			template < class U >
			bool operator== (const const_map_iterator<U> & rhs) const
			{
				return (this->_node == rhs.base());
			}

			template < class U >
			bool operator!= (const const_map_iterator<U> &rhs) const
			{
				return this->_node != rhs.base();
			}

			reference operator* (void) const
			{
				return this->_node->val;
			}

			pointer operator-> (void) const
			{
				return &this->_node->val;
			}
	};

	template < class T >
	class const_map_iterator {

		public:

			typedef typename std::bidirectional_iterator_tag		iterator_category;
			typedef T						value_type;
			typedef const T*					pointer;
			typedef const T&					reference;
			typedef s_map_node<T>*					node;
			typedef typename iterator_traits<node>::difference_type	difference_type;

		private:

			node _node;

		public:

			const_map_iterator(void) : _node(NULL) {}
			template <class U>
			const_map_iterator(const map_iterator<U> & src) : _node(src.base()) {}
			const_map_iterator(node n) : _node(n) {}
			~const_map_iterator(void) {}

			node base(void) const {
				return this->_node;
			}

			template <class U>
			const_map_iterator &operator= (const map_iterator<U> & rhs)
			{
				if (*this != rhs)
					this->_node = rhs.base();
				return *this;
			}

			const_map_iterator &operator++ (void)
			{
				this->_node = this->_node->tree_successor();
				return *this;
			}

			const_map_iterator &operator-- (void)
			{
				if (this->_node->is_end)
					this->_node = this->_node->right;
				else
					this->_node = this->_node->tree_predecessor();
				return *this;
			}

			const_map_iterator operator++ (int)
			{
				const_map_iterator tmp = *this;
				this->_node = this->_node->tree_successor();
				return tmp;
			}

			const_map_iterator operator-- (int)
			{
				const_map_iterator tmp = *this;
				if (this->_node->is_end)
					this->_node = this->_node->right;
				else
					this->_node = this->_node->tree_predecessor();
				return tmp;
			}

			bool operator== (const const_map_iterator & rhs) const
			{
				return (this->_node == rhs._node);
			}

			bool operator!= (const const_map_iterator &rhs) const
			{
				return this->_node != rhs._node;
			}

			template < class U >
			bool operator== (const map_iterator<U> & rhs) const
			{
				return (this->_node == rhs.base());
			}

			template < class U >
			bool operator!= (const map_iterator<U> &rhs) const
			{
				return this->_node != rhs.base();
			}

			reference operator* (void) const
			{
				return this->_node->val;
			}

			pointer operator-> (void) const
			{
				return &this->_node->val;
			}
	};

}


#endif
