/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:35:43 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/03 18:07:23 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>

#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{

	template< class T, class Alloc = std::allocator<T> >
	class vector
	{

		/*
		MEMBER TYPES
		~~~~~~~~~~~~
		value_type					v
		allocator_type				v
		reference					v
		const_reference				v
		pointer						v	
		const_pointer				v	
		iterator					v
		const_iterator				v
		reverse_iterator			v
		const_reverse_iterator		v
		difference_type				v
		size_type					v
		*/

		public :

			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename ft::random_access_iterator<value_type>			iterator;
			typedef typename ft::random_access_iterator<const value_type>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t													size_type;

		private :

			allocator_type	_allocator;
			size_type		_size;
			size_type		_capacity;
			pointer			_array;

		public :

			/*
			MEMBER FUNCTIONS
			~~~~~~~~~~~~~~~~
			(constructor)
			(destructor)
			operator= (assign content)
			*/

			explicit vector(const allocator_type & alloc = allocator_type()) : _allocator(alloc), _size(0), _capacity(0), _array(NULL)
			{
				std::cout << "VECTOR CONSTRUCTED (DEFAULT)" << std::endl;
			}

			virtual ~vector() 
			{
				
				for (size_t i = 0;  i < _size; i++)
						this->_allocator.destroy(this->_array + i);
				_allocator.deallocate(_array,_size);
				std::cout << "VECTOR DESTRUCTED" << std::endl;
			};


			/*
			Iterators:
			~~~~~~~~~~
			begin
			end
			rbegin
			rend
			cbegin (c++11)
			cendy (c++11)
			crbegin (c++11)
			crend (c++11)
			*/

			/*
			Capacity:
			~~~~~~~~~
			size
			max_size
			resize
			capactity
			empty
			reserve
			shrink_to_fit (c++11)
			*/

			void	reserve(size_type new_capacity)
			{
				if (new_capacity > _allocator.max_size())
					throw std::length_error("vector::reserve");
				if (new_capacity <= _capacity)	
					return ;
				pointer new_array = _allocator.allocate(new_capacity);
				for (size_type i = 0; i < new_capacity; i++)
				{
					if (i < _size)
					{
						_allocator.construct(new_array + i, *(_array + i));
						_allocator.destroy(_array + i);  
					}
				}
				if (_capacity != 0)
					_allocator.deallocate(_array, _capacity);
				_capacity = new_capacity;
				_array = new_array;
			}

			/*
			Element access:
			~~~~~~~~~~~~~~~
			operator[]
			at
			front
			back
			data
			*/

			T &operator[](size_type index)
			{
				return *(_array + index);
			}

			const_reference operator[](size_type index) const
			{
				return *(_array + index);
			}

			/*
			Modifiers:
			~~~~~~~~~~
			assign
			push_back
			pop_back
			insert
			erase
			swap
			clear
			emplace (c++11)
			emplace_back (c++11)
			*/

			size_t	linux_capacity_caclulator(size_t n)
			{
				if (n <= _size * 2)
					return (_size * 2);
				return (n);
			}

			void push_back(const T& val)
			{
				if (_capacity == 0)
					this->reserve(1);
				else if (_capacity <= _size)
					this->reserve(linux_capacity_caclulator(_size + 1));
				this->_allocator.construct(this->_array + this->_size, val);
				_size++;
			}

			/*
			Allocator:
			~~~~~~~~~~
			get_allocator
			*/



	};




/*
Non-member function overloads:
relational operators
swap
*/
	
}





#endif
