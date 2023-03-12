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
# define NS ft
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

//	std::cout << "v[0] = " << v[0] << std::endl;
//	std::cout << "v[1] = " << v[1] << std::endl;

//	NS::vector<int> v2 = v;

//	std::cout << "v2[0] = " << v2[0] << std::endl;





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

        /*
        MEMBER FUNCTIONS
        ~~~~~~~~~~~~~~~~
        (constructor)
        (destructor)
        operator= (assign content)
        */

    std::cout << "Copy constructor (range)  : "; show_v(u);
    std::cout << "Copy constructor (range)  : "; NS::vector<int> w(u.begin(), u.end()); show_v("w", w);       


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

    std::cout << "check Iterators : begin   : " << *(v.begin()) << "\n";
    std::cout << "check Iterators : end     : " << *(v.end() - 1) << "\n";
    std::cout << "check Iterators : rbegin  : " << *(v.rbegin()) << "\n";
    std::cout << "check Iterators : rend    : " << *(v.rend() - 1) << "\n";
    std::cout << "................................................" << std::endl;
       
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

    std::cout << "check Capacity : size             : " << (v.size()) << "\n";
    std::cout << "check Capacity : capacity         : " << (v.capacity()) << "\n";
    std::cout << "check Capacity : max_size         : " << (v.max_size()) << "\n";
    std::cout << "check Capacity : resize-1 (5)     : "; (v.resize(5)); show_v(v);
    std::cout << "check Capacity : capacity         : " << (v.capacity()) << "\n";
    std::cout << "check Capacity : resize-2 (2)     : "; (v.resize(2)); show_v(v);
    std::cout << "check Capacity : capacity         : " << (v.capacity()) << "\n";
    std::cout << "check Capacity : resize-3 (7,1)   : "; (v.resize(7, 1)); show_v(v);
    std::cout << "check Capacity : capacity         : " << (v.capacity()) << "\n";
    std::cout << "check Capacity : resize-4 (9,2)   : "; (v.resize(9, 2)); show_v(v);
    std::cout << "check Capacity : capacity         : " << (v.capacity()) << "\n";
    std::cout << "check Capacity : resize-5         : size : " << (v.size()) << "\n";
    std::cout << "check Capacity : capacity         : " << (v.capacity()) << "\n";
    std::cout << "check Capacity : empty-1          : " << (v.empty()) << "\n";
    std::cout << "check Capacity : empty-2          : " << (vEmpty.empty()) << "\n";
    std::cout << "check Capacity : reserve (8)      : " ; (v.reserve(8)); show_v(v);
    std::cout << "check Capacity : capacity         : " << (v.capacity()) << "\n";
    std::cout << "check Capacity : reserve (25)     : " ; (v.reserve(25)); show_v(v);
    std::cout << "check Capacity : capacity         : " << (v.capacity()) << "\n";
    std::cout << "................................................" << std::endl;

        /*
        Element access:
        ~~~~~~~~~~~~~~~
        operator[]		v	const	v
        at				v	const	v
        front			v	const	v
        back			v	const	v
        data			v	const	v
        */

    std::cout << "check Access : operator[] ([1])   : " << (v[1]) << "\n";
    std::cout << "check Access : at (1)             : " << (v.at(1)) << "\n";
    std::cout << "check Access : front              : " << (v.front()) << "\n";
    std::cout << "check Access : back               : " << (v.back()) << "\n";
    std::cout << "check Access : data               : " << (v.data()) << "\n";
    std::cout << "check Access : assign[]           : " ; (v[2]=42) ; show_v(v);
    std::cout << "................................................" << std::endl;

        /*
        Modifiers:
        ~~~~~~~~~~
        assign				fill	v	range	v
        push_back		v
        pop_back		v
        insert			v	fill	v	range	v
        erase			v	range	v
        swap			v
        clear			v
        emplace			x (c++11)
        emplace_back	x (c++11)
        */

    std::cout << "check Modifiers : assign u "; show_v("u", u);
    std::cout << "check Modifiers : assign u - capacity : " << (u.capacity()) << " size : " << (u.size()) << "\n";
    std::cout << "check Modifiers : assign u "; show_v(v);
    std::cout << "check Modifiers : assign v - capacity : " << (v.capacity()) << " size : " << (v.size()) << "\n";
    v.assign(5, 0);
    show_v(v);
    std::cout << "check Modifiers : assign v.assign(5,0)    :";
    std::cout << "check Modifiers : assign u "; show_v(v);
    std::cout << "check Modifiers : assign v - capacity : " << (v.capacity()) << " size : " << (v.size()) << "\n";

    std::cout << std::endl;

    std::cout << "check Modifiers : pop_back        : " ; (v.pop_back()) ; show_v(v);
    std::cout << "check Modifiers : insert (p1,7)   : " ; (v.insert(v.begin() + 1, 7)) ; show_v(v);
    std::cout << "check Capacity  : capacity        : " << (v.capacity()) << " size : " << (v.size()) << "\n";;
    std::cout << "check Modifiers : insert (p4,4,8) : " ; (v.insert(v.begin() + 4, 4, 8)) ; show_v(v);
    std::cout << "check Capacity  : capacity        : " << (v.capacity()) << " size : " << (v.size()) << "\n";
    std::cout << "check Modifiers : insert (p4,10,9) : " ; (v.insert(v.begin() + 4, 10, 9)) ; show_v(v);
    std::cout << "check Capacity  : capacity        : " << (v.capacity()) << " size : " << (v.size()) << "\n";
    std::cout << "check Modifiers : insert (p4,45,3) : " ; (v.insert(v.begin() + 4, 45, 3)) ; show_v(v);
    std::cout << "check Capacity  : capacity        : " << (v.capacity()) << " size : " << (v.size()) << "\n";

    // NS::vector<int> u;

    // u.push_back(1);
    // u.push_back(2);
    // u.push_back(3);
    // u.push_back(4);
    // u.push_back(5);
    // u.push_back(6);
    // u.push_back(7);
    // u.push_back(8);
    // u.push_back(9);

    std::cout << "check Modifiers : insert (p4,b,e) : " ; (v.insert(v.begin() + 4, v.begin(), v.end())) ; show_v(v);
    std::cout << "check Capacity  : capacity        : " << (v.capacity()) << " size : " << (v.size()) << "\n";
    std::cout << "check Modifiers : vEmpty size = " << vEmpty.size() << std::endl;
