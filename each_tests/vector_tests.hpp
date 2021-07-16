/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:31:55 by llefranc          #+#    #+#             */
/*   Updated: 2021/07/16 15:55:40 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTODR_TESTS_HPP
#define VECTODR_TESTS_HPP

#include "../includes_and_utils/tester.hpp"

template <typename T>
void    vectorTest_OperatorBracelet(T& cont)
{
    std::string name("operator[]:");
    std::cout << "\n---------------------";

    printTestName("24", name);
    for (size_t i = 0; i < cont.size(); ++i)
        std::cout << cont[i] << " ";
}

template <typename T>
void    vectorTest_Size(T& cont)
{
    std::string name("size:");
    std::cout << "\n---------------------";
        
    printTestName("35", name);  std::cout << cont.size();
}

template <typename T>
void    vectorTest_Empty(T& cont)
{
    std::string name("empty:");
    std::cout << "\n---------------------";
        
    printTestName("44", name);  std::cout << cont.empty();
}

template <typename T>
void    vectorTest_Iterators(T& cont)
{
    std::string name("iterators:");
    std::cout << "\n---------------------";
        
    printTestName("53", name, "operator++");
    for (typename T::const_iterator it = cont.begin(); it != cont.end(); it++)
        std::cout << *it << " | ";

    printTestName("57", name, "++operator");
    for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << " | ";

    if (cont.size())
    {
        printTestName("63", name, "operator--");
        for (typename T::const_iterator it = cont.end(); it != cont.begin() - 1; it--)
            if (it != cont.end())
                std::cout << *it << " | ";

        printTestName("68", name, "--operator");
        for (typename T::const_iterator it = cont.end(); it != cont.begin() - 1; --it)
            if (it != cont.end())
                std::cout << *it << " | ";
    }

    printTestName("74", name, "operator+=");
    for (typename T::const_iterator it = cont.begin(); it != cont.end(); it += 1)
        std::cout << *it << " | ";
        
    printTestName("78", name, "operator+");
    for (typename T::const_iterator it = cont.begin(); it != cont.end(); it = it + 1)
        std::cout << *it << " | ";

    printTestName("82", name, "operator-=");
    for (typename T::const_iterator it = cont.end() - 1; it != cont.begin() - 1; it -= 1)
        std::cout << *it << " | ";

    printTestName("86", name, "operator-");
    for (typename T::const_iterator it = cont.end() - 1; it != cont.begin() - 1; it = it - 1)
        std::cout << *it << " | ";

    printTestName("90", name, "operator[]");
    for (std::pair<size_t, typename T::const_iterator> i(0, cont.begin()); i.first < cont.size(); ++i.first)
        std::cout << i.second[i.first] << " | ";
}

template <typename T>
void    vectorTest_ReverseIterators(T& cont)
{
    std::string name("reverse iterators:");
    std::cout << "\n---------------------";
        
    printTestName("101", name, "++operator");
    for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); ++it)
        std::cout << *it << " | ";

    printTestName("105", name, "operator++");
    for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); it++)
        std::cout << *it << " | ";  

    if (cont.size())
    {
        printTestName("111", name, "operator--");
        for (typename T::const_reverse_iterator it = cont.rend(); it != cont.rbegin() - 1; it--)
            if (it != cont.rend())
                std::cout << *it << " | ";

        printTestName("116", name, "--operator");
        for (typename T::const_reverse_iterator it = cont.rend(); it != cont.rbegin() - 1; --it)
            if (it != cont.rend())
                std::cout << *it << " | ";
    }

    printTestName("122", name, "operator+=");
    for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); it += 1)
        std::cout << *it << " | ";
        
    printTestName("126", name, "operator+");
    for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); it = it + 1)
        std::cout << *it << " | ";

    printTestName("130", name, "operator-=");
    for (typename T::const_reverse_iterator it = cont.rend() - 1; it != cont.rbegin() - 1; it -= 1)
        std::cout << *it << " | ";

    printTestName("134", name, "operator-");
    for (typename T::const_reverse_iterator it = cont.rend() - 1; it != cont.rbegin() - 1; it = it - 1)
        std::cout << *it << " | ";

    printTestName("138", name, "operator[]");
    for (std::pair<size_t, typename T::const_reverse_iterator> i(0, cont.rbegin()); i.first < cont.size(); ++i.first)
        std::cout << i.second[i.first] << " | ";
}

template <typename T>
void    vectorTest_At(T& cont)
{
    std::string name("at:");
    std::cout << "\n---------------------";
        
    printTestName("149", name);
    for (size_t i = 0; i < cont.size(); ++i)
    {
        try
        {
            std::cout << cont.at(i) << " ";
        }
        catch (std::exception& e)
        {
            std::cout << "range exception";
        }
    }
        
    // Throwing an exception
    printTestName("163", name);
    try
    {
        std::cout << cont.at(100000) << " ";
    }
    catch (std::exception& e)
    {
        std::cout << "range exception";
    }
}

template <typename T>
void    vectorTest_Front(T& cont)
{
    std::string name("front:");
    std::cout << "\n---------------------";
        
    printTestName("180", name);
    if (cont.size()) // To prevent overflow
        std::cout << cont.front();
}

template <typename T>
void    vectorTest_Back(T& cont)
{
    std::string name("back:");
    std::cout << "\n---------------------";

    printTestName("191", name);
    if (cont.size()) // To prevent overflow
        std::cout << cont.back();
}

template <typename T>
void    vectorTest_PushBack(T& cont)
{
    std::string name("push_back:");
    std::cout << "\n---------------------";
        
    printTestName("202", name);
        
    // Allows to value initialize (case size is 0, we can't assign cont.front())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();

    T tmp = cont;
    tmp.push_back(*x);

    printContainer("212", name, tmp);

    delete x;
}

template <typename T>
void    vectorTest_PopBack(T& cont)
{
    std::string name("pop_back:");
    std::cout << "\n---------------------";
        
    printTestName("223", name);
        
    if (cont.size())
    {
        T tmp = cont;
        tmp.pop_back();
        printContainer("229", name, tmp);
    }
}

template <typename T>
void    vectorTest_Clear(T& cont)
{
    std::string name("clear:");
    std::cout << "\n---------------------";
        
    T tmp = cont;
    printTestName("240", name); std::cout << "size before clear: " << tmp.size();
    tmp.clear();
        
    printTestName("243", name); std::cout << "size after clear: " << tmp.size();

    // Allows to value initialize (case size is 0, we can't assign cont.front())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();

    tmp.push_back(*x);
    printContainer("251", name, tmp);

    delete x;
}

template <typename T>
void    vectorTest_Swap(T& cont)
{
    std::string name("swap:");
    std::cout << "\n---------------------";
        
    T tmp(cont);
    T tmp2(cont);

    // Allows to value initialize (case size is 0, we can't assign cont.front())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();

    tmp.push_back(*x);
        
    printTestName("272", name); std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();
    tmp2.swap(tmp);
    printContainer("274", name, tmp2);

    printTestName("276", name); std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();

    swap(tmp2, tmp);
    printTestName("279", name); std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();
    printContainer("280", name, tmp2);

    delete x;
}

template <typename T>
void    vectorTest_Resize(T& cont)
{
    std::string name("resize:");
    std::cout << "\n---------------------";

    T tmp = cont;

    printTestName("293", name); std::cout << "size of tmp = " << tmp.size();

    // Allows to value initialize (case size is 0, we can't assign cont.front())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();

    tmp.resize(3, *x);
    printContainer("301", name, tmp);

    printTestName("303", name); std::cout << "size of tmp after resize = " << tmp.size();
        
    delete x;
}

/**
*   Test assign with iterators' range.
*/
template <typename T>
void    vectorTest_AssignRange(T& cont)
{
    std::string name("assign iterator range:");
    std::cout << "\n---------------------";

    T tmp = cont;
    printTestName("318", name); std::cout << "size of tmp = " << tmp.size();
    printContainer("319", name, tmp);

    // Allows to value initialize (case size is 0, we can't assign cont.front())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();

    T tmp2 = cont;
    tmp.resize(3, *x);
    tmp2.assign(tmp.begin(), tmp.end());

    printTestName("330", name); std::cout << "size after assign = " << tmp2.size();
    printContainer("331", name, tmp2);

    delete x;
}

