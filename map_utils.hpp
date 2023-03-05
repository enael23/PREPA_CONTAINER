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

# include <iostream>

namespace ft
{

    // enum class map_node_color : char {BLACK, RED};

    template< class value_type >
    struct s_map_node 
    {

        s_map_node*     parent;
        s_map_node*     left;
        s_map_node*     right;
        value_type      val;
        // map_node_color  color;
        bool            is_black;
        // bool            is_nil;

        s_map_node( const value_type & n_val ) : parent(NULL), left(NULL), right(NULL), val(n_val), is_black(true) {}


        s_map_node* tree_min()
        {
// std::cout << "BOB min\n";
            s_map_node* x = this;
            // while (x->left && !x->left->is_nil)
            while (x->left != x->left->parent)

                x = x->left;
            return x;
        }

        s_map_node* tree_max()
        {
            s_map_node* x = this;
            // while (x->right && !x->right->is_nil)
            while (x->right != x->right->parent)
                x = x->right;
            return x;
        }

        s_map_node* tree_successor()
        {
// std::cout << "BOB successor\n";
            s_map_node* x = this;
            // if (x->right && !x->right->is_nil)
            if (x->right != x->right->parent)
                return (x->right->tree_min());
            s_map_node* y = this->parent;
            // while (y && !y->is_nil && (x == y->right))
// std::cout << "x = " << x->val.first << ", y = " << y->val.first << "\n";
            while (y != y->parent && (x == y->right))
            {
                x = y;
                y = y->parent;
// std::cout << "x = " << x->val.first << ", y = " << y->val.first << "\n";
            }
            return y;   
        }

        s_map_node* tree_predecessor()
        {
            s_map_node* x = this;
            // if (x->left && !x->left->is_nil)
            if (x->left != x->left->parent)
                return (x->left->tree_max());
            s_map_node* y = this->parent;
            // while (y && !y->is_nil && (x == y->left))
            while (y != y->parent && (x == y->left))
            {
                x = y;
                y = y->parent;
            }
            return y;   
        }

    };
}

#endif
