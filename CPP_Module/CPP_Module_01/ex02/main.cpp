/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:15:16 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/24 02:06:37 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << " address in memory of the string           "  << &str << std::endl;
	std::cout << "address of the string by using stringPTR   " << stringPTR << std::endl;
	std::cout << "address of the string by using stringREF   " << &stringREF << std::endl;
	
	std::cout << "string using the pointer     " << *stringPTR  << std::endl;
	std::cout << "string using the references  " << stringREF << std::endl;

	return (0);
}
