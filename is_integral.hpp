/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:23:50 by jpauline          #+#    #+#             */
/*   Updated: 2023/01/30 12:36:40 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	//Default false case
	template<typename T>
	struct is_integral {static bool value = false;}

	//True specilization for integral types
	template<> struct is_integral<bool>						{static const bool value = true;}
	template<> struct is_integral<const bool>				{static const bool value = true;}
	template<> struct is_integral<char>						{static const bool value = true;}
	template<> struct is_integral<const char>				{static const bool value = true;}
	template<> struct is_integral<unsigned char>			{static const bool value = true;}
	template<> struct is_integral<const unsigned char>		{static const bool value = true;}
	template<> struct is_integral<int>						{static const bool value = true;}
	template<> struct is_integral<const int>				{static const bool value = true;}
	template<> struct is_integral<unsigned int>				{static const bool value = true;}
	template<> struct is_integral<const unsigned int>		{static const bool value = true;}
	template<> struct is_integral<long>						{static const bool value = true;}
	template<> struct is_integral<const long>				{static const bool value = true;}
	template<> struct is_integral<unsigned long>			{static const bool value = true;}
	template<> struct is_integral<const unsigned long>		{static const bool value = true;}
	template<> struct is_integral<long long>				{static const bool value = true;}
	template<> struct is_integral<const long long>			{static const bool value = true;}
	template<> struct is_integral<unsigned long long>		{static const bool value = true;}
	template<> struct is_integral<const unsigned long long>	{static const bool value = true;}
	template<> struct is_integral<short>					{static const bool value = true;}
	template<> struct is_integral<const short>				{static const bool value = true;}
	template<> struct is_integral<unsigned short>			{static const bool value = true;}
	template<> struct is_integral<const unsigned short>		{static const bool value = true;}
	template<> struct is_integral<float>					{static const bool value = true;}
	template<> struct is_integral<const float>				{static const bool value = true;}
	template<> struct is_integral<double>					{static const bool value = true;}
	template<> struct is_integral<const double>				{static const bool value = true;}
	template<> struct is_integral<long double>				{static const bool value = true;}
	template<> struct is_integral<const long double>		{static const bool value = true;}
}


#endif
