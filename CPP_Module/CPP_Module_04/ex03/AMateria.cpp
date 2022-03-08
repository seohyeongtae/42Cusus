/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:12:34 by hyseo             #+#    #+#             */
/*   Updated: 2022/03/08 02:27:56 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "";
	std::cout << "AMateria Constructor Called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	std::cout << "AMateria type Constructor Called" << std::endl;
}

std::string const AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter & target)
{
	std::cout << "AMateria use " << target.getName() << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor Called" << std::endl;
}
