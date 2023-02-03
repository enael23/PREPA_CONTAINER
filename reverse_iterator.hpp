/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:28:16 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/03 15:56:34 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{

	template<typename Iter>
	class reverse_iterator
	{
		private :

			Iter	_current;

		public :

			typedef Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;
		


		/*COPLIEN*/

			reverse_currenterator(void) : _current(NULL) {}
			explicit reverse_iterator(Iter input_iter) : _current(input_iter) {}

			template<class T>
			reverse_iterator(const reverse_iterator<T> & src) : _current(src.base()) {}

			~reverse_iterator(void) {}

			template<class T>
			reverse_iterator & operator=(const reverse_iterator<T> & rhs)
			{
				this->_current = rhs.base();
				return *this;
			}

			//Le getteur s'appelle 'base' pour les iterators
			Iter base() const { return (this->_current); }

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
				Iter tmp = this->_current;
				return (*--tmp);
			}

/* -> */	pointer operator->() const
			{
				Iter tmp = this->_current;
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

/* + */		reverse_iterator operator+(difference_type n)
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

/* - */		reverse_iterator operator-(difference_type n)
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
