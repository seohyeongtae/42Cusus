/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:14:36 by hyseo             #+#    #+#             */
/*   Updated: 2022/04/26 19:15:44 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : input(0) {}

Convert::Convert(std::string& in) : input(std::atof(in.c_str()))
{
	// char 출력
	if ((input >= 0 || input < 128) && !std::isinf(input))
	{
		if (input <= 32 || input == 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << to_Char() << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	// int 출력
	if (std::isinf(input))
		std::cout << "int: " << 2147483647 << std::endl;
	else if (std::isnan(input) || input > 2147483647 || input < -2147483648)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << to_Int() << std::endl;
	// float 출력
	if (to_Float() - to_Int() != 0)
		std::cout << "float: " << to_Float() << "f" << std::endl;
	else
		std::cout << "float: " << to_Float() << ".0f" << std::endl;
	//double 출력
	if (input - to_Int() != 0)
		std::cout << "double: " << input << std::endl;
	else
		std::cout << "double: " << input << ".0" << std::endl;
}

Convert::Convert(const Convert& c) : input(c.getInput()) { }

char	Convert::to_Char() const {
	return static_cast<char>(input);
}

int		Convert::to_Int() const {
	return static_cast<int>(input);
}

float	Convert::to_Float() const {
	return static_cast<float>(input);
}

double	Convert::to_Double() const {
	return input;
}

const double	Convert::getInput() const {
	return input;
};

Convert& Convert::operator=(const Convert& c){
	if (this != &c)
		*(const_cast<double*>(&input)) = c.getInput();
		
	return *this;
}

Convert::~Convert() { }
