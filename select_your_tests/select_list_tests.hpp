/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_list_tests.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:51:32 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/03 16:48:13 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_LIST_TESTS_HPP
#define SELECT_LIST_TESTS_HPP

#include "../each_tests/list_tests.hpp"

template <typename T>
void	testNotConstList(T& l, int testNb)
{
	printContainerInfo<T>("LIST", testNb);
	
	listTest_Size(l);						//	size
	listTest_Empty(l);						//	empty
	listTest_Iterators(l);					//	iterators / begin / end
	listTest_ReverseIterators(l);			//	reverse iterators / rbegin / rend
	listTest_Front(l);						//	front
	listTest_Back(l);						//	back
	listTest_PushBack(l);					//	push_back
	listTest_PopBack(l);					//	pop_back
	listTest_PushFront(l);
	listTest_PopFront(l);
	listTest_Clear(l);						//	clear
	listTest_Swap(l);						//	swap
	listTest_Resize(l);
	listTest_AssignRange(l);
	listTest_AssignNElem(l);
	listTest_Insert1Elem(l);
	listTest_InsertNElem(l);
	listTest_InsertRange(l);
	listTest_EraseRange(l);
	listTest_Erase1Elem(l);
	listTest_Splice1Elem(l);
	listTest_SpliceAll(l);
	listTest_SpliceRange(l);
	listTest_Remove(l);
	listTest_RemoveIf(l);
	listTest_Unique(l);
	listTest_UniqueBinaryPredicate(l);
	listTest_Merge(l);
	listTest_MergePredicate(l);
	listTest_Sort(l);
	listTest_SortPredicate(l);
	listTest_Reverse(l);
	listTest_OperatorEqualNotEqual(l);
	listTest_OperatorLessAndMore(l);
}

template <typename T>
void	testConstList(T& l, int testNb)
{
	printContainerInfo<T>("CONST LIST", testNb);
	
	listTest_Size(l);
	listTest_Iterators(l);
	listTest_ReverseIterators(l);
	listTest_Front(l);
	listTest_Back(l);
	listTest_Empty(l);
}

#endif
