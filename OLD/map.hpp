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
#include "lexicographical_compare.hpp"


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

            // typedef typename Alloc::template rebind<node>::other				allocator_type;
			// typedef typename allocator_type::reference						    reference;
			// typedef typename allocator_type::const_reference					const_reference;
			// typedef typename allocator_type::pointer							pointer;
			// typedef typename allocator_type::const_pointer						const_pointer;

			typedef typename Alloc::reference						            reference;
			typedef typename Alloc::const_reference					            const_reference;
			typedef typename Alloc::pointer							            pointer;
			typedef typename Alloc::const_pointer						        const_pointer;
            typedef typename Alloc::template rebind<node>::other				allocator_type;

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
			(constructor)				empty   v   range   NOK     copy    v
			(destructor)				v
			operator= (assign content)	v
            get_allocator               v
			*/

		public :

            explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : 
                _size(0), _alloc(alloc), _key_comp(comp), _value_comp(value_compare(comp))
            {
				_nil = _alloc.allocate(1);
                _nil->parent = _nil;
                _nil->left = _nil;
                _nil->right = _nil;
                _nil->is_black = true;
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
                _size(0), _alloc(alloc), _key_comp(comp), _value_comp(value_compare(comp))
            {
				_nil = _alloc.allocate(1);
                _nil->parent = _nil;
                _nil->left = _nil;
                _nil->right = _nil;
                _nil->is_black = true;
				insert(first, last);
			}

			map(const map &x) : 
                _size(0), _alloc(x.get_allocator()), _key_comp(x.key_comp()), _value_comp(x.value_comp())
            {
				_nil = _alloc.allocate(1);
                _nil->parent = _nil;
                _nil->left = _nil;
                _nil->right = _nil;
                _nil->is_black = true;
				insert(x.begin(), x.end());
			}

			map& operator=(const map& x)
            {
				clear();
				insert(x.begin(), x.end());
				return *this;
			}

            ~map()
            {
// std::cout << "DESTROYER";
                if (_size)
                    clear();
                // _alloc.destroy(_nil);
                _alloc.deallocate(_nil, 1);
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



			/*
			Iterators:
			~~~~~~~~~~
			begin			v   const   v
			end				v   const   v
			rbegin			v   const   v
			rend			v   const   v
			cbegin			x (c++11)
			cendy			x (c++11)
			crbegin			x (c++11)
			crend			x (c++11)
			*/

        	// iterator                begin()         { return iterator(this->_nil->right->tree_min()); }
			// const_iterator          begin() const   { return const_iterator(this->_nil->right->tree_min()); }

        	iterator                begin()         { return iterator(this->_nil->tree_min()); }
			const_iterator          begin() const   { return const_iterator(this->_nil->tree_min()); }

			iterator                end()           { return iterator(this->_nil); }
			const_iterator          end() const     { return const_iterator(this->_nil); }
			reverse_iterator        rbegin()        { return reverse_iterator(this->_nil); }
			const_reverse_iterator  rbegin() const  { return const_reverse_iterator(this->_nil); }
			reverse_iterator        rend()          { return reverse_iterator(this->begin()); }
			const_reverse_iterator  rend() const    { return const_reverse_iterator(this->begin()); }

			/*
			Element access:
			~~~~~~~~~~~~~~~
			operator[]		v
			at				v   const   v
			*/

            mapped_type& operator[](const key_type& k)
            { return (this->insert(ft::make_pair(k, mapped_type()))).first->second; }

			mapped_type& at(const key_type& k )
            {
				iterator it = find(k);
				if (it != _nil)
					return it->second;
				else
					throw std::out_of_range("map::at : out of range exception");
			}

			const mapped_type& at(const key_type& k) const
            {
				const_iterator it = find(k);
				if (it != _nil)
					return it->second;
				else
					throw std::out_of_range("map::at : out of range exception");
			}


			/*
			Capacity:
			~~~~~~~~~
			empty			v
            size			v
			max_size		v
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
			clear			v
			insert			single  v   hint    v   range   v
			erase			ite     v   key     v   range   v   	
			swap			NOK            
			*/

            void clear()
            {
// std::cout << "CLEAR";
                clear_node(_nil->left);
                _nil->left = _nil;
                _size = 0;
            }

            ft::pair<iterator, bool> insert(const value_type& val)
            {
                iterator it = find(val.first);
                if (it == end())
                    return (ft::pair<iterator, bool>(iterator(new_insert(val)), true));
                return (ft::pair<iterator, bool>(it, false));    
			}

			iterator insert(iterator position, const value_type& val)
            {
				(void)position;
				return (insert(val).first);
			}

			template <class InputIterator>
			void insert( InputIterator first, InputIterator last )
            {
				for (; first != last; first++)
					insert(*first);
			}


            void erase(iterator position)
            {
// std::cout << "ERASE IT\n";
                if (position != end())
                {
                    node* node = position.base();
                    RB_delete(node);
                    _size--;
                    _alloc.destroy(node);
                    _alloc.deallocate(node, 1);
                }
            }

            size_type erase(const key_type& k)
            {
// std::cout << "ERASE KEY " << k << "\n";
                iterator it = find(k);
                if (it == end())
                    return(0);
                erase(it);
                return(1);
            }

            void erase(iterator first, iterator last)
            {
// std::cout << "ERASE RANGE\n";
                for (; first != last; )
					erase(first++);
				// return last;
            }

			void swap(map & x)
            {
				if (*this == x)
					return ;

				node* tmp;

				tmp = x._nil;
				x._nil = this->_nil;
				this->_nil = tmp;

				size_type tmp_size; 
                tmp_size = x._size;
				x._size = this->_size;
				this->_size = tmp_size;
			}

            /*
            Lookup:
            ~~~~~~~
            find            v   const   v
            count           v
            lower_bound     v   const   v
            upper_bound     v   const   v
            equal_range     v
            */

            iterator find (const key_type& k)
            {
// std::cout << "FIND" << k << "\n";                
                node* tmp = _nil->left;

                while(tmp != _nil && !_is_equal(k, tmp->val.first))
                {
                	if (key_compare()(k, tmp->val.first))
						tmp = tmp->left;
					else
						tmp = tmp->right;    
                }
                if (tmp == _nil)
// {
// std::cout << "NOT FOUND " << k << "\n";
                    return(end());
// }
// std::cout << "FOUND " << k << "\n";
                return(iterator(tmp));
            }
            
            const_iterator find (const key_type& k) const
            {
                node* tmp = _nil->left;

                while(tmp != _nil && !_is_equal(k, tmp->val.first))
                {
                	if (key_compare()(k, tmp->val.first))
						tmp = tmp->left;
					else
						tmp = tmp->right;    
                }
                if (tmp == _nil)
                    return(_nil);
                return(const_iterator(tmp));
            }

            size_type count(const key_type & k) const
            {
				if (find(k) != _nil)
					return 1;
				return 0;
			}

            iterator lower_bound (const key_type& k)
            {
                node* tmp = _nil->left;
                node* result = _nil;//->left;

                while (tmp != _nil)
                {
                    if(!key_compare()(tmp->val.first, k))
                    {
                        result = tmp;
                        tmp = tmp->left;
                    }
                    else
                        tmp = tmp->right;
                }
                return (iterator(result));
            }

            const_iterator lower_bound (const key_type& k) const
            {
                node* tmp = _nil->left;
                node* result = _nil;//->left;

                while (tmp != _nil)
                {
                    if(!key_compare()(tmp->val.first, k))
                    {
                        result = tmp;
                        tmp = tmp->left;
                    }
                    else
                        tmp = tmp->right;
                }
                return (const_iterator(result));
            }

            iterator upper_bound (const key_type& k)
            {
                if (!key_compare()(k, _nil->left->tree_max()->val.first))
                    return(iterator(_nil));

                node* tmp = _nil->left;
                node* result = _nil->left;

                while (tmp != _nil)
                {
                    if(key_compare()(k, tmp->val.first))
                    {
                        result = tmp;
                        tmp = tmp->left;
                    }
                    else
                        tmp = tmp->right;
                }
                return (iterator(result));
            }

            const_iterator upper_bound (const key_type& k) const
            {
                if (!key_compare()(k, _nil->left->tree_max()->val.first))
                    return(const_iterator(_nil));

                node* tmp = _nil->left;
                node* result = _nil->left;

                while (tmp != _nil)
                {
                    if(key_compare()(k, tmp->val.first))
                    {
                        result = tmp;
                        tmp = tmp->left;
                    }
                    else
                        tmp = tmp->right;
                }
                return (const_iterator(result));
            }

			ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
            { return (ft::make_pair(lower_bound(k), upper_bound(k))); }

			ft::pair<iterator, iterator> equal_range(const key_type& k)
            { return (ft::make_pair(lower_bound(k), upper_bound(k))); }


            /*
            Observers:
            ~~~~~~~~~~
            key_comp        v
            value_comp      v
            */

            key_compare key_comp() const
            { return (_key_comp); }

			value_compare value_comp() const
            { return this->_value_comp; }

            /*
            Utils private member functions:
            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            */



        // private :
        public :    // For tests with tree display

node* get_root()
{ return (_nil->left); }

			bool _is_equal(const key_type & val1, const key_type & val2) const
            { return (!key_compare()(val1, val2) && !key_compare()(val2, val1)); }

            /*
            RED-BLACK Tree functions:
            ~~~~~~~~~~~~~~~~~~~~~~~~~
            */
            
            // void insert (const value_type& val)
            // {
            //     node* z = _alloc.allocate(1);

            //     node tmp(val);
            //     // tmp.is_nil = false;
            //     tmp.parent = _nil;
            //     tmp.left = _nil;
            //     tmp.right = _nil;
            //     tmp.is_black = false;

            //     _alloc.construct(z, tmp);

            //     node* y = _nil;
            //     node* x = _nil->left;
            //     while (x != _nil)
            //     {
            //         y = x;
            //         if (_value_comp(z->val, y->val))
            //             x = x->left;
            //         else 
            //             x = x->right;
            //     }
            //     z->parent = y;
            //     if (y == _nil)
            //         _nil->left = z;
            //     else if (_value_comp(z->val, y->val))
            //         y->left = z;
            //     else
            //         y->right = z;

            //     _size++;
            // }

            void left_rotate(node* x)
            {
                node* y = x->right;                  // set y
                // if (y == _nil)
                // {
                //     std::cout << "\033[91m" << "IMPOSSIBLE LEFT ROTATE" << "\033[0m" << "\n";
                //     return;
                // }
                x->right = y->left;                 // turn y's left subtree into x's right subtree
                if (y->left != _nil)
                    y->left->parent = x;
                y->parent = x->parent;              // links x's parent to y
                if (x->parent == _nil)
                    _nil->left = y;
                else if (x == x->parent->left)
                    x->parent->left = y;
                else 
                    x->parent->right = y;
                y->left = x;                        // put x on y's left
                x->parent = y;
            }

            void right_rotate(node* x)
            {
                node* y = x->left;                  // set y
                // if (y == _nil)
                // {
                //     std::cout << "\033[91m" << "IMPOSSIBLE RIGHT ROTATE" << "\033[0m" << "\n";
                //     return;
                // }
                x->left = y->right;                 // turn y's left subtree into x's right subtree
                if (y->right != _nil)
                    y->right->parent = x;
                y->parent = x->parent;              // links x's parent to y
                if (x->parent == _nil)
                    _nil->left = y;
                else if (x == x->parent->right)
                    x->parent->right = y;
                else 
                    x->parent->left = y;
                y->right = x;                        // put x on y's right
                x->parent = y;
            }

            node* new_insert(const value_type& val)
            {
                node* z = _alloc.allocate(1);

                node tmp(val);
                // tmp.is_nil = false;
                tmp.parent = _nil;
                tmp.left = _nil;
                tmp.right = _nil;
                tmp.is_black = false;

                _alloc.construct(z, tmp);
                RB_insert(z);
                _size++;
                return (z);
            }

            void RB_insert(node* z)
            {
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
                // z->left = _nil;
                // z->right = _nil;
                // z->is_black = false;
                RB_insert_fixup(z);
            }

            void RB_insert_fixup(node* z)
            {
                node* y;
                while (z->parent->is_black == false)
                {
                    if (z->parent == z->parent->parent->left)
                    {
                        y = z->parent->parent->right;
                        if (y->is_black == false)
                        {
                            z->parent->is_black = true;             //case 1 z's UNCLE is RED
                            y->is_black = true;                     //case 1 z's UNCLE is RED
                            z->parent->parent->is_black = false;    //case 1 z's UNCLE is RED
                            z = z->parent->parent;                  //case 1 z's UNCLE is RED
                        }
                        else 
                        {
                            if (z == z->parent->right)
                            {
                                z = z->parent;                      //case 2 z's UNCLE is BLACK, z is right           
                                left_rotate(z);                     //case 2 z's UNCLE is BLACK, z is right 
                            }
                            z->parent->is_black = true;             //case 3 z's UNCLE is BLACK, z is left 
                            z->parent->parent->is_black = false;    //case 3 z's UNCLE is BLACK, z is left 
                            right_rotate(z->parent->parent);        //case 3 z's UNCLE is BLACK, z is left 
                        }
                    }
                    else                                            //SYMMETRICAL
                    {
                        y = z->parent->parent->left;
                        if (y->is_black == false)
                        {
                            z->parent->is_black = true;
                            y->is_black = true;
                            z->parent->parent->is_black = false;
                            z = z->parent->parent;
                        }
                        else 
                        {
                            if (z == z->parent->left)
                            {
                                z = z->parent;
                                right_rotate(z);
                            }
                            z->parent->is_black = true;
                            z->parent->parent->is_black = false;
                            left_rotate(z->parent->parent);
                        }
                    }
                }
                _nil->left->is_black = true;
            }

            void RB_transplant(node* u, node*v)
            {
                if (u->parent == _nil)
                    _nil->left = v;
                else if (u == u->parent->left)
                    u->parent->left = v;
                else
                    u->parent->right = v;
                v->parent = u->parent; 
            }

            void RB_delete(node* z)
            {
// std::cout << "RB_DELETE " << z->val.first << "\n";
                node* x;
                node* y = z;
                bool y_original_is_black = y->is_black;
                if (z->left == _nil)
                {
                    x = z->right;
                    RB_transplant(z, z->right);
                }
                else if (z->right == _nil)
                {
                    x = z->left;
                    RB_transplant(z, z->left);
                }
                else
                {
                    y = z->right->tree_min();
                    y_original_is_black = y->is_black;
                    x = y->right;
                    if (y->parent == z)
                        x->parent = y;
                    else
                    {
                        RB_transplant(y, y->right);
                        y->right = z->right;
                        y->right->parent = y;
                    }
                    RB_transplant(z, y);
                    y->left = z->left;
                    y->left->parent = y;
                    y->is_black = z->is_black;
                }
                if (y_original_is_black == true)
                    RB_delete_fixup(x);
                _nil->parent = _nil;                // _nil might be altered in the process if x = _nil
                // _nil->is_black = true;
                // _nil->right = _nil;
            }

            void RB_delete_fixup(node* x)
            {
                node* w;
// std::cout << "RB_DELETE_FIXUP\n";
                while (x != _nil->left && x->is_black == true)
                {
                    if (x == x->parent->left)
                    {
                        w = x->parent->right;
                        if (w->is_black == false)
                        {
                            w->is_black = true;                     // CASE 1
                            x->parent->is_black = false;            // CASE 1
                            left_rotate(x->parent);                 // CASE 1
                            w = x->parent->right;                   // CASE 1
                        }
                        if (w->left->is_black == true && w->right->is_black == true)
                        {
                            w->is_black = false;                    // CASE 2
                            x = x->parent;                          // CASE 2
                        }
                        else
                        {
                            if (w->right->is_black == true)
                            {
                                w->left->is_black = true;           // CASE 3
                                w->is_black = false;                // CASE 3
                                right_rotate(w);                    // CASE 3
                                w = x->parent->right;               // CASE 3
                            }
                            w->is_black = x->parent->is_black;      // CASE 4
                            x->parent->is_black = true;             // CASE 4
                            w->right->is_black = true;              // CASE 4
                            left_rotate(x->parent);                 // CASE 4
                            x = _nil->left; // root                 // CASE 4
                        }
                    }
                    else
                    {
                        w = x->parent->left;
                        if (w->is_black == false)
                        {
                            w->is_black = true;                     // CASE 1
                            x->parent->is_black = false;            // CASE 1
                            right_rotate(x->parent);                // CASE 1
                            w = x->parent->left;                    // CASE 1
                        }
                        if (w->right->is_black == true && w->left->is_black == true)
                        {
                            w->is_black = false;                    // CASE 2
                            x = x->parent;                          // CASE 2
                        }
                        else
                        {
                            if (w->left->is_black == true)
                            {
                                w->right->is_black = true;          // CASE 3
                                w->is_black = false;                // CASE 3
                                left_rotate(w);                     // CASE 3
                                w = x->parent->left;                // CASE 3
                            }
                            w->is_black = x->parent->is_black;      // CASE 4
                            x->parent->is_black = true;             // CASE 4
                            w->left->is_black = true;               // CASE 4
                            right_rotate(x->parent);                // CASE 4
                            x = _nil->left; // root                 // CASE 4
                        }
                    }
                }
                x->is_black = true;
            }

            void clear_node(node* n)
            {
                if (n != _nil)
                {
// std::cout << "clear node key = " << n->val.first;
                    clear_node(n->left);
                    clear_node(n->right);
                    _alloc.destroy(n);
                    _alloc.deallocate(n, 1);
                }
            }

    };


    /*
    Non-member functions:
    ~~~~~~~~~~~~~~~~~~~~~
    operator==      NOK
    operator!=      NOK
    operator<       NOK
    operator<=      NOK
    operator>       NOK
    operator>=      NOK
    swap            NOK
    */

   	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{
        if (lhs.size() != rhs.size())
			return false; 
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{ return (!(lhs == rhs)); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{ return (!(rhs < lhs)); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{ return (rhs < lhs); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{ return (!(lhs < rhs)); }

	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key,T,Compare,Alloc> & x, map<Key,T,Compare,Alloc> & y)
	{ x.swap(y); }

}


#endif
