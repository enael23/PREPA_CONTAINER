/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:28:16 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/03 18:04:01 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

	template<typename Iterator>
	class reverse_iterator
	{
		private :

			Iterator	_current;

		public :

			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
		


		/*COPLIEN*/

			reverse_iterator() : _current(NULL) {}
			explicit reverse_iterator(iterator_type it) : _current(it) {}

			template<class Iter>
			reverse_iterator(const reverse_iterator<Iter> & src) : _current(src.base()) {}

			~reverse_iterator(void) {}

			template<class Iter>
			reverse_iterator & operator=(const reverse_iterator<Iter> & rhs)
			{
				this->_current = rhs.base();
				return *this;
			}

			//Le getteur s'appelle 'base' pour les iterators
			iterator_type base() const { return (this->_current); }

			/* liste des operateurs https://en.cppreference.com/w/cpp/iterator/reverse_iterator */

			// Operators by member functions
			// *
			// ->
			// []
			// ++
			// ++(int)
			// +=
			// +
			// --
			// --(int)
			// -=
			// -

/* *  */	reference operator*() const
			{
				iterator_type tmp = this->_current;
				return (*--tmp);
			}

/* -> */	pointer operator->() const
			{
				iterator_type tmp = this->_current;
				return (&(*--tmp));
			}

/* [] */	reference operator[](difference_type n)
			{
				return (*(*this + n));
			}

/* ++ */	reverse_iterator & operator++()
			{
				--(this->_current);
				return (*this);
			}

/* ++int*/	reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--(this->_current);
				return (tmp);
			}

/* += */	reverse_iterator operator+=(difference_type n)
			{
				this->_current -= n;
				return (*this);
			}

/* + */		reverse_iterator operator+(difference_type n) const
			{
				return (reverse_iterator(this->_current - n));
			}

/* -- */	reverse_iterator & operator--()
			{
				++(this->_current);
				return (*this);
			}

/* --int*/	reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++(this->_current);
				return (tmp);
			}

/* -= */	reverse_iterator operator-=(difference_type n)
			{
				this->_current += n;
				return (*this);
			}

/* - */		reverse_iterator operator-(difference_type n) const
			{
				return (reverse_iterator(this->_current + n));
			}

	};

	// Operators by non-member functions
	// ==
	// !=
	// <
	// <=
	// >
	// >=
	// +
	// -

	template< class Iter1, class Iter2 >
	bool operator==(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs)
	{ return (lhs.base() == rhs.base()); }

	template< class Iter1, class Iter2 >
	bool operator!=(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs)
	{ return (lhs.base() != rhs.base()); }

	template< class Iter1, class Iter2 >
	bool operator<(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs)
	{ return (lhs.base() > rhs.base()); }

	template< class Iter1, class Iter2 >
	bool operator<=(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs)
	{ return (lhs.base() >= rhs.base()); }

	template< class Iter1, class Iter2 >
	bool operator>(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs)
	{ return (lhs.base() < rhs.base()); }

	template< class Iter1, class Iter2 >
	bool operator>=(const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs)
	{ return (lhs.base() <= rhs.base()); }

	template<class Iter>
	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> & rhs)
	{ return (rhs + n); }

	template<class Iter>
	reverse_iterator<Iter> operator-( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> & rhs)
	{ return (rhs - n); }

	template<class Iter1, class Iter2>
	typename ft::reverse_iterator<Iter1>::difference_type operator-( const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs)
	{ return (rhs.base() - lhs.base()); }

}

#endif
