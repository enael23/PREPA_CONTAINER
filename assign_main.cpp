/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:03:31 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/13 18:55:23 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "vector.hpp"
#include <vector>

#ifndef NS
# define NS std
#endif

template<typename T>
void show_v(NS::vector<T> & v)
{
    std::cout << "v = { ";
    //for (int n : v)
    //    std::cout << n << ", ";
    for (typename NS::vector<T>::iterator i = v.begin(); i != v.end(); i++)
        std::cout << *i << ", ";
    std::cout << "}; \n";	
};

template<typename T>
void show_v(std::string str, NS::vector<T> & v)
{
    std::cout << str <<" = { ";
    //for (int n : v)
    //    std::cout << n << ", ";
    for (typename NS::vector<T>::iterator i = v.begin(); i != v.end(); i++)
        std::cout << *i << ", ";
    std::cout << "}; \n";	
};



int main()
{
    time_t start, end;
    time(&start);

    // Create a vector containing integers
    NS::vector<int> v;
    NS::vector<int> vEmpty;
 
    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);
    v.push_back(7);
 
    // Print out the vector
    // std::cout << "v = { ";
    // for (int n : v)
    //     std::cout << n << ", ";
    // std::cout << "}; \n";	
    std::cout << "v = { ";
    for (NS::vector<int>::size_type i = 0; i != v.size(); i++)
        std::cout << v[i] << ", ";
    std::cout << "}; \n";

    std::cout << "check Template function : show_v: " ; show_v(v);

    NS::vector<int> u;

    u.push_back(1);
    u.push_back(2);
    u.push_back(3);
    u.push_back(4);
    u.push_back(5);
    u.push_back(6);
    u.push_back(7);
    u.push_back(8);
    u.push_back(9);

    show_v("u", u); show_v(v);
    std::cout << "check u  : capacity        : " << (u.capacity()) << " size : " << (u.size()) << "\n";
    std::cout << "check v  : capacity        : " << (v.capacity()) << " size : " << (v.size()) << "\n";
    v.assign(5, 0);
    show_v(v);
    std::cout << "check v  : capacity        : " << (v.capacity()) << " size : " << (v.size()) << "\n";
    v.pop_back();
    show_v(v);



    time(&end);
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    std::cout << "Time taken by program is : " << std::fixed
         << time_taken;
    std::cout << " sec " << std::endl;
    return 0;

}