//  std::cout << "check Modifiers : pop_back        : " ; (vEmpty.pop_back()) ; show_v("vEmpty", vEmpty); //segfault with std
    std::cout << "check Modifiers : erase (1)       : " ; (v.erase(v.begin() + 1)) ; show_v(v);
    std::cout << "check Modifiers : erase (1,3)     : " ; (v.erase(v.begin() + 1, v.begin() + 3)) ; show_v(v);
    std::cout << "check Modifiers : erase - size    : " << (v.size()) << std::endl;
//    std::cout << "check Modifiers : erase (3,1)     : " ; (v.erase(v.begin() + 3, v.begin() + 1)) ; show_v(v);  //undefined behavior
//    std::cout << "check Modifiers : erase - size    : " << (v.size()) << std::endl;
    std::cout << "check Modifiers : swap            : " ; (v.swap(vEmpty)) ; show_v("vEmpty", vEmpty); show_v(v);
    v.swap(vEmpty); show_v(v);
    std::cout << "check Modifiers : clear           : " ; (v.clear()) ; show_v(v);
    std::cout << "check Modifiers : clear  (size)   : " << (v.size()) << std::endl;
    std::cout << "................................................" << std::endl;



    /*
    Non-member function overloads:
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    relational operators

        template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    swap
    */

    NS::vector<int> foo (3,100);   // three ints with a value of 100
    NS::vector<int> bar (2,200);   // two ints with a value of 200

    std::cout << "check relational op : ==      : "; if (foo==bar) std::cout << "foo and bar are equal";                std::cout << "\n";
    std::cout << "check relational op : !=      : "; if (foo!=bar) std::cout << "foo and bar are not equal";            std::cout << "\n";
    std::cout << "check relational op : <       : "; if (foo< bar) std::cout << "foo is less than bar";                 std::cout << "\n";
    std::cout << "check relational op : >       : "; if (foo> bar) std::cout << "foo is greater than bar";              std::cout << "\n";
    std::cout << "check relational op : <=      : "; if (foo<=bar) std::cout << "foo is less than or equal to bar";     std::cout << "\n";
    std::cout << "check relational op : >=      : "; if (foo>=bar) std::cout << "foo is greater than or equal to bar";  std::cout << "\n";


    time(&end);
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    std::cout << "Time taken by program is : " << std::fixed
         << time_taken;
    std::cout << " sec " << std::endl;
    return 0;

}
