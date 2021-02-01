/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:31:55 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/01 15:44:20 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

#include "../includes_and_utils/tester.hpp"

template <typename T>
void	testOperatorBraceletVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "operator[]"));
	std::cout << "\n---------------------";

	printTestName("24", name);
	for (size_t i = 0; i < cont.size(); ++i)
		std::cout << cont[i] << " ";
}

template <typename T>
void	testSizeVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "size"));
	std::cout << "\n---------------------";
	
	printTestName("35", name);	std::cout << cont.size();
}

template <typename T>
void	testEmptyVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "empty"));
	std::cout << "\n---------------------";
	
	printTestName("44", name);	std::cout << cont.empty();
}

template <typename T>
void	testIteratorsVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "iterators"));
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
	for (ft::pair<size_t, typename T::const_iterator> i(0, cont.begin()); i.first < cont.size(); ++i.first)
		std::cout << i.second[i.first] << " | ";
}

template <typename T>
void	testReverseIteratorsVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "reverse iterators"));
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
	for (ft::pair<size_t, typename T::const_reverse_iterator> i(0, cont.rbegin()); i.first < cont.size(); ++i.first)
		std::cout << i.second[i.first] << " | ";
}

template <typename T>
void	testAtVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "at"));
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
			std::cout << e.what();
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
		std::cout << e.what();
	}
}

template <typename T>
void	testFrontVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "front"));
	std::cout << "\n---------------------";
	
	printTestName("180", name);
	if (cont.size()) // To prevent overflow
		std::cout << cont.front();
}

template <typename T>
void	testBackVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "back"));
	std::cout << "\n---------------------";

	printTestName("191", name);
	if (cont.size()) // To prevent overflow
		std::cout << cont.back();
}

template <typename T>
void	testPushBackVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "push_back"));
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
void	testPopBackVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "pop_back"));
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
void	testClearVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "clear"));
	std::cout << "\n---------------------";
	
	T tmp = cont;
	printTestName("240", name);	std::cout << "size before clear: " << tmp.size();
	tmp.clear();
	
	printTestName("243", name);	std::cout << "size after clear: " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	tmp.push_back(*x);
	printContainer("251", name, tmp);

	delete x;
}

template <typename T>
void	testSwapVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "swap"));
	std::cout << "\n---------------------";
	
	T tmp(cont);
	T tmp2(cont);

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	tmp.push_back(*x);
	
	printTestName("272", name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();
	tmp2.swap(tmp);
	printContainer("274", name, tmp2);

	printTestName("276", name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();

	swap(tmp2, tmp);
	printTestName("279", name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();
	printContainer("280", name, tmp2);

	delete x;
}

template <typename T>
void	testResizeVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "resize"));
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName("293", name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	tmp.resize(3, *x);
	printContainer("301", name, tmp);

	printTestName("303", name);	std::cout << "size of tmp after resize = " << tmp.size();
	
	delete x;
}

/**
*	Test assign with iterators' range.
*/
template <typename T>
void	testAssignRangeVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "assign iterator range"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName("318", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("319", name, tmp);

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	T tmp2 = cont;
	tmp.resize(3, *x);
	tmp2.assign(tmp.begin(), tmp.end());

	printTestName("330", name);	std::cout << "size after assign = " << tmp2.size();
	printContainer("331", name, tmp2);

	delete x;
}

template <typename T>
void	testAssignNElemVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "assign n elems"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName("343", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("344", name, tmp);

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();
		
	tmp.resize(3, *x);

	T tmp2 = cont;
	tmp2.assign(tmp.size(), tmp.front());

	printTestName("356", name);	std::cout << "size after assign = " << tmp2.size();
	printContainer("357", name, tmp2);
		
	delete x;
}

/**
*	Inserts one element.
*/
template <typename T>
void	testInsert1ElemVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "insert 1 elem"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName("372", name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont[0])
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
	{
		*x = cont.front();
		typename T::iterator it = tmp.begin();
		++it;
		printTestName("381", name);	std::cout << "return value: " << *tmp.insert(it, *x);
	}
	printTestName("383", name);	std::cout << "return value: " << *tmp.insert(tmp.begin(), *x);
	printTestName("384", name);	std::cout << "return value: " << *tmp.insert(tmp.end(), *x);
	
	printTestName("386", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("387", name, tmp);

	delete x;
}

