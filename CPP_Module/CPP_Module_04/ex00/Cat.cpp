/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:30:58 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/22 15:47:41 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(Cat const &c) : Animal()
{
	this->type = c.type;
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat makeSound Meow Meow!!" << std::endl;
}

Cat & Cat::operator = (Cat const &c)
{
	this->type = c.type;
	std::cout << "Cat operator Called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
}
