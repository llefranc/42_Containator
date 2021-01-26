/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:31:55 by llefranc          #+#    #+#             */
/*   Updated: 2021/01/27 00:10:00 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

#include "../includes/tester.hpp"

template <typename T>
void	testOperatorBraceletVec(T& vec)
{
	printTestNumber(0);
	std::cout << "operator[]: \n\t\t\t";
	
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
}

template <typename T>
void	testSizeVec(T& vec)
{
	printTestNumber(0);
	std::cout << "size: \n\t\t\t";
	
	std::cout << vec.size();
}

// template <typename T>
// void	testCapacityVec(T& vec)
// {
// 	printTestNumber(0);
// 	std::cout << "capacity: \n\t\t\t";
	
// 	std::cout << vec.capacity();
// }

template <typename T>
void	testEmptyVec(T& vec)
{
	printTestNumber(0);
	std::cout << "empty: \n\t\t\t";
	
	std::cout << vec.empty();
}

template <typename T>
void	testIteratorsVec(T& vec)
{
	printTestNumber(0);
	std::cout << "iterators: \n";
	
	std::cout << "\t\t\toperator++: ";
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " | ";

	std::cout << "\n\t\t\t++operator: ";
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " | ";

	if (vec.size())
	{
		std::cout << "\n\t\t\toperator--: ";
		for (typename T::const_iterator it = vec.end(); it != vec.begin() - 1; it--)
			if (it != vec.end())
				std::cout << *it << " | ";

		std::cout << "\n\t\t\t--operator: ";
		for (typename T::const_iterator it = vec.end(); it != vec.begin() - 1; --it)
			if (it != vec.end())
				std::cout << *it << " | ";
	}

	std::cout << "\n\t\t\toperator+=: ";
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); it += 1)
		std::cout << *it << " | ";
	
	std::cout << "\n\t\t\toperator+: ";
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); it = it + 1)
		std::cout << *it << " | ";

	std::cout << "\n\t\t\toperator-=: ";
	for (typename T::const_iterator it = vec.end() - 1; it != vec.begin() - 1; it -= 1)
		std::cout << *it << " | ";

	std::cout << "\n\t\t\toperator-: ";
	for (typename T::const_iterator it = vec.end() - 1; it != vec.begin() - 1; it = it - 1)
		std::cout << *it << " | ";

	std::cout << "\n\t\t\toperator[]: ";
	for (ft::pair<size_t, typename T::const_iterator> i(0, vec.begin()); i.first < vec.size(); ++i.first)
		std::cout << i.second[i.first] << " | ";
}

template <typename T>
void	testReverseIteratorsVec(T& vec)
{
	printTestNumber(0);
	std::cout << "reverse iterators: \n";
	
	std::cout << "\t\t\t++operator: ";
	for (typename T::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		std::cout << *it << " | ";

	std::cout << "\n\t\t\toperator++: ";
	for (typename T::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
		std::cout << *it << " | ";	

	if (vec.size())
	{
		std::cout << "\n\t\t\toperator--: ";
		for (typename T::const_reverse_iterator it = vec.rend(); it != vec.rbegin() - 1; it--)
			if (it != vec.rend())
				std::cout << *it << " | ";

		std::cout << "\n\t\t\t--operator: ";
		for (typename T::const_reverse_iterator it = vec.rend(); it != vec.rbegin() - 1; --it)
			if (it != vec.rend())
				std::cout << *it << " | ";
	}

	std::cout << "\n\t\t\toperator+=: ";
	for (typename T::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it += 1)
		std::cout << *it << " | ";
	
	std::cout << "\n\t\t\toperator+: ";
	for (typename T::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it = it + 1)
		std::cout << *it << " | ";

	std::cout << "\n\t\t\toperator-=: ";
	for (typename T::const_reverse_iterator it = vec.rend() - 1; it != vec.rbegin() - 1; it -= 1)
		std::cout << *it << " | ";

	std::cout << "\n\t\t\toperator-: ";
	for (typename T::const_reverse_iterator it = vec.rend() - 1; it != vec.rbegin() - 1; it = it - 1)
		std::cout << *it << " | ";

	std::cout << "\n\t\t\toperator[]: ";
	for (ft::pair<size_t, typename T::const_reverse_iterator> i(0, vec.rbegin()); i.first < vec.size(); ++i.first)
		std::cout << i.second[i.first] << " | ";
}
template <typename T>
void	testAtVec(T& vec)
{
	printTestNumber(0);
	std::cout << "at: \n\t\t\t";
	
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
	printTestNumber(0);
	std::cout << "front: \n\t\t\t";
	
	if (vec.size()) // To prevent overflow
		std::cout << vec.front();
}

template <typename T>
void	testBackVec(T& vec)
{
	printTestNumber(0);
	std::cout << "back: \n\t\t\t";
	
	if (vec.size()) // To prevent overflow
		std::cout << vec.back();
}

template <typename T>
void	testPushBackVec(T& vec)
{
	printTestNumber(0);
	std::cout << "push_back: \n\t\t\t";
	
	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];

	T tmp = vec;
	tmp.push_back(*x);
	std::cout << "new elem = " << tmp.back();

	std::cout << "\n\t\t\tnew tmp: ";
	for (typename T::const_iterator it = tmp.begin(); it != tmp.end(); ++it)
		std::cout << *it << " | ";

	delete x;
}

template <typename T>
void	testPopBackVec(T& vec)
{
	printTestNumber(0);
	std::cout << "pop_back: \n\t\t\t";
	
	if (vec.size())
	{
		T tmp = vec;
		tmp.pop_back();
		if (tmp.size()) // To prevent overflow
			std::cout << "new elem = " << tmp.back();

		std::cout << "\n\t\t\tnew tmp: ";
		for (typename T::const_iterator it = tmp.begin(); it != tmp.end(); ++it)
			std::cout << *it << " | ";
	}
}

template <typename T>
void	testClearVec(T& vec)
{
	printTestNumber(0);
	std::cout << "clear: \n\t\t\t";
	
	T tmp = vec;
	std::cout << "size before clear: " << tmp.size() << " | ";
	tmp.clear();
	std::cout << "\n\t\t\tsize after clear: " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];

	tmp.push_back(*x);
	std::cout << "\n\t\t\tnew vector: ";
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " | ";

	delete x;
}

template <typename T>
void	testSwapVec(T& vec)
{
	printTestNumber(0);
	std::cout << "swap member and non member: \n\t\t\t";

	T tmp(vec);
	T tmp2(vec);

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];

	tmp.push_back(*x);
	
	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size() << "\n";
	tmp2.swap(tmp);
	std::cout << "\t\t\tsize of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size() << "\n";

	swap(tmp2, tmp);
	std::cout << "\t\t\tsize of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();

	delete x;
}

template <typename T>
void	testResizeVec(T& vec)
{
	printTestNumber(0);
	std::cout << "resize: \n\t\t\t";

	T tmp = vec;
	std::cout << "size of tmp = " << tmp.size() << "\n";

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];

	tmp.resize(3, *x);
	std::cout << "\t\t\tnew elem = " << tmp.back();
	std::cout << "\n\t\t\tsize of tmp after resize = " << tmp.size();
	
	delete x;
}

/**
*	Test assign with iterators' range.
*/
template <typename T>
void	testAssign1Vec(T& vec)
{
	printTestNumber(0);
	std::cout << "assign1: \n\t\t\t";

	T tmp = vec;
	std::cout << "size of tmp = " << tmp.size() << "\n";

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];

	tmp.resize(3, *x);
	std::cout << "\t\t\tnew elem = " << tmp.back();

	T tmp2 = vec;
	tmp2.assign(tmp.begin(), tmp.end());
	std::cout << "\n\t\t\tsize after assign = " << tmp2.size() << " and content is:\n\t\t\t";

	for (typename T::iterator it = tmp2.begin(); it != tmp2.end(); ++it)
		std::cout << *it << " | ";

	delete x;
}

