/* ************************************************************************** */
/*                                      */
/*                            :::     ::::::::   */
/*   create_containers.hpp                :+:   :+:    :+:   */
/*                          +:+ +:+       +:+    */
/*   By: llefranc <llefranc@student.42.fr>      +#+  +:+       +#+    */
/*                        +#+#+#+#+#+   +#+     */
/*   Created: 2021/01/26 14:42:21 by hherin   #+#  #+#          */
/*   Updated: 2021/02/17 09:58:00 by llefranc       ###   ########.fr    */
/*                                      */
/* ************************************************************************** */

#ifndef CONTAINERCREATE_HPP
# define CONTAINERCREATE_HPP

#include <iostream>

/**
*	Constructs the following containers for testing : vector, list.
*/
template <class T, class Cont, class Func, class FuncC>
void constructVectorList(const T (&x)[20], Func execNonConst, FuncC execConst)
{   
    int nb = 0;
    Cont c0;
	execNonConst(c0, ++nb);

    for (int i = 0; i < 10; i++){
        c0.push_back(x[i]);
        execNonConst(c0, ++nb);
        
        if (!i%3){
            Cont tmp(c0);
            execNonConst(tmp, ++nb);
        }
        if (!i%2){
            Cont tmp;
            tmp = c0;
            execNonConst(tmp, ++nb);
        }
    }

    Cont c1(c0);
    execNonConst(c1, ++nb);
        
    Cont c2; c2 = c0;
    execNonConst(c2, ++nb);

	typename Cont::iterator beg = c0.begin(); ++beg;
	typename Cont::iterator end = c0.end(); --end;
    Cont c3(beg, end);
    execNonConst(c3, ++nb);

    Cont c4(c0.begin(), c0.begin());
    execNonConst(c4, ++nb);
        
    Cont c5(10, x[11]);
    execNonConst(c5, ++nb);
        
    Cont c6(0, x[12]);
    execNonConst(c6, ++nb);

    Cont c7(12, x[13]);
    execNonConst(c7, ++nb);

    Cont c8(c0); c8.push_back(x[19]); c8.push_back(x[19]); c8.front() = x[14];
    execNonConst(c8, ++nb);

	const Cont c9;
	execConst(c9, ++nb);

    const Cont c10(5, x[15]);
    execConst(c10, ++nb);
        
	const Cont c11;
	execConst(c11, ++nb);
    		
	const Cont c12(c1);
    execConst(c12, ++nb);
        
	const Cont c13(c9);
    execConst(c13, ++nb);

	const Cont c14(3, x[16]);
    execConst(c14, ++nb);
}

/**
*	Constructs the following containers for testing : queue, stack.
*/
template <class T, class StaQue, class Cont, class Func>
void constructStackQueue(const T (&x)[20], Func execNonConst)
{   
    int nb = 0;
    Cont c0;
	StaQue stEmpty(c0);
	execNonConst(stEmpty, ++nb);

    for (int i = 0; i < 10; i++){
        c0.push_back(x[i]);
        StaQue st0(c0);
        execNonConst(st0, ++nb);
        
        if (!i%3){
            StaQue stmp(c0);
            execNonConst(stmp, ++nb);
        }
        if (!i%2){
            StaQue stmp = st0;
            execNonConst(stmp, ++nb);
        }
    }

    StaQue st1(c0);
    execNonConst(st1, ++nb);
        
    Cont c2; c2 = c0;
    StaQue st2; st2 = st1;
    execNonConst(st2, ++nb);

	typename Cont::iterator beg = c0.begin(); ++beg;
	typename Cont::iterator end = c0.end(); --end;

    Cont c3(beg, end);
    StaQue st3(c3);
    execNonConst(st3, ++nb);

    Cont c4(c0.begin(), c0.begin());
    StaQue st4(c4);
    execNonConst(st4, ++nb);
        
    Cont c5(10, x[5]);
    StaQue st5(c5);
    execNonConst(st5, ++nb);
        
    Cont c6(0, x[6]);
    StaQue st6(c6);
    execNonConst(st6, ++nb);

    Cont c7(12, x[10]);
    StaQue st7(c7);
    execNonConst(st7, ++nb);

    Cont c8(c0); c8.push_back(x[19]); c8.push_back(x[19]); c8.front() = x[15];
    StaQue st8(c8);
    execNonConst(st8, ++nb);

}

/**
*	Constructs the following containers for testing : map.
*/
template <class T1, class T2, class Cont, class P, class Func, class FuncC>
void constructMap(const T1 (&x)[20], const T2 (&y)[20], Func execNonConst, FuncC execConst)
{   
	(void)execConst;
	
    int nb = 0;
    Cont c0;
    for (int i = 0; i < 10; i++){
		P pair(x[i], y[i]);
        c0.insert(pair);
        execNonConst(c0, ++nb);
        
        if (!i%3){
            Cont tmp(c0);
            execNonConst(tmp, ++nb);
        }
        if (!i%2){
            Cont tmp;
            tmp = c0;
            execNonConst(tmp, ++nb);
        }
    }
	
    Cont c1(c0);
    execNonConst(c1, ++nb);
        
    Cont c2; c2 = c0;
    execNonConst(c2, ++nb);

	typename Cont::iterator beg = c0.begin(); ++beg;
	typename Cont::iterator end = c0.end(); --end;
    Cont c3(beg, end);
    execNonConst(c3, ++nb);

    Cont c4(c0.begin(), c0.begin());
    execNonConst(c4, ++nb);
        
	P pair19(x[19], y[19]);
	P pair14(x[14], y[14]);
    Cont c8(c0); c8.insert(pair19); c8.insert(pair14);
    execNonConst(c8, ++nb);

	const Cont c10;
	execConst(c10, ++nb);
    		
	const Cont c11(c1);
    execConst(c11, ++nb);
}


#endif