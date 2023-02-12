/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:35:43 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/09 21:36:26 by jpauline         ###   ########.fr       */
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
			begin			v	const	v
			end				v	const	v
			rbegin			v	const	v
			rend			v	const	v
			cbegin			x (c++11)
			cendy			x (c++11)
			crbegin			x (c++11)
			crend			x (c++11)
			*/

			iterator				begin()				{ return (iterator(this->_array)); }
			const_iterator			begin() const		{ return (const_iterator(this->_array)); }
			iterator				end()				{ return (iterator(this->_array + this->_size)); }
			const_iterator			end() const			{ return (const_iterator(this->_array + this->_size)); }
			reverse_iterator		rbegin()			{ return (reverse_iterator(this->end())); }
			const_reverse_iterator	rbegin() const		{ return (const_reverse_iterator(this->end())); }
			reverse_iterator		rend()				{ return (reverse_iterator(this->begin())); }
			const_reverse_iterator	rend() const		{ return (const_reverse_iterator(this->begin())); }

			/*
			Capacity:
			~~~~~~~~~
			size			v
			max_size		v
			resize			v
			capactity		v
			empty			v
			reserve			v
			shrink_to_fit	x (c++11)
			*/

			size_type size() const
			{ return this->_size; }
			
			size_type max_size() const
			{ return this->_allocator.max_size(); }

			void resize(size_type n, value_type val = value_type())
			{
				if (n > _allocator.max_size())
					throw std::length_error("vector::resize");
				if (n == _size)
					return;
				if (n < _size)
				{
					for (size_type i = n; i < _size; i++)
						_allocator.destroy(_array + i);
				}
				else if (n > _size)
				{
					if (n > _capacity)
						reserve(capacity_reserve_caclulator(n));
					for (size_type i = _size; i < n; i++)
						_allocator.construct(_array + i, val);
				}
				_size = n;
			}

			size_type capacity() const
			{ return this->_capacity; }

			bool empty() const
			{
				if (_size == 0)
					return (true);
				return (false);
			}

			void reserve(size_type new_capacity)
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
			operator[]		v	const	v
			at				v	const	v
			front			v	const	v
			back			v	const	v
			data			v	const	v
			*/

			reference operator[] (size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("vector::[] -> index out of range !");
				return (*(_array + n));
			}
			
			const_reference operator[] (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector::[] -> index out of range !");
				return (*(_array + n));
			}

			reference at (size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("vector::at -> index out of range !");
				return (*(_array + n));	
			}
			
			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector::at -> index out of range !");
				return (*(_array + n));	
			}

			reference front()
			{ return (*(_array)); }
			
			const_reference front() const
			{ return (*(_array)); }

			reference back()
			{
				if (_size > 0)
					return (*(_array + _size - 1));
				return (*(_array));
			}
			
			const_reference back() const
			{
				if (_size > 0)
					return (*(_array + _size - 1));
				return (*(_array));
			}

			value_type* data()
			{ return _array; }

			const value_type* data() const
			{ return _array; }

			/*
			Modifiers:
			~~~~~~~~~~
			assign
			push_back		v
			pop_back		v
			insert
			erase
			swap
			clear
			emplace			x (c++11)
			emplace_back	x (c++11)
			*/

			void push_back(const value_type& val)
			{
				if (_capacity == 0)
					this->reserve(1);
				else if (_capacity <= _size)
					this->reserve(capacity_reserve_caclulator(_size + 1));
				this->_allocator.construct(this->_array + this->_size, val);
				_size++;
			}

			void pop_back()
			{
				if (_size > 0) //std is apparently not protected
				{
					_size--;
					_allocator.destroy(_array + _size);
				}
			}

			void swap(vector & x)
			{
				allocator_type tmp_allocator = x.get_allocator();
				x._allocator = _allocator;
				_allocator = tmp_allocator;

				size_type tmp_size = x.size();
				x._size = _size;
				_size = tmp_size;

				size_type tmp_capacity = x.capacity();
				x._capacity = _capacity;
				_capacity = tmp_capacity;

				pointer tmp_array = x._array;
				x._array = _array;
				_array = tmp_array;
			}

			/*
			Allocator:
			~~~~~~~~~~
			get_allocator	v
			*/

			allocator_type get_allocator() const
			{ return(_allocator); }

			
		private :

			size_t	capacity_reserve_caclulator(size_t n)
			{
				if (n <= _size * 2)
					return (_size * 2);
				return (n);
			}



	};




/*
Non-member function overloads:
relational operators
swap
*/
	
}





#endif
