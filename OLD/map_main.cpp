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



// C++ Program to print binary tree in 2D
#include <bits/stdc++.h>
 
// using namespace std;
#define COUNT 10
 
// // A binary tree node
// class Node {
// public:
//     int data;
//     Node *left, *right;
 
//     /* Constructor that allocates a new node with the
//     given data and NULL left and right pointers. */
//     Node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
 
// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(ft::s_map_node<ft::pair<const int, char> >* root, int space)
{
// std::cout << "goprint_2\n";
    // Base case
    if (root == root->parent)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->val.first << "\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(ft::s_map_node<ft::pair<const int, char> >* root)
{
    // Pass initial space count as 0
// std::cout << "goprint_1\n";
    print2DUtil(root, 0);
}


int main()
{
	NS::map<int,char> mymap;

	std::cout << "Is mymap empty? : " << mymap.empty() << std::endl;

	mymap.insert(NS::pair<int, char>(12,'a'));
	mymap.insert(NS::pair<int, char>(5,'b'));
	mymap.insert(NS::pair<int, char>(3,'b'));
	mymap.insert(NS::pair<int, char>(4,'b'));
	mymap.insert(NS::pair<int, char>(10,'b'));
	mymap.insert(NS::pair<int, char>(11,'b'));
	mymap.insert(NS::pair<int, char>(7,'b'));
	mymap.insert(NS::pair<int, char>(6,'b'));
	mymap.insert(NS::pair<int, char>(8,'b'));
	mymap.insert(NS::pair<int, char>(15,'b'));
	mymap.insert(NS::pair<int, char>(13,'b'));
	mymap.insert(NS::pair<int, char>(17,'b'));
	mymap.insert(NS::pair<int, char>(14,'b'));

	std::cout << "Is mymap empty? : " << mymap.empty() << std::endl;


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

	std::cout << "\nTEST AFFICHAGE\n_______________________\n";

	print2DUtil(mymap.get_root(), 0);


	return (0); 
}