template <typename T>
void    vectorTest_AssignNElem(T& cont)
{
    std::string name("assign n elems:");
    std::cout << "\n---------------------";

    T tmp = cont;
    printTestName("343", name); std::cout << "size of tmp = " << tmp.size();
    printContainer("344", name, tmp);

    // Allows to value initialize (case size is 0, we can't assign cont.front())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();
        
    tmp.resize(3, *x);

    T tmp2 = cont;
    tmp2.assign(tmp.size(), tmp.front());

    printTestName("356", name); std::cout << "size after assign = " << tmp2.size();
    printContainer("357", name, tmp2);
        
    delete x;
}

/**
*   Inserts one element.
*/
template <typename T>
void    vectorTest_Insert1Elem(T& cont)
{
    std::string name("insert 1 elem:");
    std::cout << "\n---------------------";

    T tmp = cont;
    printTestName("372", name); std::cout << "size of tmp = " << tmp.size();

    // Allows to value initialize (case size is 0, we can't assign cont[0])
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
    {
        *x = cont.front();
        typename T::iterator it = tmp.begin();
        ++it;
        printTestName("381", name); std::cout << "return value: " << *tmp.insert(it, *x);
    }
    printTestName("383", name); std::cout << "return value: " << *tmp.insert(tmp.begin(), *x);
    printTestName("384", name); std::cout << "return value: " << *tmp.insert(tmp.end(), *x);
        
    printTestName("386", name); std::cout << "size of tmp = " << tmp.size();
    printContainer("387", name, tmp);

    delete x;
}

