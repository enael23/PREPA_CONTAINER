/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main_test_uninitialized.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:20:13 by jpauline          #+#    #+#             */
/*   Updated: 2023/03/08 19:46:39 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include <iostream>

#ifndef NS
# define NS ft
#endif

template <class Key, class T>
void	print(NS::map<Key, T>& lst)
{
	for (typename NS::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

int main()
{
	NS::pair<int, std::string>			my_pair(8, "salut");
	NS::map<int, std::string>			test;
/*	NS::map<int, std::string>::iterator	it;

	test.insert(my_pair);
	test.insert(NS::pair<int, std::string>(-4, "bar"));
	test.insert(NS::pair<int, std::string>(2, "machin"));
	test.insert(NS::pair<int, std::string>(3, "foo"));
	test.insert(NS::pair<int, std::string>(746, "Marcel"));
	test.insert(NS::pair<int, std::string>(1, "truc"));
	it = test.begin();
	std::cout << '\n';

	while (it != test.end())
	{
		// cout << "start of while\n";
		std::cout << it->first << ", " << it->second << '\n';
		it++;
// 		cout << "iterator incremented\n";

// #ifndef STD
// 		cout << it.getPointer() << '\n';
// 		cout << test.end().getPointer() << '\n';
// #endif

	}
	std::cout << "End of display loop\n";*/
}

