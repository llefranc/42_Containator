/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:31:55 by llefranc          #+#    #+#             */
/*   Updated: 2021/01/29 13:41:41 by llefranc         ###   ########.fr       */
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

	printTestName(name);
	for (size_t i = 0; i < cont.size(); ++i)
		std::cout << cont[i] << " ";
}

template <typename T>
void	testSizeVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "size"));
	std::cout << "\n---------------------";
	
	printTestName(name);	std::cout << cont.size();
}

// template <typename T>
// void	testCapacityVec(T& cont)
// {
	// std::string name(getTestName(getTestNumber(0), "size"));
	// std::cout << "\n---------------------";
	
// 	printTestName(name);	std::cout << cont.capacity();
// }

template <typename T>
void	testEmptyVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "empty"));
	std::cout << "\n---------------------";
	
	printTestName(name);	std::cout << cont.empty();
}

template <typename T>
void	testIteratorsVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "iterators"));
	std::cout << "\n---------------------";
	
	printTestName(name, "operator++");
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); it++)
		std::cout << *it << " | ";

	printTestName(name, "++operator");
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << " | ";

	if (cont.size())
	{
		printTestName(name, "operator--");
		for (typename T::const_iterator it = cont.end(); it != cont.begin() - 1; it--)
			if (it != cont.end())
				std::cout << *it << " | ";

		printTestName(name, "--operator");
		for (typename T::const_iterator it = cont.end(); it != cont.begin() - 1; --it)
			if (it != cont.end())
				std::cout << *it << " | ";
	}

	printTestName(name, "operator+=");
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); it += 1)
		std::cout << *it << " | ";
	
	printTestName(name, "operator+");
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); it = it + 1)
		std::cout << *it << " | ";

	printTestName(name, "operator-=");
	for (typename T::const_iterator it = cont.end() - 1; it != cont.begin() - 1; it -= 1)
		std::cout << *it << " | ";

	printTestName(name, "operator-");
	for (typename T::const_iterator it = cont.end() - 1; it != cont.begin() - 1; it = it - 1)
		std::cout << *it << " | ";

	printTestName(name, "operator[]");
	for (ft::pair<size_t, typename T::const_iterator> i(0, cont.begin()); i.first < cont.size(); ++i.first)
		std::cout << i.second[i.first] << " | ";
}

template <typename T>
void	testReverseIteratorsVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "reverse iterators"));
	std::cout << "\n---------------------";
	
	printTestName(name, "++operator");
	for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); ++it)
		std::cout << *it << " | ";

	printTestName(name, "operator++");
	for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); it++)
		std::cout << *it << " | ";	

	if (cont.size())
	{
		printTestName(name, "operator--");
		for (typename T::const_reverse_iterator it = cont.rend(); it != cont.rbegin() - 1; it--)
			if (it != cont.rend())
				std::cout << *it << " | ";

		printTestName(name, "--operator");
		for (typename T::const_reverse_iterator it = cont.rend(); it != cont.rbegin() - 1; --it)
			if (it != cont.rend())
				std::cout << *it << " | ";
	}

	printTestName(name, "operator+=");
	for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); it += 1)
		std::cout << *it << " | ";
	
	printTestName(name, "operator+");
	for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); it = it + 1)
		std::cout << *it << " | ";

	printTestName(name, "operator-=");
	for (typename T::const_reverse_iterator it = cont.rend() - 1; it != cont.rbegin() - 1; it -= 1)
		std::cout << *it << " | ";

	printTestName(name, "operator-");
	for (typename T::const_reverse_iterator it = cont.rend() - 1; it != cont.rbegin() - 1; it = it - 1)
		std::cout << *it << " | ";

	printTestName(name, "operator[]");
	for (ft::pair<size_t, typename T::const_reverse_iterator> i(0, cont.rbegin()); i.first < cont.size(); ++i.first)
		std::cout << i.second[i.first] << " | ";
}

