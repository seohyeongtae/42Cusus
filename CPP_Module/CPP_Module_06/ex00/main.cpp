/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:54:31 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/26 19:12:20 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
		std::cout << "please check input  [ ./Convert {input} ]" << std::endl;
	else
	{
		std::string input = argv[1];
		Convert c(input);
		// // 문자열은 들어오지 않는다.
		// int convertInt = std::atoi(argv[1]);
		// double convertDouble = std::atof(argv[1]);
		// std::cout << static_cast<char>(convertDouble) << std::endl;
		// std::cout << static_cast<int>(convertDouble) << std::endl;
		// std::cout << static_cast<float>(convertDouble) << std::endl;
		// std::cout << convertDouble << std::endl;
	}
	return (0);
}