/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:03:31 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/09 20:42:22 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "vector.hpp"
#include <vector>

#ifndef NS
#define NS=ft
#endif

template<typename T>
void show_v(NS::vector<T> & v)
{
    std::cout << "v = { ";
    for (int n : v)
        std::cout << n << ", ";
    std::cout << "}; \n";	
};


int main()
{
    // Create a vector containing integers
    NS::vector<int> v;
    NS::vector<int> vEmpty;
 
    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);
    v.push_back(7);
 
    // Print out the vector
    std::cout << "v = { ";
    for (int n : v)
        std::cout << n << ", ";
    std::cout << "}; \n";	

    std::cout << "check Template function : show_v: " ; show_v(v);

//	std::cout << "v[0] = " << v[0] << std::endl;
//	std::cout << "v[1] = " << v[1] << std::endl;

//	NS::vector<int> v2 = v;

//	std::cout << "v2[0] = " << v2[0] << std::endl;


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

    std::cout << "check Iterators : begin   : " << *(v.begin()) << std::endl;
    std::cout << "check Iterators : end     : " << *(v.end() - 1) << std::endl;
    std::cout << "check Iterators : rbegin  : " << *(v.rbegin()) << std::endl;
    std::cout << "check Iterators : rend    : " << *(v.rend() - 1) << std::endl;
       
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

    std::cout << "check Capacity : size     : " << (v.size()) << std::endl;
    std::cout << "check Capacity : capacity : " << (v.capacity()) << std::endl;
    std::cout << "check Capacity : max_size : " << (v.max_size()) << std::endl;
    std::cout << "check Capacity : resize-1 : "; (v.resize(5)); show_v(v);
    std::cout << "check Capacity : capacity : " << (v.capacity()) << std::endl;
    std::cout << "check Capacity : resize-2 : "; (v.resize(2)); show_v(v);
    std::cout << "check Capacity : capacity : " << (v.capacity()) << std::endl;
    std::cout << "check Capacity : resize-3 : "; (v.resize(5, 1)); show_v(v);
    std::cout << "check Capacity : capacity : " << (v.capacity()) << std::endl;
    std::cout << "check Capacity : resize-4 : size : " << (v.size()) << std::endl;
    std::cout << "check Capacity : capacity : " << (v.capacity()) << std::endl;
    std::cout << "check Capacity : empty-1  : " << (v.empty()) << std::endl;
    std::cout << "check Capacity : empty-2  : " << (vEmpty.empty()) << std::endl;
    std::cout << "check Capacity : reserve8 : " ; (v.reserve(8)); show_v(v);
    std::cout << "check Capacity : capacity : " << (v.capacity()) << std::endl;
    std::cout << "check Capacity : reserve25: " ; (v.reserve(25)); show_v(v);
    std::cout << "check Capacity : capacity : " << (v.capacity()) << std::endl;


        /*
        Element access:
        ~~~~~~~~~~~~~~~
        operator[]		v	const	v
        at				v	const	v
        front			v	const	v
        back			v	const	v
        data			v	const	v
        */


}