/**
*	Inserts n elements.
*/
template <typename T>
void	testInsertNElemVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "insert n elem"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName("402", name);	std::cout << "size of tmp = " << tmp.size();

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
	
	printTestName("416", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("417", name, tmp);

	delete x;
}

/**
*	Inserts an iterators' range of elements.
*/
template <typename T>
void	testInsertRangeVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "insert iterator range"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName("432", name);	std::cout << "size of tmp = " << tmp.size();

	tmp.insert(tmp.begin(), cont.begin(), cont.end());
	if (tmp.size())
	{
		typename T::iterator it = tmp.begin();
		++it;
		tmp.insert(it, cont.begin(), cont.end());
	}
	tmp.insert(tmp.end(), cont.begin(), cont.end());
	tmp.insert(tmp.end(), cont.begin(), cont.begin());
	
	printTestName("444", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("445", name, tmp);
}

template <typename T>
void	testEraseRangeVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "erase iterator range"));
	std::cout << "\n---------------------";

	// Erase everything
	{
		printTestName("456", name);	std::cout << "----- erase nothing -----";

		T tmp = cont;
		printTestName("459", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin(), tmp.end());
		if (tmp.size())
			{ printTestName("463", name);	std::cout << "new elem after erase: " << *iter; }

		printTestName("465", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("466", name, tmp);
	}

	// Erase nothing
	{
		printTestName("471", name);	std::cout << "----- erase nothing -----";

		T tmp = cont;
		printTestName("474", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.end(), tmp.end());
		
		printTestName("478", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("482", name);	std::cout << "size of tmp = " << tmp.size();

		iter = tmp.erase(tmp.begin(), tmp.begin());
		if (tmp.size())
			{ printTestName("486", name);	std::cout << "new elem after erase: " << *iter; }

		printContainer("488", name, tmp);
	}
	
	// Erase last elem
	if (cont.size())
	{
		printTestName("494", name);	std::cout << "----- erase last elem -----";
		
		T tmp = cont;
		printTestName("497", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.end() - 1, tmp.end());

		printTestName("501", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("505", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("506", name, tmp);
	}

	// Erase everything except first elem
	if (cont.size())
	{
		printTestName("512", name);	std::cout << "----- erase everything except first elem -----";

		T tmp = cont;
		printTestName("515", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin() + 1, tmp.end());

		printTestName("519", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("523", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("524", name, tmp);
	}

	// Erase only first elem
	if (cont.size())
	{
		printTestName("530", name);	std::cout << "----- erase only first elem -----";

		T tmp = cont;
		printTestName("533", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin(), tmp.begin() + 1);

		printTestName("537", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("541", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("542", name, tmp);
	}
}

template <typename T>
void	testErase1ElemVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "erase 1 elem"));
	std::cout << "\n---------------------";

	// Erase first elem
	if (cont.size() > 1)
	{
		printTestName("555", name);	std::cout << "----- erase first elem -----";
		
		T tmp = cont;
		printTestName("558", name);	std::cout << "size of tmp = " << tmp.size();

		printContainer("560", name, tmp);
		typename T::iterator iter = tmp.erase(tmp.begin());
		if (tmp.size())
			{ printTestName("563", name);	std::cout << "return value: " << *iter; }
		printContainer("564", name, tmp);

		printTestName("566", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";
			
		printTestName("570", name);	std::cout << "size of tmp = " << tmp.size();
	}

	// Erase last elem
	if (cont.size())
	{
		printTestName("576", name);	std::cout << "----- erase last elem -----";
		
		T tmp = cont;
		printTestName("579", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.end() - 1);
		printContainer("582", name, tmp);

		printTestName("584", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("588", name);	std::cout << "size of tmp = " << tmp.size();
	}

	// Erase one elem
	if (cont.size() > 1)
	{
		printTestName("594", name);	std::cout << "----- erase second elem -----";

		T tmp = cont;
		printTestName("597", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin() + 1);
		if (tmp.size() > 2)
			{ printTestName("601", name);	std::cout << "return value: " << *iter; }
		printContainer("602", name, tmp);

		printTestName("604", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("608", name);	std::cout << "size of tmp = " << tmp.size();
	}
}

template <typename T>
void	testOperatorEqualNotEqualVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "operator==/!="));
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName("620", name, "tmp == cont");	std::cout << (tmp == cont);
	printTestName("621", name, "tmp != cont");	std::cout << (tmp != cont);
	
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont[0];
	
	tmp.push_back(*x);
	printTestName("628", name, "tmp == cont");	std::cout << (tmp == cont);
	printTestName("629", name, "tmp != cont");	std::cout << (tmp != cont);

	T tmp2 = tmp;
	tmp.clear();
	printTestName("633", name, "tmp == cont");	std::cout << (tmp2 == tmp);
	printTestName("634", name, "tmp != cont");	std::cout << (tmp2 != tmp);

	tmp2.clear();
	printTestName("637", name, "tmp == cont");	std::cout << (tmp2 == tmp);
	printTestName("638", name, "tmp != cont");	std::cout << (tmp2 != tmp);

	delete x;
}

template <typename T>
void	testOperatorLessAndMoreVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "operator</>/<=/>="));
	std::cout << "\n---------------------";

	T tmp = cont;
	typename T::value_type* x = new typename T::value_type ();

	printTestName("652", name, "tmp < cont");	std::cout << (tmp < cont);
	printTestName("653", name, "tmp > cont");	std::cout << (tmp > cont);
	printTestName("654", name, "tmp <= cont");	std::cout << (tmp <= cont);
	printTestName("655", name, "tmp >= cont");	std::cout << (tmp >= cont);
	
	if (cont.size())
		*x = cont.front();
	tmp.push_back(*x);
	
	printTestName("661", name, "tmp < cont");	std::cout << (cont < tmp);
	printTestName("662", name, "tmp > cont");	std::cout << (cont > tmp);
	printTestName("663", name, "tmp <= cont");	std::cout << (cont <= tmp);
	printTestName("664", name, "tmp >= cont");	std::cout << (cont >= tmp);

	T tmp2 = tmp;
	if (cont.size())
		*x = cont.back();
	tmp2.push_back(*x);
	
	printTestName("671", name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName("672", name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName("673", name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName("674", name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

	tmp.clear();
	printTestName("677", name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName("678", name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName("679", name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName("680", name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

	tmp2.clear();
	printTestName("683", name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName("684", name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName("685", name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName("686", name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

	delete x;
}


template <typename T>
void	testNotConstVec(T& cont, int testNb)
{
	std::cout << "\n\n--------------------------------\n";
	std::cout << "------\tTESTING VECTOR " << testNb << " ------\n";
	std::cout << "--------------------------------\n";
	
	std::cout << "\t\tVECTOR TYPE: ";
	print_type<typename T::value_type>();
	
	// Tests for non-const vectors
	testOperatorBraceletVec(cont);
	testSizeVec(cont);
	testEmptyVec(cont);
	testIteratorsVec(cont);
	testReverseIteratorsVec(cont);
	testAtVec(cont);
	testFrontVec(cont);
	testBackVec(cont);
	testPushBackVec(cont);
	testPopBackVec(cont);
	testClearVec(cont);
	testSwapVec(cont);
	testResizeVec(cont);
	testAssignRangeVec(cont);
	testAssignNElemVec(cont);
	testInsert1ElemVec(cont);
	testInsertNElemVec(cont);
	testInsertRangeVec(cont);
	testEraseRangeVec(cont);
	testErase1ElemVec(cont);
	testOperatorEqualNotEqualVec(cont);
	testOperatorLessAndMoreVec(cont);
}

template <typename T>
void	testConstVec(T& cont, int testNb)
{
	std::cout << "\n\n--------------------------------\n";
	std::cout << "------\tTESTING CONST VECTOR " << testNb << " ------\n";
	std::cout << "--------------------------------\n";
	
	std::cout << "\t\tVECTOR TYPE: ";
	print_type<typename T::value_type>();
	
	// Tests for const vectors
	testOperatorBraceletVec(cont);
	testSizeVec(cont);
	testEmptyVec(cont);
	testIteratorsVec(cont);
	testReverseIteratorsVec(cont);
	testAtVec(cont);
	testFrontVec(cont);
	testBackVec(cont);

}

#endif



































































































































