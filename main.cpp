/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:37:35 by hherin            #+#    #+#             */
/*   Updated: 2021/01/26 23:41:35 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/tester.hpp"
#include "each_tests/ContainerCreate.hpp"
#include "each_tests/list_tests.hpp"
#include "each_tests/vector_tests.hpp"

std::ofstream stdFile;
std::ofstream ftFile;

void    CreateTestFiles()
{
    stdFile.open("results/std_vector.txt");
    ftFile.open("results/ft_vector.txt");
}

void	printTestNumber(int *nb)
{
	static int i = 0;

	if (nb)
		i = *nb;
	else
		std::cout << "\n---------------------\ntest " <<++i << ":\t";
}

int main(void)
{
    // char arrChar[20] =  {-1, 0, 32, 33, 48,  36, 76, 117, 82, 21, 105, 72, 99, 111, 125, 122, 43, 50, 69, 88};
    int arrInt[20] = {58966, 2147483647, 256, -2147483648, 0, -1, 2, 3, 4, 5, 6, 7, 7, 8, 54634152, 9, 10, 11, 56, 56465};
    // std::string arrString[20] = {"hello coco", "j'arrive", "oui-oui", "kafeolait", "jul d'ananas", "42", "gnou", "jura", "saperlipopette", "anticonstitutionnellement", "Pneumonoultramicroscopicsilicovolcanoconiosis", "Blue", "Red", "Orange", "Yellow", "boulette de viande hache",
    //                                 "raviolis du nord est", "PNY", "street bangkok", "confifi"};
    
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    CreateTestFiles();
    
	int nb = 0;
	printTestNumber(&nb);
	
    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to ft::vector_result.txt
    ContainerConstruct<int, std::vector<int> >(arrInt, executeVecNonConst<std::vector<int> >, executeVecConst<const std::vector<int> >);
    // ContainerConstruct<int, std::vector<int> >(arrInt, executeVecNonConst<std::vector<int> >, executeVecConst<const std::vector<int> >);
    // ContainerConstruct<std::string, std::vector<std::string> >(arrString, executeVecNonConst<std::string>, executeVecConst<std::string>);
    // ContainerConstruct<char, std::vector<char> >(arrChar, executeVecNonConst<char>, executeVecConst<char>);

	nb = 0;
	printTestNumber(&nb);

	std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to std::vector_result.txt
    ContainerConstruct<int, ft::vector<int> >(arrInt, executeVecNonConst<ft::vector<int> >, executeVecConst<const ft::vector<int> >);
    // ContainerConstruct<int, ft::vector<int> >(arrInt, executeVecNonConst<ft::vector<int> >, executeVecConst<const ft::vector<int> >);
    // ContainerConstruct<std::string, ft::vector<std::string> >(arrString, executeVecNonConst<std::string>, executeVecConst<std::string>);
    // ContainerConstruct<char, ft::vector<char> >(arrChar, executeVecNonConst<char>, executeVecConst<char>);

    std::cout.rdbuf(coutbuf); //reset to standard output again
    
}