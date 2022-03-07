/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:50:41 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/07 21:04:51 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Constructor Called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &c)
{
	this->type = c.type;
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat makeSound Meow Meow!!" << std::endl;
}

WrongCat & WrongCat::operator = (WrongCat const &c)
{
	this->type = c.type;
	std::cout << "WrongCat operator Called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called" << std::endl;
}
