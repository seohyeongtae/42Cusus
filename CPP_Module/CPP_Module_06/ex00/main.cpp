/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:54:31 by hyseo             #+#    #+#             */
/*   Updated: 2022/06/14 15:15:42 by hyseo            ###   ########.fr       */
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
	}
	return (0);
}