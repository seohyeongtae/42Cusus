/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:20:49 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/19 17:42:46 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

#define exit 1

int main(int argc, char **argv)
{
	while (exit)
	{
		if (argc == 1)
			std::cout << "Plase input command" << std::endl;
		else if (argc == 2)
		{
			std::string str;
			str = argv[1];
			printf("%s", str.c_str());

		}
		else
			std::cout << "To many command" << std::endl;
		std::string a;
			std::cin >> a;
	}
}