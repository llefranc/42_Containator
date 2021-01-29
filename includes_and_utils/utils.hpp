/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:44:08 by llefranc          #+#    #+#             */
/*   Updated: 2021/01/29 15:06:11 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

int	getTestNumber(int *nb);
const std::string getTestName(int testNb, std::string name);
std::string toString(int i);
void printTestName(std::string name, const std::string& info = "");

#endif