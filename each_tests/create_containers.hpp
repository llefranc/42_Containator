/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContainerCreate.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:42:21 by hherin            #+#    #+#             */
/*   Updated: 2021/02/03 12:27:31 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERCREATE_HPP
# define CONTAINERCREATE_HPP

#include <iostream>

/**
*	Constructs the following containers for testing : vector, list.
*/
template <class T, class C, class Func, class FuncC>
void ContainerConstruct(const T (&x)[20], Func execNonConst, FuncC execConst)
{    
    int nb = 0;
    C c0;
    for (int i = 0; i < 10; i++){
        c0.push_back(x[i]);
        execNonConst(c0, ++nb);
        
        if (!i%3){
            C tmp(c0);
            execNonConst(tmp, ++nb);
        }
        if (!i%2){
            C tmp;
            tmp = c0;
            execNonConst(tmp, ++nb);
        }
    }

    C c1(c0);
    execNonConst(c1, ++nb);
    
    C c2; c2 = c0;
    execNonConst(c2, ++nb);

	typename C::iterator beg = c0.begin(); ++beg;
	typename C::iterator end = c0.end(); --end;
    C c3(beg, end);
    execNonConst(c3, ++nb);

    C c4(c0.begin(), c0.begin());
    execNonConst(c4, ++nb);
    
    C c5(10, x[11]);
    execNonConst(c5, ++nb);
    
    C c6(0, x[12]);
    execNonConst(c6, ++nb);

    C c7(12, x[13]);
    execNonConst(c7, ++nb);

    C c8(c0); c8.push_back(x[19]); c8.push_back(x[19]); c8.front() = x[14];
    execNonConst(c8, ++nb);

    const C c9(5, x[15]);
    execConst(c9, ++nb);
    
	const C c10;
	execConst(c10, ++nb);
    		
	const C c11(c1);
    execConst(c11, ++nb);
    
	const C c12(c9);
    execConst(c12, ++nb);

	const C c13(3, x[16]);
    execConst(c13, ++nb);
}

/**
*	Constructs the following containers for testing : queue, stack.
*/
template <class T, class S, class C, class Func>
void StaQueuConstruct(const T (&x)[20], Func execNonConst)
{    
    int nb = 0;
    C c0;

    for (int i = 0; i < 10; i++){
        c0.push_back(x[i]);
        S st0(c0);
        execNonConst(st0, ++nb);
        
        if (!i%3){
            S stmp(c0);
            execNonConst(stmp, ++nb);
        }
        if (!i%2){
            S stmp = st0;
            execNonConst(stmp, ++nb);
        }
    }

    S st1(c0);
    execNonConst(st1, ++nb);
    
    C c2; c2 = c0;
    S st2; st2 = st1;
    execNonConst(st2, ++nb);

	typename C::iterator beg = c0.begin(); ++beg;
	typename C::iterator end = c0.end(); --end;

    C c3(beg, end);
    S st3(c3);
    execNonConst(st3, ++nb);

    C c4(c0.begin(), c0.begin());
    S st4(c4);
    execNonConst(st4, ++nb);
    
    C c5(10, x[5]);
    S st5(c5);
    execNonConst(st5, ++nb);
    
    C c6(0, x[6]);
    S st6(c6);
    execNonConst(st6, ++nb);

    C c7(12, x[10]);
    S st7(c7);
    execNonConst(st7, ++nb);

    C c8(c0); c8.push_back(x[19]); c8.push_back(x[19]); c8.front() = x[15];
    S st8(c8);
    execNonConst(st8, ++nb);

}


#endif