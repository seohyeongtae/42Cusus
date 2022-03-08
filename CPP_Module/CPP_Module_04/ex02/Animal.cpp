/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:16:32 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/08 00:55:13 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(/* args */)
{
	this->type = "";
	std::cout << "Animal Constructor Called" << std::endl;
}

Animal::Animal(std::string name)
{
	this->type = name;
	std::cout << "Animal Constructor with name Called" << std::endl;
}

Animal::Animal(Animal const &ani)
{
	this->type = ani.type;
	std::cout << "Animal Copy Constructor Called" << std::endl; 
}

Animal & Animal::operator = (Animal const &ani)
{
	this->type = ani.type;
	std::cout << "Animal operator Called" << std::endl;
	return (*this);
}

void	Animal::setType(std::string const n)
{
	this->type = n;
}

std::string	Animal::getType() const
{
	return (this->type);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}
