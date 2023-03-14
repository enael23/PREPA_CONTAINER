/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:47:19 by jpauline          #+#    #+#             */
/*   Updated: 2023/03/13 20:49:49 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "set.hpp"
#include <set>

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
 
int height(ft::s_set_node<ft::pair<const int, char> >* root) 
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
 
void printTree(int **M, ft::s_set_node<ft::pair<const int, char> >* root, int col, int row, int height) 
{
    if (root == root->parent)
        return;
    M[row][col] = root->val.first;
    printTree(M, root->left, col - pow(2, height - 2), row + 1, height - 1);
    printTree(M, root->right, col + pow(2, height - 2), row + 1, height - 1);
}
 
void TreePrinter(ft::s_set_node<ft::pair<const int, char> >* root) 
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

void print_list (NS::set<int> & myset)
{
	std::cout << "Check list      : ";
	for (NS::set<int>::iterator it = myset.begin(); it!=myset.end();it++)
		std::cout << *it << " ";
	std::cout << "\n";
}

int main()
{
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


	NS::set<int>::iterator it;
	it = myset.begin();


	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";


	std::cout << "\n-----------\nTEST BOUCLE\n-----------\n";
	// myset.iterator it2;
	NS::set<int>::iterator it2, end2;
	it2 = myset.begin();
	end2 = myset.end();
	for (;it2!=end2;it2++)
		std::cout << *it2 << " ";
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
	for (NS::set<int>::iterator it = myset.begin(); it!=myset.end();it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "Check list rev  : ";
	for (NS::set<int>::reverse_iterator it = myset.rbegin(); it!=myset.rend();it++)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << "\n-----------\nTEST ERASE\n-----------\n";
	std::cout << "Erase 10      - "; myset.erase(10); print_list(myset);

	// std::cout << "Ceck list      : ";
	// for (NS::set<int>::iterator it = myset.begin(); it!=myset.end();it++)
	// 	std::cout << *it << " ";
	// std::cout << "\n";

	// std::cout << "Erase 30\n"; myset.erase(30); std::cout << "DONE"; print_list(myset);
	std::cout << "Erase first   - "; myset.erase(myset.begin()); print_list(myset);

	// std::cout << "Ceck list      : ";
	// for (NS::set<int>::iterator it = myset.begin(); it!=myset.end();it++)
	// 	std::cout << *it << " ";
	// std::cout << "\n";

	NS::set<int>::iterator it3 = myset.begin();
	it3++;
	it3++;
	std::cout << "Erase third   - "; myset.erase(it3); print_list(myset);


	// 	std::cout << "Ceck list      : ";
	// for (NS::set<int>::iterator it = myset.begin(); it!=myset.end();it++)
	// 	std::cout << *it << " ";
	// std::cout << "\n";

	// std::cout << "\n--------------\nTEST AFFICHAGE\n--------------\n";

	// TreePrinter(myset.get_root());




	return (0); 
}
