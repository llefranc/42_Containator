/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:31:55 by llefranc          #+#    #+#             */
/*   Updated: 2021/01/27 12:45:21 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

#include "../includes_and_utils/tester.hpp"

template <typename T>
void	testOperatorBraceletVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "operator[]"));
	std::cout << "\n---------------------";

	printTestName(name);
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
}

template <typename T>
void	testSizeVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "size"));
	std::cout << "\n---------------------";
	
	printTestName(name);	std::cout << vec.size();
}

// template <typename T>
// void	testCapacityVec(T& vec)
// {
// 	getTestNumber(0);
// 	std::cout << "capacity: \n\t\t\t";
	
// 	std::cout << vec.capacity();
// }

template <typename T>
void	testEmptyVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "empty"));
	std::cout << "\n---------------------";
	
	printTestName(name);	std::cout << vec.empty();
}

template <typename T>
void	testIteratorsVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "iterators"));
	std::cout << "\n---------------------";
	
	printTestName(name, "operator++");
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " | ";

	printTestName(name, "++operator");
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " | ";

	if (vec.size())
	{
		printTestName(name, "operator--");
		for (typename T::const_iterator it = vec.end(); it != vec.begin() - 1; it--)
			if (it != vec.end())
				std::cout << *it << " | ";

		printTestName(name, "--operator");
		for (typename T::const_iterator it = vec.end(); it != vec.begin() - 1; --it)
			if (it != vec.end())
				std::cout << *it << " | ";
	}

	printTestName(name, "operator+=");
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); it += 1)
		std::cout << *it << " | ";
	
	printTestName(name, "operator+");
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); it = it + 1)
		std::cout << *it << " | ";

	printTestName(name, "operator-=");
	for (typename T::const_iterator it = vec.end() - 1; it != vec.begin() - 1; it -= 1)
		std::cout << *it << " | ";

	printTestName(name, "operator-");
	for (typename T::const_iterator it = vec.end() - 1; it != vec.begin() - 1; it = it - 1)
		std::cout << *it << " | ";

	printTestName(name, "operator[]");
	for (ft::pair<size_t, typename T::const_iterator> i(0, vec.begin()); i.first < vec.size(); ++i.first)
		std::cout << i.second[i.first] << " | ";
}

template <typename T>
void	testReverseIteratorsVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "reverse iterators"));
	std::cout << "\n---------------------";
	
	printTestName(name, "++operator");
	for (typename T::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		std::cout << *it << " | ";

	printTestName(name, "operator++");
	for (typename T::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
		std::cout << *it << " | ";	

	if (vec.size())
	{
		printTestName(name, "operator--");
		for (typename T::const_reverse_iterator it = vec.rend(); it != vec.rbegin() - 1; it--)
			if (it != vec.rend())
				std::cout << *it << " | ";

		printTestName(name, "--operator");
		for (typename T::const_reverse_iterator it = vec.rend(); it != vec.rbegin() - 1; --it)
			if (it != vec.rend())
				std::cout << *it << " | ";
	}

	printTestName(name, "operator+=");
	for (typename T::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it += 1)
		std::cout << *it << " | ";
	
	printTestName(name, "operator+");
	for (typename T::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it = it + 1)
		std::cout << *it << " | ";

	printTestName(name, "operator-=");
	for (typename T::const_reverse_iterator it = vec.rend() - 1; it != vec.rbegin() - 1; it -= 1)
		std::cout << *it << " | ";

	printTestName(name, "operator-");
	for (typename T::const_reverse_iterator it = vec.rend() - 1; it != vec.rbegin() - 1; it = it - 1)
		std::cout << *it << " | ";

	printTestName(name, "operator[]");
	for (ft::pair<size_t, typename T::const_reverse_iterator> i(0, vec.rbegin()); i.first < vec.size(); ++i.first)
		std::cout << i.second[i.first] << " | ";
}

template <typename T>
void	testAtVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "at"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	for (size_t i = 0; i < vec.size(); ++i)
	{
		try
		{
			std::cout << vec.at(i) << " ";
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
		std::cout << vec.at(100000) << " ";
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

template <typename T>
void	testFrontVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "front"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	if (vec.size()) // To prevent overflow
		std::cout << vec.front();
}

template <typename T>
void	testBackVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "back"));
	std::cout << "\n---------------------";

	printTestName(name);
	if (vec.size()) // To prevent overflow
		std::cout << vec.back();
}

template <typename T>
void	testPushBackVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "push_back"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	
	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];

	T tmp = vec;
	tmp.push_back(*x);

	printContainer(name, tmp);

	delete x;
}

template <typename T>
void	testPopBackVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "pop_back"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	
	if (vec.size())
	{
		T tmp = vec;
		tmp.pop_back();
		printContainer(name, tmp);
	}
}

template <typename T>
void	testClearVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "clear"));
	std::cout << "\n---------------------";
	
	T tmp = vec;
	printTestName(name);	std::cout << "size before clear: " << tmp.size();
	tmp.clear();
	
	printTestName(name);	std::cout << "size after clear: " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];

	tmp.push_back(*x);
	printContainer(name, tmp);

	delete x;
}

template <typename T>
void	testSwapVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "swap"));
	std::cout << "\n---------------------";
	
	T tmp(vec);
	T tmp2(vec);

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];

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
void	testResizeVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "resize"));
	std::cout << "\n---------------------";

	T tmp = vec;

	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];

	tmp.resize(3, *x);
	printContainer(name, tmp);

	printTestName(name);	std::cout << "size of tmp after resize = " << tmp.size();
	
	delete x;
}

/**
*	Test assign with iterators' range.
*/
template <typename T>
void	testAssignRangeVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "assign iterator range"));
	std::cout << "\n---------------------";

	T tmp = vec;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];

	T tmp2 = vec;
	tmp.resize(3, *x);
	tmp2.assign(tmp.begin(), tmp.end());

	printTestName(name);	std::cout << "size after assign = " << tmp2.size();
	printContainer(name, tmp2);

	delete x;
}

