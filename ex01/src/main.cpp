/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:02:26 by dacortes          #+#    #+#             */
/*   Updated: 2024/05/02 08:26:58 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/iter.hpp"

/******************************************************************************/
/*                            COLORS                                          */
/******************************************************************************/

# define E "\033[m"                 //end
# define R "\033[1m\033[1;31m"      //red
# define G "\033[1m\033[1;32m"      //green
# define Y "\033[1m\033[1;33m"      //yellow
# define B "\033[1;34m"             //blue
# define T "\033[1m\033[1;35m"      //Turquesa
# define C "\033[1;36m"             //Cyan
# define O "\033[1m\033[38;5;208m"  //orange
# define F "\033[1m\033[38;5;128m"  //purple

/******************************************************************************/
/*                            MACROS                                          */
/******************************************************************************/

# define SIZE_INT 4
# define SIZE_STRING 24

int main (void)
{
	int arrayInt[] = {1, 2, 3, 4, 5, 6};
	std::string arrayString[] = {"foo", "fuu", "fui", "fiu"};
	size_t sizeArrayInt = sizeof(arrayInt) / SIZE_INT;
	size_t sizeArrayString = sizeof(arrayString) / SIZE_STRING;
	std::cout << "sizestring: " << sizeArrayString << std::endl;
	std::cout << O << "Test Array Int" << E << std::endl;
	::iter(arrayInt, sizeArrayInt, ::funcPrint<int>);
	std::cout << O << "Test Array string" << E << std::endl;
	::iter(arrayString, sizeArrayString, ::funcPrint<std::string>);
	return (EXIT_SUCCESS);
}

