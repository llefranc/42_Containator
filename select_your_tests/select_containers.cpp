/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_containers.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:37:35 by hherin            #+#    #+#             */
/*   Updated: 2021/07/16 16:33:11 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_and_utils/tester.hpp"
#include "../each_tests/create_containers.hpp"
#include "../select_your_tests/select_vector_tests.hpp"
#include "../select_your_tests/select_list_tests.hpp"
#include "../select_your_tests/select_stack_tests.hpp"
#include "../select_your_tests/select_queue_tests.hpp"
#include "../select_your_tests/select_map_tests.hpp"

int main(void)
{
    const int arrInt[20] = {58966, 2147483647, 256, -2147483648, 0, 
                            -1, 2, 3, 4, 5, 6, 7, 7, 8, 54634152, 9, 
                            10, 11, 56, 56465};

    const std::string arrString[20] = {"hello coco", "j'arrive", "oui-oui", "kafeolait", 
                                        "jul d'ananas", "jul d'ananas", "42", "jura", 
                                        "saperlipopette", "anticonstitutionnellement", 
                                        "Pneumonoultramicroscopicsilicovolcanoconiosis", "Blue", 
                                        "Red", "Orange", "Yellow", "boulette de viande hache",
                                        "raviolis du nord est", "PNY", "street bangkok", "confifi"};

    
    // ---------------------------------------------------------------------------
    // CHOOSE HERE WHICH CONTAINERS YOU WANT TO TEST. YOU HAVE ALSO TO COMMENT
    // THE WHOLE FUNCTION BELOW.
        
    testVector(arrInt, arrString);  // Comment if you don't want to test VECTOR   
   //  testList(arrInt, arrString);    // Comment if you don't want to test LIST   
    testStack(arrInt, arrString);   // Comment if you don't want to test STACK   
   //  testQueue(arrInt, arrString);   // Comment if you don't want to test QUEUE   
    testMap(arrInt, arrString);     // Comment if you don't want to test MAP   

    // ---------------------------------------------------------------------------
}


// ---------------------------------------------------------------------------
// COMMENT THE WHOLE FUNCTION IF YOU DON'T WANT TO TEST VECTOR.
// ---------------------------------------------------------------------------
void    testVector(const int (&arrInt)[20], const std::string (&arrString)[20])
{
    //save old buf
    std::streambuf *coutbuf = std::cout.rdbuf();
        
    std::ofstream stdFile("results/vector_std.txt");
    std::ofstream ftFile("results/vector_ft.txt");

    //redirect std::cout to std::vector_result.txt
    std::cout.rdbuf(stdFile.rdbuf());
        
    /* STL TESTS */
    constructVectorList<int, std::vector<int> >(arrInt, testNotConstVec<std::vector<int> >, testConstVec<const std::vector<int> >);
    constructVectorList<std::string, std::vector<std::string> >(arrString, testNotConstVec<std::vector<std::string> >, testConstVec<const std::vector<std::string> >);
        
    //redirect std::cout to ft::vector_result.txt
    std::cout.rdbuf(ftFile.rdbuf());
        
    /* FT TESTS */
    constructVectorList<int, ft::vector<int> >(arrInt, testNotConstVec<ft::vector<int> >, testConstVec<const ft::vector<int> >);
    constructVectorList<std::string, ft::vector<std::string> >(arrString, testNotConstVec<ft::vector<std::string> >, testConstVec<const ft::vector<std::string> >);

    //reset to standard output again
    std::cout.rdbuf(coutbuf);
}


// ---------------------------------------------------------------------------
// COMMENT THE WHOLE FUNCTION IF YOU DON'T WANT TO TEST LIST.
// ---------------------------------------------------------------------------
// void    testList(const int (&arrInt)[20], const std::string (&arrString)[20])
// {
//  //save old buf
//     std::streambuf *coutbuf = std::cout.rdbuf();
        
//     std::ofstream stdFile("results/list_std.txt");
//     std::ofstream ftFile("results/list_ft.txt");

//  //redirect std::cout to std::vector_result.txt
//     std::cout.rdbuf(stdFile.rdbuf());
        
//  /* STL TESTS */
//     constructVectorList<int, std::list<int> >(arrInt, testNotConstList<std::list<int> >, testConstList<const std::list<int> >);
//     constructVectorList<std::string, std::list<std::string> >(arrString, testNotConstList<std::list<std::string> >, testConstList<const std::list<std::string> >);

//  //redirect std::cout to ft::list_result.txt
//     std::cout.rdbuf(ftFile.rdbuf());
        
//  /* FT TESTS */
//     constructVectorList<int, ft::list<int> >(arrInt, testNotConstList<ft::list<int> >, testConstList<const ft::list<int> >);
//     constructVectorList<std::string, ft::list<std::string> >(arrString, testNotConstList<ft::list<std::string> >, testConstList<const ft::list<std::string> >);

//  //reset to standard output again
//     std::cout.rdbuf(coutbuf);
// }