template <typename T>
void	testAtVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "at"));
	std::cout << "\n---------------------";
	
	printTestName(name);
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
	printTestName(name);
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
	
	printTestName(name);
	if (cont.size()) // To prevent overflow
		std::cout << cont.front();
}

template <typename T>
void	testBackVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "back"));
	std::cout << "\n---------------------";

	printTestName(name);
	if (cont.size()) // To prevent overflow
		std::cout << cont.back();
}

template <typename T>
void	testPushBackVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "push_back"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	
	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	T tmp = cont;
	tmp.push_back(*x);

	printContainer(name, tmp);

	delete x;
}

template <typename T>
void	testPopBackVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "pop_back"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	
	if (cont.size())
	{
		T tmp = cont;
		tmp.pop_back();
		printContainer(name, tmp);
	}
}

template <typename T>
void	testClearVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "clear"));
	std::cout << "\n---------------------";
	
	T tmp = cont;
	printTestName(name);	std::cout << "size before clear: " << tmp.size();
	tmp.clear();
	
	printTestName(name);	std::cout << "size after clear: " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	tmp.push_back(*x);
	printContainer(name, tmp);

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
	
	printTestName(name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();
	tmp2.swap(tmp);
	printContainer(name, tmp2);

	printTestName(name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();

	swap(tmp2, tmp);
	printTestName(name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();
	printContainer(name, tmp2);

	delete x;
}

template <typename T>
void	testResizeVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "resize"));
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	tmp.resize(3, *x);
	printContainer(name, tmp);

	printTestName(name);	std::cout << "size of tmp after resize = " << tmp.size();
	
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
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	T tmp2 = cont;
	tmp.resize(3, *x);
	tmp2.assign(tmp.begin(), tmp.end());

	printTestName(name);	std::cout << "size after assign = " << tmp2.size();
	printContainer(name, tmp2);

	delete x;
}

template <typename T>
void	testAssignNElemVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "assign n elems"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();
		
	tmp.resize(3, *x);

	T tmp2 = cont;
	tmp2.assign(tmp.size(), tmp.front());

	printTestName(name);	std::cout << "size after assign = " << tmp2.size();
	printContainer(name, tmp2);
		
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
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont[0])
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
	{
		*x = cont.front();
		typename T::iterator it = tmp.begin();
		++it;
		printTestName(name);	std::cout << "return value: " << *tmp.insert(it, *x);
	}
	printTestName(name);	std::cout << "return value: " << *tmp.insert(tmp.begin(), *x);
	printTestName(name);	std::cout << "return value: " << *tmp.insert(tmp.end(), *x);
	
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

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
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

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
	
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

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
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	tmp.insert(tmp.begin(), cont.begin(), cont.end());
	if (tmp.size())
	{
		typename T::iterator it = tmp.begin();
		++it;
		tmp.insert(it, cont.begin(), cont.end());
	}
	tmp.insert(tmp.end(), cont.begin(), cont.end());
	tmp.insert(tmp.end(), cont.begin(), cont.begin());
	
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);
}

