/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:58:51 by dacortes          #+#    #+#             */
/*   Updated: 2024/05/02 08:24:48 by dacortes         ###   ########.fr       */
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
/*                            TEMPLATES                                       */
/******************************************************************************/

template <typename T, typename Func>
void iter(T *array, size_t len, Func f)
{
	if (array == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}
template <typename T>
void iter(T *array, size_t len, void (*f)(const T&))
{
	if (array == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void	funcPrint(const T &element)
{
	std::cout << "pos: " << element << std::endl;
}
#endif
