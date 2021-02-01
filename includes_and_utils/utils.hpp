/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:44:08 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/01 15:22:59 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

int	getTestNumber(int *nb);
const std::string getTestName(int testNb, std::string name);
std::string toString(int i);
void printTestName(const std::string& nbLine, std::string name, const std::string& info = "");
std::string NumberToString (int Number);

#endif