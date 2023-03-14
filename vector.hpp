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

// #include <memory>
// #include <iostream>

#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"

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
			typedef typename ft::vector_iterator<value_type>				iterator;
			typedef typename ft::vector_iterator<const value_type>			const_iterator;
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
			(constructor)				default		v	fill	v	range	v	copy	v
			(destructor)				v
			operator= (assign content)	v
			*/

			// Default constructor
			explicit vector(const allocator_type & alloc = allocator_type()) : _allocator(alloc), _size(0), _capacity(0), _array(NULL)
			{
// std::cout << "VECTOR CONSTRUCTED (DEFAULT)" << std::endl;
			}

			// Fill constructor
			vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
				_allocator(alloc), _size(n), _capacity(n), _array(NULL)
			{
				if (n > max_size())
					throw std::length_error("vector::not enough capacity");
				if (n > 0)
				{
					_array = _allocator.allocate(_size);
					for (size_type i = 0; i < n; i++)
						_allocator.construct(_array + i, val);
// std::cout << "VECTOR CONSTRUCTED (FILL)" << std::endl;
				}
				return;
			}	

			// Range Constructor
			template< class InputIterator >
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, void **>::type = 0 ) :
				_allocator(alloc), _size(0), _capacity(0), _array(0)
			{

				if (first != last)
					this->reserve(1);
				size_type i = 0;
				for (; first != last; first++)
				{
					if (i == this->_capacity)
						this->reserve(this->_capacity * 2);
					this->_allocator.construct(this->_array + i++, *first);
					this->_size++;
				}
				this->shrink_to_fit();
			}

			vector(const vector& x) : _size(0), _capacity(0), _array(NULL)
			{
				this->_allocator = x.get_allocator();
				this->_size = x.size();
				this->_capacity = x.size();
				if (x.size() > 0)
				{
					this->_array = this->_allocator.allocate(this->_capacity);
					for (size_type i = 0; i < x.size(); i++)
						this->_allocator.construct(this->_array + i, x.at(i));
				}
			}

			// Destrcutor
			virtual ~vector() 
			{
				
				for (size_t i = 0;  i < _size; i++)
						this->_allocator.destroy(this->_array + i);
				if (_capacity > 0)
					_allocator.deallocate(_array,_capacity);
// std::cout << "VECTOR DESTRUCTED" << std::endl;
			};

			// Operator=
			vector& operator=(const vector& x)
			{
				if (this != &x)
					assign(x.begin(), x.end());
				return (*this);
			}

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

			iterator				begin()				{ return (iterator(_array)); }
			const_iterator			begin() const		{ return (const_iterator(_array)); }
			iterator				end()				{ return (iterator(_array + _size)); }
			const_iterator			end() const			{ return (const_iterator(_array + _size)); }
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

			void reserve(size_type n)
			{
				if (n > _allocator.max_size())
					throw std::length_error("vector::reserve");
				if (n <= _capacity)	
					return ;
				pointer new_array = _allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					if (i < _size)
					{
						_allocator.construct(new_array + i, *(_array + i));
						_allocator.destroy(_array + i);  
					}
				}				
				if (_capacity != 0)
					_allocator.deallocate(_array, _capacity);
				_capacity = n;
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
				// if (n >= _size)
				// 	throw std::out_of_range("vector::[] -> index out of range !");
				return (*(_array + n));
			}
			
			const_reference operator[] (size_type n) const
			{
				// if (n >= _size)
				// 	throw std::out_of_range("vector::[] -> index out of range !");
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
			assign				fill	v	range	v
			push_back		v
			pop_back		v
			insert			v	fill	v	range	v
			erase			v	range	v
			swap			v
			clear			v
			emplace			x (c++11)
			emplace_back	x (c++11)
			*/

			void	assign(size_t n, const value_type &val)
			{
				clear();
				if (n == 0)
					return;
				_size = n;
				if (_capacity < n)
				{
					if (_capacity)
						_allocator.deallocate(_array, _capacity);
					_capacity = n;
					_array = _allocator.allocate(_capacity);
				}
				for (size_type i = 0; i < n; i++)
					_allocator.construct(_array + i, val);
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, void **>::type = 0)
			{
				clear();
				insert(begin(), first, last);
			}

			void push_back(const value_type& val)
			{
				if (_capacity == 0)
					this->reserve(1);
				else if (_capacity <= _size)
					this->reserve(capacity_reserve_caclulator(_size + 1));
				_allocator.construct(_array + _size, val);
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

			iterator insert(iterator position, const value_type& val)
			{
				difference_type pos = position - begin();
				if (_capacity < _size + 1)
					reserve(capacity_reserve_caclulator(_size + 1));
				iterator ite_cur = end();
				position = begin() + pos;
				if (_size && position != ite_cur)
				{
				_allocator.construct(_array + _size, *(--ite_cur));
				for (; (ite_cur) != position; ite_cur--)
					*ite_cur = *(ite_cur - 1);
				_allocator.destroy(_array + (position - begin()));
				}
				_allocator.construct(_array + (position - begin()), val);
				_size++;
				return(begin() + pos);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				difference_type pos = position - begin();
				if (n == 0)
					return;
				if (_capacity < _size + n)
					reserve(capacity_reserve_caclulator(_size + n));
				iterator ite_cur = this->end() + (n - 1);
				position = begin() + pos;
				while (ite_cur >= this->end() && ite_cur >= position + n)
				{
					_allocator.construct(_array + (ite_cur - begin()), *(ite_cur - n));
					ite_cur--;
				}
				while (ite_cur >= position + n)
				{
					*ite_cur = *(ite_cur - n);
					ite_cur--;
				}
				while (ite_cur >= position)
				{
					if (ite_cur < end())
						_allocator.destroy(_array + (ite_cur - begin()));
					_allocator.construct(_array + (ite_cur - begin()), val);
					ite_cur--;
				}
				_size+= n;
				return;
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, void **>::type = 0)
			{
				if (last == first)
					return;
				size_type n = 0;

				vector<T, Alloc> v_tmp(first, last);
				n = v_tmp.size();
				if (n == 0)
					return;

				difference_type pos = position - begin();
				if (_capacity < _size + n)
					reserve(capacity_reserve_caclulator(_size + n));
				position = begin() + pos;
				iterator ite_cur = this->end() + (n - 1);
				while (ite_cur >= this->end() && ite_cur >= position + n)
				{
					_allocator.construct(_array + (ite_cur - begin()), *(ite_cur - n));
					ite_cur--;
				} 
				while (ite_cur >= position + n)
				{
					*ite_cur = *(ite_cur - n);
					ite_cur--;
				}
				iterator new_last = v_tmp.end();

				while (ite_cur >= position)
				{
					if (ite_cur < end())
						_allocator.destroy(_array + (ite_cur - begin()));
					new_last--;	
					_allocator.construct(_array + (ite_cur - begin()), *new_last);
					ite_cur--;
				}
				_size+= n;
				return;

			}



			iterator erase (iterator position)
			{
				for (size_type i = position - begin() ; i < _size - 1 ; i++)
					_array[i] = _array[i + 1];
				_size--;
				_allocator.destroy(_array + _size);

				return (position);
			}

			iterator erase (iterator first, iterator last)
			{
				if (this->empty() || (last <= first))
					return(first);

				iterator ite_cur = first;
				difference_type ite_dif = last - first;
				iterator ite_end = this->end();

				for (; (ite_cur + 1) != ite_end - ite_dif + 1; ite_cur++)
					*ite_cur = *(ite_cur + ite_dif);
				for (difference_type i = 0; i != ite_dif; i++)
 					_allocator.destroy(_array + _size - 1 - i);

				_size-= ite_dif;
				return (first);
			}

			void swap(vector & x)
			{
				// allocator_type tmp_allocator = x.get_allocator();
				// x._allocator = _allocator;
				// _allocator = tmp_allocator;

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

			void clear()
			{
				if (_size)
				{
					for (size_type i = 0; i < _size; i++)
						this->_allocator.destroy(_array + i);
					this->_size = 0;
				}
			}

			/*
			Allocator:
			~~~~~~~~~~
			get_allocator	v
			*/

			allocator_type get_allocator() const
			{ return(_allocator); }

			
		private :

			// size_t	capacity_reserve_caclulator(size_t n)
			// {
			// 	if (n <= _size * 2)
			// 		return (_size * 2);
			// 	return (n);
			// }

			size_t	capacity_reserve_caclulator(size_t n)
			{
				size_t s = _size * 2; 
				if (n <= s)
				{
					if (s <= _allocator.max_size())
						return (s);
					return (_allocator.max_size());
				}
				return (n);
			}

			void shrink_to_fit( void )
			{
			if (_capacity != _size)
				{
					pointer tmp = _allocator.allocate(_size);
					iterator it = begin();
					for (size_type i = 0; i < _size; i++)
					{
						_allocator.construct(tmp + i, *it);
						it++;
					}
					size_type size = _size;
					clear();
					_allocator.deallocate(_array, _capacity);
					_array = tmp;
					_size = size;
					_capacity = size;
				}
			}

	};

/*
Non-member function overloads:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
relational operators

	template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

swap
*/

	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs[i] != rhs[i])
					return false;
			}
			return true;
		}
		return false;
	}

  	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return !(lhs == rhs); }

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (rhs < lhs); }

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return !(lhs > rhs); }

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return !(lhs < rhs); }

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{ x.swap(y); }
	
}

#endif
