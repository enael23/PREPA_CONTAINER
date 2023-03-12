/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:13:04 by jpauline          #+#    #+#             */
/*   Updated: 2023/02/18 20:46:28 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "test_utils.hpp"
//#include "VECTOR_UC.HPP"
#include <vector>
#include "vector.hpp"


#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void    print(vector<vector<T> >& lst)
{
    for (typename vector<vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
    {
        for (typename vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
            std::cout << *it2 << ' ';
        std::cout << '\n';
    }
}

template <class T>
void    print(vector<T>& lst)
{
    for (typename vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
}


int main ()
{
  vector<int> myvector (3,100);
  vector<int>::iterator it;

std::cout << "BOB_0\n";

//  it = myvector.begin();
//  it = myvector.insert ( it , 200 );

  it = myvector.insert ( myvector.begin() , 200 );

std::cout << "BOB_1\n";

  myvector.insert (it,2,300);

std::cout << "BOB_1.2\n";

  // "it" no longer valid, get a new one:
  it = myvector.begin();

std::cout << "BOB_2" << std::endl;

  vector<int> anothervector (2,400);
std::cout << "BOB_2.2" << std::endl;
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

std::cout << "BOB_3\n";

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

std::cout << "BOB_4\n";

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