template <typename T>
void	testAssignNElemVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "assign n elems"));
	std::cout << "\n---------------------";

	T tmp = vec;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];
		
	tmp.resize(3, *x);

	T tmp2 = vec;
	tmp2.assign(tmp.size(), tmp.front());

	printTestName(name);	std::cout << "size after assign = " << tmp2.size();
	printContainer(name, tmp2);
		
	delete x;
}

/**
*	Inserts one element.
*/
template <typename T>
void	testInsert1ElemVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "insert 1 elem"));
	std::cout << "\n---------------------";

	T tmp = vec;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
	{
		*x = vec.front();
		printTestName(name);	std::cout << "return value: " << *tmp.insert(tmp.begin() + 1, *x);
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
void	testInsertNElemVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "insert n elem"));
	std::cout << "\n---------------------";

	T tmp = vec;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
	{
		*x = vec.front();
		tmp.insert(tmp.begin() + 1, 5, *x);
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
void	testInsertRangeVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "insert iterator range"));
	std::cout << "\n---------------------";

	T tmp = vec;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	tmp.insert(tmp.begin(), vec.begin(), vec.end());
	if (tmp.size())
		tmp.insert(tmp.begin() + 1, vec.begin(), vec.end());
	tmp.insert(tmp.end(), vec.begin(), vec.end());
	tmp.insert(tmp.end(), vec.begin(), vec.begin());
	
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);
}

template <typename T>
void	testEraseRangeVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "erase iterator range"));
	std::cout << "\n---------------------";

	// Erase everything
	{
		T tmp = vec;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin(), tmp.end());
		if (tmp.size())
			{ printTestName(name);	std::cout << "new elem after erase: " << *iter; }

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printContainer(name, tmp);
	}

	// Erase nothing
	{
		T tmp = vec;
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
	if (vec.size())
	{
		T tmp = vec;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.end() - 1, tmp.end());

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printContainer(name, tmp);
	}

	// Erase everything except first elem
	if (vec.size())
	{
		T tmp = vec;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin() + 1, tmp.end());

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
		printContainer(name, tmp);
	}
}

template <typename T>
void	testErase1ElemVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "erase 1 elem"));
	std::cout << "\n---------------------";

	// Erase first elem
	if (vec.size())
	{
		T tmp = vec;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin());
		if (tmp.size())
			{ printTestName(name);	std::cout << "new elem after erase: " << *iter; }

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";
			
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	}

	// Erase last elem
	if (vec.size())
	{
		T tmp = vec;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.end() - 1);

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	}

	// Erase one elem
	if (vec.size() > 1)
	{
		T tmp = vec;
		printTestName(name);	std::cout << "size of tmp = " << tmp.size();

		typename T::iterator iter = tmp.erase(tmp.begin() + 1);

		printTestName(name);
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";

		printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	}
}

template <typename T>
void	testOperatorEqualNotEqualVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "operator==/!="));
	std::cout << "\n---------------------";

	T tmp = vec;

	printTestName(name, "tmp == vec");	std::cout << (tmp == vec);
	printTestName(name, "tmp != vec");	std::cout << (tmp != vec);
	
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];
	
	tmp.push_back(*x);
	printTestName(name, "tmp == vec");	std::cout << (tmp == vec);
	printTestName(name, "tmp != vec");	std::cout << (tmp != vec);

	T tmp2 = tmp;
	tmp.clear();
	printTestName(name, "tmp == vec");	std::cout << (tmp2 == tmp);
	printTestName(name, "tmp != vec");	std::cout << (tmp2 != tmp);

	tmp2.clear();
	printTestName(name, "tmp == vec");	std::cout << (tmp2 == tmp);
	printTestName(name, "tmp != vec");	std::cout << (tmp2 != tmp);

	delete x;
}

