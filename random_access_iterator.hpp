/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:28:16 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/03 18:03:16 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

	template<typename T>
	class random_access_iterator
	{
		public :

			typedef typename ft::random_access_iterator_tag	iterator_category;
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef size_t									size_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef const T*								const_pointer;
			typedef const T&								const_reference;

		private :

			pointer	_ptr;

		public :
		
			/*COPLIEN*/

			random_access_iterator(void) : _ptr(NULL) {}
			random_access_iterator(pointer _ptr) : _ptr(_ptr) {}
			random_access_iterator(const random_access_iterator<T> & src) : _ptr(src.base()) {}
			~random_access_iterator(void) {}

			random_access_iterator & operator=(random_access_iterator<T> const & rhs)
			{
				this->_ptr = rhs.base();
				return *this;
			}
			
		/* Necessaire pour creer un const iterator a partir d'un iterator, sinon ca ne compile pas */
			operator random_access_iterator<T const>() const
			{ return random_access_iterator<T const>(this->_ptr); } 
		

			//Le getteur s'appelle 'base' pour les iterators
			pointer base() const
			{ return this->_ptr; }


		/*Liste des surcharges a assurer : https://cplusplus.com/reference/iterator/RandomAccessIterator/ */

			bool operator==(const random_access_iterator & src) const
			{ return (this->_ptr == src.base()); }

			bool operator!=(const random_access_iterator & src) const
			{ return !(operator==(src)); }

			bool operator>(const random_access_iterator & src) const
			{ return (this->_ptr > src.base()); }
			
			bool operator>=(const random_access_iterator & src) const
			{ return (this->_ptr >= src.base()); }
			
			bool operator<(const random_access_iterator & src) const
			{ return (this->_ptr < src.base()); }
			
			bool operator<=(const random_access_iterator & src) const
			{ return (this->_ptr <= src.base()); }

			pointer operator->(void) 
			{ return (this->_ptr); }

			reference operator*(void)
			{ return (*this->_ptr); }
			
			random_access_iterator & operator++(void) 
			{
				this->_ptr++;
				return *this;
			}

			random_access_iterator operator++(int)
			{
				random_access_iterator tmp = *this;
				++this->_ptr;
				return tmp;
			}

			random_access_iterator & operator--(void)
			{
				--this->_ptr;
				return *this;
			}

			random_access_iterator operator--(int)
			{
				random_access_iterator tmp = *this;
				--this->_ptr;
				return tmp;
			}

			random_access_iterator operator+(difference_type n) const
			{ return (this->_ptr + n); }

			difference_type operator+(const random_access_iterator & rhs) const
			{ return (this->_ptr + rhs.base()); }

			random_access_iterator operator-(difference_type n) const
			{ return (this->_ptr - n); }

			difference_type operator-(const random_access_iterator & rhs) const
			{ return (this->_ptr - rhs.base()); }

			random_access_iterator & operator+=(difference_type n)
			{
				this->_ptr += n;
				return *this;
			}

			random_access_iterator & operator-=(difference_type n)
			{
				this->_ptr -= n;
				return *this;
			}
	
			reference operator[](difference_type n) const
			{ return *(*this + n); }
			
	};


		template<class T>
		random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &rhs)
		{ return rhs + n; }

		template< typename Iter1, typename Iter2 >
		typename ft::random_access_iterator<Iter1>::difference_type operator-(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2> &rhs)
		{ return (lhs.base() - rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator==(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2> &rhs)
		{ return (lhs.base() == rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator!=(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2> &rhs)
		{ return (lhs.base() != rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator<(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2> &rhs)
		{ return (lhs.base() < rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator>(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2> &rhs)
		{ return (lhs.base() > rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator>=(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2> &rhs)
		{ return (lhs.base() >= rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator<=(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2> &rhs)
		{ return (lhs.base() <= rhs.base()); }

}

#endif
