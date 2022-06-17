/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:15:11 by hyseo             #+#    #+#             */
/*   Updated: 2022/06/17 15:23:03 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    std::string s[3] = { "42", "Seoul", "hyseo" };
    int i[6] = { 0 , 1, 2, 3, 4, 5 };
    double d[9] = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    char c[12] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l' };

    std::cout << "String Iteration\t: ";
    iter(s, sizeof(s) / sizeof(*s), print);
    std::cout << std::endl;
    std::cout << "Int Iteration\t\t: ";
    iter(i, sizeof(i) / sizeof(*i), print);
    std::cout << std::endl;
    std::cout << "Double Iteration\t: ";
    iter(d, sizeof(d) / sizeof(*d), print);
    std::cout << std::endl;
    std::cout << "Char Iteration\t\t: ";
    iter(c, sizeof(c) / sizeof(*c), print);
    std::cout << std::endl;
    return (0);
}