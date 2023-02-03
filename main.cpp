/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:03:31 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/03 18:18:46 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "vector.hpp"

int main()
{
    // Create a vector containing integers
    ft::vector<int> v;
 
    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);
 
    // Print out the vector
//    std::cout << "v = { ";
//    for (int n : v)
//        std::cout << n << ", ";
//    std::cout << "}; \n";	


	std::cout << "v[0] = " << v[0] << std::endl;
	std::cout << "v[1] = " << v[1] << std::endl;
}