template <typename T>
void	testOperatorLessAndMoreVec(T& vec)
{
	std::string name(getTestName(getTestNumber(0), "operator</>/<=/>="));
	std::cout << "\n---------------------";

	T tmp = vec;
	typename T::value_type* x = new typename T::value_type ();

	printTestName(name, "tmp < vec");	std::cout << (tmp < vec);
	printTestName(name, "tmp > vec");	std::cout << (tmp > vec);
	printTestName(name, "tmp <= vec");	std::cout << (tmp <= vec);
	printTestName(name, "tmp >= vec");	std::cout << (tmp >= vec);
	
	if (vec.size())
		*x = vec.front();
	tmp.push_back(*x);
	
	printTestName(name, "tmp < vec");	std::cout << (vec < tmp);
	printTestName(name, "tmp > vec");	std::cout << (vec > tmp);
	printTestName(name, "tmp <= vec");	std::cout << (vec <= tmp);
	printTestName(name, "tmp >= vec");	std::cout << (vec >= tmp);

	T tmp2 = tmp;
	if (vec.size())
		*x = vec.back();
	tmp2.push_back(*x);
	
	printTestName(name, "tmp < vec");	std::cout << (tmp2 < tmp);
	printTestName(name, "tmp > vec");	std::cout << (tmp2 > tmp);
	printTestName(name, "tmp <= vec");	std::cout << (tmp2 <= tmp);
	printTestName(name, "tmp >= vec");	std::cout << (tmp2 >= tmp);

	tmp.clear();
	printTestName(name, "tmp < vec");	std::cout << (tmp2 < tmp);
	printTestName(name, "tmp > vec");	std::cout << (tmp2 > tmp);
	printTestName(name, "tmp <= vec");	std::cout << (tmp2 <= tmp);
	printTestName(name, "tmp >= vec");	std::cout << (tmp2 >= tmp);

	tmp2.clear();
	printTestName(name, "tmp < vec");	std::cout << (tmp2 < tmp);
	printTestName(name, "tmp > vec");	std::cout << (tmp2 > tmp);
	printTestName(name, "tmp <= vec");	std::cout << (tmp2 <= tmp);
	printTestName(name, "tmp >= vec");	std::cout << (tmp2 >= tmp);

	delete x;
}


template <typename T>
void	executeVecNonConst(T& vec, int testNb)
{
	std::cout << "\n\n--------------------------------\n";
	std::cout << "------\tTESTING VECTOR " << testNb << " ------\n";
	std::cout << "--------------------------------\n";
	
	std::cout << "\t\tVECTOR TYPE: ";
	print_type<typename T::value_type>();
	
	// Tests for non-const vectors
	testOperatorBraceletVec(vec);
	testSizeVec(vec);
	testEmptyVec(vec);
	// testCapacityVec(vec);
	testIteratorsVec(vec);
	testReverseIteratorsVec(vec);
	testAtVec(vec);
	testFrontVec(vec);
	testBackVec(vec);
	testPushBackVec(vec);
	testPopBackVec(vec);
	testClearVec(vec);
	testSwapVec(vec);
	testResizeVec(vec);
	testAssignRangeVec(vec);
	testAssignNElemVec(vec);
	testInsert1ElemVec(vec);
	testInsertNElemVec(vec);
	testInsertRangeVec(vec);
	testEraseRangeVec(vec);
	testErase1ElemVec(vec);
	testOperatorEqualNotEqualVec(vec);
	testOperatorLessAndMoreVec(vec);
}

template <typename T>
void	executeVecConst(T& vec, int testNb)
{
	std::cout << "\n\n--------------------------------\n";
	std::cout << "------\tTESTING CONST VECTOR " << testNb << " ------\n";
	std::cout << "--------------------------------\n";
	
	std::cout << "\t\tVECTOR TYPE: ";
	print_type<typename T::value_type>();
	
	// Tests for const vectors
	testOperatorBraceletVec(vec);
	testSizeVec(vec);
	// testCapacityVec(vec);
	testEmptyVec(vec);
	testIteratorsVec(vec);
	testReverseIteratorsVec(vec);
	testAtVec(vec);
	testFrontVec(vec);
	testBackVec(vec);

}

#endif