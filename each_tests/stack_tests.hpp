/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:10:49 by hherin            #+#    #+#             */
/*   Updated: 2021/02/17 10:52:22 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TESTS_HPP
#define STACK_TESTS_HPP

#include "../includes_and_utils/tester.hpp"

template <typename T>
void    stackTest_Empty(T& cont)
{
    std::string name("empty:");
    std::cout << "\n---------------------";
        
    printTestName("24", name);  std::cout << cont.empty();
}

template <typename T>
void    stackTest_Size(T& cont)
{
    std::string name("size:");
    std::cout << "\n---------------------";
        
    printTestName("33", name);  std::cout << cont.size();
}

template <typename T>
void    stackTest_Top(T& cont)
{
    std::string name("top:");
    std::cout << "\n---------------------";
        
    printTestName("42", name);
    if (cont.size()) // To prevent overflow
        std::cout << cont.top();
}

template <typename T>
void    stackTest_Pop(T& cont)
{
    std::string name("pop:");
    std::cout << "\n---------------------";
        
    printTestName("53", name);
        
    if (cont.size())
    {
        T tmp = cont;
        while (tmp.size()){
            std::cout << tmp.top() << " | ";
            tmp.pop();
        }
    }
}

template <typename T>
void    stackTest_Push(T& cont)
{
    std::string name("push:");
    std::cout << "\n---------------------";
        
    // Allows to value initialize (case size is 0, we can't assign cont.top())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.top();

    T tmp = cont;
    tmp.push(*x);

    printTestName("79", name);  std::cout << "size queue " << tmp.size();

    printTestName("81", name);
    while (tmp.size()){
        std::cout << tmp.top() << " | ";
        tmp.pop();
    }
    delete x;
}

template <typename T>
void    stackTest_OperatorEqualNotEqual(T& cont)
{
    std::string name("operator==/!=:");
    std::cout << "\n---------------------";

    T tmp = cont;

    printTestName("97", name, "tmp == cont");   std::cout << (tmp == cont);
    printTestName("98", name, "tmp != cont");   std::cout << (tmp != cont);
        
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.top();
        
    tmp.push(*x);
    printTestName("105", name, "tmp == cont");  std::cout << (tmp == cont);
    printTestName("106", name, "tmp != cont");  std::cout << (tmp != cont);

    T tmp2 = tmp;
    while (tmp.size())
        tmp.pop();
    printTestName("111", name, "tmp == cont");  std::cout << (tmp2 == tmp);
    printTestName("112", name, "tmp != cont");  std::cout << (tmp2 != tmp);

    while (tmp2.size())
        tmp2.pop();
    printTestName("116", name, "tmp == cont");  std::cout << (tmp2 == tmp);
    printTestName("117", name, "tmp != cont");  std::cout << (tmp2 != tmp);

    delete x;
}


template <typename T>
void    stackTest_OperatorLessAndMore(T& cont)
{
    std::string name("operator</>/<=/>=:");
    std::cout << "\n---------------------";

    T tmp = cont;
    typename T::value_type* x = new typename T::value_type ();

    printTestName("132", name, "tmp < cont");   std::cout << (tmp < cont);
    printTestName("133", name, "tmp > cont");   std::cout << (tmp > cont);
    printTestName("134", name, "tmp <= cont");  std::cout << (tmp <= cont);
    printTestName("135", name, "tmp >= cont");  std::cout << (tmp >= cont);
        
    if (cont.size())
        *x = cont.top();
    tmp.push(*x);
        
    printTestName("141", name, "tmp < cont");   std::cout << (cont < tmp);
    printTestName("142", name, "tmp > cont");   std::cout << (cont > tmp);
    printTestName("143", name, "tmp <= cont");  std::cout << (cont <= tmp);
    printTestName("144", name, "tmp >= cont");  std::cout << (cont >= tmp);

    T tmp2 = tmp;
    if (cont.size())
        *x = cont.top();
    tmp2.push(*x);
        
    printTestName("151", name, "tmp < cont");   std::cout << (tmp2 < tmp);
    printTestName("152", name, "tmp > cont");   std::cout << (tmp2 > tmp);
    printTestName("153", name, "tmp <= cont");  std::cout << (tmp2 <= tmp);
    printTestName("154", name, "tmp >= cont");  std::cout << (tmp2 >= tmp);

    while (tmp.size())
        tmp.pop();
    printTestName("158", name, "tmp < cont");   std::cout << (tmp2 < tmp);
    printTestName("159", name, "tmp > cont");   std::cout << (tmp2 > tmp);
    printTestName("160", name, "tmp <= cont");  std::cout << (tmp2 <= tmp);
    printTestName("161", name, "tmp >= cont");  std::cout << (tmp2 >= tmp);

    while (tmp2.size())
        tmp2.pop();
    printTestName("165", name, "tmp < cont");   std::cout << (tmp2 < tmp);
    printTestName("166", name, "tmp > cont");   std::cout << (tmp2 > tmp);
    printTestName("167", name, "tmp <= cont");  std::cout << (tmp2 <= tmp);
    printTestName("168", name, "tmp >= cont");  std::cout << (tmp2 >= tmp);

    delete x;
}

#endif
