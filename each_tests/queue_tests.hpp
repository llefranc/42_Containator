/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_tests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:10:49 by hherin            #+#    #+#             */
/*   Updated: 2021/02/17 10:52:25 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_TESTS_HPP
#define QUEUE_TESTS_HPP

#include "../includes_and_utils/tester.hpp"

template <typename T>
void    queueTest_Empty(T& cont)
{
    std::string name("empty:");
    std::cout << "\n---------------------";
        
    printTestName("24", name);  std::cout << cont.empty();
}

template <typename T>
void    queueTest_Size(T& cont)
{
    std::string name("size:");
    std::cout << "\n---------------------";
        
    printTestName("33", name);  std::cout << cont.size();
}

template <typename T>
void    queueTest_Front(T& cont)
{
    std::string name("front:");
    std::cout << "\n---------------------";
        
    printTestName("42", name);
    if (cont.size()) // To prevent overflow
        std::cout << cont.front();
}

template <typename T>
void    queueTest_Back(T& cont)
{
    std::string name("back:");
    std::cout << "\n---------------------";
        
    printTestName("53", name);
    if (cont.size()) // To prevent overflow
        std::cout << cont.back();
}

template <typename T>
void    queueTest_Pop(T& cont)
{
    std::string name("pop:");
    std::cout << "\n---------------------";
        
    printTestName("64", name);
        
    if (cont.size())
    {
        T tmp = cont;
        while (tmp.size()){
            std::cout << tmp.front() << " | ";
            tmp.pop();
        }
    }
}

template <typename T>
void    queueTest_Push(T& cont)
{
    std::string name("push:");
    std::cout << "\n---------------------";
        
    printTestName("82", name);
        
    // Allows to value initialize (case size is 0, we can't assign cont.front())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();

    T tmp = cont;
    tmp.push(*x);

    printTestName("92", name);      std::cout << "size queue " << tmp.size();

    printTestName("94", name);
    while (tmp.size()){
        std::cout << tmp.front() << " | ";
        tmp.pop();
    }

    delete x;
}

template <typename T>
void    queueTest_OperatorEqualNotEqual(T& cont)
{
    std::string name("operator==/!=:");
    std::cout << "\n---------------------";

    T tmp = cont;

    printTestName("111", name, "tmp == cont");  std::cout << (tmp == cont);
    printTestName("112", name, "tmp != cont");  std::cout << (tmp != cont);
        
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();
        
    tmp.push(*x);
    printTestName("119", name, "tmp == cont");  std::cout << (tmp == cont);
    printTestName("120", name, "tmp != cont");  std::cout << (tmp != cont);

    T tmp2 = tmp;
    while (tmp.size())
        tmp.pop();
    printTestName("125", name, "tmp == cont");  std::cout << (tmp2 == tmp);
    printTestName("126", name, "tmp != cont");  std::cout << (tmp2 != tmp);

    while (tmp2.size())
        tmp2.pop();
    printTestName("130", name, "tmp == cont");  std::cout << (tmp2 == tmp);
    printTestName("131", name, "tmp != cont");  std::cout << (tmp2 != tmp);

    delete x;
}


template <typename T>
void    queueTest_OperatorLessAndMore(T& cont)
{
    std::string name("operator</>/<=/>=:");
    std::cout << "\n---------------------";

    T tmp = cont;
    typename T::value_type* x = new typename T::value_type ();

    printTestName("146", name, "tmp < cont");   std::cout << (tmp < cont);
    printTestName("147", name, "tmp > cont");   std::cout << (tmp > cont);
    printTestName("148", name, "tmp <= cont");  std::cout << (tmp <= cont);
    printTestName("149", name, "tmp >= cont");  std::cout << (tmp >= cont);
        
    if (cont.size())
        *x = cont.front();
    tmp.push(*x);
        
    printTestName("155", name, "tmp < cont");   std::cout << (cont < tmp);
    printTestName("156", name, "tmp > cont");   std::cout << (cont > tmp);
    printTestName("157", name, "tmp <= cont");  std::cout << (cont <= tmp);
    printTestName("158", name, "tmp >= cont");  std::cout << (cont >= tmp);

    T tmp2 = tmp;
    if (cont.size())
        *x = cont.front();
    tmp2.push(*x);
        
    printTestName("165", name, "tmp < cont");   std::cout << (tmp2 < tmp);
    printTestName("166", name, "tmp > cont");   std::cout << (tmp2 > tmp);
    printTestName("167", name, "tmp <= cont");  std::cout << (tmp2 <= tmp);
    printTestName("168", name, "tmp >= cont");  std::cout << (tmp2 >= tmp);

    while (tmp.size())
        tmp.pop();
    printTestName("172", name, "tmp < cont");   std::cout << (tmp2 < tmp);
    printTestName("173", name, "tmp > cont");   std::cout << (tmp2 > tmp);
    printTestName("174", name, "tmp <= cont");  std::cout << (tmp2 <= tmp);
    printTestName("175", name, "tmp >= cont");  std::cout << (tmp2 >= tmp);

    while (tmp2.size())
        tmp2.pop();
    printTestName("179", name, "tmp < cont");   std::cout << (tmp2 < tmp);
    printTestName("180", name, "tmp > cont");   std::cout << (tmp2 > tmp);
    printTestName("181", name, "tmp <= cont");  std::cout << (tmp2 <= tmp);
    printTestName("182", name, "tmp >= cont");  std::cout << (tmp2 >= tmp);

    delete x;
}

#endif