/**
*   Inserts n elements.
*/
template <typename T>
void    vectorTest_InsertNElem(T& cont)
{
    std::string name("insert n elem:");
    std::cout << "\n---------------------";

    T tmp = cont;
    printTestName("402", name); std::cout << "size of tmp = " << tmp.size();

    // Allows to value initialize (case size is 0, we can't assign cont[0])
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
    {
        *x = cont.front();
        typename T::iterator it = tmp.begin();
        ++it;
        tmp.insert(it, 5, *x);
    }
    tmp.insert(tmp.begin(), 5, *x);
    tmp.insert(tmp.end(), 5, *x);
        
    printTestName("416", name); std::cout << "size of tmp = " << tmp.size();
    printContainer("417", name, tmp);

    delete x;
}

/**
*   Inserts an iterators' range of elements.
*/
template <typename T>
void    vectorTest_InsertRange(T& cont)
{
    std::string name("insert iterator range:");
    std::cout << "\n---------------------";

    T tmp = cont;
    printTestName("432", name); std::cout << "size of tmp = " << tmp.size();

    tmp.insert(tmp.begin(), cont.begin(), cont.end());
    if (tmp.size())
    {
        typename T::iterator it = tmp.begin();
        ++it;
        tmp.insert(it, cont.begin(), cont.end());
    }
    tmp.insert(tmp.end(), cont.begin(), cont.end());
    tmp.insert(tmp.end(), cont.begin(), cont.begin());
        
    printTestName("444", name); std::cout << "size of tmp = " << tmp.size();
    printContainer("445", name, tmp);
}

