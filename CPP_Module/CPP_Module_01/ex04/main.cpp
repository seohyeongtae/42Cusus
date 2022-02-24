/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:24:48 by hyseo             #+#    #+#             */
/*   Updated: 2022/02/25 00:37:29 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4 || std::strlen(argv[1]) == 0)
	{
		std::cout << " plaese check filename ,s1 ,s2 " << std::endl;
		return (1);
	}
	for (int i = 1; i < 4; i++)
	{
		if (std::strlen(argv[i]) == 0)
		{
			std::cout << " plaese check filename ,s1 ,s2 " << std::endl;
			return (1);
		}
	}
	std::ifstream	ifs;
	
	ifs.open(argv[1]);
	if (ifs.fail())
	{
		std::cout << " error : open(filename) " << std::endl;
		ifs.close();
		return (1);
	}
	std::ofstream	ofs;
	std::string	replace = argv[1];
	replace.append(".replace");
	ofs.open(replace);
	if (ofs.fail())
	{
		std::cout <<  " error : create(filename.replace) " << std::endl;
		ofs.close();
		return (1);
	}
	while(!ifs.eof())
	{
		std::string str;
		std::getline(ifs , str);

		std::size_t	index = str.find(argv[2]);
		while (index != std::string::npos)
		{
			std::string	prev = str.substr(0, index);
			ofs << prev << argv[3];
			std::string	after = str.substr(index + std::strlen(argv[2]));
			str = after;
			index = str.find(argv[2]);
		}
		ofs << str;
		if (!ifs.eof())
			ofs << std::endl;
	}
	return (0);
}
