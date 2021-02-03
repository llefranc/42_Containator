/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherin <hherin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:10:49 by hherin            #+#    #+#             */
/*   Updated: 2021/02/03 10:56:00 by hherin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TEST_HPP
#define STACK_TEST_HPP

#include "../includes_and_utils/tester.hpp"

template <typename T>
void	testEmptyStack(T& st)
{
	std::string name("empty:");
	std::cout << "\n---------------------";
	
	printTestName("33", name);	std::cout << st.empty();
}

template <typename T>
void	testSizeStack(T& st)
{
	std::string name("size:");
	std::cout << "\n---------------------";
	
	printTestName("24", name);	std::cout << st.size();
}

template <typename T>
void	testTopStack(T& st)
{
	std::string name("front:");
	std::cout << "\n---------------------";
	
	printTestName("98", name);
	if (st.size()) // To prevent overflow
		std::cout << st.top();
}

template <typename T>
void	testPopStack(T& st)
{
	std::string name("pop:");
	std::cout << "\n---------------------";
	
	printTestName("141", name);
	
	if (st.size())
	{
		T tmp = st;
        while (tmp.size()){
            std::cout << tmp.top() << " | ";
            tmp.pop();
        }
	}
}

template <typename T>
void	testPushStack(T& st)
{
	std::string name("push:");
	std::cout << "\n---------------------";
	
	printTestName("120", name);
	
	// Allows to value initialize (case size is 0, we can't assign st.top())
	typename T::value_type* x = new typename T::value_type ();
	if (st.size())
		*x = st.top();

	T tmp = st;
	tmp.push(*x);

	std::cout << "size stack " << tmp.size() << "\n";
    while (tmp.size()){
        std::cout << tmp.top() << " | ";
        tmp.pop();
    }

	delete x;
}

template <typename T>
void	testOperatorEqualNotEqualStack(T& cont)
{
	std::string name("operator==/!=:");
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName("1248", name, "tmp == cont");	std::cout << (tmp == cont);
	printTestName("1249", name, "tmp != cont");	std::cout << (tmp != cont);
	
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.top();
	
	tmp.push(*x);
	printTestName("1256", name, "tmp == cont");	std::cout << (tmp == cont);
	printTestName("1257", name, "tmp != cont");	std::cout << (tmp != cont);

	T tmp2 = tmp;
    while (tmp.size())
	    tmp.pop();
	printTestName("1261", name, "tmp == cont");	std::cout << (tmp2 == tmp);
	printTestName("1262", name, "tmp != cont");	std::cout << (tmp2 != tmp);

    while (tmp2.size())
	    tmp2.pop();
	printTestName("1265", name, "tmp == cont");	std::cout << (tmp2 == tmp);
	printTestName("1266", name, "tmp != cont");	std::cout << (tmp2 != tmp);

	delete x;
}


template <typename T>
void	testOperatorLessAndMoreStack(T& cont)
{
	std::string name("operator</>/<=/>=:");
	std::cout << "\n---------------------";

	T tmp = cont;
	typename T::value_type* x = new typename T::value_type ();

	printTestName("1280", name, "tmp < cont");	std::cout << (tmp < cont);
	printTestName("1281", name, "tmp > cont");	std::cout << (tmp > cont);
	printTestName("1282", name, "tmp <= cont");	std::cout << (tmp <= cont);
	printTestName("1283", name, "tmp >= cont");	std::cout << (tmp >= cont);
	
	if (cont.size())
		*x = cont.top();
	tmp.push(*x);
	
	printTestName("1289", name, "tmp < cont");	std::cout << (cont < tmp);
	printTestName("1290", name, "tmp > cont");	std::cout << (cont > tmp);
	printTestName("1291", name, "tmp <= cont");	std::cout << (cont <= tmp);
	printTestName("1292", name, "tmp >= cont");	std::cout << (cont >= tmp);

	T tmp2 = tmp;
	if (cont.size())
		*x = cont.top();
	tmp2.push(*x);
	
	printTestName("1299", name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName("1300", name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName("1301", name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName("1302", name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

	while (tmp.size())
	    tmp.pop();
	printTestName("1305", name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName("1306", name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName("1307", name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName("1308", name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

	while (tmp2.size())
	    tmp2.pop();
	printTestName("1311", name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName("1312", name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName("1313", name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName("1314", name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

	delete x;
}

template <typename T>
void	testStack(T& st, int testNb)
{
	std::cout << "\n\n--------------------------------\n";
	std::cout << "------\tTESTING STACK " << testNb << " -----\n";
	std::cout << "--------------------------------\n";
	
	std::cout << "\t\tSTACK CONTAINER TYPE: ";
	print_type<typename T::value_type>();
	
	testSizeStack(st);
	testEmptyStack(st);
	testTopStack(st);
	testPopStack(st);
	testPushStack(st);
    testOperatorEqualNotEqualStack(st);
    testOperatorLessAndMoreStack(st);
}




#endif