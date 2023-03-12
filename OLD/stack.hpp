/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:46:28 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/20 20:08:11 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

/*NORME :*/
/*
namespace std 
{
	template <class T, class Container = deque<T> >
	class stack
	{
		public:
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef Container container_type;
		
		protected:
			Container c;

		public:
			explicit stack(const Container& = Container());
			bool empty() const { return c.empty(); }
			size_type size() const { return c.size(); }
			value_type& top() { return c.back(); }
			const value_type& top() const { return c.back(); }
			void push(const value_type& x) { c.push_back(x); }
			void pop() { c.pop_back(); }
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container>& x, const stack<T, Container>& y);
	template <class T, class Container>
	bool operator< (const stack<T, Container>& x, const stack<T, Container>& y);
	template <class T, class Container>
	bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y);
	template <class T, class Container> 
	bool operator> (const stack<T, Container>& x, const stack<T, Container>& y);
	template <class T, class Container>
	bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y);
	template <class T, class Container>
	bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y);
}
*/

#include <iostream>

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		public:
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef Container							container_type;

			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;
		
		protected:
			Container _c;

		public:
			// explicit stack(const Container& = Container()) { std::cout << "DEFAULT CONSTRUCTOR\n";} 
			// explicit stack(const Container& other): _c(other) { std::cout << "COPY CONSTRUCTOR\n";} 

			// explicit stack(const Container& = Container()) {}
			explicit stack(const Container& other = Container()) : _c(other) {}
			
			//explicit stack( void ) {}
			// stack( const stack& other ) : _c(other._c) {}
			// stack( const container_type& other ) : _c(other) {}
			~stack() {}
			stack& operator=( const stack& other )
			{
				this->_c = other._c;
				return *this;
			}




			bool empty() const				{ return _c.empty(); }
			size_type size() const			{ return _c.size(); }
			value_type& top()				{ return _c.back(); }
			const value_type& top() const	{ return _c.back(); }
			void push(const value_type& x)	{ _c.push_back(x); }
			void pop()						{ _c.pop_back(); }

			friend bool operator== (const stack & lhs, const stack & rhs) { return (lhs._c == rhs._c); }
			friend bool operator<  (const stack & lhs, const stack & rhs) { return (lhs._c < rhs._c); }

	};

	template <class T, class Container>
	bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)	{ return (x == y); }
	template <class T, class Container>
	bool operator< (const stack<T, Container>& x, const stack<T, Container>& y) { return (x < y); }
	template <class T, class Container>
	bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y) { return (!(x == y)); }
	template <class T, class Container> 
	bool operator> (const stack<T, Container>& x, const stack<T, Container>& y) { return (y < x); }
	template <class T, class Container>
	bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y) { return (!(x < y)); }
	template <class T, class Container>
	bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y) { return (!(y < x)); }
}

#endif