// ---------------------------------------------------------------------------
// COMMENT THE WHOLE FUNCTION IF YOU DON'T WANT TO TEST STACK.
// ---------------------------------------------------------------------------
void    testStack(const int (&arrInt)[20], const std::string (&arrString)[20])
{
    //save old buf
    std::streambuf *coutbuf = std::cout.rdbuf();
        
    std::ofstream stdFile("results/stack_std.txt");
    std::ofstream ftFile("results/stack_ft.txt");

    //redirect std::cout to std::stack_result.txt
    std::cout.rdbuf(stdFile.rdbuf());
        
    /* STL TESTS */
    constructStackQueue<int, std::stack<int, std::list<int> >, std::list<int> >(arrInt, testNonConstStack<std::stack<int, std::list<int> > >);
    constructStackQueue<std::string, std::stack<std::string, std::list<std::string> >, std::list<std::string> > (arrString, testNonConstStack<std::stack<std::string, std::list<std::string> > >);

    //redirect std::cout to ft::stack_result.txt
    std::cout.rdbuf(ftFile.rdbuf());
        
    /* FT TESTS */
    constructStackQueue<int, ft::stack<int, std::list<int> >, std::list<int> >(arrInt, testNonConstStack<ft::stack<int, std::list<int> > >);
    constructStackQueue<std::string, ft::stack<std::string, std::list<std::string> >, std::list<std::string> >(arrString, testNonConstStack<ft::stack<std::string, std::list<std::string> > >);

    //reset to standard output again
    std::cout.rdbuf(coutbuf);
}


// ---------------------------------------------------------------------------
// COMMENT THE WHOLE FUNCTION IF YOU DON'T WANT TO TEST QUEUE.
// ---------------------------------------------------------------------------
// void    testQueue(const int (&arrInt)[20], const std::string (&arrString)[20])
// {
//  //save old buf
//     std::streambuf *coutbuf = std::cout.rdbuf();
        
//     std::ofstream stdFile("results/queue_std.txt");
//     std::ofstream ftFile("results/queue_ft.txt");
        
//  //redirect std::cout to std::queue_result.txt
//     std::cout.rdbuf(stdFile.rdbuf());
        
//  /* STL TESTS */
//     constructStackQueue<int, std::queue<int, std::list<int> >, std::list<int> >(arrInt, testNonConstQueue<std::queue<int, std::list<int> > >);
//     constructStackQueue<std::string, std::queue<std::string, std::list<std::string> >, std::list<std::string> > (arrString, testNonConstQueue<std::queue<std::string, std::list<std::string> > >);
    
//  //redirect std::cout to ft::queue_result.txt
//     std::cout.rdbuf(ftFile.rdbuf());
        
//  /* FT TESTS */
//     constructStackQueue<int, ft::queue<int, std::list<int> >, std::list<int> >(arrInt, testNonConstQueue<ft::queue<int, std::list<int> > >);
//     constructStackQueue<std::string, ft::queue<std::string, std::list<std::string> >, std::list<std::string> >(arrString, testNonConstQueue<ft::queue<std::string, std::list<std::string> > >);

//  //reset to standard output again
//     std::cout.rdbuf(coutbuf);
// }


// ---------------------------------------------------------------------------
// COMMENT THE WHOLE FUNCTION IF YOU DON'T WANT TO TEST MAP.
// ---------------------------------------------------------------------------
void    testMap(const int (&arrInt)[20], const std::string (&arrString)[20])
{
 //save old buf
    std::streambuf *coutbuf = std::cout.rdbuf();
        
    std::ofstream stdFile("results/map_std.txt");
    std::ofstream ftFile("results/map_ft.txt");
        
 //redirect std::cout to ft::map_result.txt
    std::cout.rdbuf(stdFile.rdbuf());
 /* STL TESTS */
    constructMap<int, std::string, std::map<int, std::string>, std::pair<int, std::string> >
        (arrInt, arrString, testNotConstMap<std::map<int, std::string> >, testConstMap<const std::map<int, std::string> >);
    constructMap<std::string, int, std::map<std::string, int>, std::pair<std::string, int> >
        (arrString, arrInt, testNotConstMap<std::map<std::string, int> >, testConstMap<const std::map<std::string, int> >);

 //redirect std::cout to std::map_result.txt
    std::cout.rdbuf(ftFile.rdbuf());
        
 /* FT TESTS */
    constructMap<int, std::string, ft::map<int, std::string>, ft::pair<int, std::string> >
        (arrInt, arrString, testNotConstMap<ft::map<int, std::string> >, testConstMap<const ft::map<int, std::string> >);
    constructMap<std::string, int, ft::map<std::string, int>, ft::pair<std::string, int> >
        (arrString, arrInt, testNotConstMap<ft::map<std::string, int> >, testConstMap<const ft::map<std::string, int> >);

 //reset to standard output again
    std::cout.rdbuf(coutbuf);
}