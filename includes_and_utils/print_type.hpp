/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:32:08 by llefranc          #+#    #+#             */
/*   Updated: 2021/01/29 15:06:45 by llefranc         ###   ########.fr       */
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


/**
*	Calls the correct type's predicate (used in remove_if (list))
*/
template <typename T>
inline bool predicateTest(const T&) {} // Inline keywork to avoid duplicate symbol error

template <>
inline bool predicateTest<int>(const int& value) { return value < 100; }

template <>
inline bool predicateTest<char>(const char& value) { return value < 'f'; }

template <>
inline bool predicateTest<std::string>(const std::string& value) { return value < "oooooo"; }


template <typename T>
inline void printContainer(const std::string& name, T& cont)
{
	printTestName(name);
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << " | ";
}


#endif