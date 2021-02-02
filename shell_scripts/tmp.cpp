/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:31:55 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/02 08:06:11 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_TESTS_HPP
#define LIST_TESTS_HPP

#include "../includes_and_utils/tester.hpp"

template <typename T>
void	testSizeList(T& cont)
{
	std::string name("size:");
	std::cout << "\n---------------------";
	
	printTestName("24", name);	std::cout << cont.size();
}

template <typename T>
void	testEmptyList(T& lis)
{
	std::string name("empty:");
	std::cout << "\n---------------------";
	
	printTestName("33", name);	std::cout << lis.empty();
}

template <typename T>
void	testIteratorsList(T& cont)
{
	std::string name("iterators:");
	std::cout << "\n---------------------";
	
	printTestName("42", name, "operator++");
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); it++)
		std::cout << *it << " | ";

	printTestName("46", name, "++operator");
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << " | ";

	if (cont.size())
	{
		printTestName("52", name, "operator--");
		for (typename T::const_iterator it = cont.end(); it != cont.begin(); it--)
			if (it != cont.end())
				std::cout << *it << " | ";

		printTestName("57", name, "--operator");
		for (typename T::const_iterator it = cont.end(); it != cont.begin(); --it)
			if (it != cont.end())
				std::cout << *it << " | ";
	}
}

template <typename T>
void	testReverseIteratorsList(T& cont)
{
	std::string name("reverse iterators:");
	std::cout << "\n---------------------";
	
	printTestName("70", name, "++operator");
	for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); ++it)
		std::cout << *it << " | ";

	printTestName("74", name, "operator++");
	for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); it++)
		std::cout << *it << " | ";	

	if (cont.size())
	{
		printTestName("80", name, "operator--");
		for (typename T::const_reverse_iterator it = cont.rend(); it != cont.rbegin(); it--)
			if (it != cont.rend())
				std::cout << *it << " | ";

		printTestName("85", name, "--operator");
		for (typename T::const_reverse_iterator it = cont.rend(); it != cont.rbegin(); --it)
			if (it != cont.rend())
				std::cout << *it << " | ";
	}
}

template <typename T>
void	testFrontList(T& cont)
{
	std::string name("front:");
	std::cout << "\n---------------------";
	
	printTestName("98", name);
	if (cont.size()) // To prevent overflow
		std::cout << cont.front();
}

template <typename T>
void	testBackList(T& cont)
{
	std::string name("back:");
	std::cout << "\n---------------------";

	printTestName("109", name);
	if (cont.size()) // To prevent overflow
		std::cout << cont.back();
}

template <typename T>
void	testPushBackList(T& cont)
{
	std::string name("push_back:");
	std::cout << "\n---------------------";
	
	printTestName("120", name);
	
	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	T tmp = cont;
	tmp.push_back(*x);

	printContainer("130", name, tmp);

	delete x;
}

template <typename T>
void	testPopBackList(T& cont)
{
	std::string name("pop_back:");
	std::cout << "\n---------------------";
	
	printTestName("141", name);
	
	if (cont.size())
	{
		T tmp = cont;
		tmp.pop_back();
		printContainer("147", name, tmp);
	}
}

template <typename T>
void	testPushFrontList(T& lis)
{
	std::string name("push_front:");
	std::cout << "\n---------------------";
	
	printTestName("157", name);
	
	// Allows to value initialize (case size is 0, we can't assign lis.front())
	typename T::value_type* x = new typename T::value_type ();
	if (lis.size())
		*x = lis.front();

	T tmp = lis;
	tmp.push_front(*x);

	printContainer("167", name, tmp);

	delete x;
}

template <typename T>
void	testPopFrontList(T& lis)
{
	std::string name("pop_front:");
	std::cout << "\n---------------------";
	
	printTestName("178", name);
	
	if (lis.size())
	{
		T tmp = lis;
		tmp.pop_front();
		printContainer("184", name, tmp);
	}
}

template <typename T>
void	testClearList(T& cont)
{
	std::string name("clear:");
	std::cout << "\n---------------------";
	
	T tmp = cont;
	printTestName("195", name);	std::cout << "size before clear: " << tmp.size();
	tmp.clear();
	
	printTestName("198", name);	std::cout << "size after clear: " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	tmp.push_back(*x);
	printContainer("206", name, tmp);

	delete x;
}

