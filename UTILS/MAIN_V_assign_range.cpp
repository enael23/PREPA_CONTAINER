/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_range_main.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:37:50 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/21 18:25:58 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <sstream>

//typedef NAMESPACE::vector<char, track_allocator<char> > charvector;

int main()
    {
        // This test checks if vector works with iterators tagged as std::input_iterator_tag
std::cout << "Input iterator test\n";
 //       charvector v;
		ft::vector<char> v;

        std::istringstream str("1 2 3 4 5 6 7");
        std::istreambuf_iterator<char> it(str), end;

//std::cout << "test it 	= " << it << "\n";
//std::cout << "test end 	= " << end << "\n";

		auto it1 = it;
		auto end1 = end;

std::cout << "display vector0 : ";
		int n = 0;
		while (it1 != end1)
		{
			std::cout << n << ":" << *it1 << " ,";
			it1++;
		}

		//auto it2 = it;

        //CHECK_AND_PRINT_ALL(v);
std::cout << "lance v.assign(it, end)\n";
        v.assign(it, end);
std::cout << "dernier check\n";
std::cout << "v RESULT size = " << v.size() << "\n";
        //CHECK_AND_PRINT_ALL(v);
	
		ft::vector<char>::iterator it2 = v.begin();
		ft::vector<char>::iterator end2 = v.end();		
	
std::cout << "display vector : ";
		int n2 = 0;
		while (it2 != end2)
		{
			std::cout << n2;
			std::cout << ":";
			std::cout << *it2;
			std::cout << " ,";
			it2++;
			n2++;
			std::cout << "\n";
		}
std::cout << "\nFIN\n";
		return(0);
    }

