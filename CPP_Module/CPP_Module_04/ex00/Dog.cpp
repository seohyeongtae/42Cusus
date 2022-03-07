/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:30:58 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/07 23:09:29 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog Constructor Called" << std::endl;
}

Dog::Dog(Dog const &d) : Animal()
{
	this->type = d.type;
	std::cout << "Dog Copy Constructor Called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog makeSound bark bark!!" << std::endl;
}

Dog & Dog::operator = (Dog const &d)
{
	this->type = d.type;
	std::cout << "Dog operator Called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
}
