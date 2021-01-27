/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:32:08 by llefranc          #+#    #+#             */
/*   Updated: 2021/01/27 12:45:07 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_TYPE
#define PRINT_TYPE

#include "utils.hpp"

class Bob;

/**
*	Prints the type of the template parameter.
*/
template <typename T>
inline void print_type() {} // Inline keywork to avoid duplicate symbol error

template <>
inline void print_type<int>() { std::cout << "int\n"; }

template <>
inline void print_type<char>() { std::cout << "char\n"; }

template <>
inline void print_type<Bob>() { std::cout << "Class test\n"; }

template <>
inline void print_type<double*>() { std::cout << "double*\n"; }

template <>
inline void print_type<std::string>() { std::cout << "std::string\n"; }

template <typename T>
inline void printContainer(const std::string& name, T& cont)
{
	printTestName(name);
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << " | ";
}


#endif