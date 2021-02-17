/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_vector_tests.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:51:32 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/17 10:51:08 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_VECTOR_TESTS_HPP
#define SELECT_VECTOR_TESTS_HPP

#include "../each_tests/vector_tests.hpp"

template <typename T>
void    testNotConstVec(T& v, int testNb)
{
    printContainerInfo<T>("VECTOR", testNb);
        
    vectorTest_OperatorBracelet(v);         //  operator[]
    vectorTest_Size(v);                     //  size
    vectorTest_Empty(v);                    //  empty
    vectorTest_Iterators(v);                //  iterators / begin / end
    vectorTest_ReverseIterators(v);         //  reverse iterators / rbegin / rend
    vectorTest_At(v);                       //  at
    vectorTest_Front(v);                    //  front
    vectorTest_Back(v);                     //  back
    vectorTest_PushBack(v);                 //  push_back
    vectorTest_PopBack(v);                  //  pop_back
    vectorTest_Clear(v);                    //  clear
    vectorTest_Swap(v);                     //  swap
    vectorTest_Resize(v);                   //  resize
    vectorTest_AssignRange(v);              //  assign an iterator range
    vectorTest_AssignNElem(v);              //  assign n elements
    vectorTest_InsertRange(v);              //  insert an iterator range
    vectorTest_InsertNElem(v);              //  insert n elements
    vectorTest_Insert1Elem(v);              //  insert one element
    vectorTest_EraseRange(v);               //  erase an iterator range
    vectorTest_Erase1Elem(v);               //  erase one element
    vectorTest_OperatorEqualNotEqual(v);    //  == / !=
    vectorTest_OperatorLessAndMore(v);      //  < / <= / > / >=
}

template <typename T>
void    testConstVec(T& v, int testNb)
{
    printContainerInfo<T>("CONST VECTOR", testNb);
        
    vectorTest_OperatorBracelet(v);         //  operator[]
    vectorTest_Size(v);                     //  size
    vectorTest_Empty(v);                    //  empty
    vectorTest_Iterators(v);                //  iterators / begin / end
    vectorTest_ReverseIterators(v);         //  reverse iterators / rbegin / rend
    vectorTest_At(v);                       //  at
    vectorTest_Front(v);                    //  front
    vectorTest_Back(v);                     //  back
}

#endif