template <typename T>
void    vectorTest_EraseRange(T& cont)
{
    std::string name("erase iterator range:");
    std::cout << "\n---------------------";

    typename T::value_type* x = new typename T::value_type ();

    // Erase everything
    {
        printTestName("458", name); std::cout << "----- erase nothing -----";

        T tmp = cont;
        printTestName("461", name); std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.begin(), tmp.end());
        if (tmp.size())
            { printTestName("465", name);   std::cout << "new elem after erase: " << *iter; }

        printTestName("467", name); std::cout << "size of tmp = " << tmp.size();
        printContainer("468", name, tmp);

        // checking if everything was correcty destroyed
        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
    }

    // Erase nothing
    {
        printTestName("477", name); std::cout << "----- erase nothing -----";

        T tmp = cont;
        printTestName("480", name); std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.end(), tmp.end());
        
        printTestName("484", name);
        for (typename T::iterator it = tmp.begin(); it != iter; ++it)
            std::cout << *it << " | ";

        printTestName("488", name); std::cout << "size of tmp = " << tmp.size();

        iter = tmp.erase(tmp.begin(), tmp.begin());
        if (tmp.size())
            { printTestName("492", name);   std::cout << "new elem after erase: " << *iter; }

        printContainer("494", name, tmp);

        // checking if everything was correcty destroyed and if we can push_back on erased values
        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
        printContainer("499", name, tmp);
    }
        
    // Erase last elem
    if (cont.size())
    {
        printTestName("505", name); std::cout << "----- erase last elem -----";
        
        T tmp = cont;
        printTestName("508", name); std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.end() - 1, tmp.end());

        printTestName("512", name);
        for (typename T::iterator it = tmp.begin(); it != iter; ++it)
            std::cout << *it << " | ";

        printTestName("516", name); std::cout << "size of tmp = " << tmp.size();
        printContainer("517", name, tmp);

        // checking if everything was correcty destroyed and if we can push_back on erased values
        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
        printContainer("522", name, tmp);
    }

    // Erase everything except first elem
    if (cont.size())
    {
        printTestName("528", name); std::cout << "----- erase everything except first elem -----";

        T tmp = cont;
        printTestName("531", name); std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.begin() + 1, tmp.end());

        printTestName("535", name);
        for (typename T::iterator it = tmp.begin(); it != iter; ++it)
            std::cout << *it << " | ";

        printTestName("539", name); std::cout << "size of tmp = " << tmp.size();
        printContainer("540", name, tmp);
        
        // checking if everything was correcty destroyed and if we can push_back on erased values
        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
        printContainer("545", name, tmp);
    }

    // Erase only first elem
    if (cont.size())
    {
        printTestName("551", name); std::cout << "----- erase only first elem -----";

        T tmp = cont;
        printTestName("554", name); std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.begin(), tmp.begin() + 1);

        printTestName("558", name);
        for (typename T::iterator it = tmp.begin(); it != iter; ++it)
            std::cout << *it << " | ";

        printTestName("562", name); std::cout << "size of tmp = " << tmp.size();
        printContainer("563", name, tmp);
        
        // checking if everything was correcty destroyed and if we can push_back on erased values
        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
        printContainer("568", name, tmp);
    }

    delete x;
}

template <typename T>
void    vectorTest_Erase1Elem(T& cont)
{
    std::string name("erase 1 elem:");
    std::cout << "\n---------------------";

    typename T::value_type* x = new typename T::value_type ();

    // Erase first elem
    if (cont.size() > 1)
    {
        printTestName("585", name); std::cout << "----- erase first elem -----";
        
        T tmp = cont;
        printTestName("588", name); std::cout << "size of tmp = " << tmp.size();

        printContainer("590", name, tmp);
        typename T::iterator iter = tmp.erase(tmp.begin());
        if (tmp.size())
            { printTestName("593", name);   std::cout << "return value: " << *iter; }
        printContainer("594", name, tmp);

        printTestName("596", name);
        for (typename T::iterator it = tmp.begin(); it != iter; ++it)
            std::cout << *it << " | ";
            
        printTestName("600", name); std::cout << "size of tmp = " << tmp.size();

        // checking if everything was correcty destroyed and if we can push_back on erased values
        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
        printContainer("605", name, tmp);
    }

    // Erase last elem
    if (cont.size())
    {
        printTestName("611", name); std::cout << "----- erase last elem -----";
        
        T tmp = cont;
        printTestName("614", name); std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.end() - 1);
        printContainer("617", name, tmp);

        printTestName("619", name);
        for (typename T::iterator it = tmp.begin(); it != iter; ++it)
            std::cout << *it << " | ";

        printTestName("623", name); std::cout << "size of tmp = " << tmp.size();

        // checking if everything was correcty destroyed and if we can push_back on erased values
        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
        printContainer("628", name, tmp);
    }

    // Erase one elem
    if (cont.size() > 1)
    {
        printTestName("634", name); std::cout << "----- erase second elem -----";

        T tmp = cont;
        printTestName("637", name); std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.begin() + 1);
        if (tmp.size() > 2)
            { printTestName("641", name);   std::cout << "return value: " << *iter; }
        printContainer("642", name, tmp);

        printTestName("644", name);
        for (typename T::iterator it = tmp.begin(); it != iter; ++it)
            std::cout << *it << " | ";

        printTestName("648", name); std::cout << "size of tmp = " << tmp.size();

        // checking if everything was correcty destroyed and if we can push_back on erased values
        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
        printContainer("653", name, tmp);
    }

    delete x;
}

