/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_vector_tests.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:51:32 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/03 16:03:14 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_VECTOR_TESTS_HPP
#define SELECT_VECTOR_TESTS_HPP

#include "../each_tests/vector_tests.hpp"

template <typename T>
void	testNotConstVec(T& v, int testNb)
{
	printContainerInfo<T>("VECTOR", testNb);
	
	// Tests for non-const vectors
	vectorTest_OperatorBracelet(v);
	vectorTest_Size(v);
	vectorTest_Empty(v);
	vectorTest_Iterators(v);
	vectorTest_ReverseIterators(v);
	vectorTest_At(v);
	vectorTest_Front(v);
	vectorTest_Back(v);
	vectorTest_PushBack(v);
	vectorTest_PopBack(v);
	vectorTest_Clear(v);
	vectorTest_Swap(v);
	vectorTest_Resize(v);
	vectorTest_AssignRange(v);
	vectorTest_AssignNElem(v);
	vectorTest_Insert1Elem(v);
	vectorTest_InsertNElem(v);
	vectorTest_InsertRange(v);
	vectorTest_EraseRange(v);
	vectorTest_Erase1Elem(v);
	vectorTest_OperatorEqualNotEqual(v);
	vectorTest_OperatorLessAndMore(v);
}

template <typename T>
void	testConstVec(T& v, int testNb)
{
	printContainerInfo<T>("CONST VECTOR", testNb);
	
	// Tests for const vectors
	vectorTest_OperatorBracelet(v);
	vectorTest_Size(v);
	vectorTest_Empty(v);
	vectorTest_Iterators(v);
	vectorTest_ReverseIterators(v);
	vectorTest_At(v);
	vectorTest_Front(v);
	vectorTest_Back(v);
}

#endif
