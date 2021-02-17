/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:27:13 by llefranc          #+#    #+#             */
/*   Updated: 2021/02/17 10:51:52 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

// Include the containers to test
#include "../../42_ft_containers/containers/vector.hpp"
#include "../../42_ft_containers/containers/list.hpp"
# include "../../42_ft_containers/containers/stack.hpp"
# include "../../42_ft_containers/containers/queue.hpp"
# include "../../42_ft_containers/containers/map.hpp"

// Needed for testing
#include "stl_like.hpp"
#include "utils.hpp"
#include "print_type.hpp"

void    testVector(const int (&arrInt)[20], const std::string (&arrString)[20]);
void    testList(const int (&arrInt)[20], const std::string (&arrString)[20]);
void    testStack(const int (&arrInt)[20], const std::string (&arrString)[20]);
void    testQueue(const int (&arrInt)[20], const std::string (&arrString)[20]);
void    testMap(const int (&arrInt)[20], const std::string (&arrString)[20]);

#endif