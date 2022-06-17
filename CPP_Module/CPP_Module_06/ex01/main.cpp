/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:54:31 by hyseo             #+#    #+#             */
/*   Updated: 2022/06/17 14:05:07 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

struct Data
{
	std::string s1;
	std::string s2;
	int s3;
};

static uintptr_t serialize_ptr(Data * d)
{
	return(reinterpret_cast<uintptr_t>(d));
}

static Data* deserialize(uintptr_t u)
{
	return (reinterpret_cast<Data *>(u));
}

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
