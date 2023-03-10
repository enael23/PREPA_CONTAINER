/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:10:14 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/26 18:10:50 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_HPP
# define MAP_UTILS_HPP

// # include <iostream>
#include <cstdio>

namespace ft
{

    template< class value_type >
    struct s_map_node 
    {

        s_map_node*     parent;
        s_map_node*     left;
        s_map_node*     right;
        value_type      val;
        bool            is_black;

        s_map_node( const value_type & n_val ) : parent(NULL), left(NULL), right(NULL), val(n_val), is_black(true) {}

        s_map_node* tree_min()
        {
            s_map_node* x = this;
            while (x->left != x->left->parent)                               // initial NIL CHECK
                x = x->left;
            return x;
        }

        s_map_node* tree_max()
        {
            s_map_node* x = this;
            while (x->right != x->right->parent)                             // initial NIL CHECK
                x = x->right;
            return x;
        }

        s_map_node* tree_successor()
        {
            s_map_node* x = this;
            if (x->right != x->right->parent)
                return (x->right->tree_min());
            s_map_node* y = this->parent;
            while (y != y->parent && (x == y->right))                        // initial NIL CHECK
            {
                x = y;
                y = y->parent;
            }
            return y;   
        }

        s_map_node* tree_predecessor()
        {
            s_map_node* x = this;
            if (x->left != x->left->parent)
                return (x->left->tree_max());
            s_map_node* y = this->parent;
            while (y != y->parent && (x == y->left))                         // initial NIL CHECK
            {
                x = y;
                y = y->parent;
            }
            return y;   
        }

    };
}

#endif