template <typename T>
void	testEraseRangeVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "erase iterator range"));
	std::cout << "\n---------------------";

	// Erase everything
	{
		printTestName(name);	std::cout << "----- erase nothing -----";

		T tmp = cont;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin(), tmp.end());
		if (tmp.size())
			{ printTestName(name);	std::cout << "new elem after erase: " << *iter; }

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printContainer(name, tmp);
	}

	// Erase nothing
	{
		printTestName(name);	std::cout << "----- erase nothing -----";

		T tmp = cont;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.end(), tmp.end());
		
		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		iter = tmp.erase(tmp.begin(), tmp.begin());
		if (tmp.size())
			{ printTestName(name);	std::cout << "new elem after erase: " << *iter; }

		printContainer(name, tmp);
	}
	
	// Erase last elem
	if (cont.size())
	{
		printTestName(name);	std::cout << "----- erase last elem -----";
		
		T tmp = cont;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.end() - 1, tmp.end());

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printContainer(name, tmp);
	}

	// Erase everything except first elem
	if (cont.size())
	{
		printTestName(name);	std::cout << "----- erase everything except first elem -----";

		T tmp = cont;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin() + 1, tmp.end());

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printContainer(name, tmp);
	}

	// Erase only first elem
	if (cont.size())
	{
		printTestName(name);	std::cout << "----- erase only first elem -----";

		T tmp = cont;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin(), tmp.begin() + 1);

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printContainer(name, tmp);
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
		printTestName(name);	std::cout << "----- erase first elem -----";
		
		T tmp = cont;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		printContainer(name, tmp);
		typename T::iterator iter = tmp.erase(tmp.begin());
		if (tmp.size())
			{ printTestName(name);	std::cout << "return value: " << *iter; }
		printContainer(name, tmp);

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";
			
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	}

	// Erase last elem
	if (cont.size())
	{
		printTestName(name);	std::cout << "----- erase last elem -----";
		
		T tmp = cont;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.end() - 1);
		printContainer(name, tmp);

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	}

	// Erase one elem
	if (cont.size() > 1)
	{
		printTestName(name);	std::cout << "----- erase second elem -----";

		T tmp = cont;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin() + 1);
		if (tmp.size() > 2)
			{ printTestName(name);	std::cout << "return value: " << *iter; }
		printContainer(name, tmp);

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	}
}

template <typename T>
void	testOperatorEqualNotEqualVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "operator==/!="));
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName(name, "tmp == cont");	std::cout << (tmp == cont);
	printTestName(name, "tmp != cont");	std::cout << (tmp != cont);
	
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont[0];
	
	tmp.push_back(*x);
	printTestName(name, "tmp == cont");	std::cout << (tmp == cont);
	printTestName(name, "tmp != cont");	std::cout << (tmp != cont);

	T tmp2 = tmp;
	tmp.clear();
	printTestName(name, "tmp == cont");	std::cout << (tmp2 == tmp);
	printTestName(name, "tmp != cont");	std::cout << (tmp2 != tmp);

	tmp2.clear();
	printTestName(name, "tmp == cont");	std::cout << (tmp2 == tmp);
	printTestName(name, "tmp != cont");	std::cout << (tmp2 != tmp);

	delete x;
}

template <typename T>
void	testOperatorLessAndMoreVec(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "operator</>/<=/>="));
	std::cout << "\n---------------------";

	T tmp = cont;
	typename T::value_type* x = new typename T::value_type ();

	printTestName(name, "tmp < cont");	std::cout << (tmp < cont);
	printTestName(name, "tmp > cont");	std::cout << (tmp > cont);
	printTestName(name, "tmp <= cont");	std::cout << (tmp <= cont);
	printTestName(name, "tmp >= cont");	std::cout << (tmp >= cont);
	
	if (cont.size())
		*x = cont.front();
	tmp.push_back(*x);
	
	printTestName(name, "tmp < cont");	std::cout << (cont < tmp);
	printTestName(name, "tmp > cont");	std::cout << (cont > tmp);
	printTestName(name, "tmp <= cont");	std::cout << (cont <= tmp);
	printTestName(name, "tmp >= cont");	std::cout << (cont >= tmp);

	T tmp2 = tmp;
	if (cont.size())
		*x = cont.back();
	tmp2.push_back(*x);
	
	printTestName(name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName(name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName(name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName(name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

	tmp.clear();
	printTestName(name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName(name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName(name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName(name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

	tmp2.clear();
	printTestName(name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName(name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName(name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName(name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

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
	// testCapacityVec(cont);
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
	// testCapacityVec(cont);
	testEmptyVec(cont);
	testIteratorsVec(cont);
	testReverseIteratorsVec(cont);
	testAtVec(cont);
	testFrontVec(cont);
	testBackVec(cont);

}

#endif