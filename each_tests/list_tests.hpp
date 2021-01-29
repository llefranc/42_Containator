/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:31:55 by llefranc          #+#    #+#             */
/*   Updated: 2021/01/29 15:30:52 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_TESTS_HPP
#define LIST_TESTS_HPP

#include "../includes_and_utils/tester.hpp"

template <typename T>
void	testSizeList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "size"));
	std::cout << "\n---------------------";
	
	printTestName(name);	std::cout << cont.size();
}

template <typename T>
void	testEmptyList(T& lis)
{
	std::string name(getTestName(getTestNumber(0), "empty"));
	std::cout << "\n---------------------";
	
	printTestName(name);	std::cout << lis.empty();
}

template <typename T>
void	testIteratorsList(T& cont)
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
		for (typename T::const_iterator it = cont.end(); it != cont.begin(); it--)
			if (it != cont.end())
				std::cout << *it << " | ";

		printTestName(name, "--operator");
		for (typename T::const_iterator it = cont.end(); it != cont.begin(); --it)
			if (it != cont.end())
				std::cout << *it << " | ";
	}
}

template <typename T>
void	testReverseIteratorsList(T& cont)
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
		for (typename T::const_reverse_iterator it = cont.rend(); it != cont.rbegin(); it--)
			if (it != cont.rend())
				std::cout << *it << " | ";

		printTestName(name, "--operator");
		for (typename T::const_reverse_iterator it = cont.rend(); it != cont.rbegin(); --it)
			if (it != cont.rend())
				std::cout << *it << " | ";
	}
}

template <typename T>
void	testFrontList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "front"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	if (cont.size()) // To prevent overflow
		std::cout << cont.front();
}

template <typename T>
void	testBackList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "back"));
	std::cout << "\n---------------------";

	printTestName(name);
	if (cont.size()) // To prevent overflow
		std::cout << cont.back();
}

template <typename T>
void	testPushBackList(T& cont)
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
void	testPopBackList(T& cont)
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
void	testPushFrontList(T& lis)
{
	std::string name(getTestName(getTestNumber(0), "push_front"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	
	// Allows to value initialize (case size is 0, we can't assign lis.front())
	typename T::value_type* x = new typename T::value_type ();
	if (lis.size())
		*x = lis.front();

	T tmp = lis;
	tmp.push_front(*x);

	printContainer(name, tmp);

	delete x;
}

template <typename T>
void	testPopFrontList(T& lis)
{
	std::string name(getTestName(getTestNumber(0), "pop_front"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	
	if (lis.size())
	{
		T tmp = lis;
		tmp.pop_front();
		printContainer(name, tmp);
	}
}

template <typename T>
void	testClearList(T& cont)
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
void	testSwapList(T& cont)
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
void	testResizeList(T& cont)
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
void	testAssignRangeList(T& cont)
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

/**
*	Inserts n elements.
*/
template <typename T>
void	testAssignNElemList(T& cont)
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
void	testInsert1ElemList(T& cont)
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
void	testInsertNElemList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "insert n elem"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
	{
		*x = cont.front();
		tmp.insert(++tmp.begin(), 5, *x);
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
void	testInsertRangeList(T& cont)
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
void	testEraseRangeList(T& cont)
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

		typename T::iterator pos = tmp.end();
		--pos;
		typename T::iterator iter = tmp.erase(pos, tmp.end());

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

		typename T::iterator pos = tmp.begin();
		++pos;
		typename T::iterator iter = tmp.erase(pos, tmp.end());

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

		typename T::iterator iter = tmp.erase(tmp.begin(), ++tmp.begin());

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printContainer(name, tmp);
	}
}

template <typename T>
void	testErase1ElemList(T& cont)
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

		typename T::iterator iter = tmp.erase(--tmp.end());
		printContainer(name, tmp);

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	}

	// Erase second elem
	if (cont.size() > 1)
	{
		printTestName(name);	std::cout << "----- erase second elem -----";

		T tmp = cont;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(++tmp.begin());
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
void	testSplice1ElemList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "splice 1 elem"));
	std::cout << "\n---------------------";

	// Splice at beginning
	{
		printTestName(name);	std::cout << "----- splice at beginning -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		tmp.splice(tmp.begin(), tmp2, tmp2.begin());

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);

		delete x;
	}

	// Splice at end
	{
		printTestName(name);	std::cout << "----- splice at end -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		tmp.splice(tmp.end(), tmp2, tmp2.begin());

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);

		delete x;
	}

	// Splice at second elem
	if (cont.size())
	{
		printTestName(name);	std::cout << "----- splice at second elem -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		tmp.splice(++tmp.begin(), tmp2, tmp2.begin());

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);

		delete x;
	}
}

