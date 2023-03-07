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



//C++ code for the above approach
#include <bits/stdc++.h>
using namespace std;
 
class Treenode 
{
public:
    int data;
    Treenode *left, *right;
    Treenode(int data) {
        this->data = data;
        left = right = NULL;
    }
};
 
class Tree 
{
public:
    Treenode *root;
    Tree() {
        root = NULL;
    }
};
 
int height(ft::s_map_node<ft::pair<const int, char> >* root) 
{
    if (root == root->parent)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
 
int getcol(int h) 
{
    if (h == 1)
        return 1;
    return getcol(h - 1) + getcol(h - 1) + 1;
}
 
void printTree(int **M, ft::s_map_node<ft::pair<const int, char> >* root, int col, int row, int height) 
{
    if (root == root->parent)
        return;
    M[row][col] = root->val.first;
    printTree(M, root->left, col - pow(2, height - 2), row + 1, height - 1);
    printTree(M, root->right, col + pow(2, height - 2), row + 1, height - 1);
}
 
void TreePrinter(ft::s_map_node<ft::pair<const int, char> >* root) 
{
    int h = height(root);
    int col = getcol(h);
    int **M = new int*[h];
    for (int i = 0; i < h; i++) 
        M[i] = new int[col];
    printTree(M, root, col / 2, 0, h);
    for (int i = 0; i < h; i++) 
	{
        for (int j = 0; j < col; j++) 
		{
            if (M[i][j] == 0)
                cout << " " << " ";
            else
                cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void print_list (NS::map<int,char> & mymap)
{
	std::cout << "Ceck list      : ";
	for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
		std::cout << it->first << " ";
	std::cout << "\n";
}

int main()
{
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
	std::cout << "Ceck list      : ";
	for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
		std::cout << it->first << " ";
	std::cout << "\n";
	std::cout << "Ceck list rev  : ";
	for (NS::map<int,char>::reverse_iterator it = mymap.rbegin(); it!=mymap.rend();it++)
		std::cout << it->first << " ";
	std::cout << "\n";

	std::cout << "\n-----------\nTEST ERASE\n-----------\n";
	std::cout << "Erase 10\n"; mymap.erase(10); print_list(mymap);

	// std::cout << "Ceck list      : ";
	// for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
	// 	std::cout << it->first << " ";
	// std::cout << "\n";

	// std::cout << "Erase 30\n"; mymap.erase(30); std::cout << "DONE"; print_list(mymap);
	std::cout << "Erase first\n"; mymap.erase(mymap.begin()); print_list(mymap);

	// std::cout << "Ceck list      : ";
	// for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
	// 	std::cout << it->first << " ";
	// std::cout << "\n";

	NS::map<int,char>::iterator it3 = mymap.begin();
	it3++;
	it3++;
	std::cout << "Erase third\n"; mymap.erase(it3); print_list(mymap);


	// 	std::cout << "Ceck list      : ";
	// for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
	// 	std::cout << it->first << " ";
	// std::cout << "\n";
	


	// std::cout << "\n--------------\nTEST AFFICHAGE\n--------------\n";

	// TreePrinter(mymap.get_root());

	return (0); 
}