template <typename T>
void	testAssign2Vec(T& vec)
{
	printTestNumber(0);
	std::cout << "assign2: \n\t\t\t";

	T tmp = vec;
	std::cout << "size of tmp = " << tmp.size() << "\n";

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];
		
	tmp.resize(3, *x);
	std::cout << "\t\t\tnew elem = " << tmp.back();

	T tmp2 = vec;
	tmp2.assign(tmp.size(), tmp.front());
	std::cout << "\n\t\t\tsize after assign = " << tmp2.size() << " and content is:\n\t\t\t";

	for (typename T::iterator it = tmp2.begin(); it != tmp2.end(); ++it)
		std::cout << *it << " | ";
		
	delete x;
}

/**
*	Inserts one element.
*/
template <typename T>
void	testInsert1Vec(T& vec)
{
	printTestNumber(0);
	std::cout << "insert1: \n\t\t\t";

	T tmp = vec;
	std::cout << "size of tmp = " << tmp.size() << "\n";

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
	{
		*x = vec.front();
		std::cout << "\t\t\treturn value: " << *tmp.insert(tmp.begin() + 1, *x) << "\n";
	}
	std::cout << "\t\t\treturn value: " << *tmp.insert(tmp.begin(), *x) << "\n";
	std::cout << "\t\t\treturn value: " << *tmp.insert(tmp.end(), *x) << "\n";
	
	std::cout << "\t\t\tnew vector: ";
	for (typename T::iterator it = tmp.begin(); it != tmp.end(); ++it)
		std::cout << *it << " | ";
	std::cout << "\n\t\t\tsize of tmp = " << tmp.size();

	delete x;
}

