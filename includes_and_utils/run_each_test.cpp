/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_each_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:10:27 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/18 15:01:46 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"
#include "../each_tests/create_containers.hpp"
#include "../select_your_tests/select_vector_tests.hpp"
#include "../select_your_tests/select_list_tests.hpp"
#include "../select_your_tests/select_stack_tests.hpp"
#include "../select_your_tests/select_queue_tests.hpp"
#include "../select_your_tests/select_map_tests.hpp"

void    testVector(const int (&arrInt)[20], const std::string (&arrString)[20])
{
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::ofstream stdFile("results/vector_std.txt");
    std::ofstream ftFile("results/vector_ft.txt");
        

    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to std::vector_result.txt
    constructVectorList<int, std::vector<int> >(arrInt, testNotConstVec<std::vector<int> >, testConstVec<const std::vector<int> >);
    constructVectorList<std::string, std::vector<std::string> >(arrString, testNotConstVec<std::vector<std::string> >, testConstVec<const std::vector<std::string> >);

    std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to ft::vector_result.txt
    constructVectorList<int, ft::vector<int> >(arrInt, testNotConstVec<ft::vector<int> >, testConstVec<const ft::vector<int> >);
    constructVectorList<std::string, ft::vector<std::string> >(arrString, testNotConstVec<ft::vector<std::string> >, testConstVec<const ft::vector<std::string> >);

    std::cout.rdbuf(coutbuf); //reset to standard output again
}

void    testList(const int (&arrInt)[20], const std::string (&arrString)[20])
{
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::ofstream stdFile("results/list_std.txt");
    std::ofstream ftFile("results/list_ft.txt");


    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to std::vector_result.txt
    constructVectorList<int, std::list<int> >(arrInt, testNotConstList<std::list<int> >, testConstList<const std::list<int> >);
    constructVectorList<std::string, std::list<std::string> >(arrString, testNotConstList<std::list<std::string> >, testConstList<const std::list<std::string> >);

    std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to ft::list_result.txt
    constructVectorList<int, ft::list<int> >(arrInt, testNotConstList<ft::list<int> >, testConstList<const ft::list<int> >);
    constructVectorList<std::string, ft::list<std::string> >(arrString, testNotConstList<ft::list<std::string> >, testConstList<const ft::list<std::string> >);

    std::cout.rdbuf(coutbuf); //reset to standard output again
}

void    testStack(const int (&arrInt)[20], const std::string (&arrString)[20])
{
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::ofstream stdFile("results/stack_std.txt");
    std::ofstream ftFile("results/stack_ft.txt");


    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to std::stack_result.txt
    constructStackQueue<int, std::stack<int, std::list<int> >, std::list<int> >(arrInt, testNonConstStack<std::stack<int, std::list<int> > >);
    constructStackQueue<std::string, std::stack<std::string, std::list<std::string> >, std::list<std::string> > (arrString, testNonConstStack<std::stack<std::string, std::list<std::string> > >);

    std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to ft::stack_result.txt
    constructStackQueue<int, ft::stack<int, std::list<int> >, std::list<int> >(arrInt, testNonConstStack<ft::stack<int, std::list<int> > >);
    constructStackQueue<std::string, ft::stack<std::string, ft::list<std::string> >, ft::list<std::string> >(arrString, testNonConstStack<ft::stack<std::string, ft::list<std::string> > >);

    std::cout.rdbuf(coutbuf); //reset to standard output again
}

void    testQueue(const int (&arrInt)[20], const std::string (&arrString)[20])
{
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::ofstream stdFile("results/queue_std.txt");
    std::ofstream ftFile("results/queue_ft.txt");
        
        
    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to std::queue_result.txt
    constructStackQueue<int, std::queue<int, std::list<int> >, std::list<int> >(arrInt, testNonConstQueue<std::queue<int, std::list<int> > >);
    constructStackQueue<std::string, std::queue<std::string, std::list<std::string> >, std::list<std::string> > (arrString, testNonConstQueue<std::queue<std::string, std::list<std::string> > >);
    
    std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to ft::queue_result.txt
    constructStackQueue<int, ft::queue<int, std::list<int> >, std::list<int> >(arrInt, testNonConstQueue<ft::queue<int, std::list<int> > >);
    constructStackQueue<std::string, ft::queue<std::string, ft::list<std::string> >, ft::list<std::string> >(arrString, testNonConstQueue<ft::queue<std::string, ft::list<std::string> > >);

    std::cout.rdbuf(coutbuf); //reset to standard output again
}

void    testMap(const int (&arrInt)[20], const std::string (&arrString)[20])
{
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::ofstream stdFile("results/map_std.txt");
    std::ofstream ftFile("results/map_ft.txt");
        
        
    std::cout.rdbuf(stdFile.rdbuf()); //redirect std::cout to ft::map_result.txt
    constructMap<int, std::string, std::map<int, std::string>, std::pair<int, std::string> >
        (arrInt, arrString, testNotConstMap<std::map<int, std::string> >, testConstMap<const std::map<int, std::string> >);
    constructMap<std::string, int, std::map<std::string, int>, std::pair<std::string, int> >
        (arrString, arrInt, testNotConstMap<std::map<std::string, int> >, testConstMap<const std::map<std::string, int> >);

    std::cout.rdbuf(ftFile.rdbuf()); //redirect std::cout to std::map_result.txt
    constructMap<int, std::string, ft::map<int, std::string>, ft::pair<int, std::string> >
        (arrInt, arrString, testNotConstMap<ft::map<int, std::string> >, testConstMap<const ft::map<int, std::string> >);
    constructMap<std::string, int, ft::map<std::string, int>, ft::pair<std::string, int> >
        (arrString, arrInt, testNotConstMap<ft::map<std::string, int> >, testConstMap<const ft::map<std::string, int> >);

    std::cout.rdbuf(coutbuf); //reset to standard output again
}