template <typename T>
void    vectorTest_OperatorEqualNotEqual(T& cont)
{
    std::string name("operator==/!=:");
    std::cout << "\n---------------------";

    T tmp = cont;

    printTestName("667", name, "tmp == cont");  std::cout << (tmp == cont);
    printTestName("668", name, "tmp != cont");  std::cout << (tmp != cont);
        
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();
        
    tmp.push_back(*x);
    printTestName("675", name, "tmp == cont");  std::cout << (tmp == cont);
    printTestName("676", name, "tmp != cont");  std::cout << (tmp != cont);

    T tmp2 = tmp;
    tmp.clear();
    printTestName("680", name, "tmp == cont");  std::cout << (tmp2 == tmp);
    printTestName("681", name, "tmp != cont");  std::cout << (tmp2 != tmp);

    tmp2.clear();
    printTestName("684", name, "tmp == cont");  std::cout << (tmp2 == tmp);
    printTestName("685", name, "tmp != cont");  std::cout << (tmp2 != tmp);

    delete x;
}

template <typename T>
void    vectorTest_OperatorLessAndMore(T& cont)
{
    std::string name("operator</>/<=/>=:");
    std::cout << "\n---------------------";

    T tmp = cont;
    typename T::value_type* x = new typename T::value_type ();

    printTestName("699", name, "tmp < cont");   std::cout << (tmp < cont);
    printTestName("700", name, "tmp > cont");   std::cout << (tmp > cont);
    printTestName("701", name, "tmp <= cont");  std::cout << (tmp <= cont);
    printTestName("702", name, "tmp >= cont");  std::cout << (tmp >= cont);
        
    if (cont.size())
        *x = cont.front();
    tmp.push_back(*x);
        
    printTestName("708", name, "tmp < cont");   std::cout << (cont < tmp);
    printTestName("709", name, "tmp > cont");   std::cout << (cont > tmp);
    printTestName("710", name, "tmp <= cont");  std::cout << (cont <= tmp);
    printTestName("711", name, "tmp >= cont");  std::cout << (cont >= tmp);

    T tmp2 = tmp;
    if (cont.size())
        *x = cont.back();
    tmp2.push_back(*x);
        
    printTestName("718", name, "tmp < cont");   std::cout << (tmp2 < tmp);
    printTestName("719", name, "tmp > cont");   std::cout << (tmp2 > tmp);
    printTestName("720", name, "tmp <= cont");  std::cout << (tmp2 <= tmp);
    printTestName("721", name, "tmp >= cont");  std::cout << (tmp2 >= tmp);

    tmp.clear();
    printTestName("724", name, "tmp < cont");   std::cout << (tmp2 < tmp);
    printTestName("725", name, "tmp > cont");   std::cout << (tmp2 > tmp);
    printTestName("726", name, "tmp <= cont");  std::cout << (tmp2 <= tmp);
    printTestName("727", name, "tmp >= cont");  std::cout << (tmp2 >= tmp);

    tmp2.clear();
    printTestName("730", name, "tmp < cont");   std::cout << (tmp2 < tmp);
    printTestName("731", name, "tmp > cont");   std::cout << (tmp2 > tmp);
    printTestName("732", name, "tmp <= cont");  std::cout << (tmp2 <= tmp);
    printTestName("733", name, "tmp >= cont");  std::cout << (tmp2 >= tmp);

    delete x;
}

#endif
