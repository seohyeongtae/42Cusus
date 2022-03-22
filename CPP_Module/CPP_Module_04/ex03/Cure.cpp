/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:24:53 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/22 18:52:26 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Constructor Called" << std::endl;
}

AMateria * Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(const ICharacter & target)
{
	std::cout << "heals " << target.getName() << "'s wounds" << std::endl;
}

Cure::Cure(const std::string& type) : AMateria(type)
{
	std::cout << "Cure Constructor Called With name" << std::endl;
}

Cure::Cure(const Cure & c)
{
	this->type = c.type;
	std::cout << "Cure Copy Constructor Called" << std::endl;
}

Cure & Cure::operator=(const Cure& c)
{
	this->type = c.type;
	std::cout << "Cure operator Called" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor Called" << std::endl;
}
