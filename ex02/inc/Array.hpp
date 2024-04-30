/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:38:18 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/30 10:58:10 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
# define ARRAY_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

# include <string>
# include <cerrno>
# include <cstdlib>
# include <iostream>

/******************************************************************************/
/*                            COLORS                                          */
/******************************************************************************/

# define E "\033[m"                 //end
# define R "\033[1m\033[1;31m"    	//red
# define G "\033[1m\033[1;32m"    	//green
# define Y "\033[1m\033[1;33m"    	//yellow
# define B "\033[1;34m"    			//blue
# define C "\033[1;36m"				//Cyan
# define O "\033[1m\033[38;5;208m"	//orange
# define F "\033[38;5;128m"			//purple

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

# define ERROR "\033[1m\033[1;31mError: \033[m"
# define ERROR_SF "Segmentation fault"
# define ERROR_INDEX "array index past the end of the array"
template <class T>
class Array
{
	private:
		T	*_array;
		unsigned int _size;
	public:
		/*
		* Orthodox Canonical Form
		*/
		Array(void): _array(NULL), _size(0)
		{
			std::cout << "Default constructor called" << std::endl;
		}
		Array(unsigned int n): _size(n)
		{
			std::cout << "Init constructor called" << std::endl;
			if (_size)
			{
				this->_array = new T[n];
				for (unsigned int i = 0; i < n; ++i)
					this->_array[i] = 0;
			}
		}
		Array(const Array& obj): _size(obj._size)
		{
			std::cout << "Copy constructor called" << std::endl;
			if (obj._array)
			{
				this->_array = new T[obj._size];
				for (unsigned int i = 0; i < obj._size; ++i)
					this->_array[i] = obj._array[i];
			}
		}
		~Array(void)
		{
			std::cout << "Destructor called" << std::endl;
			if (this->_array)
				delete [] this->_array;
		}
		/*
		* Funtions
		*/
		Array &operator=(const Array& obj)
		{
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &obj)
			{
				if (this->_array)
					delete [] this->_array;
				this->_array = new T[obj._size];
				this->_size = obj._size;
				for (unsigned int i = 0; i < this->_size; ++i)
					this->_array[i] = obj._array[i];
			}
			return (*this);
		}
		unsigned int getSize(void) const
		{
			return (this->_size);
		}
		T& operator[](int n)
		{
			if (this->_array == NULL and (n >= 0 or n <= 0))
				throw ErrorArray(std::string(ERROR) + std::string(ERROR_SF));
			else if (this->_array && (n < 0 or n >= static_cast<int>(this->_size)))
				throw ErrorArray(std::string(ERROR) + std::string(ERROR_INDEX));
			return (this->_array[n]);
			// if (this->_array == NULL and (n >= 0 or n <= 0))
			// 	throw ErrorArray();
			// else if (this->_array && (n < 0 or n >= static_cast<int>(this->_size)))
			// 	throw ErrorArray();
			return (this->_array[n]);
		}
		// const T& operator[](int n) const
		// {
		// 	if (this->_array == NULL and (n >= 0 or n <= 0))
		// 		throw ErrorArray(std::string(ERROR) + std::string(ERROR_SF));
		// 	else if (this->_array && (n < 0 or n >= static_cast<int>(this->_size)))
		// 		throw ErrorArray(std::string(ERROR) + std::string(ERROR_INDEX));
		// 	return (this->_array[n]);
		// }
		class ErrorArray: public std::exception
		{
			private:
				std::string _msgError;
			public:
				ErrorArray(const std::string& msg) throw(): _msgError(msg){}
				virtual const char *what() const throw()
				{
					return (_msgError.c_str());
				}
		};
};
#endif
