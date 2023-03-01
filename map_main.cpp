/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:47:19 by jpauline          #+#    #+#             */
/*   Updated: 2023/03/01 21:10:09 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "map.hpp"
#include "pair.hpp"
#include <map>

#ifndef NS
# define NS ft
#endif


int main()
{
	NS::map<int,char> mymap;
	mymap.insert(NS::pair<int, char>(1,'a'));
	mymap.insert(NS::pair<int, char>(2,'b'));

	std::cout << "MAP ELEMENT 1 : \n";
	std::cout << "KEY = " << mymap._nil->left->val.first;
	std::cout << ", VAL = " << mymap._nil->left->val.second << std::endl;

	std::cout << "MAP ELEMENT 2 : \n";
	std::cout << "KEY = " << mymap._nil->left->right->val.first;
	std::cout << ", VAL = " << mymap._nil->left->right->val.second << std::endl;

	NS::map<int,char>::iterator it;
	it = mymap.begin();

	std::cout << "IT TEST 1 = " << it->first << ", a = " << it->second << std::endl;
	it++;
		
	std::cout << "IT TEST 2 = " << it->first << ", b = " << it->second << std::endl;
	it--;
	std::cout << "IT TEST 1 = " << it->first << ", a = " << it->second << std::endl;

	return (0); 
}
