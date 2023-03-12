/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:28:16 by jpauline          #+#    #+#             */
/*   Updated: 2023/03/12 20:53:11 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

	template<typename T>
	class vector_iterator
	{
		public :

			typedef typename std::random_access_iterator_tag	iterator_category;
			typedef std::ptrdiff_t								difference_type;
			typedef T											value_type;
			typedef size_t										size_type;
			typedef T*											pointer;
			typedef T&											reference;
			typedef const T*									const_pointer;
			typedef const T&									const_reference;

		private :

			pointer	_ptr;

		public :
		
			/*COPLIEN*/

			vector_iterator(void) : _ptr(NULL) {}
			vector_iterator(pointer _ptr) : _ptr(_ptr) {}
			vector_iterator(const vector_iterator<T> & src) : _ptr(src.base()) {}
			~vector_iterator(void) {}

			vector_iterator & operator=(vector_iterator<T> const & rhs)
			{
				this->_ptr = rhs.base();
				return *this;
			}
			
		/* Necessaire pour creer un const iterator a partir d'un iterator, sinon ca ne compile pas */
			operator vector_iterator<T const>() const
			{ return vector_iterator<T const>(this->_ptr); } 
		

			//Le getteur s'appelle 'base' pour les iterators
			pointer base() const
			{ return this->_ptr; }


		/*Liste des surcharges a assurer : https://cplusplus.com/reference/iterator/RandomAccessIterator/ */

			bool operator==(const vector_iterator & src) const
			{ return (this->_ptr == src.base()); }

			bool operator!=(const vector_iterator & src) const
			{ return !(operator==(src)); }

			bool operator>(const vector_iterator & src) const
			{ return (this->_ptr > src.base()); }
			
			bool operator>=(const vector_iterator & src) const
			{ return (this->_ptr >= src.base()); }
			
			bool operator<(const vector_iterator & src) const
			{ return (this->_ptr < src.base()); }
			
			bool operator<=(const vector_iterator & src) const
			{ return (this->_ptr <= src.base()); }

			pointer operator->(void) 
			{ return (this->_ptr); }

			reference operator*(void)
			{ return (*this->_ptr); }
			
			vector_iterator & operator++(void) 
			{
				this->_ptr++;
				return *this;
			}

			vector_iterator operator++(int)
			{
				vector_iterator tmp = *this;
				++this->_ptr;
				return tmp;
			}

			vector_iterator & operator--(void)
			{
				--this->_ptr;
				return *this;
			}

			vector_iterator operator--(int)
			{
				vector_iterator tmp = *this;
				--this->_ptr;
				return tmp;
			}

			vector_iterator operator+(difference_type n) const
			{ return (this->_ptr + n); }

			difference_type operator+(const vector_iterator & rhs) const
			{ return (this->_ptr + rhs.base()); }

			vector_iterator operator-(difference_type n) const
			{ return (this->_ptr - n); }

			difference_type operator-(const vector_iterator & rhs) const
			{ return (this->_ptr - rhs.base()); }

			vector_iterator & operator+=(difference_type n)
			{
				this->_ptr += n;
				return *this;
			}

			vector_iterator & operator-=(difference_type n)
			{
				this->_ptr -= n;
				return *this;
			}
	
			reference operator[](difference_type n) const
			{ return *(*this + n); }
			
	};


		template<class T>
		vector_iterator<T> operator+(typename vector_iterator<T>::difference_type n, const vector_iterator<T> &rhs)
		{ return rhs + n; }

		template< typename Iter1, typename Iter2 >
		typename ft::vector_iterator<Iter1>::difference_type operator-(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
		{ return (lhs.base() - rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator==(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
		{ return (lhs.base() == rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator!=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
		{ return (lhs.base() != rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator<(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
		{ return (lhs.base() < rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator>(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
		{ return (lhs.base() > rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator>=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
		{ return (lhs.base() >= rhs.base()); }

		template< typename Iter1, typename Iter2 >
		bool operator<=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
		{ return (lhs.base() <= rhs.base()); }

}

#endif
