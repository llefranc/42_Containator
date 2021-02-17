/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _select_your_containers.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:37:35 by hherin            #+#    #+#             */
/*   Updated: 2021/02/17 10:51:29 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_and_utils/tester.hpp"

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

    
    testVector(arrInt, arrString);
    testList(arrInt, arrString);
    testStack(arrInt, arrString);
    testQueue(arrInt, arrString);
    testMap(arrInt, arrString);
}