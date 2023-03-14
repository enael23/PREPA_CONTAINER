/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:47:19 by jpauline          #+#    #+#             */
/*   Updated: 2023/03/13 20:50:23 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "stack.hpp"
#include <stack>

#ifndef NS
# define NS ft
#endif

template <typename T>
void print(NS::stack<T> v)
{
	std::cout << "Stack size : " << v.size();
	if (v.size() > 0)
		std::cout << " top = " << v.top();
	std::cout << std::endl;
}

int main() {

		NS::stack<int> v1;
		std::cout << "v1 (empty)	: "; print(v1);

		std::cout << "v1.push(5);\n"; v1.push(5);

		NS::stack<int> v2(v1);
		std::cout << "v2(v1)		: "; print(v2);

		NS::stack<int> v3;
		v3 = v2;
		std::cout << "v3 = v2		: "; print(v3);


		for (int i = 0; i < 1000; i++)
			v1.push(i);
		std::cout << "Loop test		: "; print(v1);
		v1.pop();
		v1.pop();
		v1.pop();
		v1.pop();
		v1.pop();
		v1.pop();
		v1.pop();
		v1.pop();
		std::cout << "pop test		: "; print(v1);

		std::cout << "(v1 == v2)	: " << (v1 == v2) << "\n";
		std::cout << "(v1 != v2)	: " << (v1 != v2) << "\n";
		std::cout << "(v1 < v2)	: " << (v1 < v2) << "\n";
		std::cout << "(v1 <= v2)	: " << (v1 <= v2) << "\n";
		std::cout << "(v1 > v2)	: " << (v1 > v2) << "\n";
		std::cout << "(v1 >= v2)	: " << (v1 >= v2) << "\n";

	return 0;
}