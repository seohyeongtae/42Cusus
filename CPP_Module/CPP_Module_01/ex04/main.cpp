/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:24:48 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/24 23:31:36 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4 || std::strlen(argv[1]) == 0)
	{
		std::cout << " plaese check argc, argv " << std::endl;
		return (1);
	}
	for (int i = 1; i < 4; i++)
	{
		if (std::strlen(argv[i]) == 0)
		{
			std::cout << " plaese check argc, argv " << std::endl;
			return (1);
		}
	}
	
	return (0);
}