template <typename T>
void	testSpliceAllList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "splice all list"));
	std::cout << "\n---------------------";

	// Splice at beginning
	{
		printTestName(name);	std::cout << "----- splice at beginning -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		tmp.splice(tmp.begin(), tmp2);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);

		delete x;
	}

	// Splice at end
	{
		printTestName(name);	std::cout << "----- splice at end -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		tmp.splice(tmp.end(), tmp2);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);

		delete x;
	}

	// Splice at second elem
	if (cont.size())
	{
		printTestName(name);	std::cout << "----- splice at second elem -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		tmp.splice(++tmp.begin(), tmp2);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);

		delete x;
	}
}

template <typename T>
void	testSpliceRangeList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "splice range"));
	std::cout << "\n---------------------";

	// Splice at beginning
	{
		printTestName(name);	std::cout << "----- splice 1 elem at beginning -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		tmp.splice(tmp.begin(), tmp2, tmp2.begin(), ++tmp2.begin());

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		delete x;
	}

	// Splice at end
	{
		printTestName(name);	std::cout << "----- splice all list at end -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		tmp.splice(tmp.end(), tmp2, tmp2.begin(), tmp2.end());

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		delete x;
	}

	// Splice at second elem
	if (cont.size())
	{
		printTestName(name);	std::cout << "----- splice everything except last elem at second elem -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		tmp.splice(++tmp.begin(), tmp2, tmp2.begin(), --tmp2.end());

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		delete x;
	}

	// Splice nothing
	if (cont.size())
	{
		printTestName(name);	std::cout << "----- splice nothing at second elem -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);
		
		tmp.splice(++tmp.begin(), tmp2, tmp2.begin(), tmp2.begin());
		tmp.splice(++tmp.begin(), tmp2, ++tmp2.begin(), ++tmp2.begin());
		tmp.splice(++tmp.begin(), tmp2, tmp2.end(), tmp2.end());

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printTestName(name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer(name, tmp);
		printContainer(name, tmp2);

		delete x;
	}
}

template <typename T>
void	testRemoveList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "remove"));
	std::cout << "\n---------------------";

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();
	
	T tmp = cont;

	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	tmp.remove(*x);
	
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	delete x;
}

template <typename T>
void	testRemoveIfList(T& cont)
{
	(void)cont;
	std::string name(getTestName(getTestNumber(0), "remove if"));
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	tmp.remove_if(predicateTest<typename T::value_type>);
	
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);
}

template <typename T>
void	testReverseList(T& lis)
{
	std::string name(getTestName(getTestNumber(0), "reverse"));
	std::cout << "\n---------------------";

	T tmp = lis;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	tmp.reverse();
	
	printTestName(name);	std::cout << "size after resize = " << tmp.size();
	printContainer(name, tmp);
}


template <typename T>
void	testNotConstList(T& lis, int testNb)
{
	std::cout << "\n\n--------------------------------\n";
	std::cout << "------\tTESTING LIST " << testNb << " ------\n";
	std::cout << "--------------------------------\n";
	
	std::cout << "\t\tLIST TYPE: ";
	print_type<typename T::value_type>();
	
	// Tests for non-const lists
	testSizeList(lis);
	testEmptyList(lis);
	testIteratorsList(lis);
	testReverseIteratorsList(lis);
	testFrontList(lis);
	testBackList(lis);
	testPushBackList(lis);
	testPopBackList(lis);
	testPushFrontList(lis);
	testPopFrontList(lis);
	testClearList(lis);
	testSwapList(lis);
	testResizeList(lis);
	testAssignRangeList(lis);
	testAssignNElemList(lis);
	testInsert1ElemList(lis);
	testInsertNElemList(lis);
	testInsertRangeList(lis);
	testEraseRangeList(lis);
	testErase1ElemList(lis);
	testSplice1ElemList(lis);
	testSpliceAllList(lis);
	testSpliceRangeList(lis);
	testRemoveList(lis);
	testRemoveIfList(lis);
	testReverseList(lis);
}

template <typename T>
void	testConstList(T& lis, int testNb)
{
	std::cout << "\n\n--------------------------------\n";
	std::cout << "------\tTESTING CONST LIST " << testNb << " ------\n";
	std::cout << "--------------------------------\n";
	
	std::cout << "\t\tLIST TYPE: ";
	print_type<typename T::value_type>();
	
	// Tests for const lists
	testSizeList(lis);
	testIteratorsList(lis);
	testReverseIteratorsList(lis);
	testFrontList(lis);
	testBackList(lis);
	testEmptyList(lis);
}

#endif