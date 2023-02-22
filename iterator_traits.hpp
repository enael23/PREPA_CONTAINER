/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:50:05 by jpauline          #+#    #+#             */
/*   Updated: 2023/01/30 17:20:23 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef> //pour std::ptrdiff_t

namespace ft
{
//	struct input_operator_tag {};
//	struct output_iterator_tag {};
//	struct forward_iterator_tag : public input_operator_tag {};
//	struct bidirectionnal_iterator_tag : public forward_iterator_tag {};
//	struct random_access_iterator_tag : public std::bidirectional_iterator_tag {};
	struct random_access_iterator_tag : public std::random_access_iterator_tag {};

	template<class Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	/*
	Specialization:
	This type trait may be specialized for user-provided types that may be used as iterators. 
	The standard library provides partial specializations for pointer types T*,
	which makes it possible to use all iterator-based algorithms with raw pointers.
	*/

	template<class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};

}


#endif
