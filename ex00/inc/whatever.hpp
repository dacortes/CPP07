/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:58:51 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/18 15:32:48 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WHATEVER_HPP
# define WHATEVER_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

# include <string>
# include <iostream>
# include <cstdlib>
# include <cerrno>

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

template <typename T>
void swap(T &x, T &y)
{
	T tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T max(T &x, T &y)
{
	return ((x > y) ? x:y);
}

template <typename T>
T min(T &x, T &y)
{
	return ((x < y) ? x:y);
}
#endif
