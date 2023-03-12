/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:18:25 by jpauline          #+#    #+#             */
/*   Updated: 2023/03/11 20:18:59 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ITERATOR_HPP
#define SET_ITERATOR_HPP

// #include <iostream>

// #include <iterator>

# include "iterator_traits.hpp"
# include "set_utils.hpp"

namespace ft
{

    template < class T >
	class const_set_iterator;

    template < class T >
	class set_iterator 
    {
		public:

			typedef typename std::bidirectional_iterator_tag		    iterator_category;
			typedef T   					                            value_type;
			typedef T*						                            pointer;
			typedef T&						                            reference;
			typedef s_set_node<T>*					                    node;
			typedef typename iterator_traits<node>::difference_type	    difference_type;

		private:

			node _node;

		public:

			set_iterator(void) : _node(NULL) {}
			set_iterator(const set_iterator & src) : _node(src.base()) {}
			set_iterator(node n) : _node(n) {}
			~set_iterator(void) {}

			node base(void) const 
            {
				return this->_node;
			}

			set_iterator &operator= (const set_iterator & rhs)
			{
				if (*this != rhs)
					this->_node = rhs.base();
				return *this;
			}

			set_iterator &operator++ (void)
			{
				this->_node = this->_node->tree_successor();
				return *this;
			}

			set_iterator &operator-- (void)
			{
				this->_node = this->_node->tree_predecessor();
				return *this;
			}

			set_iterator operator++ (int)
			{
				set_iterator tmp = *this;
				this->_node = this->_node->tree_successor();
				return tmp;
			}

			set_iterator operator-- (int)
			{
				set_iterator tmp = *this;
				this->_node = this->_node->tree_predecessor();
				return tmp;
			}

			bool operator== (const set_iterator & rhs) const { return (this->_node == rhs._node); }
			bool operator!= (const set_iterator & rhs) const { return this->_node != rhs._node; }

			template < class U >
			bool operator== (const const_set_iterator<U> & rhs) const
			{ return (this->_node == rhs.base()); }

			template < class U >
			bool operator!= (const const_set_iterator<U> &rhs) const
			{ return this->_node != rhs.base(); }

			reference operator* (void) const { return this->_node->val; }
			pointer operator-> (void) const { return &this->_node->val; }
	};

	template < class T >
	class const_set_iterator
    {

		public:

			typedef typename std::bidirectional_iterator_tag		    iterator_category;
			typedef T						                           value_type;
			typedef const T*					                        pointer;
			typedef const T&					                        reference;
			typedef s_set_node<T>*					                    node;
			typedef typename iterator_traits<node>::difference_type	    difference_type;

		private:

			node _node;

		public:

			const_set_iterator(void) : _node(NULL) {}
			template <class U>
			const_set_iterator(const set_iterator<U> & src) : _node(src.base()) {}
			const_set_iterator(node n) : _node(n) {}
			~const_set_iterator(void) {}

			node base(void) const
            { return this->_node; }

			template <class U>
			const_set_iterator &operator= (const set_iterator<U> & rhs)
			{
				if (*this != rhs)
					this->_node = rhs.base();
				return *this;
			}

			const_set_iterator &operator++ (void)
			{
				this->_node = this->_node->tree_successor();
				return *this;
			}

			const_set_iterator &operator-- (void)
			{
				this->_node = this->_node->tree_predecessor();
				return *this;
			}

			const_set_iterator operator++ (int)
			{
				const_set_iterator tmp = *this;
				this->_node = this->_node->tree_successor();
				return tmp;
			}

			const_set_iterator operator-- (int)
			{
				const_set_iterator tmp = *this;
				this->_node = this->_node->tree_predecessor();
				return tmp;
			}

			bool operator== (const const_set_iterator & rhs) const { return (this->_node == rhs._node); }
			bool operator!= (const const_set_iterator &rhs) const { return this->_node != rhs._node; }

			template < class U >
			bool operator== (const set_iterator<U> & rhs) const { return (this->_node == rhs.base()); }

			template < class U >
			bool operator!= (const set_iterator<U> &rhs) const { return this->_node != rhs.base(); }

			reference operator* (void) const { return this->_node->val; }
			pointer operator-> (void) const { return &this->_node->val; }
	};

}

#endif