/**
*	Inserts n elements.
*/
template <typename T>
void	testInsert2Vec(T& vec)
{
	printTestNumber(0);
	std::cout << "insert2: \n\t\t\t";

	T tmp = vec;
	std::cout << "size of tmp = " << tmp.size() << "\n";

	// Allows to value initialize (case size is 0, we can't assign vec[0])
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
	{
		*x = vec.front();
		tmp.insert(tmp.begin() + 1, 5, *x);
	}
	tmp.insert(tmp.begin(), 5, *x);
	tmp.insert(tmp.end(), 5, *x);
	
	std::cout << "\t\t\tnew vector: ";
	for (typename T::iterator it = tmp.begin(); it != tmp.end(); ++it)
		std::cout << *it << " | ";
	std::cout << "\n\t\t\tsize of tmp = " << tmp.size();

	delete x;
}

/**
*	Inserts an iterators' range of elements.
*/
template <typename T>
void	testInsert3Vec(T& vec)
{
	printTestNumber(0);
	std::cout << "insert3: \n\t\t\t";

	T tmp = vec;
	std::cout << "size of tmp = " << tmp.size() << "\n";

	tmp.insert(tmp.begin(), vec.begin(), vec.end());
	if (tmp.size())
		tmp.insert(tmp.begin() + 1, vec.begin(), vec.end());
	tmp.insert(tmp.end(), vec.begin(), vec.end());
	tmp.insert(tmp.end(), vec.begin(), vec.begin());
	
	std::cout << "\t\t\tnew vector: ";
	for (typename T::iterator it = tmp.begin(); it != tmp.end(); ++it)
		std::cout << *it << " | ";
	std::cout << "\n\t\t\tsize of tmp = " << tmp.size();
}

template <typename T>
void	testErase1Vec(T& vec)
{
	printTestNumber(0);
	std::cout << "erase1: \n\t\t\t";

	// Erase everything
	{
		T tmp = vec;
		std::cout << "size of tmp = " << tmp.size() << "\n\t\t\t";

		typename T::iterator iter = tmp.erase(tmp.begin(), tmp.end());
		if (tmp.size())
			std::cout << "new elem after erase: " << *iter << "\n\t\t\t";

		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";
		std::cout << "size of tmp = " << tmp.size() << "\n\t\t\t";
	}

	// Erase nothing
	{
		T tmp = vec;
		std::cout << "size of tmp = " << tmp.size() << "\n\t\t\t";

		typename T::iterator iter = tmp.erase(tmp.end(), tmp.end());
		
		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";
		std::cout << "\n\t\t\tsize of tmp = " << tmp.size();

		iter = tmp.erase(tmp.begin(), tmp.begin());
		if (tmp.size())
			std::cout << "\n\t\t\tnew elem after erase: " << *iter << "\n\t\t\t";
	}
	
	// Erase last elem
	if (vec.size())
	{
		T tmp = vec;
		std::cout << "size of tmp = " << tmp.size() << "\n\t\t\t";

		typename T::iterator iter = tmp.erase(tmp.end() - 1, tmp.end());

		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";
		std::cout << "\n\t\t\tsize of tmp = " << tmp.size() << "\n\t\t\t";
	}

	// Erase everything except first elem
	if (vec.size())
	{
		T tmp = vec;
		std::cout << "size of tmp = " << tmp.size() << "\n\t\t\t";

		typename T::iterator iter = tmp.erase(tmp.begin() + 1, tmp.end());

		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";
		std::cout << "\n\t\t\tsize of tmp = " << tmp.size();
	}
}

template <typename T>
void	testErase2Vec(T& vec)
{
	printTestNumber(0);
	std::cout << "erase2: \n\t\t\t";

	// Erase first elem
	if (vec.size())
	{
		T tmp = vec;
		std::cout << "size of tmp = " << tmp.size() << "\n\t\t\t";

		typename T::iterator iter = tmp.erase(tmp.begin());
		if (tmp.size())
			std::cout << "new elem after erase: " << *iter << "\n\t\t\t";

		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";
		std::cout << "size of tmp = " << tmp.size() << "\n\t\t\t";
	}

	// Erase last elem
	if (vec.size())
	{
		T tmp = vec;
		std::cout << "size of tmp = " << tmp.size() << "\n\t\t\t";

		typename T::iterator iter = tmp.erase(tmp.end() - 1);

		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";
		std::cout << "\n\t\t\tsize of tmp = " << tmp.size() << "\n\t\t\t";
	}

	// Erase one elem
	if (vec.size() > 1)
	{
		T tmp = vec;
		std::cout << "size of tmp = " << tmp.size() << "\n\t\t\t";

		typename T::iterator iter = tmp.erase(tmp.begin() + 1);

		for (typename T::iterator it = tmp.begin(); it != iter; ++it)
			std::cout << *it << " | ";
		std::cout << "\n\t\t\tsize of tmp = " << tmp.size();
	}
}

