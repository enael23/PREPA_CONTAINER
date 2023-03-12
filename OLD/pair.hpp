/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:30:53 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/25 20:31:24 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

/*NORME*/
/*The library provides a template for heterogeneous pairs of values. The library also provides a matching
template function to simplify their construction.*/
// template <class T1, class T2>
// struct pair
// {
//     typedef T1  first_type;
//     typedef T2  second_type;

//     T1 first;
//     T2 second;
    
//     pair();
//     pair(const T1& x, const T2& y);
//     template<class U, class V> pair(const pair<U, V> &p);
// };

// pair();
// 2 Effects: Initializes its members as if implemented: pair() : first(T1()), second(T2()) {}
// pair(const T1& x, const T2& y);
// 3 Effects: The constructor initializes first with x and second with y.
// template<class U, class V> pair(const pair<U, V> &p);
// 4 Effects: Initializes members from the corresponding members of the argument, performing implicit conversions as needed.
// template <class T1, class T2>
// bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y);
// 5 Returns: x.first == y.first && x.second == y.second.
// template <class T1, class T2>
// bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y);
// 6 Returns: x.first < y.first || (!(y.first < x.first) && x.second <
// y.second).
// template <class T1, class T2>
// pair<T1, T2> make_pair(const T1& x, const T2& y);
// 7 Returns: pair<T1, T2>(x, y).
// 8 [Example: In place of:
// return pair<int, double>(5, 3.1415926); // explicit types
// a C++ program may contain:
// return make_pair(5, 3.1415926); // types are deduced
    

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        typedef T1  first_type;
        typedef T2  second_type;

        T1 first;
        T2 second;
        
        pair() : first(T1()), second(T2()) {} //Default constructor
        pair(const T1& x, const T2& y) : first(x), second(y) {} //Initialization constructor
        template<class U, class V>
        pair(const pair<U, V> &p) : first(p.first), second(p.second) {} //Copy const.
        ~pair() {} //Destructor

        pair &operator= (const pair& rhs)
        {
            if (*this == rhs)
                return(*this);
            first = rhs.first;
            second = rhs.second;
            return (*this);
        }
    };

    template <class U, class V>
	ft::pair<U, V> make_pair(U x, V y)
	{ return ( ft::pair<U, V>(x, y)); }

    template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }


    // template <class T1, class T2, class U1, class U2>
	// bool operator== (const pair<T1,T2>& lhs, const pair<U1,U2>& rhs)
	// { return lhs.first==rhs.first && lhs.second==rhs.second; }

	// template <class T1, class T2, class U1, class U2>
	// bool operator!= (const pair<T1,T2>& lhs, const pair<U1,U2>& rhs)
	// { return !(lhs==rhs); }

	// template <class T1, class T2, class U1, class U2>
	// bool operator<  (const pair<T1,T2>& lhs, const pair<U1,U2>& rhs)
	// { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	// template <class T1, class T2, class U1, class U2>
	// bool operator<= (const pair<T1,T2>& lhs, const pair<U1,U2>& rhs)
	// { return !(rhs<lhs); }

	// template <class T1, class T2, class U1, class U2>
	// bool operator>  (const pair<T1,T2>& lhs, const pair<U1,U2>& rhs)
	// { return rhs<lhs; }

	// template <class T1, class T2, class U1, class U2>
	// bool operator>= (const pair<T1,T2>& lhs, const pair<U1,U2>& rhs)
	// { return !(lhs<rhs); }

}


// namespace ft {

// 	template< class T1, class T2 >
// 	class pair {
	
// 		public :

// 			T1 first;
// 			T2 second;

// 			pair( void ) : first(T1()), second(T2()) {}
// 			pair( const T1 & x, const T2 & y ) : first(x), second(y) {}
// 			template< class U1, class U2 >
// 			pair( const pair<U1, U2> & p ) : first(p.first), second(p.second) {}
// 			pair & operator=( const pair & p ) {
// 				if (*this == p)
// 					return *this;
// 				this->first = p.first;
// 				this->second = p.second;
// 				return *this;
// 			}
// 			~pair( void ) {}

// 	};

// 	template< class T1, class T2 >
// 	ft::pair<T1, T2> make_pair(T1 x, T2 y) {
// 		return (ft::pair<T1, T2>(x, y));
// 	}

// 	template< class T1, class T2 >
// 	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
// 		if (lhs.first == rhs.first && lhs.second == rhs.second)
// 			return true;
// 		return false;
// 	};
	
// 	template< class T1, class T2 >
// 	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
// 		return !(lhs == rhs);
// 	};
	
// 	template< class T1, class T2 >
// 	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
// 		if (lhs.first < rhs.first)
// 			return true;
// 		if (rhs.first < lhs.first)
// 			return false;
// 		if (lhs.second < rhs.second)
// 			return true;
// 		return false;
// 	};
	
// 	template< class T1, class T2 >
// 	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
// 		return !(rhs < lhs);
// 	};
	
// 	template< class T1, class T2 >
// 	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
// 		return (rhs < lhs);
// 	};
	
// 	template< class T1, class T2 >
// 	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
// 		return !(lhs < rhs);
// 	};

// }

#endif
