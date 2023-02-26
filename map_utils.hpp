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

enum class map_node_color : char {BLACK, RED};

template< class value_type >
struct s_map_node 
{

	s_map_node*     parent;
	s_map_node*     left;
	s_map_node*     right;
	value_type      val;
    map_node_color  color;
	bool            is_nil;

	s_node( const value_type & val ) : parent(NULL), left(NULL), right(NULL), root(val), color(BLACK), is_nil(false) {}


    s_map_node* tree_min()
    {
        s_map_node* x = this;
        while (x->left && !x->left->is_nil)
            x = x->left;
        return x;
    }

    s_map_node* tree_max()
    {
        s_map_node* x = this;
        while (x->right && !x->right->is_nil)
            x = x->right;
        return x;
    }

    s_map_node* tree_successor()
    {
        s_map_node* x = this;
        if (x->right && !x->right->is_nil)
            return (x->tree_min());
        s_map_node* y = this->parent;
        while (y && !y->is_nil && (x == y->right))
        {
            x = y;
            y = y->parent;
        }
        return y;   
    }

    s_map_node* tree_predeccessor()
    {
        s_map_node* x = this;
        if (x->left && !x->left->is_nil)
            return (x->tree_max());
        s_map_node* y = this->parent;
        while (y && !y->is_nil && (x == y->left))
        {
            x = y;
            y = y->parent;
        }
        return y;   
    }

};

#endif
