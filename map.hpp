/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:30:27 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/25 17:30:31 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

/*NORME*/
/*
namespace std
{
    template <class Key, class T, class Compare = less<Key>,
    class Allocator = allocator<pair<const Key, T> > >
    class map
    {
        public:
        // types:
        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef pair<const Key, T>                          value_type;
        typedef Compare                                     key_compare;
        typedef Allocator                                   allocator_type;
        typedef typename Allocator::reference               reference;
        typedef typename Allocator::const_reference         const_reference;
        typedef implementation defined                      iterator; // See 23.1
        typedef implementation defined                      const_iterator; // See 23.1
        typedef implementation defined                      size_type; // See 23.1
        typedef implementation defined                      difference_type;// See 23.1
        typedef typename Allocator::pointer                 pointer;
        typedef typename Allocator::const_pointer           const_pointer;
        typedef std::reverse_iterator<iterator>             reverse_iterator;
        typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;

        class value_compare
        : public binary_function<value_type,value_type,bool>
        {
            friend class map;
            
            protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}
            
            public:
            bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
        };
        
        // 23.3.1.1 construct/copy/destroy:
        explicit map(const Compare& comp = Compare(),
        const Allocator& = Allocator());
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
        const Compare& comp = Compare(), const Allocator& = Allocator());
        map(const map<Key,T,Compare,Allocator>& x);
        ~map();
        map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x);
        
        // iterators:
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;
        
        // capacity:
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        
        // 23.3.1.2 element access:
        T& operator[](const key_type& x);
        // modifiers:
        pair<iterator, bool> insert(const value_type& x);
        iterator insert(iterator position, const value_type& x);
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last);
        void erase(iterator position);
        size_type erase(const key_type& x);
        void erase(iterator first, iterator last);
        void swap(map<Key,T,Compare,Allocator>&);
        void clear();
        // observers:
        key_compare key_comp() const;
        value_compare value_comp() const;

        // 23.3.1.3 map operations:
        iterator find(const key_type& x);
        const_iterator find(const key_type& x) const;
        size_type count(const key_type& x) const;
        iterator lower_bound(const key_type& x);
        const_iterator lower_bound(const key_type& x) const;
        iterator upper_bound(const key_type& x);
        const_iterator upper_bound(const key_type& x) const;
        pair<iterator,iterator> equal_range(const key_type& x);
        pair<const_iterator,const_iterator> equal_range(const key_type& x) const;
    };
        
    template <class Key, class T, class Compare, class Allocator>
    bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator< (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator> (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator>=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator<=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
    // specialized algorithms:
    template <class Key, class T, class Compare, class Allocator>
    void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y);
}
*/

#include "map_utils.hpp"
#include "pair.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"


namespace ft 
{

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map 
    {
		
		public :

			typedef Key	                                                        key_type;
			typedef T									                        mapped_type;
			typedef typename ft::pair<const key_type, mapped_type>		        value_type;
			typedef Compare									                    key_compare;
			typedef s_map_node<value_type>							            node;
            typedef typename Alloc::template rebind<node>::other				allocator_type;
			typedef typename allocator_type::reference						    reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
            typedef typename ft::map_iterator<value_type>					    iterator;
			typedef typename ft::const_map_iterator<value_type>				    const_iterator;
			typedef typename ft::reverse_iterator<iterator>					    reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef size_t									                    size_type;
			
			class value_compare 
            {
				private :
					Compare v_comp;
				public :
					value_compare(Compare c) : v_comp(c) {}
					bool operator()(const value_type & x, const value_type & y ) const 
                    { return (v_comp(x.first, y.first)); }
			};

		public :

			node*		        _nil;
			size_type           _size;
			allocator_type      _alloc;
			key_compare         _key_comp;
			value_compare       _value_comp;

			/*
			MEMBER FUNCTIONS
			~~~~~~~~~~~~~~~~
			(constructor)				x
			(destructor)				x
			operator= (assign content)	x
            get_allocator               x
			*/

		public :

            explicit map ( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : 
                _size(0), _alloc(alloc), _key_comp(comp), _value_comp(value_compare(comp))
            {
				_nil = _alloc.allocate(1);
                // _nil->is_nil = true;
                _nil->parent = _nil;
                _nil->left = _nil;
                _nil->right = _nil;
                _nil->is_black = true;
			}

            allocator_type get_allocator() const 
            { return this->_alloc; }
/*
        void _new_nil_node (void)
        {
            _nil = _alloc.allocate(1);
            this->_construct(_nil);
            _nil->color = BLACK_;
        }

        void _construct (node * ptr, const value_type & val = value_type())
        {
            node tmp(val);
            tmp.left = _nil;
            tmp.right = _nil;
            tmp.parent = _nil;
            tmp.color = RED_;
            _alloc.construct(ptr, tmp);
        }
*/

            void insert (const value_type& val)
            {
                node* z = _alloc.allocate(1);

                node tmp(val);
                // tmp.is_nil = false;
                tmp.parent = _nil;
                tmp.left = _nil;
                tmp.right = _nil;
                tmp.is_black = false;

                _alloc.construct(z, tmp);

                node* y = _nil;
                node* x = _nil->left;
                while (x != _nil)
                {
                    y = x;
                    if (_value_comp(z->val, y->val))
                        x = x->left;
                    else 
                        x = x->right;
                }
                z->parent = y;
                if (y == _nil)
                    _nil->left = z;
                else if (_value_comp(z->val, y->val))
                    y->left = z;
                else
                    y->right = z;

                _size++;
            }

			/*
			Iterators:
			~~~~~~~~~~
			begin			x
			end				x
			rbegin			x
			rend			x
			cbegin			x (c++11)
			cendy			x (c++11)
			crbegin			x (c++11)
			crend			x (c++11)
			*/

        	iterator                begin()         { return iterator(this->_nil->right->tree_min()); }
			const_iterator          begin() const   { return const_iterator(this->_nil->right->tree_min()); }
			iterator                end()           { return iterator(this->_nil); }
			const_iterator          end() const     { return const_iterator(this->_nil); }
			reverse_iterator        rbegin()        { return reverse_iterator(this->_nil()); }
			const_reverse_iterator  rbegin() const  { return const_reverse_iterator(this->_nil()); }
			reverse_iterator        rend()          { return reverse_iterator(this->begin()); }
			const_reverse_iterator  rend() const    { return const_reverse_iterator(this->begin()); }

			/*
			Element access:
			~~~~~~~~~~~~~~~
			operator[]		x
			at				x
			*/

            node* get_root()
            { return (_nil->left); }



			/*
			Capacity:
			~~~~~~~~~
			empty			x
            size			x
			max_size		x
			*/
			
            bool empty() const
            {
				if (!_size)
					return true;
				return false;
			}

			size_type size() const
            { return (_size); }

			size_type max_size() const
            { return (_alloc.max_size()); }
			
            /*
			Modifiers:
			~~~~~~~~~~
			clear			x
			insert			x
			erase			x	
			swap			x            
			*/

            /*
            Lookup:
            ~~~~~~~
            count           x
            find            x
            equal_range     x
            lower_bound     x
            upper_bound     x
            */

            /*
            Observers:
            ~~~~~~~~~~
            key_comp        x
            value_comp      x
            */

        

    };

    /*
    Non-member functions:
    ~~~~~~~~~~~~~~~~~~~~~
    operator==
    operator!=
    operator<
    operator<=
    operator>
    operator>=
    swap
    */
}


#endif
