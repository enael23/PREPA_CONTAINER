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
#include <ctime>


#include "vector.hpp"
#include <vector>
#include "stack.hpp"
#include <stack>
#include "map.hpp"
#include "pair.hpp"
#include <map>
#include "set.hpp"
#include <set>




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

template <typename T>
void print(NS::stack<T> v)
{
	std::cout << "Stack size : " << v.size();
	if (v.size() > 0)
		std::cout << " top = " << v.top();
	std::cout << std::endl;
}

void print_list (NS::map<int,char> & mymap)
{
	std::cout << "Check list      : ";
	for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
		std::cout << it->first << " ";
	std::cout << "\n";
}

void print_list (NS::set<int> & myset)
{
	std::cout << "Check list      : ";
	for (NS::set<int>::iterator it = myset.begin(); it!=myset.end();it++)
		std::cout << *it << " ";
	std::cout << "\n";
}

int main()
{
    time_t start, end;
    time(&start);

    clock_t t = clock();

    std::cout << "................................................" << std::endl;
    std::cout << "....................VECTOR......................" << std::endl;
    std::cout << "................................................" << std::endl;

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


std::cout << "................................................" << std::endl;
std::cout << "....................STACK......................." << std::endl;
std::cout << "................................................" << std::endl;


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


std::cout << "................................................" << std::endl;
std::cout << ".....................MAP........................" << std::endl;
std::cout << "................................................" << std::endl;

    NS::map<int,char> mymap;

	std::cout << "Is mymap empty? : " << mymap.empty() << std::endl;

	mymap.insert(NS::pair<int, char>(12,'a'));
	mymap.insert(NS::pair<int, char>(5,'b'));
	mymap.insert(NS::pair<int, char>(3,'b'));
	mymap.insert(NS::pair<int, char>(4,'b'));
	mymap.insert(NS::pair<int, char>(10,'c'));
	mymap.insert(NS::pair<int, char>(11,'b'));
	mymap.insert(NS::pair<int, char>(7,'b'));
	mymap.insert(NS::pair<int, char>(6,'b'));
	mymap.insert(NS::pair<int, char>(8,'b'));
	mymap.insert(NS::pair<int, char>(15,'b'));
	mymap.insert(NS::pair<int, char>(13,'b'));
	mymap.insert(NS::pair<int, char>(17,'b'));
	mymap.insert(NS::pair<int, char>(14,'b'));

	std::cout << "Is mymap empty? : " << mymap.empty() << std::endl;

	// std::cout << "MAP ELEMENT 1 : \n";
	// std::cout << "KEY = " << mymap._nil->left->val.first;
	// std::cout << ", VAL = " << mymap._nil->left->val.second << std::endl;

	// std::cout << "MAP ELEMENT 2 : \n";
	// std::cout << "KEY = " << mymap._nil->left->right->val.first;
	// std::cout << ", VAL = " << mymap._nil->left->right->val.second << std::endl;

	NS::map<int,char>::iterator it;
	it = mymap.begin();

	std::cout << "IT TEST 1 = " << it->first << ", a = " << it->second << std::endl;
	it++;
		
	std::cout << "IT TEST 2 = " << it->first << ", b = " << it->second << std::endl;
	it--;
	std::cout << "IT TEST 1 = " << it->first << ", a = " << it->second << std::endl;

	//  std::cout << "\n--------------\nTEST AFFICHAGE\n--------------\n";

	//  TreePrinter(mymap.get_root());


	it++;
	std::cout << "IT TEST 4 = " << it->first << ", b = " << it->second << std::endl;
	// std::cout << "Est ce que it(4)->right == end()? : " << (mymap._nil->left->left->right->right == mymap._nil) << "\n";

	it++;
	std::cout << it->first << "\n";
	it++;
	std::cout << it->first << "\n";
	it++;
	std::cout << it->first << "\n";
	it++;
	std::cout << it->first << "\n";
	it++;
	std::cout << it->first << "\n";
	it++;
	std::cout << it->first << "\n";
	it++;
	std::cout << it->first << "\n";
	it++;
	std::cout << it->first << "\n";


	std::cout << "\n-----------\nTEST BOUCLE\n-----------\n";
	// mymap.iterator it2;
	NS::map<int,char>::iterator it2, end2;
	it2 = mymap.begin();
	end2 = mymap.end();
	for (;it2!=end2;it2++)
		std::cout << it2->first << " ";
	std::cout << "\n";


	std::cout << "\n-----------\nTEST COUNT\n-----------\n";
	std::cout << "Count 10 = " << mymap.count(10) << "\n";
	std::cout << "Count 9 = " << mymap.count(9) << "\n";

	std::cout << "\n-----------\nTEST FIND\n-----------\n";
	std::cout << "Find 10 second = " << mymap.find(10)->second << "\n";
	std::cout << "Find 10 == end? " << (mymap.find(10) == mymap.end()) << "\n";	
	std::cout << "Find 9 == end? " << (mymap.find(9) == mymap.end()) << "\n";

	std::cout << "\n-----------\nLOWER BOUND\n-----------\n";
	std::cout << "Lower bound for 10 = " << mymap.lower_bound(10)->first << "\n";
	std::cout << "Upper bound for 10 = " << mymap.upper_bound(10)->first << "\n";
	std::cout << "Lower bound for 9 = " << mymap.lower_bound(9)->first << "\n";
	std::cout << "Upper bound for 9 = " << mymap.upper_bound(9)->first << "\n";
	std::cout << "Test lower bound min (2) = end : " << (mymap.lower_bound(2) == mymap.end()) << "\n";
	std::cout << "Lower bound for 2 : " << mymap.lower_bound(2)->first << "\n";
	std::cout << "Upper bound for 2 : " << mymap.upper_bound(2)->first << "\n";
	std::cout << "Lower bound for 17 : " << mymap.lower_bound(17)->first << "\n";
	// std::cout << "Upper bound for 17 : " << mymap.upper_bound(17)->first << "\n";
	std::cout << "Test upper bound min (17) = end : " << (mymap.upper_bound(17) == mymap.end()) << "\n";
	// std::cout << "Lower bound for 20 : " << mymap.lower_bound(20)->first << "\n";
	// std::cout << "Upper bound for 20 : " << mymap.upper_bound(20)->first << "\n";
	std::cout << "Test upper bound min (20) = end : " << (mymap.upper_bound(20) == mymap.end()) << "\n";

	std::cout << "\n-----------\nTEST AT\n-----------\n";
	std::cout << "at 10 = c : " << mymap.at(10) << "\n";
	std::cout << "at 15 = b : " << mymap.at(15) << "\n";
	try
	{
		std::cout << "at 9 = c : " << mymap.at(9) << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		
	std::cout << "\n-----------\nTEST OPERATROR[]\n-----------\n";
	std::cout << "Value for 10 got with [] (c) : " << mymap[10] << "\n";
	std::cout << "Value for 15 got with [] (b) : " << mymap[15] << "\n";
	std::cout << "Modification of 15 value to d with []\n"; mymap[15] = 'd';
	std::cout << "Value for 15 got with [] (d) : " << mymap[15] << "\n";
	std::cout << "Mymap size = (13) : " << mymap.size() << "\n";
	std::cout << "New element 9, e set with []\n"; mymap[9] = 'e';
	std::cout << "Value for 9 got with [] (e) : " << mymap[9] << "\n";
	std::cout << "Mymap size = (14) : " << mymap.size() << "\n";

	std::cout << "\n-----------\nTEST BOUCLE + REV\n-----------\n";
	std::cout << "Check list      : ";
	for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
		std::cout << it->first << " ";
	std::cout << "\n";
	std::cout << "Check list rev  : ";
	for (NS::map<int,char>::reverse_iterator it = mymap.rbegin(); it!=mymap.rend();it++)
		std::cout << it->first << " ";
	std::cout << "\n";

	std::cout << "\n-----------\nTEST ERASE\n-----------\n";
	std::cout << "Erase 10      - "; mymap.erase(10); print_list(mymap);

	// std::cout << "Ceck list      : ";
	// for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
	// 	std::cout << it->first << " ";
	// std::cout << "\n";

	// std::cout << "Erase 30\n"; mymap.erase(30); std::cout << "DONE"; print_list(mymap);
	std::cout << "Erase first   - "; mymap.erase(mymap.begin()); print_list(mymap);

	// std::cout << "Ceck list      : ";
	// for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
	// 	std::cout << it->first << " ";
	// std::cout << "\n";

	NS::map<int,char>::iterator it3 = mymap.begin();
	it3++;
	it3++;
	std::cout << "Erase third   - "; mymap.erase(it3); print_list(mymap);


    std::cout << "................................................" << std::endl;
    std::cout << ".....................SET........................" << std::endl;
    std::cout << "................................................" << std::endl;

    NS::set<int> myset;

	std::cout << "Is myset empty? : " << myset.empty() << std::endl;

	myset.insert(12);
	myset.insert(5);
	myset.insert(3);
	myset.insert(4);
	myset.insert(10);
	myset.insert(11);
	myset.insert(7);
	myset.insert(6);
	myset.insert(8);
	myset.insert(15);
	myset.insert(13);
	myset.insert(17);
	myset.insert(14);

	std::cout << "Is myset empty? : " << myset.empty() << std::endl;


	NS::set<int>::iterator its;
	its = myset.begin();


	its++;
	std::cout << *its << "\n";
	its++;
	std::cout << *its << "\n";
	its++;
	std::cout << *its << "\n";
	its++;
	std::cout << *its << "\n";
	its++;
	std::cout << *its << "\n";
	its++;
	std::cout << *its << "\n";
	its++;
	std::cout << *its << "\n";
	its++;
	std::cout << *its << "\n";


	std::cout << "\n-----------\nTEST BOUCLE\n-----------\n";
	// myset.iterator its2;
	NS::set<int>::iterator its2, ends2;
	its2 = myset.begin();
	ends2 = myset.end();
	for (;its2!=ends2;its2++)
		std::cout << *its2 << " ";
	std::cout << "\n";


	std::cout << "\n-----------\nTEST COUNT\n-----------\n";
	std::cout << "Count 10 = " << myset.count(10) << "\n";
	std::cout << "Count 9 = " << myset.count(9) << "\n";

	std::cout << "\n-----------\nTEST FIND\n-----------\n";
	std::cout << "Find 10 second = " << *myset.find(10) << "\n";
	std::cout << "Find 10 == end? " << (myset.find(10) == myset.end()) << "\n";	
	std::cout << "Find 9 == end? " << (myset.find(9) == myset.end()) << "\n";

	std::cout << "\n-----------\nLOWER BOUND\n-----------\n";
	std::cout << "Lower bound for 10 = " << *myset.lower_bound(10) << "\n";
	std::cout << "Upper bound for 10 = " << *myset.upper_bound(10) << "\n";
	std::cout << "Lower bound for 9 = " << *myset.lower_bound(9) << "\n";
	std::cout << "Upper bound for 9 = " << *myset.upper_bound(9) << "\n";
	std::cout << "Test lower bound min (2) = end : " << (myset.lower_bound(2) == myset.end()) << "\n";
	std::cout << "Lower bound for 2 : " << *myset.lower_bound(2) << "\n";
	std::cout << "Upper bound for 2 : " << *myset.upper_bound(2) << "\n";
	std::cout << "Lower bound for 17 : " << *myset.lower_bound(17) << "\n";
	// std::cout << "Upper bound for 17 : " << myset.upper_bound(17) << "\n";
	std::cout << "Test upper bound min (17) = end : " << (myset.upper_bound(17) == myset.end()) << "\n";
	// std::cout << "Lower bound for 20 : " << myset.lower_bound(20) << "\n";
	// std::cout << "Upper bound for 20 : " << myset.upper_bound(20) << "\n";
	std::cout << "Test upper bound min (20) = end : " << (myset.upper_bound(20) == myset.end()) << "\n";


	std::cout << "\n-----------\nTEST BOUCLE + REV\n-----------\n";
	std::cout << "Check list      : ";
	for (NS::set<int>::iterator its = myset.begin(); its!=myset.end();its++)
		std::cout << *its << " ";
	std::cout << "\n";
	std::cout << "Check list rev  : ";
	for (NS::set<int>::reverse_iterator its = myset.rbegin(); its!=myset.rend();its++)
		std::cout << *its << " ";
	std::cout << "\n";

	std::cout << "\n-----------\nTEST ERASE\n-----------\n";
	std::cout << "Erase 10      - "; myset.erase(10); print_list(myset);

	// std::cout << "Ceck list      : ";
	// for (NS::set<int>::iterator its = myset.begin(); its!=myset.end();its++)
	// 	std::cout << *its << " ";
	// std::cout << "\n";

	// std::cout << "Erase 30\n"; myset.erase(30); std::cout << "DONE"; print_list(myset);
	std::cout << "Erase first   - "; myset.erase(myset.begin()); print_list(myset);

	// std::cout << "Ceck list      : ";
	// for (NS::set<int>::iterator its = myset.begin(); its!=myset.end();its++)
	// 	std::cout << *its << " ";
	// std::cout << "\n";

	NS::set<int>::iterator its3 = myset.begin();
	its3++;
	its3++;
	std::cout << "Erase third   - "; myset.erase(its3); print_list(myset);

    std::cout << "................................................" << std::endl;
    std::cout << ".....................END........................" << std::endl;
    std::cout << "................................................" << std::endl;

    std::cout << "\n" << std::endl;

    time(&end);
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    std::cout << "Time taken by program is : " << std::fixed
         << time_taken;
    std::cout << " sec " << std::endl;


    t = clock() - t;
	std::cout << "\n\nTemps d'execution du programme : " << (((float)t/CLOCKS_PER_SEC) * 1000) << " millisecondes."<< std::endl;



    return 0;

}
