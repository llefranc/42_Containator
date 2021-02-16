/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_map_tests.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:51:32 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/16 15:46:34 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_MAP_TESTS_HPP
#define SELECT_MAP_TESTS_HPP

#include "../each_tests/map_tests.hpp"

template <typename T>
void	testNotConstMap(T& l, int testNb)
{
	printContainerInfo<T>("MAP", testNb);
	
	mapTest_Size(l);						//	size
	mapTest_Empty(l);						//	empty
	mapTest_Iterators(l);					//	iterators / begin / end
	mapTest_ReverseIterators(l);			//	reverse iterators / rbegin / rend
	mapTest_operatorBracelet(l);						//	operator[]
	// mapTest_Back(l);						//	back
	// mapTest_PushBack(l);					//	push_back
	// mapTest_PopBack(l);					//	pop_back
	// mapTest_PushFront(l);					//	push_front
	// mapTest_PopFront(l);					//	pop_front
	mapTest_Clear(l);						//	clear
	mapTest_Swap(l);						//	swap
	// mapTest_Resize(l);						//	resize
	// mapTest_AssignRange(l);				//	assign an iterator range
	// mapTest_AssignNElem(l);				//	assign n elements
	mapTest_InsertRange(l);				//	insert an iterator range
	mapTest_InsertToAPosition(l);				//	insert n elements
	mapTest_Insert1Elem(l);				//	insert one element
	// mapTest_EraseRange(l);					//	erase an iterator range
	// mapTest_Erase1Elem(l);					//	erase one element
	// mapTest_SpliceRange(l);				//	splice an iterator range
	// mapTest_SpliceAll(l);					//	splice an entire list
	// mapTest_Splice1Elem(l);				//	splice one element
	// mapTest_Remove(l);						//	remove
	// mapTest_RemoveIf(l);					//	remove if (using an unary predicate)
	// mapTest_Unique(l);						//	unique
	// mapTest_UniqueBinaryPredicate(l);		//	unique (using a binary predicate)
	// mapTest_Merge(l);						//	merge
	// mapTest_MergePredicate(l);				//	merge (using a binary predicate)
	// mapTest_Sort(l);						//	sort
	// mapTest_SortPredicate(l);				//	sort (using a binary predicate)
	// mapTest_Reverse(l);					//	reverse
	// mapTest_OperatorEqualNotEqual(l);		//	== / !=
	// mapTest_OperatorLessAndMore(l);		//	< / <= / > / >=
}

template <typename T>
void	testConstMap(T& l, int testNb)
{
	printContainerInfo<T>("CONST MAP", testNb);
	
	mapTest_Size(l);						//	size
	mapTest_Empty(l);						//	empty
	mapTest_Iterators(l);					//	iterators / begin / end
	mapTest_ReverseIterators(l);			//	reverse iterators / rbegin / rend
	// mapTest_Front(l);						//	front
	// mapTest_Back(l);						//	back
}

#endif
