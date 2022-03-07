/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:50:58 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/07 21:04:45 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */)
{
	this->type = "";
	std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name)
{
	this->type = name;
	std::cout << "WrongAnimal Constructor with name Called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &ani)
{
	this->type = ani.type;
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl; 
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makeSound" << std::endl;
}

WrongAnimal & WrongAnimal::operator = (WrongAnimal const &ani)
{
	this->type = ani.type;
	std::cout << "WrongAnimal operator Called" << std::endl;
	return (*this);
}

void	WrongAnimal::setType(std::string const n)
{
	this->type = n;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}
