/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_queue_tests.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:51:32 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/03 16:10:00 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_QUEUE_TESTS_HPP
#define SELECT_QUEUE_TESTS_HPP

#include "../each_tests/queue_tests.hpp"

template <typename T>
void	testNonConstQueue(T& q, int testNb)
{
	printContainerInfo<T>("QUEUE", testNb);
	
	queueTest_Size(q);
	queueTest_Empty(q);
	queueTest_Front(q);
	queueTest_Back(q);
	queueTest_Pop(q);
	queueTest_Push(q);
    queueTest_OperatorEqualNotEqual(q);
    queueTest_OperatorLessAndMore(q);
}

#endif
