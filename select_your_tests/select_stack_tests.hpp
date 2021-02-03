/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_stack_tests.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:51:32 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/03 16:08:16 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_STACK_TESTS_HPP
#define SELECT_STACK_TESTS_HPP

#include "../each_tests/stack_tests.hpp"

template <typename T>
void	testNonConstStack(T& s, int testNb)
{
	printContainerInfo<T>("STACK", testNb);
	
	// Tests for non-const vectors
	stackTest_Size(s);
	stackTest_Empty(s);
	stackTest_Top(s);
	stackTest_Pop(s);
	stackTest_Push(s);
    stackTest_OperatorEqualNotEqual(s);
    stackTest_OperatorLessAndMore(s);
}

#endif
