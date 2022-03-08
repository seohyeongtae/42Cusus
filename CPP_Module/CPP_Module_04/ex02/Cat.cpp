/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:30:58 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/07 23:43:59 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->attribute = new Brain();
	std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(Cat const &c) : Animal()
{
	if (c.attribute)
		this->attribute = new Brain(*c.attribute);
	else
		this->attribute = new Brain();
	this->type = c.type;
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat makeSound Meow Meow!!" << std::endl;
}

Brain	*Cat::getBrain() const
{
	if (this->attribute)
		return (this->attribute);
	return NULL;
}

Cat & Cat::operator = (Cat const &c)
{
	this->type = c.type;
	this->attribute = new Brain(*c.getBrain());
	std::cout << "Cat operator Called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
	delete this->attribute;
}