template <typename T>
void	testSwapList(T& cont)
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
	
	printTestName("227", name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();
	tmp2.swap(tmp);
	printContainer("229", name, tmp2);

	printTestName("231", name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();

	swap(tmp2, tmp);
	printTestName("234", name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();
	printContainer("235", name, tmp2);

	delete x;
}

template <typename T>
void	testResizeList(T& cont)
{
	std::string name("resize:");
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName("248", name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	tmp.resize(3, *x);
	printContainer("256", name, tmp);

	printTestName("258", name);	std::cout << "size of tmp after resize = " << tmp.size();
	
	delete x;
}

/**
*	Test assign with iterators' range.
*/
template <typename T>
void	testAssignRangeList(T& cont)
{
	std::string name("assign iterator range:");
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName("273", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("274", name, tmp);

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	T tmp2 = cont;
	tmp.resize(3, *x);
	tmp2.assign(tmp.begin(), tmp.end());

	printTestName("285", name);	std::cout << "size after assign = " << tmp2.size();
	printContainer("286", name, tmp2);

	delete x;
}

/**
*	Inserts n elements.
*/
template <typename T>
void	testAssignNElemList(T& cont)
{
	std::string name("assign n elems:");
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName("301", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("302", name, tmp);

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();
		
	tmp.resize(3, *x);

	T tmp2 = cont;
	tmp2.assign(tmp.size(), tmp.front());

	printTestName("314", name);	std::cout << "size after assign = " << tmp2.size();
	printContainer("315", name, tmp2);
		
	delete x;
}

/**
*	Inserts one element.
*/
template <typename T>
void	testInsert1ElemList(T& cont)
{
	std::string name("insert 1 elem:");
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName("330", name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont[0])
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
	{
		*x = cont.front();
		typename T::iterator it = tmp.begin();
		++it;
		printTestName("339", name);	std::cout << "return value: " << *tmp.insert(it, *x);
	}
	printTestName("341", name);	std::cout << "return value: " << *tmp.insert(tmp.begin(), *x);
	printTestName("342", name);	std::cout << "return value: " << *tmp.insert(tmp.end(), *x);
	
	printTestName("344", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("345", name, tmp);

	delete x;
}

/**
*	Inserts n elements.
*/
template <typename T>
void	testInsertNElemList(T& cont)
{
	std::string name("insert n elem:");
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName("360", name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
	{
		*x = cont.front();
		tmp.insert(++tmp.begin(), 5, *x);
	}
	tmp.insert(tmp.begin(), 5, *x);
	tmp.insert(tmp.end(), 5, *x);
	
	printTestName("372", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("373", name, tmp);

	delete x;
}

/**
*	Inserts an iterators' range of elements.
*/
template <typename T>
void	testInsertRangeList(T& cont)
{
	std::string name("insert iterator range:");
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName("388", name);	std::cout << "size of tmp = " << tmp.size();

	tmp.insert(tmp.begin(), cont.begin(), cont.end());
	if (tmp.size())
	{
		typename T::iterator it = tmp.begin();
		++it;
		tmp.insert(it, cont.begin(), cont.end());
	}
	tmp.insert(tmp.end(), cont.begin(), cont.end());
	tmp.insert(tmp.end(), cont.begin(), cont.begin());
	
	printTestName("400", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("401", name, tmp);
}

template <typename T>
void	testEraseRangeList(T& cont)
{
	std::string name("erase iterator range:");
	std::cout << "\n---------------------";

	// Erase everything
	{
		printTestName("412", name);	std::cout << "----- erase nothing -----";

		T tmp = cont;
		printTestName("415", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin(), tmp.end());
		if (tmp.size())
			{ printTestName("419", name);	std::cout << "new elem after erase: " << *iter; }

		printTestName("421", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("422", name, tmp);
	}

	// Erase nothing
	{
		printTestName("427", name);	std::cout << "----- erase nothing -----";
		
		T tmp = cont;
		printTestName("430", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.end(), tmp.end());
		
		printTestName("434", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("438", name);	std::cout << "size of tmp = " << tmp.size();

		iter = tmp.erase(tmp.begin(), tmp.begin());
		if (tmp.size())
			{ printTestName("442", name);	std::cout << "new elem after erase: " << *iter; }

		printContainer("444", name, tmp);
	}
	
	// Erase last elem
	if (cont.size())
	{
		printTestName("450", name);	std::cout << "----- erase last elem -----";
		
		T tmp = cont;
		printTestName("453", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator pos = tmp.end();
		--pos;
		typename T::iterator iter = tmp.erase(pos, tmp.end());

		printTestName("459", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("463", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("464", name, tmp);
	}

	// Erase everything except first elem
	if (cont.size())
	{
		printTestName("470", name);	std::cout << "----- erase everything except first elem -----";
		
		T tmp = cont;
		printTestName("473", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator pos = tmp.begin();
		++pos;
		typename T::iterator iter = tmp.erase(pos, tmp.end());

		printTestName("479", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("483", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("484", name, tmp);
	}

	// Erase only first elem
	if (cont.size())
	{
		printTestName("490", name);	std::cout << "----- erase only first elem -----";

		T tmp = cont;
		printTestName("493", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin(), ++tmp.begin());

		printTestName("497", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("501", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("502", name, tmp);
	}
}

template <typename T>
void	testErase1ElemList(T& cont)
{
	std::string name("erase 1 elem:");
	std::cout << "\n---------------------";

	// Erase first elem
	if (cont.size() > 1)
	{
		printTestName("515", name);	std::cout << "----- erase first elem -----";
		
		T tmp = cont;
		printTestName("518", name);	std::cout << "size of tmp = " << tmp.size();

		printContainer("520", name, tmp);
		typename T::iterator iter = tmp.erase(tmp.begin());
		if (tmp.size())
			{ printTestName("523", name);	std::cout << "return value: " << *iter; }
		printContainer("524", name, tmp);

		printTestName("526", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";
			
		printTestName("530", name);	std::cout << "size of tmp = " << tmp.size();
	}

	// Erase last elem
	if (cont.size())
	{
		printTestName("536", name);	std::cout << "----- erase last elem -----";

		T tmp = cont;
		printTestName("539", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(--tmp.end());
		printContainer("542", name, tmp);

		printTestName("544", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("548", name);	std::cout << "size of tmp = " << tmp.size();
	}

	// Erase second elem
	if (cont.size() > 1)
	{
		printTestName("554", name);	std::cout << "----- erase second elem -----";

		T tmp = cont;
		printTestName("557", name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(++tmp.begin());
		if (tmp.size() > 2)
			{ printTestName("561", name);	std::cout << "return value: " << *iter; }
		printContainer("562", name, tmp);

		printTestName("564", name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName("568", name);	std::cout << "size of tmp = " << tmp.size();
	}
}

template <typename T>
void	testSplice1ElemList(T& cont)
{
	std::string name("splice 1 elem:");
	std::cout << "\n---------------------";

	// Splice at beginning
	{
		printTestName("580", name);	std::cout << "----- splice at beginning -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName("591", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("592", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("593", name, tmp);
		printContainer("594", name, tmp2);
		
		tmp.splice(tmp.begin(), tmp2, tmp2.begin());

		printTestName("598", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("599", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("600", name, tmp);
		printContainer("601", name, tmp2);

		delete x;
	}

	// Splice at end
	{
		printTestName("608", name);	std::cout << "----- splice at end -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName("619", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("620", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("621", name, tmp);
		printContainer("622", name, tmp2);
		
		tmp.splice(tmp.end(), tmp2, tmp2.begin());

		printTestName("626", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("627", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("628", name, tmp);
		printContainer("629", name, tmp2);

		delete x;
	}

	// Splice at second elem
	if (cont.size())
	{
		printTestName("637", name);	std::cout << "----- splice at second elem -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName("648", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("649", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("650", name, tmp);
		printContainer("651", name, tmp2);
		
		tmp.splice(++tmp.begin(), tmp2, tmp2.begin());

		printTestName("655", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("656", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("657", name, tmp);
		printContainer("658", name, tmp2);

		delete x;
	}
}

template <typename T>
void	testSpliceAllList(T& cont)
{
	std::string name("splice all list:");
	std::cout << "\n---------------------";

	// Splice at beginning
	{
		printTestName("672", name);	std::cout << "----- splice at beginning -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName("683", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("684", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("685", name, tmp);
		printContainer("686", name, tmp2);
		
		tmp.splice(tmp.begin(), tmp2);

		printTestName("690", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("691", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("692", name, tmp);
		printContainer("693", name, tmp2);

		delete x;
	}

	// Splice at end
	{
		printTestName("700", name);	std::cout << "----- splice at end -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName("711", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("712", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("713", name, tmp);
		printContainer("714", name, tmp2);
		
		tmp.splice(tmp.end(), tmp2);

		printTestName("718", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("719", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("720", name, tmp);
		printContainer("721", name, tmp2);

		delete x;
	}

	// Splice at second elem
	if (cont.size())
	{
		printTestName("729", name);	std::cout << "----- splice at second elem -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName("740", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("741", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("742", name, tmp);
		printContainer("743", name, tmp2);
		
		tmp.splice(++tmp.begin(), tmp2);

		printTestName("747", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("748", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("749", name, tmp);
		printContainer("750", name, tmp2);

		delete x;
	}
}

template <typename T>
void	testSpliceRangeList(T& cont)
{
	std::string name("splice range:");
	std::cout << "\n---------------------";

	// Splice at beginning
	{
		printTestName("764", name);	std::cout << "----- splice 1 elem at beginning -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName("775", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("776", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("777", name, tmp);
		printContainer("778", name, tmp2);
		
		tmp.splice(tmp.begin(), tmp2, tmp2.begin(), ++tmp2.begin());

		printTestName("782", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("783", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("784", name, tmp);
		printContainer("785", name, tmp2);
		
		delete x;
	}

	// Splice at end
	{
		printTestName("792", name);	std::cout << "----- splice all list at end -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName("803", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("804", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("805", name, tmp);
		printContainer("806", name, tmp2);
		
		tmp.splice(tmp.end(), tmp2, tmp2.begin(), tmp2.end());

		printTestName("810", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("811", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("812", name, tmp);
		printContainer("813", name, tmp2);
		
		delete x;
	}

	// Splice at second elem
	if (cont.size())
	{
		printTestName("821", name);	std::cout << "----- splice everything except last elem at second elem -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName("832", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("833", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("834", name, tmp);
		printContainer("835", name, tmp2);
		
		tmp.splice(++tmp.begin(), tmp2, tmp2.begin(), --tmp2.end());

		printTestName("839", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("840", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("841", name, tmp);
		printContainer("842", name, tmp2);
		
		delete x;
	}

	// Splice nothing
	if (cont.size())
	{
		printTestName("850", name);	std::cout << "----- splice nothing at second elem -----";

		// Allows to value initialize (case size is 0, we can't assign cont.front())
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		T tmp = cont;
		T tmp2 = cont;
		tmp2.push_front(*x);

		printTestName("861", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("862", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("863", name, tmp);
		printContainer("864", name, tmp2);
		
		tmp.splice(++tmp.begin(), tmp2, tmp2.begin(), tmp2.begin());
		tmp.splice(++tmp.begin(), tmp2, ++tmp2.begin(), ++tmp2.begin());
		tmp.splice(++tmp.begin(), tmp2, tmp2.end(), tmp2.end());

		printTestName("870", name);	std::cout << "size of tmp = " << tmp.size();
		printTestName("871", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("872", name, tmp);
		printContainer("873", name, tmp2);

		delete x;
	}
}

template <typename T>
void	testRemoveList(T& cont)
{
	std::string name("remove:");
	std::cout << "\n---------------------";

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();
	
	T tmp = cont;

	printTestName("892", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("893", name, tmp);

	tmp.remove(*x);
	
	printTestName("897", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("898", name, tmp);

	delete x;
}

template <typename T>
void	testRemoveIfList(T& cont)
{
	std::string name("remove if:");
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName("911", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("912", name, tmp);

	tmp.remove_if(predicateTest<typename T::value_type>);
	
	printTestName("916", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("917", name, tmp);
}

template <typename T>
void	testUniqueList(T& cont)
{
	std::string name("unique:");
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName("928", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("929", name, tmp);

	tmp.unique();
	
	printTestName("933", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("934", name, tmp);
}

template <typename T>
void	testUniqueBinaryPredicateList(T& cont)
{
	std::string name("unique binary predicate:");
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName("945", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("946", name, tmp);

	tmp.unique(binaryPredicateTest<typename T::value_type>);
	
	printTestName("950", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("951", name, tmp);
}

template <typename T>
void	testMergeList(T& cont)
{
	std::string name("merge:");
	std::cout << "\n---------------------";

	// Merging 2 non empty list
	{
		printTestName("962", name);	std::cout << "----- merging two non empty list -----";
		
		T tmp = cont;
		T tmp2 = cont;
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		for (int i = 0; i < 3; ++i)
			tmp2.push_front(*x);
		for (int i = 0; i < 3; ++i)
			tmp2.push_back(*x);

		printTestName("975", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("976", name, tmp);
		printTestName("977", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("978", name, tmp2);

		tmp.merge(tmp2);

		printTestName("982", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("983", name, tmp);
		printTestName("984", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("985", name, tmp2);

		delete x;
	}

	// Merging one empty list into non empty list
	{
		printTestName("992", name);	std::cout << "----- merging one empty list into non empty list -----";
		
		T tmp = cont;
		T tmp2 = cont;
		
		tmp2.clear();

		printTestName("999", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1000", name, tmp);
		printTestName("1001", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1002", name, tmp2);

		tmp.merge(tmp2);

		printTestName("1006", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1007", name, tmp);
		printTestName("1008", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1009", name, tmp2);
	}

	// Merging non empty list into empty list
	{
		printTestName("1014", name);	std::cout << "----- merging non empty list into empty list -----";

		T tmp = cont;
		T tmp2 = cont;
		
		tmp.clear();

		printTestName("1021", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1022", name, tmp);
		printTestName("1023", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1024", name, tmp2);

		tmp.merge(tmp2);

		printTestName("1028", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1029", name, tmp);
		printTestName("1030", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1031", name, tmp2);
	}

	// Merging two empty list
	{
		printTestName("1036", name);	std::cout << "----- merging two empty list -----";
		
		T tmp = cont;
		T tmp2 = cont;
		
		tmp.clear();
		tmp2.clear();

		printTestName("1044", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1045", name, tmp);
		printTestName("1046", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1047", name, tmp2);

		tmp.merge(tmp2);

		printTestName("1051", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1052", name, tmp);
		printTestName("1053", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1054", name, tmp2);
	}
}

template <typename T>
void	testMergePredicateList(T& cont)
{
	std::string name("merge predicate:");
	std::cout << "\n---------------------";

	// Merging 2 non empty list
	{
		printTestName("962", name);	std::cout << "----- merging two non empty list -----";
		
		T tmp = cont;
		T tmp2 = cont;
		typename T::value_type* x = new typename T::value_type ();
		if (cont.size())
			*x = cont.front();

		for (int i = 0; i < 3; ++i)
			tmp2.push_front(*x);
		for (int i = 0; i < 3; ++i)
			tmp2.push_back(*x);

		printTestName("975", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("976", name, tmp);
		printTestName("977", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("978", name, tmp2);

		tmp.merge(tmp2, binaryPredicateTest<typename T::value_type>);

		printTestName("982", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("983", name, tmp);
		printTestName("984", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("985", name, tmp2);

		delete x;
	}

	// Merging one empty list into non empty list
	{
		printTestName("992", name);	std::cout << "----- merging one empty list into non empty list -----";
		
		T tmp = cont;
		T tmp2 = cont;
		
		tmp2.clear();

		printTestName("999", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1000", name, tmp);
		printTestName("1001", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1002", name, tmp2);

		tmp.merge(tmp2, binaryPredicateTest<typename T::value_type>);

		printTestName("1006", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1007", name, tmp);
		printTestName("1008", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1009", name, tmp2);
	}

	// Merging non empty list into empty list
	{
		printTestName("1014", name);	std::cout << "----- merging non empty list into empty list -----";

		T tmp = cont;
		T tmp2 = cont;
		
		tmp.clear();

		printTestName("1021", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1022", name, tmp);
		printTestName("1023", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1024", name, tmp2);

		tmp.merge(tmp2, binaryPredicateTest<typename T::value_type>);

		printTestName("1028", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1029", name, tmp);
		printTestName("1030", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1031", name, tmp2);
	}

	// Merging two empty list
	{
		printTestName("1036", name);	std::cout << "----- merging two empty list -----";
		
		T tmp = cont;
		T tmp2 = cont;
		
		tmp.clear();
		tmp2.clear();

		printTestName("1044", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1045", name, tmp);
		printTestName("1046", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1047", name, tmp2);

		tmp.merge(tmp2, binaryPredicateTest<typename T::value_type>);

		printTestName("1051", name);	std::cout << "size of tmp = " << tmp.size();
		printContainer("1052", name, tmp);
		printTestName("1053", name);	std::cout << "size of tmp2 = " << tmp2.size();
		printContainer("1054", name, tmp2);
	}
}

template <typename T>
void	testSortList(T& lis)
{
	std::string name("sort:");
	std::cout << "\n---------------------";

	T tmp = lis;
	printTestName("1169", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("1170", name, tmp);

	tmp.sort();
	
	printTestName("1174", name);	std::cout << "size after resize = " << tmp.size();
	printContainer("1175", name, tmp);
}

template <typename T>
void	testSortPredicateList(T& lis)
{
	std::string name("sort predicate:");
	std::cout << "\n---------------------";

	T tmp = lis;
	printTestName("1185", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("1186", name, tmp);

	tmp.sort(binaryPredicateTest<typename T::value_type>);
	
	printTestName("1190", name);	std::cout << "size after resize = " << tmp.size();
	printContainer("1191", name, tmp);
}

template <typename T>
void	testReverseList(T& lis)
{
	std::string name("reverse:");
	std::cout << "\n---------------------";

	T tmp = lis;
	printTestName("1201", name);	std::cout << "size of tmp = " << tmp.size();
	printContainer("1202", name, tmp);

	tmp.reverse();
	
	printTestName("1206", name);	std::cout << "size after resize = " << tmp.size();
	printContainer("1207", name, tmp);
}

template <typename T>
void	testOperatorEqualNotEqualList(T& cont)
{
	std::string name("operator==/!=:");
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName("1218", name, "tmp == cont");	std::cout << (tmp == cont);
	printTestName("1219", name, "tmp != cont");	std::cout << (tmp != cont);
	
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();
	
	tmp.push_back(*x);
	printTestName("1226", name, "tmp == cont");	std::cout << (tmp == cont);
	printTestName("1227", name, "tmp != cont");	std::cout << (tmp != cont);

	T tmp2 = tmp;
	tmp.clear();
	printTestName("1231", name, "tmp == cont");	std::cout << (tmp2 == tmp);
	printTestName("1232", name, "tmp != cont");	std::cout << (tmp2 != tmp);

	tmp2.clear();
	printTestName("1235", name, "tmp == cont");	std::cout << (tmp2 == tmp);
	printTestName("1236", name, "tmp != cont");	std::cout << (tmp2 != tmp);

	delete x;
}

template <typename T>
void	testOperatorLessAndMoreList(T& cont)
{
	std::string name("operator</>/<=/>=:");
	std::cout << "\n---------------------";

	T tmp = cont;
	typename T::value_type* x = new typename T::value_type ();

	printTestName("1250", name, "tmp < cont");	std::cout << (tmp < cont);
	printTestName("1251", name, "tmp > cont");	std::cout << (tmp > cont);
	printTestName("1252", name, "tmp <= cont");	std::cout << (tmp <= cont);
	printTestName("1253", name, "tmp >= cont");	std::cout << (tmp >= cont);
	
	if (cont.size())
		*x = cont.front();
	tmp.push_back(*x);
	
	printTestName("1259", name, "tmp < cont");	std::cout << (cont < tmp);
	printTestName("1260", name, "tmp > cont");	std::cout << (cont > tmp);
	printTestName("1261", name, "tmp <= cont");	std::cout << (cont <= tmp);
	printTestName("1262", name, "tmp >= cont");	std::cout << (cont >= tmp);

	T tmp2 = tmp;
	if (cont.size())
		*x = cont.back();
	tmp2.push_back(*x);
	
	printTestName("1269", name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName("1270", name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName("1271", name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName("1272", name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

	tmp.clear();
	printTestName("1275", name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName("1276", name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName("1277", name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName("1278", name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

	tmp2.clear();
	printTestName("1281", name, "tmp < cont");	std::cout << (tmp2 < tmp);
	printTestName("1282", name, "tmp > cont");	std::cout << (tmp2 > tmp);
	printTestName("1283", name, "tmp <= cont");	std::cout << (tmp2 <= tmp);
	printTestName("1284", name, "tmp >= cont");	std::cout << (tmp2 >= tmp);

	delete x;
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
	testUniqueList(lis);
	testUniqueBinaryPredicateList(lis);
	testMergeList(lis);
	testMergePredicateList(lis);
	testSortList(lis);
	testSortPredicateList(lis);
	testReverseList(lis);
	testOperatorEqualNotEqualList(lis);
	testOperatorLessAndMoreList(lis);
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















































