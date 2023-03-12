/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:19:16 by jpauline          #+#    #+#             */
/*   Updated: 2023/03/11 20:19:46 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_UTILS_HPP
#define SET_UTILS_HPP

// # include <iostream>
#include <cstdio>

namespace ft
{

    template< class value_type >
    struct s_set_node 
    {

        s_set_node*         parent;
        s_set_node*         left;
        s_set_node*         right;
        value_type          val;
        bool                is_black;

        s_set_node( const value_type& n_val ) : parent(NULL), left(NULL), right(NULL), val(n_val), is_black(true) {}


        s_set_node* tree_min()
        {
            s_set_node* x = this;
            while (x->left != x->left->parent)                               // initial NIL CHECK
                x = x->left;
            return x;
        }

        s_set_node* tree_max()
        {
            s_set_node* x = this;
            while (x->right != x->right->parent)                             // initial NIL CHECK
                x = x->right;
            return x;
        }

        s_set_node* tree_successor()
        {
            s_set_node* x = this;
            if (x->right != x->right->parent)
                return (x->right->tree_min());
            s_set_node* y = this->parent;
            while (y != y->parent && (x == y->right))                        // initial NIL CHECK
            {
                x = y;
                y = y->parent;
            }
            return y;   
        }

        s_set_node* tree_predecessor()
        {
            s_set_node* x = this;
            if (x->left != x->left->parent)
                return (x->left->tree_max());
            s_set_node* y = this->parent;
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
