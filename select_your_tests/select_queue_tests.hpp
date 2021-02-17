/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_queue_tests.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:51:32 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/17 10:51:20 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_QUEUE_TESTS_HPP
#define SELECT_QUEUE_TESTS_HPP

#include "../each_tests/queue_tests.hpp"

template <typename T>
void    testNonConstQueue(T& q, int testNb)
{
    printContainerInfo<T>("QUEUE", testNb);
        
    queueTest_Size(q);                      //  size
    queueTest_Empty(q);                     //  empty
    queueTest_Front(q);                     //  front
    queueTest_Back(q);                      //  back
    queueTest_Pop(q);                       //  pop
    queueTest_Push(q);                      //  push
    queueTest_OperatorEqualNotEqual(q);     //  == / !=
    queueTest_OperatorLessAndMore(q);       //  < / <= / > / >=
}

#endif
