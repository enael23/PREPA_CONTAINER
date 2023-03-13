/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:02:55 by jpauline          #+#    #+#             */
/*   Updated: 2023/03/11 21:04:10 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

int		main(void)
{
	ft::set<int> const st;
	ft::set<int>::iterator it = st.begin(); // <-- no error, actually ! set allows for const_iterator => iterator conversion

	(void)it;
	return (0);
}

