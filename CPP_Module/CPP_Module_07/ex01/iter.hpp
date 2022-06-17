/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:15:30 by hyseo             #+#    #+#             */
/*   Updated: 2022/06/17 15:23:31 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* type, int size, void(*f)(T&))
{
    for (int i = 0; i < size; i++)
        f(type[i]);
}

template<typename T>
void print(T p)
{
    std::cout << p << std::endl;
}

#endif