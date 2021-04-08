/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_map_tests.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:51:32 by llefranc          #+#    #+#             */
/*   Updated: 2021/04/08 11:29:45 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_MAP_TESTS_HPP
#define SELECT_MAP_TESTS_HPP

#include "../each_tests/map_tests.hpp"

template <typename T>
void    testNotConstMap(T& l, int testNb)
{
    printContainerInfo<T>("MAP", testNb);
        
    mapTest_Size(l);                        //  size
    mapTest_Empty(l);                       //  empty
    mapTest_Iterators(l);                   //  iterators / begin / end
    mapTest_ReverseIterators(l);            //  reverse iterators / rbegin / rend
    mapTest_operatorBracelet(l);            //  operator[]
    mapTest_Clear(l);                       //  clear
    mapTest_Swap(l);                        //  swap
    mapTest_InsertRange(l);                 //  insert an iterator range
    mapTest_InsertToAPosition(l);           //  insert n elements
    mapTest_Insert1Elem(l);                 //  insert one element
    mapTest_EraseRange(l);                  //  erase an iterator range
    mapTest_EraseToAPosition(l);            //  erase one element
    mapTest_EraseASpecificKey(l);           //  erase one element
    mapTest_find(l);                        // find one element
    mapTest_count(l);                       // count key's occurence
    mapTest_lowerBound(l);                  // iterator just before a specific key
    mapTest_upperBound(l);                  // iterator just after a specific key
    mapTest_equalRange(l);                  // iterator's range with a specific key
}

template <typename T>
void    testConstMap(T& l, int testNb)
{
    printContainerInfo<T>("CONST MAP", testNb);

    mapTest_Size(l);                        //  size
    mapTest_Empty(l);                       //  empty
    mapTest_Iterators(l);                   //  iterators / begin / end
    mapTest_ReverseIterators(l);            //  reverse iterators / rbegin / rend
    mapTest_find(l);                        // find one element
    mapTest_count(l);                       // count key's occurence
    mapTest_lowerBound(l);                  // iterator just before a specific key
    mapTest_upperBound(l);                  // iterator just after a specific key
    mapTest_equalRange(l);                  // iterator's range with a specific key
}

#endif
