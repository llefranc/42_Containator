/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:38:11 by llefranc          #+#    #+#             */
/*   Updated: 2021/01/27 12:39:27 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

std::string toString(int i)
{
   std::stringstream ss;
   ss << i;
   return ss.str();
}

const std::string getTestName(int testNb, std::string name)
{
	return std::string("\ntest " + toString(testNb) + ": " + name + ":");
}

void printTestName(std::string name, const std::string& info)
{
	std::cout.width(45);
	if (!info.empty())
		name = name + " " + info + ":";
	std::cout << std::left << name;
	std::cout.width(0);
}

int	getTestNumber(int *nb)
{
	static int i = 0;

	if (nb)
		i = *nb;
	else
		return ++i;
	return 0;
}