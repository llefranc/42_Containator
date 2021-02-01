/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:37:35 by hherin            #+#    #+#             */
/*   Updated: 2021/02/01 13:51:02 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_and_utils/tester.hpp"
#include "each_tests/ContainerCreate.hpp"
#include "each_tests/list_tests.hpp"
#include "each_tests/vector_tests.hpp"

void	testVector(const char (&arrChar)[20], const int (&arrInt)[20], const std::string (&arrString)[20])
{
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::ofstream stdFile("results/vector_std.txt");
    std::ofstream ftFile("results/vector_ft.txt");
	
	(void)arrString;
    
	int nb = 0;
	getTestNumber(&nb);
	
    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to ft::vector_result.txt
    ContainerConstruct<int, std::vector<int> >(arrInt, testNotConstVec<std::vector<int> >, testConstVec<const std::vector<int> >);
    ContainerConstruct<std::string, std::vector<std::string> >(arrString, testNotConstVec<std::vector<std::string> >, testConstVec<const std::vector<std::string> >);
    ContainerConstruct<char, std::vector<char> >(arrChar, testNotConstVec<std::vector<char> >, testConstVec<const std::vector<char> >);

	nb = 0;
	getTestNumber(&nb);

	std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to std::vector_result.txt
    ContainerConstruct<int, ft::vector<int> >(arrInt, testNotConstVec<ft::vector<int> >, testConstVec<const ft::vector<int> >);
    ContainerConstruct<std::string, ft::vector<std::string> >(arrString, testNotConstVec<ft::vector<std::string> >, testConstVec<const ft::vector<std::string> >);
    ContainerConstruct<char, ft::vector<char> >(arrChar, testNotConstVec<ft::vector<char> >, testConstVec<const ft::vector<char> >);

    std::cout.rdbuf(coutbuf); //reset to standard output again
}

void	testList(const char (&arrChar)[20], const int (&arrInt)[20], const std::string (&arrString)[20])
{
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::ofstream stdFile("results/list_std.txt");
    std::ofstream ftFile("results/list_ft.txt");
	
	(void)arrString;
    
	int nb = 0;
	getTestNumber(&nb);
	
    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to ft::vector_result.txt
    ContainerConstruct<int, std::list<int> >(arrInt, testNotConstList<std::list<int> >, testConstList<const std::list<int> >);
    ContainerConstruct<std::string, std::list<std::string> >(arrString, testNotConstList<std::list<std::string> >, testConstList<const std::list<std::string> >);
    ContainerConstruct<char, std::list<char> >(arrChar, testNotConstList<std::list<char> >, testConstList<const std::list<char> >);

	nb = 0;
	getTestNumber(&nb);

	std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to std::list_result.txt
    ContainerConstruct<int, ft::list<int> >(arrInt, testNotConstList<ft::list<int> >, testConstList<const ft::list<int> >);
    ContainerConstruct<std::string, ft::list<std::string> >(arrString, testNotConstList<ft::list<std::string> >, testConstList<const ft::list<std::string> >);
    ContainerConstruct<char, ft::list<char> >(arrChar, testNotConstList<ft::list<char> >, testConstList<const ft::list<char> >);

    std::cout.rdbuf(coutbuf); //reset to standard output again
}

int main(void)
{
	const char arrChar[20] =  {94, 96, 32, 33, 48,  36, 76, 117, 82, 56, 99, 99, 99, 111, 125, 122, 43, 50, 69, 88};
    const int arrInt[20] = {58966, 2147483647, 256, -2147483648, 0, -1, 2, 3, 4, 5, 6, 7, 7, 8, 54634152, 9, 10, 11, 56, 56465};
    const std::string arrString[20] = {"hello coco", "j'arrive", "oui-oui", "kafeolait", "jul d'ananas", "jul d'ananas", "42", "jura", "saperlipopette", "anticonstitutionnellement", "Pneumonoultramicroscopicsilicovolcanoconiosis", "Blue", "Red", "Orange", "Yellow", "boulette de viande hache",
                                    "raviolis du nord est", "PNY", "street bangkok", "confifi"};

    
	testVector(arrChar, arrInt, arrString);
	testList(arrChar, arrInt, arrString);
}