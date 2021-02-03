/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_each_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:10:27 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/03 16:17:49 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"
#include "../each_tests/create_containers.hpp"
#include "../select_your_tests/select_vector_tests.hpp"
#include "../select_your_tests/select_list_tests.hpp"
#include "../select_your_tests/select_stack_tests.hpp"
#include "../select_your_tests/select_queue_tests.hpp"

void	testVector(const int (&arrInt)[20], const std::string (&arrString)[20])
{
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::ofstream stdFile("results/vector_std.txt");
    std::ofstream ftFile("results/vector_ft.txt");
	
	int nb = 0;
	getTestNumber(&nb);
	
    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to ft::vector_result.txt
    ContainerConstruct<int, std::vector<int> >(arrInt, testNotConstVec<std::vector<int> >, testConstVec<const std::vector<int> >);
    ContainerConstruct<std::string, std::vector<std::string> >(arrString, testNotConstVec<std::vector<std::string> >, testConstVec<const std::vector<std::string> >);

	nb = 0;
	getTestNumber(&nb);

	std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to std::vector_result.txt
    ContainerConstruct<int, ft::vector<int> >(arrInt, testNotConstVec<ft::vector<int> >, testConstVec<const ft::vector<int> >);
    ContainerConstruct<std::string, ft::vector<std::string> >(arrString, testNotConstVec<ft::vector<std::string> >, testConstVec<const ft::vector<std::string> >);

    std::cout.rdbuf(coutbuf); //reset to standard output again
}

void	testList(const int (&arrInt)[20], const std::string (&arrString)[20])
{
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::ofstream stdFile("results/list_std.txt");
    std::ofstream ftFile("results/list_ft.txt");
	
	int nb = 0;
	getTestNumber(&nb);
	
    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to ft::vector_result.txt
    ContainerConstruct<int, std::list<int> >(arrInt, testNotConstList<std::list<int> >, testConstList<const std::list<int> >);
    ContainerConstruct<std::string, std::list<std::string> >(arrString, testNotConstList<std::list<std::string> >, testConstList<const std::list<std::string> >);

	nb = 0;
	getTestNumber(&nb);

	std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to std::list_result.txt
    ContainerConstruct<int, ft::list<int> >(arrInt, testNotConstList<ft::list<int> >, testConstList<const ft::list<int> >);
    ContainerConstruct<std::string, ft::list<std::string> >(arrString, testNotConstList<ft::list<std::string> >, testConstList<const ft::list<std::string> >);

    std::cout.rdbuf(coutbuf); //reset to standard output again
}

void    testStack(const int (&arrInt)[20], const std::string (&arrString)[20])
{
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::ofstream stdFile("results/stack_std.txt");
    std::ofstream ftFile("results/stack_ft.txt");
	    
	int nb = 0;
	getTestNumber(&nb);
	
    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to std::stack_result.txt
    StaQueuConstruct<int, std::stack<int, std::list<int> >, std::list<int> >(arrInt, testNonConstStack<std::stack<int, std::list<int> > >);
    StaQueuConstruct<std::string, std::stack<std::string, std::list<std::string> >, std::list<std::string> > (arrString, testNonConstStack<std::stack<std::string, std::list<std::string> > >);
    
	nb = 0;
	getTestNumber(&nb);

	std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to ft::stack_result.txt
    StaQueuConstruct<int, ft::stack<int, std::list<int> >, std::list<int> >(arrInt, testNonConstStack<ft::stack<int, std::list<int> > >);
    StaQueuConstruct<std::string, ft::stack<std::string, ft::list<std::string> >, ft::list<std::string> >(arrString, testNonConstStack<ft::stack<std::string, ft::list<std::string> > >);

    std::cout.rdbuf(coutbuf); //reset to standard output again
}

void    testQueue(const int (&arrInt)[20], const std::string (&arrString)[20])
{
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::ofstream stdFile("results/queue_std.txt");
    std::ofstream ftFile("results/queue_ft.txt");
	    
	int nb = 0;
	getTestNumber(&nb);
	
    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to std::queue_result.txt
    StaQueuConstruct<int, std::queue<int, std::list<int> >, std::list<int> >(arrInt, testNonConstQueue<std::queue<int, std::list<int> > >);
    StaQueuConstruct<std::string, std::queue<std::string, std::list<std::string> >, std::list<std::string> > (arrString, testNonConstQueue<std::queue<std::string, std::list<std::string> > >);
    
	nb = 0;
	getTestNumber(&nb);

	std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to ft::queue_result.txt
    StaQueuConstruct<int, ft::queue<int, std::list<int> >, std::list<int> >(arrInt, testNonConstQueue<ft::queue<int, std::list<int> > >);
    StaQueuConstruct<std::string, ft::queue<std::string, ft::list<std::string> >, ft::list<std::string> >(arrString, testNonConstQueue<ft::queue<std::string, ft::list<std::string> > >);

    std::cout.rdbuf(coutbuf); //reset to standard output again
}
