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


