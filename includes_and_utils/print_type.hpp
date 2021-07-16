/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:32:08 by llefranc          #+#    #+#             */
/*   Updated: 2021/07/16 15:46:53 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_TYPE
#define PRINT_TYPE

#include "utils.hpp"

/**
*   Prints the type of the template parameter.
*/
template <typename T>
inline void print_type() {} // Inline keywork to avoid duplicate symbol error

template <>
inline void print_type<int>() { std::cout << "int\n"; }

template <>
inline void print_type<char>() { std::cout << "char\n"; }

template <>
inline void print_type<double*>() { std::cout << "double*\n"; }

template <>
inline void print_type<std::string>() { std::cout << "std::string\n"; }

template <>
inline void print_type<std::pair<const int, std::string> >() { std::cout << "pair(const int, std::string)\n"; }

template <>
inline void print_type<ft::pair<const int, std::string> >() { std::cout << "pair(const int, std::string)\n"; }

template <>
inline void print_type<std::pair<const std::string, int> >() { std::cout << "pair(const std::string, int)\n"; }

template <>
inline void print_type<ft::pair<const std::string, int> >() { std::cout << "pair(const std::string, int)\n"; }


/**
*   Prints a header of informations for the tested container.
*/
template <typename T>
inline void printContainerInfo(const std::string& info, int testNb)
{
    std::cout << "\n\n--------------------------------\n";
    std::cout << "------\tTESTING " << info << " " << testNb << " ------\n";
    std::cout << "--------------------------------\n";
        
    std::cout << "\t\t" << info << " TYPE: ";
    print_type<typename T::value_type>();
}


/**
*   Calls the correct type's predicate (used in remove_if (list))
*/
template <typename T>
inline bool predicateTest(const T&) { return true; } // Inline keywork to avoid duplicate symbol error

template <>
inline bool predicateTest<int>(const int& value) { return value < 100; }

template <>
inline bool predicateTest<char>(const char& value) { return value < 'f'; }

template <>
inline bool predicateTest<std::string>(const std::string& value) { return value < "oooooo"; }


/**
*   Calls the correct type's binaryPredicate (used in unique predicate (list))
*/
template <typename T>
inline bool binaryPredicateTest(const T& a, const T& b) { return a < b; } // Inline keywork to avoid duplicate symbol error

template <>
inline bool binaryPredicateTest<int>(const int& a, const int& b) { return a < b; }

template <>
inline bool binaryPredicateTest<char>(const char& a,const char& b) { return a < b; }

template <>
inline bool binaryPredicateTest<std::string>(const std::string& a, const std::string& b) { return a < b; }


template <typename T>
inline void printContainer(const std::string& nbLine, std::string name, T& cont)
{
    printTestName(nbLine, name);
    for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << " | ";
}

template <typename T>
inline void printMapContainer(const std::string& nbLine, std::string name, T& cont)
{
    printTestName(nbLine, name);
    for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
        std::cout << "[" << it->first << "][" << it->second << "] | ";
}

#endif