/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:54:31 by hyseo             #+#    #+#             */
/*   Updated: 2022/06/14 20:24:32 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


int main(void)
{
	Data temp;
	temp.s1 = "Hello";
	temp.s2 = "world";
	temp.s3 = 10;

	uintptr_t serialize_ptr = serialize(&temp);
	std::cout << "serialize ptr = " << serialize_ptr << std::endl;

	Data *ptr = deserialize(serialize_ptr);
	std::cout << &ptr << std::endl;
	std::cout << "deserialize  s1 = " << ptr->s1 << "  s2 = " << ptr->s2 << "   s3   =  " << ptr->s3;

	return (0);
}
