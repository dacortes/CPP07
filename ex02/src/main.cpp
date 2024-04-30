/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:36:52 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/30 15:48:01 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    std::srand(static_cast<unsigned int>(std::clock()));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
        if (!(numbers[i] == mirror[i]))
        {
            std::cout << "Not equal" << std::endl;
            break;
        }
    }
    std::cout << "Arrays are equal" << std::endl;

    //SCOPE
     {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] != test[i])
            {
                std::cout << "Not equal" << std::endl;
                break;
            }
        }
        std::cout << "Arrays are equal" << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    Array<int> new_to_copy;
    Array<int> *test = new Array<int>(50);

    for (int i = 0; i < 50; i++)
    {
        const int value = std::rand();
        (*test)[i] = value;
    }

    new_to_copy = *test;
    for (int i = 0; i < 50; i++)
    {
        if (new_to_copy[i] != (*test)[i])
        {
            std::cout << "Not equal" << std::endl;
            break;
        }
    } 
    std::cout << "Finished checking before deleting test" << std::endl;
    delete [] mirror;
    delete test;
    for (int i = 0; i < 50 ; i++)
        std::cout << new_to_copy[i] << std::endl;
    std::cout << "Finished priting after deleting test" << std::endl;
    return (EXIT_SUCCESS);
}
