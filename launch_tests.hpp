/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:51:31 by llefranc          #+#    #+#             */
/*   Updated: 2021/01/27 13:10:15 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCH_TEST_HPP
#define LAUNCH_TEST_HPP

#include <string>

extern std::ofstream stdFile;
extern std::ofstream ftFile;

void    CreateTestFiles(std::string fileName);

template <typename Tint, typename ftContInt, typename stdContInt >
void launch_tests(const char (&arrChar)[20], const int (&arrInt)[20], const std::string (&arrString)[20], const std::string& fileName)
{
	(void)arrChar;
	(void)arrString;
	
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	CreateTestFiles(fileName);

	int nb = 0;
	getTestNumber(&nb);

	std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to ft::filename_result.txt
	ContainerConstruct<Tint, ftContInt >(arrInt, executeVecNonConst<ftContInt >, executeVecConst<const ftContInt >);
	// ContainerConstruct<std::string, ftCont<std::string> >(arrString, executeVecNonConst<ftCont<std::string> >, executeVecConst<const ftCont<std::string> >);
	// ContainerConstruct<char, ftCont<char> >(arrChar, executeVecNonConst<ftCont<char> >, executeVecConst<const ftCont<char> >);

	nb = 0;
	getTestNumber(&nb);

	std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to std::filename_result.txt
	ContainerConstruct<Tint, stdContInt >(arrInt, executeVecNonConst<stdContInt >, executeVecConst<const stdContInt >);
	// ContainerConstruct<std::string, stdCont<std::string> >(arrString, executeVecNonConst<stdCont<std::string> >, executeVecConst<const stdCont<std::string> >);
	// ContainerConstruct<char, stdCont<char> >(arrChar, executeVecNonConst<stdCont<char> >, executeVecConst<const stdCont<char> >);

	std::cout.rdbuf(coutbuf); //reset to standard output again
}

#endif