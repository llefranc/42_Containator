/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_list_tests.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:51:32 by llefranc          #+#    #+#             */
/*   Updated: 2021/06/13 18:26:17 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_LIST_TESTS_HPP
#define SELECT_LIST_TESTS_HPP

#include "../each_tests/list_tests.hpp"

template <typename T>
void    testNotConstList(T& l, int testNb)
{
    printContainerInfo<T>("LIST", testNb);
        
    listTest_Size(l);                       //  size
    listTest_Empty(l);                      //  empty
    listTest_Iterators(l);                  //  iterators / begin / end
    listTest_ReverseIterators(l);           //  reverse iterators / rbegin / rend
    listTest_Front(l);                      //  front
    listTest_Back(l);                       //  back
    listTest_PushBack(l);                   //  push_back
    listTest_PopBack(l);                    //  pop_back
    listTest_PushFront(l);                  //  push_front
    listTest_PopFront(l);                   //  pop_front
    listTest_Clear(l);                      //  clear
    listTest_Swap(l);                       //  swap
    listTest_Resize(l);                     //  resize
    listTest_AssignRange(l);                //  assign an iterator range
    listTest_AssignNElem(l);                //  assign n elements
    listTest_InsertRange(l);                //  insert an iterator range
    listTest_InsertNElem(l);                //  insert n elements
    listTest_Insert1Elem(l);                //  insert one element
    listTest_EraseRange(l);                 //  erase an iterator range
    listTest_Erase1Elem(l);                 //  erase one element
    listTest_SpliceRange(l);                //  splice an iterator range
    listTest_SpliceAll(l);                  //  splice an entire list
    listTest_Splice1Elem(l);                //  splice one element
    listTest_Remove(l);                     //  remove
    listTest_RemoveIf(l);                   //  remove if (using an unary predicate)
    listTest_Unique(l);                     //  unique
    listTest_UniqueBinaryPredicate(l);      //  unique (using a binary predicate)
    listTest_Merge(l);                      //  merge
    listTest_MergePredicate(l);             //  merge (using a binary predicate)
    listTest_Sort(l);                       //  sort
    listTest_SortPredicate(l);              //  sort (using a binary predicate)
    listTest_Reverse(l);                    //  reverse
    listTest_OperatorEqualNotEqual(l);      //  == / !=
    listTest_OperatorLessAndMore(l);        //  < / <= / > / >=
}

template <typename T>
void    testConstList(T& l, int testNb)
{
    printContainerInfo<T>("CONST LIST", testNb);
        
    listTest_Size(l);                       //  size
    listTest_Empty(l);                      //  empty
    listTest_Iterators(l);                  //  iterators / begin / end
    listTest_ReverseIterators(l);           //  reverse iterators / rbegin / rend
    listTest_Front(l);                      //  front
    listTest_Back(l);                       //  back
}

#endif
