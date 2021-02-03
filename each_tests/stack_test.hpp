/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:10:49 by hherin            #+#    #+#             */
/*   Updated: 2021/02/03 10:38:57 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TEST_HPP
#define STACK_TEST_HPP

#include "../includes_and_utils/tester.hpp"

template <typename S>
void	testEmptyStack(S& st)
{
	std::string name("empty:");
	std::cout << "\n---------------------";
	
	printTestName("33", name);	std::cout << st.empty();
}

template <typename S>
void	testSizeStack(S& st)
{
	std::string name("size:");
	std::cout << "\n---------------------";
	
	printTestName("24", name);	std::cout << st.size();
}

template <typename S>
void	testTopStack(S& st)
{
	std::string name("front:");
	std::cout << "\n---------------------";
	
	printTestName("98", name);
	if (st.size()) // To prevent overflow
		std::cout << st.top();
}

template <typename S>
void	testPopStack(S& st)
{
	std::string name("pop:");
	std::cout << "\n---------------------";
	
	printTestName("141", name);
	
	if (st.size())
	{
		S tmp = st;
        while (tmp.size()){
            std::cout << tmp.top() << " | ";
            tmp.pop();
        }
	}
}

template <typename S>
void	testPushStack(S& st)
{
	std::string name("push:");
	std::cout << "\n---------------------";
	
	printTestName("120", name);
	
	// Allows to value initialize (case size is 0, we can't assign st.top())
	typename S::value_type* x = new typename S::value_type ();
	if (st.size())
		*x = st.top();

	S tmp = st;
	tmp.push(*x);

	std::cout << "size stack " << tmp.size() << "\n";
    while (tmp.size()){
        std::cout << tmp.top() << " | ";
        tmp.pop();
    }

	delete x;
}



template <typename S>
void	testStack(S& st, int testNb)
{
	std::cout << "\n\n--------------------------------\n";
	std::cout << "------\tTESTING STACK " << testNb << " -----\n";
	std::cout << "--------------------------------\n";
	
	std::cout << "\t\tSTACK CONTAINER TYPE: ";
	print_type<typename S::value_type>();
	
	testSizeStack(st);
	testEmptyStack(st);
	testTopStack(st);
	testPopStack(st);
	testPushStack(st);
}




#endif