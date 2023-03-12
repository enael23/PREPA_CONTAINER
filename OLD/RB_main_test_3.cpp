/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_main_test_3.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:47:19 by jpauline          #+#    #+#             */
/*   Updated: 2023/03/12 18:08:19 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "map.hpp"
#include "pair.hpp"
#include <map>


#ifndef NS
# define NS ft
#endif


#define RESET   "\033[0m"
#define RED     "\033[91m"      /* Red */


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
 
void printTree(ft::pair<int, bool> **M, ft::s_map_node<ft::pair<const int, char> >* root, int col, int row, int height) 
{
    if (root == root->parent)
        return;
    M[row][col].first = root->val.first;
    M[row][col].second = root->is_black;
    printTree(M, root->left, col - pow(2, height - 2), row + 1, height - 1);
    printTree(M, root->right, col + pow(2, height - 2), row + 1, height - 1);
}
 
void TreePrinter(ft::s_map_node<ft::pair<const int, char> >* root) 
{
    int h = height(root);
    int col = getcol(h);
    ft::pair<int,bool> **M = new ft::pair<int, bool>*[h];
    for (int i = 0; i < h; i++) 
        M[i] = new ft::pair<int, bool>[col];
    printTree(M, root, col / 2, 0, h);
    for (int i = 0; i < h; i++) 
	{
        for (int j = 0; j < col; j++) 
		{
            if (M[i][j].first == 0)
                cout << " " << " ";
            else if (M[i][j].second == true)
                cout << M[i][j].first << " ";
			else
                cout << RED << M[i][j].first << RESET << " ";
                //cout << "\033[91m" << M[i][j].first << "\033[0m" << " ";
        }
        cout << endl;
    }
}


int main()
{
	NS::map<int,char> mymap;
/*
	mymap.insert(NS::pair<int, char>(12,'a'));
	std::cout << "\n\nInsert 12 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(5,'b'));
	std::cout << "\n\nInsert 5 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(3,'b'));
	std::cout << "\n\nInsert 3 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(4,'b'));
	std::cout << "\n\nInsert 4 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(10,'c'));
	std::cout << "\n\nInsert 10 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(11,'b'));
	std::cout << "\n\nInsert 11 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(7,'b'));
	std::cout << "\n\nInsert 7 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(6,'b'));
	std::cout << "\n\nInsert 6 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(8,'b'));
	std::cout << "\n\nInsert 8 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(15,'b'));
	std::cout << "\n\nInsert 15 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(13,'b'));
	std::cout << "\n\nInsert 13 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(17,'b'));
	std::cout << "\n\nInsert 17 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(14,'b'));
	std::cout << "\n\nInsert 14 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(14,'b'));
	std::cout << "\n\nInsert 14 :\n";
	TreePrinter(mymap.get_root());

	// NS::map<int,char> mymap2;
	// std::cout << "\n~~~~~~~~~~~~~~~~~\nSORTED INSERTIONS\n~~~~~~~~~~~~~~~~~~~~\n";
	// for (int i = 1; i < 30; i++)
	// {
	// 	std::cout << "\n\nInsert : " << i << "\n";
	// 	mymap2.insert(NS::pair<int, char>(i,'b'));
	// 	TreePrinter(mymap2.get_root());
	// }

	std::cout << "\n~~~~~~~~~~~~~~~~~\nTEST RB_DELET\n~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "RB_delete du 3 :\n";
	// mymap.RB_delete(mymap._nil->left->left->left);
	mymap.RB_delete(((mymap.find(3)).base()));
	TreePrinter(mymap.get_root());
	std::cout << "Ceck list      : ";
	for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
		std::cout << it->first << " ";
	std::cout << "\n";
	std::cout << "Ceck list rev  : ";
	for (NS::map<int,char>::reverse_iterator it = mymap.rbegin(); it!=mymap.rend();it++)
		std::cout << it->first << " ";
	std::cout << "\n";
	
	std::cout << "RB_delete du 13 :\n";
	// mymap.RB_delete(mymap._nil->left->left);
	// mymap.RB_delete(((mymap.find(5)).base()));
	mymap.RB_delete(((mymap.find(13)).base()));

	TreePrinter(mymap.get_root());
	std::cout << "done\n";

	std::cout << "Root key = " << mymap._nil->left->val.first << "\n";
	std::cout << "Root->left key = " << mymap._nil->left->left->val.first << "\n";
	std::cout << "Root->left->left key = " << mymap._nil->left->left->left->val.first << "\n";
	std::cout << "est-ce que Rlll est _nil? " << (mymap._nil->left->left->left->left == mymap._nil) << "\n";
	std::cout << "est-ce que Rllr est _nil? " << (mymap._nil->left->left->left->right == mymap._nil) << "\n";

	std::cout << "est-ce que nil->parent == nil? " << (mymap._nil->parent == mymap._nil) << "\n";
	std::cout << "nil->parent key ? " << (mymap._nil->parent->val.first) << "\n";

	NS::map<int,char>::iterator it_test = mymap.begin();
	std::cout << "begin est : " << it_test->first << "\n"; 

	std::cout << "Ceck list      : ";
	for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
		std::cout << it->first << " ";
	std::cout << "\n";
	std::cout << "Ceck list rev  : ";
	for (NS::map<int,char>::reverse_iterator it = mymap.rbegin(); it!=mymap.rend();it++)
		std::cout << it->first << " ";
	std::cout << "\n";

	TreePrinter(mymap.get_root());

	std::cout << "RB_delete du 13 :\n";
	// mymap.RB_delete(mymap._nil->left);
	mymap.RB_delete(((mymap.find(13)).base()));
	TreePrinter(mymap.get_root());
	std::cout << "Ceck list      : ";
	for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
		std::cout << it->first << " ";
	std::cout << "\n";
	std::cout << "Ceck list rev  : ";
	for (NS::map<int,char>::reverse_iterator it = mymap.rbegin(); it!=mymap.rend();it++)
		std::cout << it->first << " ";
	std::cout << "\n";

	std::cout << "RB_delete du 17 :\n";
	// mymap.RB_delete(mymap._nil->left->tree_max());
	mymap.RB_delete(((mymap.find(17)).base()));
	TreePrinter(mymap.get_root());
	std::cout << "Ceck list      : ";
	for (NS::map<int,char>::iterator it = mymap.begin(); it!=mymap.end();it++)
		std::cout << it->first << " ";
	std::cout << "\n";
	std::cout << "Ceck list rev  : ";
	for (NS::map<int,char>::reverse_iterator it = mymap.rbegin(); it!=mymap.rend();it++)
		std::cout << it->first << " ";
	std::cout << "\n";
*/

	
	mymap.insert(NS::pair<int, char>(1,'a'));
	std::cout << "\n\nInsert 5 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(48,'a'));
	std::cout << "\n\nInsert 5 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(78,'a'));
	std::cout << "\n\nInsert 5 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(-666,'a'));
	std::cout << "\n\nInsert 5 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(28,'a'));
	std::cout << "\n\nInsert 5 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(60,'a'));
	std::cout << "\n\nInsert 5 :\n";
	TreePrinter(mymap.get_root());
	mymap.insert(NS::pair<int, char>(39,'a'));
	std::cout << "\n\nInsert 5 :\n";
	TreePrinter(mymap.get_root());

	return (0); 
}