template <typename T>
void	testOperatorEqualNotEqualVec(T& vec)
{
	printTestNumber(0);
	std::cout << "operator==/!=: \n\t\t\t";

	T tmp = vec;

	std::cout << "tmp == vec (should be true): " << (tmp == vec) << "\n\t\t\t";
	std::cout << "tmp != vec (should be false): " << (tmp != vec) << "\n\t\t\t";
	
	typename T::value_type* x = new typename T::value_type ();
	if (vec.size())
		*x = vec[0];
	
	tmp.push_back(*x);
	std::cout << "tmp == vec (should be false): " << (tmp == vec) << "\n\t\t\t";
	std::cout << "tmp != vec (should be true): " << (tmp != vec) << "\n\t\t\t";

	T tmp2 = tmp;
	tmp.clear();
	std::cout << "tmp == vec (should be false): " << (tmp2 == tmp) << "\n\t\t\t";
	std::cout << "tmp2 != tmp (should be true): " << (tmp2 != tmp) << "\n\t\t\t";

	tmp2.clear();
	std::cout << "tmp == vec (should be true): " << (tmp2 == tmp) << "\n\t\t\t";
	std::cout << "tmp2 != tmp (should be false): " << (tmp2 != tmp);

	delete x;
}

template <typename T>
void	testOperatorLessAndMoreVec(T& vec)
{
	printTestNumber(0);
	std::cout << "operator</>/<=/>=: \n\t\t\t";

	T tmp = vec;
	typename T::value_type* x = new typename T::value_type ();

	std::cout << "tmp < vec: " << (tmp < vec) << "\n\t\t\t";
	std::cout << "tmp > vec: " << (tmp > vec) << "\n\t\t\t";
	std::cout << "tmp <= vec: " << (tmp <= vec) << "\n\t\t\t";
	std::cout << "tmp >= vec: " << (tmp >= vec) << "\n\t\t\t";
	
	if (vec.size())
		*x = vec.front();
	tmp.push_back(*x);
	
	std::cout << "vec < tmp: " << (vec < tmp) << "\n\t\t\t";
	std::cout << "vec > tmp: " << (vec > tmp) << "\n\t\t\t";
	std::cout << "vec <= tmp: " << (vec <= tmp) << "\n\t\t\t";
	std::cout << "vec >= tmp: " << (vec >= tmp) << "\n\t\t\t";

	T tmp2 = tmp;
	if (vec.size())
		*x = vec.back();
	tmp2.push_back(*x);
	
	std::cout << "tmp2 < tmp: " << (tmp2 < tmp) << "\n\t\t\t";
	std::cout << "tmp2 > tmp: " << (tmp2 > tmp) << "\n\t\t\t";
	std::cout << "tmp2 <= tmp: " << (tmp2 <= tmp) << "\n\t\t\t";
	std::cout << "tmp2 >= tmp: " << (tmp2 >= tmp) << "\n\t\t\t";

	tmp.clear();
	std::cout << "tmp2 < tmp: " << (tmp2 < tmp) << "\n\t\t\t";
	std::cout << "tmp2 > tmp: " << (tmp2 > tmp) << "\n\t\t\t";
	std::cout << "tmp2 <= tmp: " << (tmp2 <= tmp) << "\n\t\t\t";
	std::cout << "tmp2 >= tmp: " << (tmp2 >= tmp) << "\n\t\t\t";

	tmp2.clear();
	std::cout << "tmp2 < tmp: " << (tmp2 < tmp) << "\n\t\t\t";
	std::cout << "tmp2 > tmp: " << (tmp2 > tmp) << "\n\t\t\t";
	std::cout << "tmp2 <= tmp: " << (tmp2 <= tmp) << "\n\t\t\t";
	std::cout << "tmp2 >= tmp: " << (tmp2 >= tmp);

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
	testSwapVec(vec);
	testResizeVec(vec);
	testAssign1Vec(vec);
	testAssign2Vec(vec);
	testInsert1Vec(vec);
	testInsert2Vec(vec);
	testInsert3Vec(vec);
	testErase1Vec(vec);
	testErase2Vec(vec);
	testClearVec(vec);
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